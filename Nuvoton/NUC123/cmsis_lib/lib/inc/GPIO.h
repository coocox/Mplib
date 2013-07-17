/******************************************************************************
 * @file     GPIO.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/14 15:12p $
 * @brief    NUC123 Series GPIO Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup GPIO_MACRO GPIO Macro
  * @{
  */

/** @addtogroup GPIO_MACRO_CONTANT GPIO Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIOx_PMD constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INPUT                      0x0UL                  /*!< Input Mode */
#define GPIO_OUTPUT                     0x1UL                  /*!< Output Mode */
#define GPIO_OPEN_DRAIN                 0x2UL                  /*!< Open-Drain Mode */
#define GPIO_QUASI                      0x3UL                  /*!< Quasi-bidirectional Mode */
#define GPIO_MODE(pin, mode)            ((mode) << ((pin)<<1)) /*!< Generate the PMD mode setting for each pin  */

#define GPIO_Px15_IN                    (0UL<<GPIO_PMD_PMD15_Pos) /*!< Set GPIOx_P15 pin to input mode */
#define GPIO_Px15_OUT                   (1UL<<GPIO_PMD_PMD15_Pos) /*!< Set GPIOx_P15 pin to output mode */
#define GPIO_Px15_OD                    (2UL<<GPIO_PMD_PMD15_Pos) /*!< Set GPIOx_P15 pin to open-drain mode */
#define GPIO_Px15_QB                    (3UL<<GPIO_PMD_PMD15_Pos) /*!< Set GPIOx_P15 pin to quasi-bidirectional mode */

#define GPIO_Px14_IN                    (0UL<<GPIO_PMD_PMD15_Pos) /*!< Set GPIOx_P14 pin to input mode */
#define GPIO_Px14_OUT                   (1UL<<GPIO_PMD_PMD14_Pos) /*!< Set GPIOx_P14 pin to output mode */
#define GPIO_Px14_OD                    (2UL<<GPIO_PMD_PMD14_Pos) /*!< Set GPIOx_P14 pin to open-drain mode */
#define GPIO_Px14_QB                    (3UL<<GPIO_PMD_PMD14_Pos) /*!< Set GPIOx_P14 pin to quasi-bidirectional mode */

#define GPIO_Px13_IN                    (0UL<<GPIO_PMD_PMD13_Pos) /*!< Set GPIOx_P13 pin to input mode */
#define GPIO_Px13_OUT                   (1UL<<GPIO_PMD_PMD13_Pos) /*!< Set GPIOx_P13 pin to output mode */
#define GPIO_Px13_OD                    (2UL<<GPIO_PMD_PMD13_Pos) /*!< Set GPIOx_P13 pin to open-drain mode */
#define GPIO_Px13_QB                    (3UL<<GPIO_PMD_PMD13_Pos) /*!< Set GPIOx_P13 pin to quasi-bidirectional mode */

#define GPIO_Px12_IN                    (0UL<<GPIO_PMD_PMD12_Pos) /*!< Set GPIOx_P12 pin to input mode */
#define GPIO_Px12_OUT                   (1UL<<GPIO_PMD_PMD12_Pos) /*!< Set GPIOx_P12 pin to output mode */
#define GPIO_Px12_OD                    (2UL<<GPIO_PMD_PMD12_Pos) /*!< Set GPIOx_P12 pin to open-drain mode */
#define GPIO_Px12_QB                    (3UL<<GPIO_PMD_PMD12_Pos) /*!< Set GPIOx_P12 pin to quasi-bidirectional mode */

#define GPIO_Px11_IN                    (0UL<<GPIO_PMD_PMD11_Pos) /*!< Set GPIOx_P11 pin to input mode */
#define GPIO_Px11_OUT                   (1UL<<GPIO_PMD_PMD11_Pos) /*!< Set GPIOx_P11 pin to output mode */
#define GPIO_Px11_OD                    (2UL<<GPIO_PMD_PMD11_Pos) /*!< Set GPIOx_P11 pin to open-drain mode */
#define GPIO_Px11_QB                    (3UL<<GPIO_PMD_PMD11_Pos) /*!< Set GPIOx_P11 pin to quasi-bidirectional mode */

#define GPIO_Px10_IN                    (0UL<<GPIO_PMD_PMD10_Pos) /*!< Set GPIOx_P10 pin to input mode */
#define GPIO_Px10_OUT                   (1UL<<GPIO_PMD_PMD10_Pos) /*!< Set GPIOx_P10 pin to output mode */
#define GPIO_Px10_OD                    (2UL<<GPIO_PMD_PMD10_Pos) /*!< Set GPIOx_P10 pin to open-drain mode */
#define GPIO_Px10_QB                    (3UL<<GPIO_PMD_PMD10_Pos) /*!< Set GPIOx_P10 pin to quasi-bidirectional mode */

#define GPIO_Px9_IN                     (0UL<<GPIO_PMD_PMD9_Pos) /*!< Set GPIOx_P9 pin to input mode */
#define GPIO_Px9_OUT                    (1UL<<GPIO_PMD_PMD9_Pos) /*!< Set GPIOx_P9 pin to output mode */
#define GPIO_Px9_OD                     (2UL<<GPIO_PMD_PMD9_Pos) /*!< Set GPIOx_P9 pin to open-drain mode */
#define GPIO_Px9_QB                     (3UL<<GPIO_PMD_PMD9_Pos) /*!< Set GPIOx_P9 pin to quasi-bidirectional mode */

#define GPIO_Px8_IN                     (0UL<<GPIO_PMD_PMD8_Pos) /*!< Set GPIOx_P8 pin to input mode */
#define GPIO_Px8_OUT                    (1UL<<GPIO_PMD_PMD8_Pos) /*!< Set GPIOx_P8 pin to output mode */
#define GPIO_Px8_OD                     (2UL<<GPIO_PMD_PMD8_Pos) /*!< Set GPIOx_P8 pin to open-drain mode */
#define GPIO_Px8_QB                     (3UL<<GPIO_PMD_PMD8_Pos) /*!< Set GPIOx_P8 pin to quasi-bidirectional mode */

#define GPIO_Px7_IN                     (0UL<<GPIO_PMD_PMD7_Pos) /*!< Set GPIOx_P7 pin to input mode */
#define GPIO_Px7_OUT                    (1UL<<GPIO_PMD_PMD7_Pos) /*!< Set GPIOx_P7 pin to output mode */
#define GPIO_Px7_OD                     (2UL<<GPIO_PMD_PMD7_Pos) /*!< Set GPIOx_P7 pin to open-drain mode */
#define GPIO_Px7_QB                     (3UL<<GPIO_PMD_PMD7_Pos) /*!< Set GPIOx_P7 pin to quasi-bidirectional mode */

#define GPIO_Px6_IN                     (0UL<<GPIO_PMD_PMD6_Pos) /*!< Set GPIOx_P6 pin to input mode */
#define GPIO_Px6_OUT                    (1UL<<GPIO_PMD_PMD6_Pos) /*!< Set GPIOx_P6 pin to output mode */
#define GPIO_Px6_OD                     (2UL<<GPIO_PMD_PMD6_Pos) /*!< Set GPIOx_P6 pin to open-drain mode */
#define GPIO_Px6_QB                     (3UL<<GPIO_PMD_PMD6_Pos) /*!< Set GPIOx_P6 pin to quasi-bidirectional mode */

#define GPIO_Px5_IN                     (0UL<<GPIO_PMD_PMD5_Pos) /*!< Set GPIOx_P5 pin to input mode */
#define GPIO_Px5_OUT                    (1UL<<GPIO_PMD_PMD5_Pos) /*!< Set GPIOx_P5 pin to output mode */
#define GPIO_Px5_OD                     (2UL<<GPIO_PMD_PMD5_Pos) /*!< Set GPIOx_P5 pin to open-drain mode */
#define GPIO_Px5_QB                     (3UL<<GPIO_PMD_PMD5_Pos) /*!< Set GPIOx_P5 pin to quasi-bidirectional mode */

#define GPIO_Px4_IN                     (0UL<<GPIO_PMD_PMD4_Pos) /*!< Set GPIOx_P4 pin to input mode */
#define GPIO_Px4_OUT                    (1UL<<GPIO_PMD_PMD4_Pos) /*!< Set GPIOx_P4 pin to output mode */
#define GPIO_Px4_OD                     (2UL<<GPIO_PMD_PMD4_Pos) /*!< Set GPIOx_P4 pin to open-drain mode */
#define GPIO_Px4_QB                     (3UL<<GPIO_PMD_PMD4_Pos) /*!< Set GPIOx_P4 pin to quasi-bidirectional mode */

#define GPIO_Px3_IN                     (0UL<<GPIO_PMD_PMD3_Pos) /*!< Set GPIOx_P3 pin to input mode */
#define GPIO_Px3_OUT                    (1UL<<GPIO_PMD_PMD3_Pos) /*!< Set GPIOx_P3 pin to output mode */
#define GPIO_Px3_OD                     (2UL<<GPIO_PMD_PMD3_Pos) /*!< Set GPIOx_P3 pin to open-drain mode */
#define GPIO_Px3_QB                     (3UL<<GPIO_PMD_PMD3_Pos) /*!< Set GPIOx_P3 pin to quasi-bidirectional mode */

#define GPIO_Px2_IN                     (0UL<<GPIO_PMD_PMD2_Pos) /*!< Set GPIOx_P2 pin to input mode */
#define GPIO_Px2_OUT                    (1UL<<GPIO_PMD_PMD2_Pos) /*!< Set GPIOx_P2 pin to output mode */
#define GPIO_Px2_OD                     (2UL<<GPIO_PMD_PMD2_Pos) /*!< Set GPIOx_P2 pin to open-drain mode */
#define GPIO_Px2_QB                     (3UL<<GPIO_PMD_PMD2_Pos) /*!< Set GPIOx_P2 pin to quasi-bidirectional mode */

#define GPIO_Px1_IN                     (0UL<<GPIO_PMD_PMD1_Pos) /*!< Set GPIOx_P1 pin to input mode */
#define GPIO_Px1_OUT                    (1UL<<GPIO_PMD_PMD1_Pos) /*!< Set GPIOx_P1 pin to output mode */
#define GPIO_Px1_OD                     (2UL<<GPIO_PMD_PMD1_Pos) /*!< Set GPIOx_P1 pin to open-drain mode */
#define GPIO_Px1_QB                     (3UL<<GPIO_PMD_PMD1_Pos) /*!< Set GPIOx_P1 pin to quasi-bidirectional mode */

#define GPIO_Px0_IN                     (0UL<<GPIO_PMD_PMD0_Pos) /*!< Set GPIOx_P0 pin to input mode */
#define GPIO_Px0_OUT                    (1UL<<GPIO_PMD_PMD0_Pos) /*!< Set GPIOx_P0 pin to output mode */
#define GPIO_Px0_OD                     (2UL<<GPIO_PMD_PMD0_Pos) /*!< Set GPIOx_P0 pin to open-drain mode */
#define GPIO_Px0_QB                     (3UL<<GPIO_PMD_PMD0_Pos) /*!< Set GPIOx_P0 pin to quasi-bidirectional mode */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIOx_OFFD constant definitions.                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_OFFD_ENABLE(pin)           (1UL<<((pin)+16)) /*!< OFFD setting for disable specified pin I/O digital input path */
#define GPIO_OFFD_DISABLE(pin)          (~(1UL<<((pin)+16))) /*!< OFFD setting for enable specified pin I/O digital input path */

#define GPIO_OFFD_Px15_OFF              (1UL<<GPIO_OFFD_OFFD15_Pos) /*!< Disable GPIOx_P15 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px15_ON               (0UL<<GPIO_OFFD_OFFD15_Pos) /*!< Enable GPIOx_P15 pin digital input path */

#define GPIO_OFFD_Px14_OFF              (1UL<<GPIO_OFFD_OFFD14_Pos) /*!< Disable GPIOx_P14 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px14_ON               (0UL<<GPIO_OFFD_OFFD14_Pos) /*!< Enable GPIOx_P14 pin digital input path */

#define GPIO_OFFD_Px13_OFF              (1UL<<GPIO_OFFD_OFFD13_Pos) /*!< Disable GPIOx_P13 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px13_ON               (0UL<<GPIO_OFFD_OFFD13_Pos) /*!< Enable GPIOx_P13 pin digital input path */

#define GPIO_OFFD_Px12_OFF              (1UL<<GPIO_OFFD_OFFD12_Pos) /*!< Disable GPIOx_P12 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px12_ON               (0UL<<GPIO_OFFD_OFFD12_Pos) /*!< Enable GPIOx_P12 pin digital input path */

#define GPIO_OFFD_Px11_OFF              (1UL<<GPIO_OFFD_OFFD11_Pos) /*!< Disable GPIOx_P11 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px11_ON               (0UL<<GPIO_OFFD_OFFD11_Pos) /*!< Enable GPIOx_P11 pin digital input path */

#define GPIO_OFFD_Px10_OFF              (1UL<<GPIO_OFFD_OFFD10_Pos) /*!< Disable GPIOx_P10 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px10_ON               (0UL<<GPIO_OFFD_OFFD10_Pos) /*!< Enable GPIOx_P10 pin digital input path */

#define GPIO_OFFD_Px9_OFF               (1UL<<GPIO_OFFD_OFFD9_Pos) /*!< Disable GPIOx_P9 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px9_ON                (0UL<<GPIO_OFFD_OFFD9_Pos) /*!< Enable GPIOx_P9 pin digital input path */

#define GPIO_OFFD_Px8_OFF               (1UL<<GPIO_OFFD_OFFD8_Pos) /*!< Disable GPIOx_P8 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px8_ON                (0UL<<GPIO_OFFD_OFFD8_Pos) /*!< Enable GPIOx_P8 pin digital input path */

#define GPIO_OFFD_Px7_OFF               (1UL<<GPIO_OFFD_OFFD7_Pos) /*!< Disable GPIOx_P7 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px7_ON                (0UL<<GPIO_OFFD_OFFD7_Pos) /*!< Enable GPIOx_P7 pin digital input path */

#define GPIO_OFFD_Px6_OFF               (1UL<<GPIO_OFFD_OFFD6_Pos) /*!< Disable GPIOx_P6 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px6_ON                (0UL<<GPIO_OFFD_OFFD6_Pos) /*!< Enable GPIOx_P6 pin digital input path */

#define GPIO_OFFD_Px5_OFF               (1UL<<GPIO_OFFD_OFFD5_Pos) /*!< Disable GPIOx_P5 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px5_ON                (0UL<<GPIO_OFFD_OFFD5_Pos) /*!< Enable GPIOx_P5 pin digital input path */

#define GPIO_OFFD_Px4_OFF               (1UL<<GPIO_OFFD_OFFD4_Pos) /*!< Disable GPIOx_P4 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px4_ON                (0UL<<GPIO_OFFD_OFFD4_Pos) /*!< Enable GPIOx_P4 pin digital input path */

#define GPIO_OFFD_Px3_OFF               (1UL<<GPIO_OFFD_OFFD3_Pos) /*!< Disable GPIOx_P3 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px3_ON                (0UL<<GPIO_OFFD_OFFD3_Pos) /*!< Enable GPIOx_P3 pin digital input path */

#define GPIO_OFFD_Px2_OFF               (1UL<<GPIO_OFFD_OFFD2_Pos) /*!< Disable GPIOx_P2 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px2_ON                (0UL<<GPIO_OFFD_OFFD2_Pos) /*!< Enable GPIOx_P2 pin digital input path */

#define GPIO_OFFD_Px1_OFF               (1UL<<GPIO_OFFD_OFFD1_Pos) /*!< Disable GPIOx_P1 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px1_ON                (0UL<<GPIO_OFFD_OFFD1_Pos) /*!< Enable GPIOx_P1 pin digital input path */

#define GPIO_OFFD_Px0_OFF               (1UL<<GPIO_OFFD_OFFD0_Pos) /*!< Disable GPIOx_P0 pin digital input path(digital input tied to low) */
#define GPIO_OFFD_Px0_ON                (0UL<<GPIO_OFFD_OFFD0_Pos) /*!< Enable GPIOx_P0 pin digital input path */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIOx_DMASK constant definitions.                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_DMASK_ENABLE(pin)          (1UL << (pin)) /*!< DMASK setting for mask specified pin DOUT function */
#define GPIO_DMASK_DISABLE(pin)         (~(1UL << (pin))) /*!< DMASK setting for unmask specified pin DOUT function */

#define GPIO_DMASK_Px15_EN              (1UL<<GPIO_DMASK_DMASK15_Pos) /*!< GPIOx_DOUT[15] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px15_DIS             (0UL<<GPIO_DMASK_DMASK15_Pos) /*!< GPIOx_DOUT[15] bit can be updated */

#define GPIO_DMASK_Px14_EN              (1UL<<GPIO_DMASK_DMASK14_Pos) /*!< GPIOx_DOUT[14] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px14_DIS             (0UL<<GPIO_DMASK_DMASK14_Pos) /*!< GPIOx_DOUT[14] bit can be updated */

#define GPIO_DMASK_Px13_EN              (1UL<<GPIO_DMASK_DMASK13_Pos) /*!< GPIOx_DOUT[13] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px13_DIS             (0UL<<GPIO_DMASK_DMASK13_Pos) /*!< GPIOx_DOUT[13] bit can be updated */

#define GPIO_DMASK_Px12_EN              (1UL<<GPIO_DMASK_DMASK12_Pos) /*!< GPIOx_DOUT[12] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px12_DIS             (0UL<<GPIO_DMASK_DMASK12_Pos) /*!< GPIOx_DOUT[12] bit can be updated */

#define GPIO_DMASK_Px11_EN              (1UL<<GPIO_DMASK_DMASK11_Pos) /*!< GPIOx_DOUT[11] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px11_DIS             (0UL<<GPIO_DMASK_DMASK11_Pos) /*!< GPIOx_DOUT[11] bit can be updated */

#define GPIO_DMASK_Px10_EN              (1UL<<GPIO_DMASK_DMASK10_Pos) /*!< GPIOx_DOUT[10] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px10_DIS             (0UL<<GPIO_DMASK_DMASK10_Pos) /*!< GPIOx_DOUT[10] bit can be updated */

#define GPIO_DMASK_Px9_EN               (1UL<<GPIO_DMASK_DMASK9_Pos) /*!< GPIOx_DOUT[9] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px9_DIS              (0UL<<GPIO_DMASK_DMASK9_Pos) /*!< GPIOx_DOUT[9] bit can be updated */

#define GPIO_DMASK_Px8_EN               (1UL<<GPIO_DMASK_DMASK8_Pos) /*!< GPIOx_DOUT[8] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px8_DIS              (0UL<<GPIO_DMASK_DMASK8_Pos) /*!< GPIOx_DOUT[8] bit can be updated */

#define GPIO_DMASK_Px7_EN               (1UL<<GPIO_DMASK_DMASK7_Pos) /*!< GPIOx_DOUT[7] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px7_DIS              (0UL<<GPIO_DMASK_DMASK7_Pos) /*!< GPIOx_DOUT[7] bit can be updated */

#define GPIO_DMASK_Px6_EN               (1UL<<GPIO_DMASK_DMASK6_Pos) /*!< GPIOx_DOUT[6] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px6_DIS              (0UL<<GPIO_DMASK_DMASK6_Pos) /*!< GPIOx_DOUT[6] bit can be updated */

#define GPIO_DMASK_Px5_EN               (1UL<<GPIO_DMASK_DMASK5_Pos) /*!< GPIOx_DOUT[5] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px5_DIS              (0UL<<GPIO_DMASK_DMASK5_Pos) /*!< GPIOx_DOUT[5] bit can be updated */

#define GPIO_DMASK_Px4_EN               (1UL<<GPIO_DMASK_DMASK4_Pos) /*!< GPIOx_DOUT[4] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px4_DIS              (0UL<<GPIO_DMASK_DMASK4_Pos) /*!< GPIOx_DOUT[4] bit can be updated */

#define GPIO_DMASK_Px3_EN               (1UL<<GPIO_DMASK_DMASK3_Pos) /*!< GPIOx_DOUT[3] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px3_DIS              (0UL<<GPIO_DMASK_DMASK3_Pos) /*!< GPIOx_DOUT[3] bit can be updated */

#define GPIO_DMASK_Px2_EN               (1UL<<GPIO_DMASK_DMASK2_Pos) /*!< GPIOx_DOUT[2] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px2_DIS              (0UL<<GPIO_DMASK_DMASK2_Pos) /*!< GPIOx_DOUT[2] bit can be updated */

#define GPIO_DMASK_Px1_EN               (1UL<<GPIO_DMASK_DMASK1_Pos) /*!< GPIOx_DOUT[1] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px1_DIS              (0UL<<GPIO_DMASK_DMASK1_Pos) /*!< GPIOx_DOUT[1] bit can be updated */

#define GPIO_DMASK_Px0_EN               (1UL<<GPIO_DMASK_DMASK0_Pos) /*!< GPIOx_DOUT[0] bit is protected, write data to this bit is ignored */
#define GPIO_DMASK_Px0_DIS              (0UL<<GPIO_DMASK_DMASK0_Pos) /*!< GPIOx_DOUT[0] bit can be updated */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIOx_DBEN constant definitions.                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_DBEN_ENABLE(pin)           (1UL << (pin)) /*!< DBEN setting for enable specified pin de-bounce function */
#define GPIO_DBEN_DISABLE(pin)          (~(1UL << (pin))) /*!< DBEN setting for disable specified pin de-bounce function */

#define GPIO_DBEN_Px15_EN               (1UL<<GPIO_DBEN_DBEN15_Pos) /*!< GPIOx_P15 de-bounce function is enabled */
#define GPIO_DBEN_Px15_DIS              (0UL<<GPIO_DBEN_DBEN15_Pos) /*!< GPIOx_P15 de-bounce function is disabled */

#define GPIO_DBEN_Px14_EN               (1UL<<GPIO_DBEN_DBEN14_Pos) /*!< GPIOx_P14 de-bounce function is enabled */
#define GPIO_DBEN_Px14_DIS              (0UL<<GPIO_DBEN_DBEN14_Pos) /*!< GPIOx_P14 de-bounce function is disabled */

#define GPIO_DBEN_Px13_EN               (1UL<<GPIO_DBEN_DBEN13_Pos) /*!< GPIOx_P13 de-bounce function is enabled */
#define GPIO_DBEN_Px13_DIS              (0UL<<GPIO_DBEN_DBEN13_Pos) /*!< GPIOx_P13 de-bounce function is disabled */

#define GPIO_DBEN_Px12_EN               (1UL<<GPIO_DBEN_DBEN12_Pos) /*!< GPIOx_P12 de-bounce function is enabled */
#define GPIO_DBEN_Px12_DIS              (0UL<<GPIO_DBEN_DBEN12_Pos) /*!< GPIOx_P12 de-bounce function is disabled */

#define GPIO_DBEN_Px11_EN               (1UL<<GPIO_DBEN_DBEN11_Pos) /*!< GPIOx_P11 de-bounce function is enabled */
#define GPIO_DBEN_Px11_DIS              (0UL<<GPIO_DBEN_DBEN11_Pos) /*!< GPIOx_P11 de-bounce function is disabled */

#define GPIO_DBEN_Px10_EN               (1UL<<GPIO_DBEN_DBEN10_Pos) /*!< GPIOx_P10 de-bounce function is enabled */
#define GPIO_DBEN_Px10_DIS              (0UL<<GPIO_DBEN_DBEN10_Pos) /*!< GPIOx_P10 de-bounce function is disabled */

#define GPIO_DBEN_Px9_EN                (1UL<<GPIO_DBEN_DBEN9_Pos) /*!< GPIOx_P9 de-bounce function is enabled */
#define GPIO_DBEN_Px9_DIS               (0UL<<GPIO_DBEN_DBEN9_Pos) /*!< GPIOx_P9 de-bounce function is disabled */

#define GPIO_DBEN_Px8_EN                (1UL<<GPIO_DBEN_DBEN8_Pos) /*!< GPIOx_P8 de-bounce function is enabled */
#define GPIO_DBEN_Px8_DIS               (0UL<<GPIO_DBEN_DBEN8_Pos) /*!< GPIOx_P8 de-bounce function is disabled */

#define GPIO_DBEN_Px7_EN                (1UL<<GPIO_DBEN_DBEN7_Pos) /*!< GPIOx_P7 de-bounce function is enabled */
#define GPIO_DBEN_Px7_DIS               (0UL<<GPIO_DBEN_DBEN7_Pos) /*!< GPIOx_P7 de-bounce function is disabled */

#define GPIO_DBEN_Px6_EN                (1UL<<GPIO_DBEN_DBEN6_Pos) /*!< GPIOx_P6 de-bounce function is enabled */
#define GPIO_DBEN_Px6_DIS               (0UL<<GPIO_DBEN_DBEN6_Pos) /*!< GPIOx_P6 de-bounce function is disabled */

#define GPIO_DBEN_Px5_EN                (1UL<<GPIO_DBEN_DBEN5_Pos) /*!< GPIOx_P5 de-bounce function is enabled */
#define GPIO_DBEN_Px5_DIS               (0UL<<GPIO_DBEN_DBEN5_Pos) /*!< GPIOx_P5 de-bounce function is disabled */

#define GPIO_DBEN_Px4_EN                (1UL<<GPIO_DBEN_DBEN4_Pos) /*!< GPIOx_P4 de-bounce function is enabled */
#define GPIO_DBEN_Px4_DIS               (0UL<<GPIO_DBEN_DBEN4_Pos) /*!< GPIOx_P4 de-bounce function is disabled */

#define GPIO_DBEN_Px3_EN                (1UL<<GPIO_DBEN_DBEN3_Pos) /*!< GPIOx_P3 de-bounce function is enabled */
#define GPIO_DBEN_Px3_DIS               (0UL<<GPIO_DBEN_DBEN3_Pos) /*!< GPIOx_P3 de-bounce function is disabled */

#define GPIO_DBEN_Px2_EN                (1UL<<GPIO_DBEN_DBEN2_Pos) /*!< GPIOx_P2 de-bounce function is enabled */
#define GPIO_DBEN_Px2_DIS               (0UL<<GPIO_DBEN_DBEN2_Pos) /*!< GPIOx_P2 de-bounce function is disabled */

#define GPIO_DBEN_Px1_EN                (1UL<<GPIO_DBEN_DBEN1_Pos) /*!< GPIOx_P1 de-bounce function is enabled */
#define GPIO_DBEN_Px1_DIS               (0UL<<GPIO_DBEN_DBEN1_Pos) /*!< GPIOx_P1 de-bounce function is disabled */

#define GPIO_DBEN_Px0_EN                (1UL<<GPIO_DBEN_DBEN0_Pos) /*!< GPIOx_P0 de-bounce function is enabled */
#define GPIO_DBEN_Px0_DIS               (0UL<<GPIO_DBEN_DBEN0_Pos) /*!< GPIOx_P0 de-bounce function is disabled */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Interrupt Type Constant Definitions                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INT_RISING                 0x00010000UL /*!< Interrupt enable by Input Rising Edge */
#define GPIO_INT_FALLING                0x00000001UL /*!< Interrupt enable by Input Falling Edge */
#define GPIO_INT_BOTH_EDGE              0x00010001UL /*!< Interrupt enable by both Rising Edge and Falling Edge */
#define GPIO_INT_HIGH                   0x80010000UL /*!< Interrupt enable by Level-High */    
#define GPIO_INT_LOW                    0x80000001UL /*!< Interrupt enable by Level-Low */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIOx_IMD constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_IMD_Px15_LEV               (1UL<<GPIO_IMD_IMD15_Pos) /*!< GPIOx_P15 level trigger interrupt */
#define GPIO_IMD_Px15_EDGE              (0UL<<GPIO_IMD_IMD15_Pos) /*!< GPIOx_P15 edge trigger interrupt */

#define GPIO_IMD_Px14_LEV               (1UL<<GPIO_IMD_IMD14_Pos) /*!< GPIOx_P14 level trigger interrupt */
#define GPIO_IMD_Px14_EDGE              (0UL<<GPIO_IMD_IMD14_Pos) /*!< GPIOx_P14 edge trigger interrupt */

#define GPIO_IMD_Px13_LEV               (1UL<<GPIO_IMD_IMD13_Pos) /*!< GPIOx_P13 level trigger interrupt */
#define GPIO_IMD_Px13_EDGE              (0UL<<GPIO_IMD_IMD13_Pos) /*!< GPIOx_P13 edge trigger interrupt */

#define GPIO_IMD_Px12_LEV               (1UL<<GPIO_IMD_IMD12_Pos) /*!< GPIOx_P12 level trigger interrupt */
#define GPIO_IMD_Px12_EDGE              (0UL<<GPIO_IMD_IMD12_Pos) /*!< GPIOx_P12 edge trigger interrupt */

#define GPIO_IMD_Px11_LEV               (1UL<<GPIO_IMD_IMD11_Pos) /*!< GPIOx_P11 level trigger interrupt */
#define GPIO_IMD_Px11_EDGE              (0UL<<GPIO_IMD_IMD11_Pos) /*!< GPIOx_P11 edge trigger interrupt */

#define GPIO_IMD_Px10_LEV               (1UL<<GPIO_IMD_IMD10_Pos) /*!< GPIOx_P10 level trigger interrupt */
#define GPIO_IMD_Px10_EDGE              (0UL<<GPIO_IMD_IMD10_Pos) /*!< GPIOx_P10 edge trigger interrupt */

#define GPIO_IMD_Px9_LEV                (1UL<<GPIO_IMD_IMD9_Pos) /*!< GPIOx_P9 level trigger interrupt */
#define GPIO_IMD_Px9_EDGE               (0UL<<GPIO_IMD_IMD9_Pos) /*!< GPIOx_P9 edge trigger interrupt */

#define GPIO_IMD_Px8_LEV                (1UL<<GPIO_IMD_IMD8_Pos) /*!< GPIOx_P8 level trigger interrupt */
#define GPIO_IMD_Px8_EDGE               (0UL<<GPIO_IMD_IMD8_Pos) /*!< GPIOx_P8 edge trigger interrupt */

#define GPIO_IMD_Px7_LEV                (1UL<<GPIO_IMD_IMD7_Pos) /*!< GPIOx_P7 level trigger interrupt */
#define GPIO_IMD_Px7_EDGE               (0UL<<GPIO_IMD_IMD7_Pos) /*!< GPIOx_P7 edge trigger interrupt */

#define GPIO_IMD_Px6_LEV                (1UL<<GPIO_IMD_IMD6_Pos) /*!< GPIOx_P6 level trigger interrupt */
#define GPIO_IMD_Px6_EDGE               (0UL<<GPIO_IMD_IMD6_Pos) /*!< GPIOx_P6 edge trigger interrupt */

#define GPIO_IMD_Px5_LEV                (1UL<<GPIO_IMD_IMD5_Pos) /*!< GPIOx_P5 level trigger interrupt */
#define GPIO_IMD_Px5_EDGE               (0UL<<GPIO_IMD_IMD5_Pos) /*!< GPIOx_P5 edge trigger interrupt */

#define GPIO_IMD_Px4_LEV                (1UL<<GPIO_IMD_IMD4_Pos) /*!< GPIOx_P4 level trigger interrupt */
#define GPIO_IMD_Px4_EDGE               (0UL<<GPIO_IMD_IMD4_Pos) /*!< GPIOx_P4 edge trigger interrupt */

#define GPIO_IMD_Px3_LEV                (1UL<<GPIO_IMD_IMD3_Pos) /*!< GPIOx_P3 level trigger interrupt */
#define GPIO_IMD_Px3_EDGE               (0UL<<GPIO_IMD_IMD3_Pos) /*!< GPIOx_P3 edge trigger interrupt */

#define GPIO_IMD_Px2_LEV                (1UL<<GPIO_IMD_IMD2_Pos) /*!< GPIOx_P2 level trigger interrupt */
#define GPIO_IMD_Px2_EDGE               (0UL<<GPIO_IMD_IMD2_Pos) /*!< GPIOx_P2 edge trigger interrupt */

#define GPIO_IMD_Px1_LEV                (1UL<<GPIO_IMD_IMD1_Pos) /*!< GPIOx_P1 level trigger interrupt */
#define GPIO_IMD_Px1_EDGE               (0UL<<GPIO_IMD_IMD1_Pos) /*!< GPIOx_P1 edge trigger interrupt */

#define GPIO_IMD_Px0_LEV                (1UL<<GPIO_IMD_IMD0_Pos) /*!< GPIOx_P0 level trigger interrupt */
#define GPIO_IMD_Px0_EDGE               (0UL<<GPIO_IMD_IMD0_Pos) /*!< GPIOx_P0 edge trigger interrupt */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIOx_IEN constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_Px15_IR_EN                 (1UL<<GPIO_IEN_IR_EN15_Pos) /*!< GPIOx_P15 level high or low-to-high interrupt enabled */
#define GPIO_Px15_IR_DIS                (0UL<<GPIO_IEN_IR_EN15_Pos) /*!< GPIOx_P15 level high or low-to-high interrupt disabled */

#define GPIO_Px14_IR_EN                 (1UL<<GPIO_IEN_IR_EN14_Pos) /*!< GPIOx_P14 level high or low-to-high interrupt enabled */
#define GPIO_Px14_IR_DIS                (0UL<<GPIO_IEN_IR_EN14_Pos) /*!< GPIOx_P14 level high or low-to-high interrupt disabled */

#define GPIO_Px13_IR_EN                 (1UL<<GPIO_IEN_IR_EN13_Pos) /*!< GPIOx_P13 level high or low-to-high interrupt enabled */
#define GPIO_Px13_IR_DIS                (0UL<<GPIO_IEN_IR_EN13_Pos) /*!< GPIOx_P13 level high or low-to-high interrupt disabled */

#define GPIO_Px12_IR_EN                 (1UL<<GPIO_IEN_IR_EN12_Pos) /*!< GPIOx_P12 level high or low-to-high interrupt enabled */
#define GPIO_Px12_IR_DIS                (0UL<<GPIO_IEN_IR_EN12_Pos) /*!< GPIOx_P12 level high or low-to-high interrupt disabled */

#define GPIO_Px11_IR_EN                 (1UL<<GPIO_IEN_IR_EN11_Pos) /*!< GPIOx_P11 level high or low-to-high interrupt enabled */
#define GPIO_Px11_IR_DIS                (0UL<<GPIO_IEN_IR_EN11_Pos) /*!< GPIOx_P11 level high or low-to-high interrupt disabled */

#define GPIO_Px10_IR_EN                 (1UL<<GPIO_IEN_IR_EN10_Pos) /*!< GPIOx_P10 level high or low-to-high interrupt enabled */
#define GPIO_Px10_IR_DIS                (0UL<<GPIO_IEN_IR_EN10_Pos) /*!< GPIOx_P10 level high or low-to-high interrupt disabled */

#define GPIO_Px9_IR_EN                  (1UL<<GPIO_IEN_IR_EN9_Pos) /*!< GPIOx_P9 level high or low-to-high interrupt enabled */
#define GPIO_Px9_IR_DIS                 (0UL<<GPIO_IEN_IR_EN9_Pos) /*!< GPIOx_P9 level high or low-to-high interrupt disabled */

#define GPIO_Px8_IR_EN                  (1UL<<GPIO_IEN_IR_EN8_Pos) /*!< GPIOx_P8 level high or low-to-high interrupt enabled */
#define GPIO_Px8_IR_DIS                 (0UL<<GPIO_IEN_IR_EN8_Pos) /*!< GPIOx_P8 level high or low-to-high interrupt disabled */

#define GPIO_Px7_IR_EN                  (1UL<<GPIO_IEN_IR_EN7_Pos) /*!< GPIOx_P7 level high or low-to-high interrupt enabled */
#define GPIO_Px7_IR_DIS                 (0UL<<GPIO_IEN_IR_EN7_Pos) /*!< GPIOx_P7 level high or low-to-high interrupt disabled */

#define GPIO_Px6_IR_EN                  (1UL<<GPIO_IEN_IR_EN6_Pos) /*!< GPIOx_P6 level high or low-to-high interrupt enabled */
#define GPIO_Px6_IR_DIS                 (0UL<<GPIO_IEN_IR_EN6_Pos) /*!< GPIOx_P6 level high or low-to-high interrupt disabled */

#define GPIO_Px5_IR_EN                  (1UL<<GPIO_IEN_IR_EN5_Pos) /*!< GPIOx_P5 level high or low-to-high interrupt enabled */
#define GPIO_Px5_IR_DIS                 (0UL<<GPIO_IEN_IR_EN5_Pos) /*!< GPIOx_P5 level high or low-to-high interrupt disabled */

#define GPIO_Px4_IR_EN                  (1UL<<GPIO_IEN_IR_EN4_Pos) /*!< GPIOx_P4 level high or low-to-high interrupt enabled */
#define GPIO_Px4_IR_DIS                 (0UL<<GPIO_IEN_IR_EN4_Pos) /*!< GPIOx_P4 level high or low-to-high interrupt disabled */

#define GPIO_Px3_IR_EN                  (1UL<<GPIO_IEN_IR_EN3_Pos) /*!< GPIOx_P3 level high or low-to-high interrupt enabled */
#define GPIO_Px3_IR_DIS                 (0UL<<GPIO_IEN_IR_EN3_Pos) /*!< GPIOx_P3 level high or low-to-high interrupt disabled */

#define GPIO_Px2_IR_EN                  (1UL<<GPIO_IEN_IR_EN2_Pos) /*!< GPIOx_P2 level high or low-to-high interrupt enabled */
#define GPIO_Px2_IR_DIS                 (0UL<<GPIO_IEN_IR_EN2_Pos) /*!< GPIOx_P2 level high or low-to-high interrupt disabled */

#define GPIO_Px1_IR_EN                  (1UL<<GPIO_IEN_IR_EN1_Pos) /*!< GPIOx_P1 level high or low-to-high interrupt enabled */
#define GPIO_Px1_IR_DIS                 (0UL<<GPIO_IEN_IR_EN1_Pos) /*!< GPIOx_P1 level high or low-to-high interrupt disabled */

#define GPIO_Px0_IR_EN                  (1UL<<GPIO_IEN_IR_EN0_Pos) /*!< GPIOx_P0 level high or low-to-high interrupt enabled */
#define GPIO_Px0_IR_DIS                 (0UL<<GPIO_IEN_IR_EN0_Pos) /*!< GPIOx_P0 level high or low-to-high interrupt disabled */

#define GPIO_Px15_IF_EN                 (1UL<<GPIO_IEN_IF_EN15_Pos) /*!< GPIOx_P15 level low or high-to-low interrupt enabled */
#define GPIO_Px15_IF_DIS                (0UL<<GPIO_IEN_IF_EN15_Pos) /*!< GPIOx_P15 level low or high-to-low interrupt disabled */

#define GPIO_Px14_IF_EN                 (1UL<<GPIO_IEN_IF_EN14_Pos) /*!< GPIOx_P14 level low or high-to-low interrupt enabled */
#define GPIO_Px14_IF_DIS                (0UL<<GPIO_IEN_IF_EN14_Pos) /*!< GPIOx_P14 level low or high-to-low interrupt disabled */

#define GPIO_Px13_IF_EN                 (1UL<<GPIO_IEN_IF_EN13_Pos) /*!< GPIOx_P13 level low or high-to-low interrupt enabled */
#define GPIO_Px13_IF_DIS                (0UL<<GPIO_IEN_IF_EN13_Pos) /*!< GPIOx_P13 level low or high-to-low interrupt disabled */

#define GPIO_Px12_IF_EN                 (1UL<<GPIO_IEN_IF_EN12_Pos) /*!< GPIOx_P12 level low or high-to-low interrupt enabled */
#define GPIO_Px12_IF_DIS                (0UL<<GPIO_IEN_IF_EN12_Pos) /*!< GPIOx_P12 level low or high-to-low interrupt disabled */

#define GPIO_Px11_IF_EN                 (1UL<<GPIO_IEN_IF_EN11_Pos) /*!< GPIOx_P11 level low or high-to-low interrupt enabled */
#define GPIO_Px11_IF_DIS                (0UL<<GPIO_IEN_IF_EN11_Pos) /*!< GPIOx_P11 level low or high-to-low interrupt disabled */

#define GPIO_Px10_IF_EN                 (1UL<<GPIO_IEN_IF_EN10_Pos) /*!< GPIOx_P10 level low or high-to-low interrupt enabled */
#define GPIO_Px10_IF_DIS                (0UL<<GPIO_IEN_IF_EN10_Pos) /*!< GPIOx_P10 level low or high-to-low interrupt disabled */

#define GPIO_Px9_IF_EN                  (1UL<<GPIO_IEN_IF_EN9_Pos) /*!< GPIOx_P9 level low or high-to-low interrupt enabled */
#define GPIO_Px9_IF_DIS                 (0UL<<GPIO_IEN_IF_EN9_Pos) /*!< GPIOx_P9 level low or high-to-low interrupt disabled */

#define GPIO_Px8_IF_EN                  (1UL<<GPIO_IEN_IF_EN8_Pos) /*!< GPIOx_P8 level low or high-to-low interrupt enabled */
#define GPIO_Px8_IF_DIS                 (0UL<<GPIO_IEN_IF_EN8_Pos) /*!< GPIOx_P8 level low or high-to-low interrupt disabled */

#define GPIO_Px7_IF_EN                  (1UL<<GPIO_IEN_IF_EN7_Pos) /*!< GPIOx_P7 level low or high-to-low interrupt enabled */
#define GPIO_Px7_IF_DIS                 (0UL<<GPIO_IEN_IF_EN7_Pos) /*!< GPIOx_P7 level low or high-to-low interrupt disabled */

#define GPIO_Px6_IF_EN                  (1UL<<GPIO_IEN_IF_EN6_Pos) /*!< GPIOx_P6 level low or high-to-low interrupt enabled */
#define GPIO_Px6_IF_DIS                 (0UL<<GPIO_IEN_IF_EN6_Pos) /*!< GPIOx_P6 level low or high-to-low interrupt disabled */

#define GPIO_Px5_IF_EN                  (1UL<<GPIO_IEN_IF_EN5_Pos) /*!< GPIOx_P5 level low or high-to-low interrupt enabled */
#define GPIO_Px5_IF_DIS                 (0UL<<GPIO_IEN_IF_EN5_Pos) /*!< GPIOx_P5 level low or high-to-low interrupt disabled */

#define GPIO_Px4_IF_EN                  (1UL<<GPIO_IEN_IF_EN4_Pos) /*!< GPIOx_P4 level low or high-to-low interrupt enabled */
#define GPIO_Px4_IF_DIS                 (0UL<<GPIO_IEN_IF_EN4_Pos) /*!< GPIOx_P4 level low or high-to-low interrupt disabled */

#define GPIO_Px3_IF_EN                  (1UL<<GPIO_IEN_IF_EN3_Pos) /*!< GPIOx_P3 level low or high-to-low interrupt enabled */
#define GPIO_Px3_IF_DIS                 (0UL<<GPIO_IEN_IF_EN3_Pos) /*!< GPIOx_P3 level low or high-to-low interrupt disabled */

#define GPIO_Px2_IF_EN                  (1UL<<GPIO_IEN_IF_EN2_Pos) /*!< GPIOx_P2 level low or high-to-low interrupt enabled */
#define GPIO_Px2_IF_DIS                 (0UL<<GPIO_IEN_IF_EN2_Pos) /*!< GPIOx_P2 level low or high-to-low interrupt disabled */

#define GPIO_Px1_IF_EN                  (1UL<<GPIO_IEN_IF_EN1_Pos) /*!< GPIOx_P1 level low or high-to-low interrupt enabled */
#define GPIO_Px1_IF_DIS                 (0UL<<GPIO_IEN_IF_EN1_Pos) /*!< GPIOx_P1 level low or high-to-low interrupt disabled */

#define GPIO_Px0_IF_EN                  (1UL<<GPIO_IEN_IF_EN0_Pos) /*!< GPIOx_P0 level low or high-to-low interrupt enabled */
#define GPIO_Px0_IF_DIS                 (0UL<<GPIO_IEN_IF_EN0_Pos) /*!< GPIOx_P0 level low or high-to-low interrupt disabled */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIOx_DBNCECON constant definitions.                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_ICLK_ON                    (1UL<<GPIO_DBNCECON_ICLK_ON_Pos) /*!< Interrupt generated circuit clock always enabled */
#define GPIO_ICLK_OFF                   (0UL<<GPIO_DBNCECON_ICLK_ON_Pos) /*!< Clock disabled if the GPIOA/B/C/D/F[n] interrupt is disabled */

#define GPIO_DBCLKSRC_OSC10K            (1UL<<GPIO_DBNCECON_DBCLKSRC_Pos) /*!< De-bounce counter clock source is internal 10 kHz oscillator */
#define GPIO_DBCLKSRC_HCLK              (0UL<<GPIO_DBNCECON_DBCLKSRC_Pos) /*!< De-bounce counter clock source is the HCLK */

#define GPIO_DBCLKSEL_1                 (0UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 1 clocks */
#define GPIO_DBCLKSEL_2                 (1UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 2 clocks */
#define GPIO_DBCLKSEL_4                 (2UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 4 clocks */
#define GPIO_DBCLKSEL_8                 (3UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 8 clocks */
#define GPIO_DBCLKSEL_16                (4UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 16 clocks */
#define GPIO_DBCLKSEL_32                (5UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 32 clocks */
#define GPIO_DBCLKSEL_64                (6UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 64 clocks */
#define GPIO_DBCLKSEL_128               (7UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 128 clocks */
#define GPIO_DBCLKSEL_256               (8UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 256 clocks */
#define GPIO_DBCLKSEL_512               (9UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 512 clocks */
#define GPIO_DBCLKSEL_1024              (10UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 1024 clocks */
#define GPIO_DBCLKSEL_2048              (11UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 2048 clocks */
#define GPIO_DBCLKSEL_4096              (12UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 4096 clocks */
#define GPIO_DBCLKSEL_8192              (13UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 8192 clocks */
#define GPIO_DBCLKSEL_16384             (14UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 16384 clocks */
#define GPIO_DBCLKSEL_32768             (15UL<<GPIO_DBNCECON_DBCLKSEL_Pos) /*!< Sample interrupt input once per 32768 clocks */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO pin address definitions.                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_PIN(port, pin)             ((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))   

typedef enum
{
  E_PORTA               = 0,            /*!< GPIOA port enumerate value */
  E_PORTB               = 1,            /*!< GPIOB port enumerate value */
  E_PORTC               = 2,            /*!< GPIOC port enumerate value */
  E_PORTD               = 3,            /*!< GPIOD port enumerate value */
  E_PORTF               = 5             /*!< GPIOF port enumerate value */   
}E_PORT;

#define PA10                            GPIO_PIN(E_PORTA, 10) /*!< Specify PA10 Pin Data Input/Output */
#define PA11                            GPIO_PIN(E_PORTA, 11) /*!< Specify PA11 Pin Data Input/Output */
#define PA12                            GPIO_PIN(E_PORTA, 12) /*!< Specify PA12 Pin Data Input/Output */
#define PA13                            GPIO_PIN(E_PORTA, 13) /*!< Specify PA13 Pin Data Input/Output */
#define PA14                            GPIO_PIN(E_PORTA, 14) /*!< Specify PA14 Pin Data Input/Output */
#define PA15                            GPIO_PIN(E_PORTA, 15) /*!< Specify PA15 Pin Data Input/Output */

#define PB0                             GPIO_PIN(E_PORTB, 0) /*!< Specify PB0 Pin Data Input/Output */
#define PB1                             GPIO_PIN(E_PORTB, 1) /*!< Specify PB1 Pin Data Input/Output */
#define PB2                             GPIO_PIN(E_PORTB, 2) /*!< Specify PB2 Pin Data Input/Output */
#define PB3                             GPIO_PIN(E_PORTB, 3) /*!< Specify PB3 Pin Data Input/Output */
#define PB4                             GPIO_PIN(E_PORTB, 4) /*!< Specify PB4 Pin Data Input/Output */
#define PB5                             GPIO_PIN(E_PORTB, 5) /*!< Specify PB5 Pin Data Input/Output */
#define PB6                             GPIO_PIN(E_PORTB, 6) /*!< Specify PB6 Pin Data Input/Output */
#define PB7                             GPIO_PIN(E_PORTB, 7) /*!< Specify PB7 Pin Data Input/Output */
#define PB8                             GPIO_PIN(E_PORTB, 8) /*!< Specify PB8 Pin Data Input/Output */
#define PB9                             GPIO_PIN(E_PORTB, 9) /*!< Specify PB9 Pin Data Input/Output */
#define PB10                            GPIO_PIN(E_PORTB, 10) /*!< Specify PB10 Pin Data Input/Output */
#define PB12                            GPIO_PIN(E_PORTB, 12) /*!< Specify PB12 Pin Data Input/Output */
#define PB13                            GPIO_PIN(E_PORTB, 13) /*!< Specify PB13 Pin Data Input/Output */
#define PB14                            GPIO_PIN(E_PORTB, 14) /*!< Specify PB14 Pin Data Input/Output */
#define PB15                            GPIO_PIN(E_PORTB, 15) /*!< Specify PB15 Pin Data Input/Output */

#define PC0                             GPIO_PIN(E_PORTC, 0) /*!< Specify PC0 Pin Data Input/Output */
#define PC1                             GPIO_PIN(E_PORTC, 1) /*!< Specify PC1 Pin Data Input/Output */
#define PC2                             GPIO_PIN(E_PORTC, 2) /*!< Specify PC2 Pin Data Input/Output */
#define PC3                             GPIO_PIN(E_PORTC, 3) /*!< Specify PC3 Pin Data Input/Output */
#define PC4                             GPIO_PIN(E_PORTC, 4) /*!< Specify PC4 Pin Data Input/Output */
#define PC5                             GPIO_PIN(E_PORTC, 5) /*!< Specify PC5 Pin Data Input/Output */
#define PC8                             GPIO_PIN(E_PORTC, 8) /*!< Specify PC8 Pin Data Input/Output */
#define PC9                             GPIO_PIN(E_PORTC, 9) /*!< Specify PC9 Pin Data Input/Output */
#define PC10                            GPIO_PIN(E_PORTC, 10) /*!< Specify PC10 Pin Data Input/Output */
#define PC11                            GPIO_PIN(E_PORTC, 11) /*!< Specify PC11 Pin Data Input/Output */
#define PC12                            GPIO_PIN(E_PORTC, 12) /*!< Specify PC12 Pin Data Input/Output */
#define PC13                            GPIO_PIN(E_PORTC, 13) /*!< Specify PC13 Pin Data Input/Output */

#define PD0                             GPIO_PIN(E_PORTD, 0) /*!< Specify PD0 Pin Data Input/Output */
#define PD1                             GPIO_PIN(E_PORTD, 1) /*!< Specify PD1 Pin Data Input/Output */
#define PD2                             GPIO_PIN(E_PORTD, 2) /*!< Specify PD2 Pin Data Input/Output */
#define PD3                             GPIO_PIN(E_PORTD, 3) /*!< Specify PD3 Pin Data Input/Output */
#define PD4                             GPIO_PIN(E_PORTD, 4) /*!< Specify PD4 Pin Data Input/Output */
#define PD5                             GPIO_PIN(E_PORTD, 5) /*!< Specify PD5 Pin Data Input/Output */
#define PD8                             GPIO_PIN(E_PORTD, 8) /*!< Specify PD8 Pin Data Input/Output */
#define PD9                             GPIO_PIN(E_PORTD, 9) /*!< Specify PD9 Pin Data Input/Output */
#define PD10                            GPIO_PIN(E_PORTD, 10) /*!< Specify PD10 Pin Data Input/Output */
#define PD11                            GPIO_PIN(E_PORTD, 11) /*!< Specify PD11 Pin Data Input/Output */

#define PF0                             GPIO_PIN(E_PORTF, 0) /*!< Specify PF0 Pin Data Input/Output */
#define PF1                             GPIO_PIN(E_PORTF, 1) /*!< Specify PF1 Pin Data Input/Output */
#define PF2                             GPIO_PIN(E_PORTF, 2) /*!< Specify PF2 Pin Data Input/Output */
#define PF3                             GPIO_PIN(E_PORTF, 3) /*!< Specify PF3 Pin Data Input/Output */


/*@}*/ /* end of group GPIO_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup GPIO_MACRO_FUNC GPIO Macro Func
  @{
*/

/**
 * @brief       Set GPIO Pin Mode
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 * @param[in]   mode        The pin mode of specified GPIO pin. It could be 
 *                          GPIO_INPUT, GPIO_OUTPUT, GPIO_OPEN_DRAIN or GPIO_QUASI.
 *
 * @return      None
 *
 * @details     Set the pin mode of specified GPIO pin.
 */
static __INLINE void GPIO_SET_MODE(GPIO_T *PORT, uint8_t pin, uint32_t mode)
{
    (PORT)->PMD = ((PORT)->PMD & (~(0x3UL<<(pin<<1)))) | GPIO_MODE(pin, mode);
}

/**
 * @brief       Enable I/O Digital Input Path
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Enable I/O digital input path of specified GPIO pin.
 */
static __INLINE void GPIO_ENABLE_DIGITAL_PATH(GPIO_T *PORT, uint8_t pin)
{
    (PORT)->OFFD &= GPIO_OFFD_DISABLE(pin);
}

/**
 * @brief       Disable I/O Digital Input Path
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Disable I/O digital input path of specified GPIO pin.
 */
static __INLINE void GPIO_DISABLE_DIGITAL_PATH(GPIO_T *PORT, uint8_t pin)
{
    (PORT)->OFFD |= GPIO_OFFD_ENABLE(pin);
}

/**
 * @brief       Mask Pin Dout Function
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Mask the data out function of specified GPIO pin, write data to the pin is ignored.
 */
static __INLINE void GPIO_ENABLE_DMASK(GPIO_T *PORT, uint8_t pin)
{
    (PORT)->DMASK |= GPIO_DMASK_ENABLE(pin);
}

/**
 * @brief       Unmask Pin De-bounce Function
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Unmask the data out function of specified GPIO pin, the pin status can be updated.
 */
static __INLINE void GPIO_DISABLE_DMASK(GPIO_T *PORT, uint8_t pin)
{
    (PORT)->DMASK &= GPIO_DMASK_DISABLE(pin);
}

/**
 * @brief       Enable Pin De-bounce Function
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Enable the interrupt de-bounce function of specified GPIO pin.
 */
static __INLINE void GPIO_ENABLE_DEBOUNCE(GPIO_T *PORT, uint8_t pin)
{
    (PORT)->DBEN |= GPIO_DBEN_ENABLE(pin);
}

/**
 * @brief       Disable Pin De-bounce Function
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Disable the interrupt de-bounce function of specified GPIO pin.
 */
static __INLINE void GPIO_DISABLE_DEBOUNCE(GPIO_T *PORT, uint8_t pin)
{
    (PORT)->DBEN &= GPIO_DBEN_DISABLE(pin);
}

/**
 * @brief       Set De-bounce Sampling Cycle Time
 *
 * @param[in]   clksrc      The de-bounce counter clock source. It could be GPIO_DBCLKSRC_HCLK or GPIO_DBCLKSRC_OSC10K.
 * @param[in]   clksel      The de-bounce sampling cycle selectionn. It could be \n
 *                              GPIO_DBCLKSEL_1, GPIO_DBCLKSEL_2, GPIO_DBCLKSEL_4, GPIO_DBCLKSEL_8, \n
 *                              GPIO_DBCLKSEL_16, GPIO_DBCLKSEL_32, GPIO_DBCLKSEL_64, GPIO_DBCLKSEL_128, \n
 *                              GPIO_DBCLKSEL_256, GPIO_DBCLKSEL_512, GPIO_DBCLKSEL_1024, GPIO_DBCLKSEL_2048, \n
 *                              GPIO_DBCLKSEL_4096, GPIO_DBCLKSEL_8192, GPIO_DBCLKSEL_16384, GPIO_DBCLKSEL_32768.
 *
 * @return      None
 *
 * @details     Set the interrupt de-bounce sampling cycle time based on the debounce counter clock source. \n
 *              Example: GPIO_SET_DEBOUNCE_TIME(GPIO_DBCLKSRC_OSC10K, GPIO_DBCLKSEL_4). \n
 *              It's meaning the De-debounce counter clock source is internal 10 KHz and sampling cycle selection is 4. \n
 *              Then the target de-bounce sampling cycle time is (2^4)*(1/(10*1000)) s = 16*0.0001 s = 1600 us,
 *              and system will sampling interrupt input once per 1600 us.
 */
static __INLINE void GPIO_SET_DEBOUNCE_TIME(uint32_t clksrc, uint32_t clksel)
{
    GPIO->DBNCECON = GPIO_DBNCECON_ICLK_ON_Msk | (clksrc) | (clksel);
}

/**
 * @brief       Get GPIO Pin Interrupt Status
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @retval      FALSE       No interrupt at specified GPIO pin
 * @retval      TRUE        The specified GPIO pin generate an interrupt
 *
 * @details     Get the interrupt status of specified GPIO pin.
 */
static __INLINE uint32_t GPIO_GET_PIN_IF(GPIO_T *PORT, uint8_t pin)
{
    return ((PORT)->ISRC & (1<<(pin)));
}

/**
 * @brief       Clear GPIO Pin Interrupt Status
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Clear the interrupt status of specified GPIO pin.
 */
static __INLINE void GPIO_CLR_PIN_IF(GPIO_T *PORT, uint8_t pin)
{
    (PORT)->ISRC = (1<<(pin));
}

/**
 * @brief       Get GPIO port Interrupt Status
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 *
 * @return      GPIO port interrupt status
 *
 * @details     Get the interrupt status of specified GPIO port.
 */
static __INLINE uint32_t GPIO_GET_PORT_IF(GPIO_T *PORT)
{
    return ((PORT)->ISRC);
}

/**
 * @brief       Clear GPIO port Interrupt Status
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 *
 * @return      None
 *
 * @details     Clear the interrupt status of specified GPIO port.
 */
static __INLINE void GPIO_CLR_PORT_IF(GPIO_T *PORT)
{
    (PORT)->ISRC = (PORT)->ISRC;
}

/**
 * @brief       Set GPIO Pin to high level
 *
 * @param[in]   pin         Specified Input/Output pin. It could be \n
                            PA10,PA11,PA12,PA13,PA14,PA15
                            PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB12,PB13,PB14,PB15 \n
                            PC0,PC1,PC2,PC3,PC4,PC5,PC8,PC9,PC10,PC11,PC12,PC13 \n
                            PD0,PD1,PD2,PD3,PD4,PD5,PD8,PD9,PD10,PD11 \n
                            PF0,PF1,PF2,PF3
 *
 * @return      None
 *
 * @details     Set status of specified GPIO pin to high level.
 */
static __INLINE void GPIO_SET_PIN(uint32_t pin)
{
    outp32(pin, 1);
}

/**
 * @brief       Set GPIO Pin to low level
 *
 * @param[in]   pin         Specified Input/Output pin. It could be \n
                            PA10,PA11,PA12,PA13,PA14,PA15
                            PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB12,PB13,PB14,PB15 \n
                            PC0,PC1,PC2,PC3,PC4,PC5,PC8,PC9,PC10,PC11,PC12,PC13 \n
                            PD0,PD1,PD2,PD3,PD4,PD5,PD8,PD9,PD10,PD11 \n
                            PF0,PF1,PF2,PF3
 *
 * @return      None
 *
 * @details     Set status of specified GPIO pin to low level.
 */
static __INLINE void GPIO_CLR_PIN(uint32_t pin)
{
    outp32(pin, 0);
}

/**
* @brief       Inverse GPIO Pin
*
* @param[in]   pin          Specified Input/Output pin. It could be \n
                            PA10,PA11,PA12,PA13,PA14,PA15
                            PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB12,PB13,PB14,PB15 \n
                            PC0,PC1,PC2,PC3,PC4,PC5,PC8,PC9,PC10,PC11,PC12,PC13 \n
                            PD0,PD1,PD2,PD3,PD4,PD5,PD8,PD9,PD10,PD11 \n
                            PF0,PF1,PF2,PF3
*
* @return      None
*
* @details     Inverse status of specified GPIO pin.
*/
static __INLINE void GPIO_INVERSE_PIN(uint32_t pin)
{
    outp32(pin, (inp32(pin) ^ 1));
}

/**
 * @brief       Get GPIO Pin status
 *
 * @param[in]   pin         Specified Input/Output pin. It could be \n
                            PA10,PA11,PA12,PA13,PA14,PA15
                            PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB12,PB13,PB14,PB15 \n
                            PC0,PC1,PC2,PC3,PC4,PC5,PC8,PC9,PC10,PC11,PC12,PC13 \n
                            PD0,PD1,PD2,PD3,PD4,PD5,PD8,PD9,PD10,PD11 \n
                            PF0,PF1,PF2,PF3
 *
 * @retval      0           Low level at specified GPIO pin
 * @retval      1           High level at specified GPIO pin
 *
 * @details     Get status of specified GPIO pin.
 */
static __INLINE uint32_t GPIO_GET_PIN(uint32_t pin)
{
    return inp32(pin);
}

/**
 * @brief       Set GPIO port status
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   val         Value to be set to specified port.
 *
 * @return      None
 *
 * @details     Set status of specified port
 */
static __INLINE void GPIO_SET_PORT(GPIO_T *PORT, uint32_t val)
{
    (PORT)->DOUT = (val);
}

/**
 * @brief       Get GPIO port status
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 *
 * @return      GPIO port status
 *
 * @details     Get status of specified port
 */
static __INLINE uint32_t GPIO_GET_PORT(GPIO_T *PORT)
{
    return ((PORT)->PIN);
}

/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Enable GPIO interrupt
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   u32Pin      The pin of specified GPIO port. It could be 0 ~ 15.
 * @param[in]   u32Attribs  The interrupt attribute of specified GPIO pin. It could be \n
 *                          GPIO_INT_RISING, GPIO_INT_FALLING, GPIO_INT_BOTH_EDGE, GPIO_INT_HIGH, GPIO_INT_LOW.
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
static __INLINE void GPIO_EnableInt(GPIO_T *PORT, uint32_t u32Pin, uint32_t u32IntAttribs)
{
    PORT->IMD = (PORT->IMD & (~(1UL<<u32Pin))) | (((u32IntAttribs&0x80000000UL)>>31) << u32Pin);
    PORT->IEN = (PORT->IEN & (~(0x00010001UL<<u32Pin))) | ((u32IntAttribs & 0x7FFFFFFFUL) << u32Pin);
}

/**
 * @brief       Disable GPIO interrupt
 *
 * @param[in]   PORT        GPIO port struct pointer. It could be PA, PB, PC, PD, PF.
 * @param[in]   u32Pin      The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     This function is used to disable specified GPIO pin interrupt.
 */
static __INLINE void GPIO_DisableInt(GPIO_T *PORT, uint32_t u32Pin)
{
    PORT->IMD &= (~(1UL << u32Pin));
    PORT->IEN &= (~((0x00010001UL) << u32Pin));
}

/**
 * @brief       Enable external interrupt 0
 *
 * @param[in]   u32Attribs  The interrupt attribute of specified GPIO pin. It could be \n
 *                          GPIO_INT_RISING, GPIO_INT_FALLING, GPIO_INT_BOTH_EDGE, GPIO_INT_HIGH, GPIO_INT_LOW.
 *
 * @return      None
 *
 * @details     This function is used to enable external interrupt 0.
 */
static __INLINE void GPIO_EnableEINT0(uint32_t u32IntAttribs)
{
    PB->IMD = (PB->IMD & (~(1UL<<14))) | (((u32IntAttribs&0x80000000UL)>>31) << 14);
    PB->IEN = (PB->IEN & (~(0x00010001UL<<14))) | ((u32IntAttribs & 0x7FFFFFFFUL) << 14);
}

/**
 * @brief       Disable external interrupt 0
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to disable external interrupt 0.
 */
static __INLINE void GPIO_DisableEINT0(void)
{
    PB->IMD &= (~(1UL << 14));
    PB->IEN &= (~(0x00010001UL << 14));
}

/**
 * @brief       Enable external interrupt 1
 *
 * @param[in]   u32Attribs  The interrupt attribute of specified GPIO pin. It could be \n
 *                          GPIO_INT_RISING, GPIO_INT_FALLING, GPIO_INT_BOTH_EDGE, GPIO_INT_HIGH, GPIO_INT_LOW.
 *
 * @return      None
 *
 * @details     This function is used to enable external interrupt 1.
 */
static __INLINE void GPIO_EnableEINT1(uint32_t u32IntAttribs)
{
    PB->IMD = (PB->IMD & (~(1UL<<15))) | (((u32IntAttribs&0x80000000UL)>>31) << 15);
    PB->IEN = (PB->IEN & (~(0x00010001UL<<15))) | ((u32IntAttribs & 0x7FFFFFFFUL) << 15);
}

/**
 * @brief       Disable external interrupt 1
 *
 * @param       None
 *
 * @return      None
 *
 * @details     This function is used to disable external interrupt 1.
 */
static __INLINE void GPIO_DisableEINT1(void)
{
    PB->IMD &= (~(1UL << 15));
    PB->IEN &= (~(0x00010001UL << 15));
}

/**
 *  GPIO_Func()              Specify PD0 Pin Data Input/Output
 *  GPIO_I2C0()              Set PF3/PF2 as I2C0 pin, PF3=CLK,PF2=DAT
 *  GPIO_I2C1()              Set PA11/PA10 as I2C0 pin, PA11=CLK,PA10=DAT
 *  GPIO_UART0()             Set all Rx/Tx/CTS/RTS pins.PB0=RX,PB1=TX,PB2=RTS,PB3=CTS
 *  GPIO_UART0_RXTX()        Only set UART RX/TX pin.PB0=RX,PB1=TX
 *  GPIO_UART0_RTSCTS()      Only set UART RTS/CTS pin.PB2=RTS,PB3=CTS
 *  GPIO_UART1()             Set all RX/TX/CTS/RTS pins.PB4=RX,PB5=TX,PB6=RTS,PB7=CTS
 *  GPIO_UART1_RXTX()        Only set UART RX/TX pin.PB4=RX,PB5=TX
 *  GPIO_UART1_RTSCTS()      Only set UART RTS/CTS pin.PB6=RTS,PB7=CTS
 *  GPIO_UART0_RXTX_PC()     Only set UART RX/TX pin.PC4=RX,PC5=TX
 *  
 *	GPIO_SPI0()              Set SPI0 MFP pin, Only set: PC0=SPISS00,PC1=SPICLK0,PC2=MISO00,PC3=MOSI00
 *  GPIO_SPI0_SS0_PC0()      Set PC0 as SPISS00 of SPI0, PC0=SS00
 *  GPIO_SPI0_CLK_PC1()      Set PC1 as SPICLK0 of SPI0, PC1=SPICLK0
 *  GPIO_SPI0_MISO0_PC2()    Set PC2 as MISO00 of SPI0,  PC2=MISO00
 *  GPIO_SPI0_MOSI0_PC3()    Set PC3 as MOSI00 of SPI0,  PC3=MOSI00
 *  GPIO_SPI0_SS1_PB10()     Set PB10 as of SPISS01 of SPI0, PB10=SS01
 *  GPIO_SPI0_SS1_PD1()      Set PD1 as SPISS01 of SPI0,PD1=SS01
 *  GPIO_SPI0_MISO1_PD2()    Set PD2 as MISO01 of SPI0, PD2=MISO01
 *  GPIO_SPI0_MOSI1_PD3()    Set PD3 as MOSI01 of SPI0, PD3=MOSI01
 *  GPIO_SPI0_MOSI1_MISO1()  Set PC5/PC4 as MOSI01/MISO01 of SPI0, PC5=MOSI01,PC4=MISO01
 *  
 *  GPIO_SPI1()              Set SPI1 MFP pins. Only set:PC8=SPISS10,PC9=SPICLK1,PC10=MISO10,PC11=MOSI10
 *  GPIO_SPI1_SS0_PC8()      Set PC0 as SS10 of SPI1, PC0=SS10
 *  GPIO_SPI1_CLK_PC9()      Set PC9 as SPICLK1 of SPI1, PC9=SPICLK1
 *  GPIO_SPI1_MISO0_PC10()   Set PC10 as MISO10 of SPI1, PC10=MISO10
 *  GPIO_SPI1_MOSI0_PC11()   Set PC11 as MOSI10 of SPI1, PC11=MOSI10
 *  GPIO_SPI1_MOSI0_PD8()    Set PD8 as MOSI10 of SPI1, PD8=MOSI10
 *  GPIO_SPI1_SS0_PB12()     Set PB12 as SS10 of SPI1, PB12=SS10
 * 	GPIO_SPI1_MISO0_PA10()   Set PA10 as MISO0 of SPI1, PA10=MISO0
 *  GPIO_SPI1_CLK_PA11()     Set PA11 as SPICLK of SPI1, PA11=SPICLK1
 *  GPIO_SPI1_SS1_PB9()      Set PB9 as SPISS11 of SPI1, PB9=SPISS11
 *  GPIO_SPI1_SS1_PB4_QFN33()Set PB4 as SPISS11 of SPI1, PB4=SPISS11
 *  GPIO_SPI1_MOSI1_MISO1()  Set PC13/PC12 as MOSI01/MISO01 of SPI1, PC13=MOSI01,PC12=MISO01
 *  GPIO_SPI2_PD()           Set PD0/PD1/PD2/PD3 as pins of SPI2, PD0=SPISS20,PD1=SPICLK2,PD2=MISO20,PD3=MOSI20
 *  GPIO_SPI2_SS0_PD0()      Set PD0 as SPISS20 of SPI2, PD0=SPISS20
 *  GPIO_SPI2_CLK_PD1()      Set PD1 as SPICLK2 of SPI2, PD1=SPICLK2
 *  GPIO_SPI2_MISO0_PD2()    Set PD2 as MISO20 of SPI2, PD2=MISO20
 *  GPIO_SPI2_MOSI0_PD3()    Set PD3 as MOSI20 of SPI2, PD3=MOSI20
 * 	GPIO_SPI2_MISO0_PA10()   Set PA10 as MISO20 of SPI2, PA10=MISO20
 *  GPIO_SPI2_MOSI0_PA11()   Set PA11 as MOSI20 of SPI2, PA11=MOSI20
 *  GPIO_SPI2_PB()           Set PB4/PB5/PB6/PB7 as pins of SPI2, PB4=SPISS20,PB5=SPICLK2,PB6=MOSI20,PB7=MISO20
 *  GPIO_SPI2_SS0_PB4()      Set PB4 as SPISS20 of SPI2, PB4=SPISS20
 *  GPIO_SPI2_CLK_PB5()      Set PB5 as SPICLK2 of SPI2, PB5=SPICLK2
 *  GPIO_SPI2_MOSI0_PB6()    Set PB6 as MOSI20 of SPI2,  PB6=MOSI20
 *  GPIO_SPI2_MISO0_PB7()    Set PB7 as MISO20 of SPI2,  PB7=MISO20
 *  GPIO_SPI2_MOSI1_MISO1()  Set PD5/PD4 as MOSI21/MISO21 of SPI2, PD5=MOSI1,PD4=MISO1
 *  	
 *  GPIO_EINT0()             Set PB14 as /INT0
 *  GPIO_EINT1()             Set PB15 as /INT1
 *  GPIO_EINT1_PD11()        Set PD11 as /INT1
 *  GPIO_CLKO_PA15()         Set PA15 as CLKO
 *  GPIO_CLKO_PB12()         Set PB12 as CLKO
 * 	GPIO_CLKO_PC13()         Set PC13 as CLKO
 *  GPIO_CLKO_PD10()         Set PD10 as CLKO
 *  GPIO_TMR0()              Set PB8 as Event Counter Input or Toggle output of Timer0
 *  GPIO_TMR1()              Set PB9 as Event Counter Input or Toggle output of Timer1
 *  GPIO_TMR2()              Set PB10 as Event Counter Input or Toggle output of Timer2
 *  GPIO_T0EX()              Set PB15 as Capture Input of Timer0
 *  GPIO_T2EX()              Set PB2 as Capture Input of Timer2
 *  GPIO_T3EX()              Set PB3 as Capture Input of Timer3
 *
 *  GPIO_PWM0()              Set PA12 as PWM0 output or Capture input pin
 *  GPIO_PWM1()              Set PA13 as PWM1 output or Capture input pin
 *  GPIO_PWM2_PA14()         Set PA14 as PWM2 output or Capture input pin
 *  GPIO_PWM2_PC12()         Set PC12 as PWM2 output or Capture input pin
 *  GPIO_PWM3_PA15()         Set PA15 as PWM3 output or Capture input pin
 *  GPIO_PWM3_PC13()         Set PC13 as PWM3 output or Capture input pin
 *  
 *  GPIO_I2S()               Set I2S pin, except MCLK.PC0=LRCLK,PC1=BCLK,PC2=DI,PC3=DO
 *  GPIO_I2S_MCLK_PA15()     Set PA15 as MCLK pin of I2S
 *  GPIO_I2S_MCLK_PC12()     Set PC12 as MCLK pin of I2S
 *  GPIO_PS2()               Set PS2 pin.PF2=PS2DAT,PF3=PS2CLK
 *  GPIO_ADC0()              Set PD0 as ADC0
 *  GPIO_ADC1()              Set PD1 as ADC1
 *  GPIO_ADC2()              Set PD2 as ADC2
 *  GPIO_ADC3()              Set PD3 as ADC3
 *  GPIO_ADC4()              Set PD4 as ADC4
 *  GPIO_ADC5()              Set PD5 as ADC5
 *  GPIO_ADC6()              Set PF2 as ADC6
 *  GPIO_ADC7()              Set PF3 as ADC7
 *  GPIO_XT1()               Set PF1/PF0 as XT1_IN/XT1_OUT pin
 *  GPIO_XT1IN()             Set PF1 as XT1_IN pin
 *  GPIO_XT1OUT()            Set PF0 as XT1_OUT pin 
 */

/**
 * @brief       Set all IO to GPIO
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set all IO to GPIO
 */
static __INLINE void GPIO_Func()
{
    outpw(&SYS->GPA_MFP, 0);
    outpw(&SYS->GPB_MFP, 0);
    outpw(&SYS->GPC_MFP, 0);
    outpw(&SYS->GPD_MFP, 0);
}

/*---------------------------------------------------------------------------------------------------------*/
/* I2C0/I2C1                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set I2C0 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PF3=CLK,PF2=DAT
 */
static __INLINE void GPIO_I2C0()
{
    outpw(&SYS->GPF_MFP, inpw(&SYS->GPF_MFP) | (0x3<<2));
    outpw(&SYS->ALT_MFP1, (inpw(&SYS->ALT_MFP1) & ~(0xF<<24)) | (0xa<<24));
}

/**
 * @brief       Set I2C1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PA11=CLK,PA10=DAT
 */
static __INLINE void GPIO_I2C1()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x3<<10));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x3<<11));
}

/*---------------------------------------------------------------------------------------------------------*/
/* UART                                                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set UART0 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set UART0 Rx/Tx/CTS/RTS pins. PB0=RX,PB1=TX,PB2=RTS,PB3=CTS
 */
static __INLINE void GPIO_UART0()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0xF<<0));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1F<<26));
}

/**
 * @brief       Set UART0 Rx/Tx MFP
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set UART0 Rx/Tx pins. PB0=RX,PB1=TX
 */
static __INLINE void GPIO_UART0_RXTX()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x3<<0));
}

/**
 * @brief       Set UART0 RTS/CTS MFP
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set UART0 RTS/CTS pins. PB2=RTS,PB3=CTS
 */
static __INLINE void GPIO_UART0_RTSCTS()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x3<<2));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x3<<26));
}

/**
 * @brief       Set UART1 MFP
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set UART1 all Rx/Tx/CTS/RTS pins. PB4=RX,PB5=TX,PB6=RTS,PB7=CTS
 */
static __INLINE void GPIO_UART1()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0xF<<4));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0xF<<15));
}

/**
 * @brief       Set UART1 Rx/Tx MFP
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set UART1 Rx/Tx pins. PB4=RX,PB5=TX
 */
static __INLINE void GPIO_UART1_RXTX()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x3<<4));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x9<<15));
}

/**
 * @brief       Set UART1 RTS/CTS MFP
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set UART1 RTS/CTS pins. PB6=RTS,PB7=CTS
 */
static __INLINE void GPIO_UART1_RTSCTS()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x3<<6));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x3<<16));
}

/**
 * @brief       Set UART0 Rx/Tx pin to PC
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Only set UART Rx/Tx pin. PC4=RX,PC5=TX
 */
static __INLINE void GPIO_UART0_RXTX_PC()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x3<<4));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x3<<29));
}

/*---------------------------------------------------------------------------------------------------------*/
/* SPI                                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set SPI0 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set SPI0 interface to PC0 ~ PC3. PC0=SPISS00,PC1=SPICLK0,PC2=MISO00,PC3=MOSI00
 */
static __INLINE void GPIO_SPI0()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0xF<<0));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0xF<<5));
}

/**
 * @brief       Set SPI0 SS00 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC0 as SS00 of SPI0. PC0=SPISS00
 */
static __INLINE void GPIO_SPI0_SS0_PC0()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<0));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<5));
}

/**
 * @brief       Set SPI0 SPICLK0 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC1 as SPICLK0 of SPI0. PC1=SPICLK0
 */
static __INLINE void GPIO_SPI0_CLK_PC1()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<1));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<6));
}

/**
 * @brief       Set SPI0 MISO00 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC2 as MISO00 of SPI0. PC2=MISO00
 */
static __INLINE void GPIO_SPI0_MISO0_PC2()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<2));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<7));
}

/**
 * @brief       Set SPI0 MOSI00 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC3 as MOSI00 of SPI0. PC3=MOSI00
 */
static __INLINE void GPIO_SPI0_MOSI0_PC3()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<3));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<8));
}

/**
 * @brief       Set SPI0 SPISS01 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB10 as SPISS01 of SPI0. PB10=SPISS01
 */
static __INLINE void GPIO_SPI0_SS1_PB10()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<10));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<0));
}

/**
 * @brief       Set SPI0 SPISS01 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD1 as SPISS01 of SPI0. PD1=SPISS01
 */
static __INLINE void GPIO_SPI0_SS1_PD1()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<1));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) & ~(0x1<<17));
}

/**
 * @brief       Set SPI0 MISO01 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD2 as MISO01 of SPI0. PD2=MISO01
 */
static __INLINE void GPIO_SPI0_MISO1_PD2()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<2));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) & ~(0x1<<18));
}     

/**
 * @brief       Set SPI0 MOSI01 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD3 as MOSI01 of SPI0. PD3=MOSI01
 */
static __INLINE void GPIO_SPI0_MOSI1_PD3()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<3));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) & ~(0x1<<19));
}      

/**
 * @brief       Set SPI0 MOSI01/MISO01 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC5/PC4 as MOSI01/MISO01 of SPI0. PC5=MOSI01,PC4=MISO01
 */
static __INLINE void GPIO_SPI0_MOSI1_MISO1()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x3<<4));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x3<<29));
}       

/**
 * @brief       Set SPI1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC11~PC8 as SPI1 pin. PC8=SPISS10,PC9=SPICLK1,PC10=MISO10,PC11=MOSI10
 */
static __INLINE void GPIO_SPI1()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0xF<<8));
}

/**
 * @brief       Set SPI1 SPISS10 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC8 as SPISS10 of SPI1. PC8=SPISS10
 */
static __INLINE void GPIO_SPI1_SS0_PC8()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<8));
}

/**
 * @brief       Set SPI1 SPICLK1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC9 as SPICLK1 of SPI1. PC9=SPICLK1
 */
static __INLINE void GPIO_SPI1_CLK_PC9()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<9));
}

/**
 * @brief       Set SPI1 MISO10 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC10 as MISO10 of SPI1. PC10:MISO10
 */
static __INLINE void GPIO_SPI1_MISO0_PC10()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<10));
}

/**
 * @brief       Set SPI1 MOSI10 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC11 as MOSI10 of SPI1. PC11=MOSI10
 */
static __INLINE void GPIO_SPI1_MOSI0_PC11()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<11));
}

/**
 * @brief       Set SPI1 MOSI10 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD8 as MOSI10 of SPI1. PD8=MOSI10
 */
static __INLINE void GPIO_SPI1_MOSI0_PD8()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<8));
}

/**
 * @brief       Set SPI1 SPISS10 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB12 as SPISS10 of SPI1. PB12=SPISS10
 */
static __INLINE void GPIO_SPI1_SS0_PB12()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<12));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<10));
}

/**
 * @brief       Set SPI1 MISO10 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA10 as MISO10 of SPI1. PA10=MISO10
 */
static __INLINE void GPIO_SPI1_MISO0_PA10()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) & ~(0x1<<10));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<12));
}

/**
 * @brief       Set SPI1 SPICLK1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA11 as SPICLK1 of SPI1. PA11=SPICLK1
 */
static __INLINE void GPIO_SPI1_CLK_PA11()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) & ~(0x1<<11));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<11));
}        

/**
 * @brief       Set SPI1 SPISS11 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB9 as SPISS11 of SPI1. PB9=SPISS11
 */
static __INLINE void GPIO_SPI1_SS1_PB9()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<9));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<1));
}		

/**
 * @brief       Set SPI1 SPISS11 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB4 as SPISS11 of SPI1. PB4=SPISS11
 */
static __INLINE void GPIO_SPI1_SS1_PB4_QFN33()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<4));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<15));
}

/**
 * @brief       Set SPI1 MOSI11/MISO11 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC13/PC12 as MOSI11/MISO11 of SPI1. PC13=MOSI11,PC12=MISO11
 */
static __INLINE void GPIO_SPI1_MOSI1_MISO1()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x3<<12));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x3<<20));
}        

/**
 * @brief       Set SPI2 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD3~PD0 as SPI2 pins. PD0=SPISS20,PD1=SPICLK2,PD2=MISO20,PD3=MOSI20
 */
static __INLINE void GPIO_SPI2_PD()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) & ~(0xF<<0));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0xF<<16));
}        

/**
 * @brief       Set SPI2 SPISS20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD0 as SPISS20 of SPI2. PD0=SPISS20
 */
static __INLINE void GPIO_SPI2_SS0_PD0()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) & ~(0x1<<0));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<16));
}

/**
 * @brief       Set SPI2 SPICLK2 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD1 as SPICLK2 of SPI2. PD1=SPICLK2
 */
static __INLINE void GPIO_SPI2_CLK_PD1()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) & ~(0x1<<1));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<17));
}        

/**
 * @brief       Set SPI2 MISO20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD2 as MISO20 of SPI2. PD2=MISO20
 */
static __INLINE void GPIO_SPI2_MISO0_PD2()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) & ~(0x1<<2));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<18));
}        

/**
 * @brief       Set SPI2 MOSI20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD3 as MOSI20 of SPI2. PD3=MOSI20
 */
static __INLINE void GPIO_SPI2_MOSI0_PD3()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) & ~(0x1<<3));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<19));
}        

/**
 * @brief       Set SPI2 MISO20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA10 as MISO20 of SPI2. PA10=MISO20
 */
static __INLINE void GPIO_SPI2_MISO0_PA10()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x1<<10));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<12));
}        

/**
 * @brief       Set SPI2 MOSI20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA11 as MOSI20 of SPI2. PA11=MOSI20
 */
static __INLINE void GPIO_SPI2_MOSI0_PA11()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x1<<11));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<11));
}        

/**
 * @brief       Set SPI2 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB7~PB4 as SPI2 pins. PB4=SPISS20,PB5=SPICLK2,PB6=MOSI20,PB7=MISO20
 */
static __INLINE void GPIO_SPI2_PB()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) & ~(0x1<<4));
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x7<<5));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0xF<<15));
}        

/**
 * @brief       Set SPI2 SPISS20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB4 as SPISS20 of SPI2. PB4=SPISS20
 */
static __INLINE void GPIO_SPI2_SS0_PB4()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) & ~(0x1<<4));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<15));
}        

/**
 * @brief       Set SPI2 SPICLK2 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB5 as SPICLK2 of SPI2. PB5=SPICLK2
 */
static __INLINE void GPIO_SPI2_CLK_PB5()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<5));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<18));
}        

/**
 * @brief       Set SPI2 MOSI20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB6 as MOSI20 of SPI2. PB6=MOSI20
 */
static __INLINE void GPIO_SPI2_MOSI0_PB6()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<6));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<17));
}        

/**
 * @brief       Set SPI2 MISO20 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB7 as MISO20 of SPI2. PB7=MISO20
 */
static __INLINE void GPIO_SPI2_MISO0_PB7()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<7));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<16));
}        

/**
 * @brief       Set SPI2 MOSI21/MISO21 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD5/PD4 as MOSI21/MISO21 of SPI2. PD5=MOSI21,PD4=MISO21
 */
static __INLINE void GPIO_SPI2_MOSI1_MISO1()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) & ~(0x3<<4));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x3<<20));
}        

/*---------------------------------------------------------------------------------------------------------*/
/* External Interrupt                                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set External Interrupt 0 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB14 as /INT0. PB14=/INT0
 */
static __INLINE void GPIO_EINT0()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<14));
}

/**
 * @brief       Set External Interrupt 1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB15 as /INT1. PB15=/INT1
 */
static __INLINE void GPIO_EINT1()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<15));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<24));
}

/**
 * @brief       Set External Interrupt 1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD11 as /INT1. PD11=/INT1
 */
static __INLINE void GPIO_EINT1_PD11()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<11));
}

/*---------------------------------------------------------------------------------------------------------*/
/* CLKO output                                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set Clock output MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA15 as CLKO. PA15=CLKO
 */
static __INLINE void GPIO_CLKO_PA15()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<11));
}        

/**
 * @brief       Set Clock output MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB12 as CLKO. PB12=CLKO
 */
static __INLINE void GPIO_CLKO_PB12()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<12));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<10));
}

/**
 * @brief       Set Clock output MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC13 as CLKO. PC13=CLKO
 */
static __INLINE void GPIO_CLKO_PC13()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) & ~(0x1<<13));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<21));
}        

/**
 * @brief       Set Clock output MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PD10 as CLKO. PD10=CLKO
 */
static __INLINE void GPIO_CLKO_PD10()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<10));
}

/*---------------------------------------------------------------------------------------------------------*/
/* TIMER                                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set Event counter input or timer toggle output MFP pin of Timer0
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB8 as TM0. PB8=TM0
 */
static __INLINE void GPIO_TMR0()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<8));
}

/**
 * @brief       Set Event counter input or timer toggle output MFP pin of Timer1
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB9 as TM1. PB9=TM1
 */
static __INLINE void GPIO_TMR1()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<9));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<1));
}    

/**
 * @brief       Set Event counter input or timer toggle output MFP pin of Timer2
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB10 as TM2. PB10=TM2
 */
static __INLINE void GPIO_TMR2()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<10));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<0));
}

/**
 * @brief       Set Timer capture input MFP pin of Timer0
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB15 as T0EX. PB15=T0EX
 */
static __INLINE void GPIO_T0EX()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<15));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<24));
}

/**
 * @brief       Set Timer capture input MFP pin of Timer2
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB2 as T2EX. PB2=T2EX
 */
static __INLINE void GPIO_T2EX()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<2));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<26));
}        

/**
 * @brief       Set Timer capture input MFP pin of Timer3
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PB3 as T3EX. PB3=T3EX
 */
static __INLINE void GPIO_T3EX()
{
    outpw(&SYS->GPB_MFP, inpw(&SYS->GPB_MFP) | (0x1<<3));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<27));
}

/*---------------------------------------------------------------------------------------------------------*/
/* PWM                                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set PWM0 MFP pin for PWM output or capture
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA12 as PWM0. PA12=PWM0
 */
static __INLINE void GPIO_PWM0()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x1<<12));
}

/**
 * @brief       Set PWM1 MFP pin for PWM output or capture
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA13 as PWM1. PA13=PWM1
 */
static __INLINE void GPIO_PWM1()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x1<<13));
}        

/**
 * @brief       Set PWM2 MFP pin for PWM output or capture
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA14 as PWM2. PA14=PWM2
 */
static __INLINE void GPIO_PWM2_PA14()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x1<<14));
}         

/**
 * @brief       Set PWM2 MFP pin for PWM output or capture
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC12 as PWM2. PC12=PWM2
 */
static __INLINE void GPIO_PWM2_PC12()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<12));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<20));
}         

/**
 * @brief       Set PWM3 MFP pin for PWM output or capture
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA15 as PWM3. PA15=PWM3
 */
static __INLINE void GPIO_PWM3_PA15()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x1<<15));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) & ~(0x1<<9));
}         

/**
 * @brief       Set PWM3 MFP pin for PWM output or capture
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC13 as PWM3. PC13=PWM3
 */
static __INLINE void GPIO_PWM3_PC13()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0x1<<13));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<21));
}

/*---------------------------------------------------------------------------------------------------------*/
/* I2S                                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set I2S pin, except MCLK
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PC0=LRCLK,PC1=BCLK,PC2=DI,PC3=DO
 */
static __INLINE void GPIO_I2S()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) | (0xF<<0));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0xF<<5));
}

/**
 * @brief       Set I2S MCLK MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PA15 as MCLK. PA15=MCLK
 */
static __INLINE void GPIO_I2S_MCLK_PA15()
{
    outpw(&SYS->GPA_MFP, inpw(&SYS->GPA_MFP) | (0x1<<15));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<9));
}

/**
 * @brief       Set I2S MCLK MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PC12 as MCLK. PC12=MCLK
 */
static __INLINE void GPIO_I2S_MCLK_PC12()
{
    outpw(&SYS->GPC_MFP, inpw(&SYS->GPC_MFP) & ~(0x1<<12));
    outpw(&SYS->ALT_MFP, inpw(&SYS->ALT_MFP) | (0x1<<20));
}

/**
 * @brief       Set PS2 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PF2=PS2DAT,PF3=PS2CLK
 */
static __INLINE void GPIO_PS2()
{
    outpw(&SYS->GPF_MFP, inpw(&SYS->GPF_MFP) | (0x3<<2));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) & ~(0xF<<24));
}

/**
 * @brief       Set ADC0 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PD0=ADC0
 */
static __INLINE void GPIO_ADC0()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<0));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<16));
}

/**
 * @brief       Set ADC1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PD1=ADC1
 */
static __INLINE void GPIO_ADC1()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<1));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<17));
}        

/**
 * @brief       Set ADC2 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PD2=ADC2
 */
static __INLINE void GPIO_ADC2()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<2));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<18));
}        

/**
 * @brief       Set ADC3 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PD3=ADC3
 */
static __INLINE void GPIO_ADC3()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<3));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<19));
}        

/**
 * @brief       Set ADC4 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PD4=ADC4
 */
static __INLINE void GPIO_ADC4()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<4));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<20));
}        

/**
 * @brief       Set ADC5 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PD5=ADC5
 */
static __INLINE void GPIO_ADC5()
{
    outpw(&SYS->GPD_MFP, inpw(&SYS->GPD_MFP) | (0x1<<5));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x1<<21));
}        

/**
 * @brief       Set ADC6 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PF2=ADC6
 */
static __INLINE void GPIO_ADC6()
{
    outpw(&SYS->GPF_MFP, inpw(&SYS->GPF_MFP) | (0x1<<2));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x3<<24));
}

/**
 * @brief       Set ADC7 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     PF3=ADC7
 */
static __INLINE void GPIO_ADC7()
{
    outpw(&SYS->GPF_MFP, inpw(&SYS->GPF_MFP) | (0x1<<3));
    outpw(&SYS->ALT_MFP1, inpw(&SYS->ALT_MFP1) | (0x3<<26));
}

/**
 * @brief       Set XT1 MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PF1/PF0 as XT1_IN/XT1_OUT pin.PF1=XT1_IN,PF0=XT1_OUT
 */
static __INLINE void GPIO_XT1()
{
    outpw(&SYS->GPF_MFP, inpw(&SYS->GPF_MFP) | (0x3<<0));
}

/**
 * @brief       Set XT1_IN MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PF1 as XT1_IN pin.PF1=XT1_IN
 */
static __INLINE void GPIO_XT1IN()
{
    outpw(&SYS->GPF_MFP, inpw(&SYS->GPF_MFP) | (0x1<<1));
}

/**
 * @brief       Set XT1_IN MFP pin
 *
 * @param       None
 *
 * @retval      None
 *
 * @details     Set PF0 as XT1_OUT pin.PF0=XT1_OUT
 */
static __INLINE void GPIO_XT1OUT()
{
    outpw(&SYS->GPF_MFP, inpw(&SYS->GPF_MFP) | (0x1<<0));
}


/*@}*/ /* end of group GPIO_MACRO_FUNC */
/*@}*/ /* end of group GPIO_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

#endif
