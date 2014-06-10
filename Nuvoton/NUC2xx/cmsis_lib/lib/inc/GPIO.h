/**************************************************************************//**
 * @file     GPIO.h
 * @version  V1.00
 * $Revision: 10 $
 * $Date: 12/10/11 11:29a $
 * @brief    NUC200 Series General Purpose I/O Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__

#include "NUC200Series.h"


/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup GPIO_FUNC GPIO Device Function Interface
  * @{
  */


/* Define GPIO Pin Data Input/Output. It could be used to control each I/O pin by pin address mapping.
   Example 1:
   
       PA0 = 1; 
   
   It is used to set GPIO PA.0 to high;
   
   Example 2:
   
       if (PA0)
           PA0 = 0;
   
   If GPIO PA.0 pin status is high, then set GPIO PA.0 data output to low.
 */
#define GPIO_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))   
#define PA0             GPIO_PIN_DATA(0, 0 ) /*!< Specify PA.0 Pin Data Input/Output */
#define PA1             GPIO_PIN_DATA(0, 1 ) /*!< Specify PA.1 Pin Data Input/Output */
#define PA2             GPIO_PIN_DATA(0, 2 ) /*!< Specify PA.2 Pin Data Input/Output */
#define PA3             GPIO_PIN_DATA(0, 3 ) /*!< Specify PA.3 Pin Data Input/Output */
#define PA4             GPIO_PIN_DATA(0, 4 ) /*!< Specify PA.4 Pin Data Input/Output */
#define PA5             GPIO_PIN_DATA(0, 5 ) /*!< Specify PA.5 Pin Data Input/Output */
#define PA6             GPIO_PIN_DATA(0, 6 ) /*!< Specify PA.6 Pin Data Input/Output */
#define PA7             GPIO_PIN_DATA(0, 7 ) /*!< Specify PA.7 Pin Data Input/Output */
#define PA8             GPIO_PIN_DATA(0, 8 ) /*!< Specify PA.8 Pin Data Input/Output */
#define PA9             GPIO_PIN_DATA(0, 9 ) /*!< Specify PA.9 Pin Data Input/Output */
#define PA10            GPIO_PIN_DATA(0, 10) /*!< Specify PA.10 Pin Data Input/Output */
#define PA11            GPIO_PIN_DATA(0, 11) /*!< Specify PA.11 Pin Data Input/Output */
#define PA12            GPIO_PIN_DATA(0, 12) /*!< Specify PA.12 Pin Data Input/Output */
#define PA13            GPIO_PIN_DATA(0, 13) /*!< Specify PA.13 Pin Data Input/Output */
#define PA14            GPIO_PIN_DATA(0, 14) /*!< Specify PA.14 Pin Data Input/Output */
#define PA15            GPIO_PIN_DATA(0, 15) /*!< Specify PA.15 Pin Data Input/Output */
#define PB0             GPIO_PIN_DATA(1, 0 ) /*!< Specify PB.0 Pin Data Input/Output */
#define PB1             GPIO_PIN_DATA(1, 1 ) /*!< Specify PB.1 Pin Data Input/Output */
#define PB2             GPIO_PIN_DATA(1, 2 ) /*!< Specify PB.2 Pin Data Input/Output */
#define PB3             GPIO_PIN_DATA(1, 3 ) /*!< Specify PB.3 Pin Data Input/Output */
#define PB4             GPIO_PIN_DATA(1, 4 ) /*!< Specify PB.4 Pin Data Input/Output */
#define PB5             GPIO_PIN_DATA(1, 5 ) /*!< Specify PB.5 Pin Data Input/Output */
#define PB6             GPIO_PIN_DATA(1, 6 ) /*!< Specify PB.6 Pin Data Input/Output */
#define PB7             GPIO_PIN_DATA(1, 7 ) /*!< Specify PB.7 Pin Data Input/Output */
#define PB8             GPIO_PIN_DATA(1, 8 ) /*!< Specify PB.8 Pin Data Input/Output */
#define PB9             GPIO_PIN_DATA(1, 9 ) /*!< Specify PB.9 Pin Data Input/Output */
#define PB10            GPIO_PIN_DATA(1, 10) /*!< Specify PB.10 Pin Data Input/Output */
#define PB11            GPIO_PIN_DATA(1, 11) /*!< Specify PB.11 Pin Data Input/Output */
#define PB12            GPIO_PIN_DATA(1, 12) /*!< Specify PB.12 Pin Data Input/Output */
#define PB13            GPIO_PIN_DATA(1, 13) /*!< Specify PB.13 Pin Data Input/Output */
#define PB14            GPIO_PIN_DATA(1, 14) /*!< Specify PB.14 Pin Data Input/Output */
#define PB15            GPIO_PIN_DATA(1, 15) /*!< Specify PB.15 Pin Data Input/Output */
#define PC0             GPIO_PIN_DATA(2, 0 ) /*!< Specify PC.0 Pin Data Input/Output */
#define PC1             GPIO_PIN_DATA(2, 1 ) /*!< Specify PC.1 Pin Data Input/Output */
#define PC2             GPIO_PIN_DATA(2, 2 ) /*!< Specify PC.2 Pin Data Input/Output */
#define PC3             GPIO_PIN_DATA(2, 3 ) /*!< Specify PC.3 Pin Data Input/Output */
#define PC4             GPIO_PIN_DATA(2, 4 ) /*!< Specify PC.4 Pin Data Input/Output */
#define PC5             GPIO_PIN_DATA(2, 5 ) /*!< Specify PC.5 Pin Data Input/Output */
#define PC6             GPIO_PIN_DATA(2, 6 ) /*!< Specify PC.6 Pin Data Input/Output */
#define PC7             GPIO_PIN_DATA(2, 7 ) /*!< Specify PC.7 Pin Data Input/Output */
#define PC8             GPIO_PIN_DATA(2, 8 ) /*!< Specify PC.8 Pin Data Input/Output */
#define PC9             GPIO_PIN_DATA(2, 9 ) /*!< Specify PC.9 Pin Data Input/Output */
#define PC10            GPIO_PIN_DATA(2, 10) /*!< Specify PC.10 Pin Data Input/Output */
#define PC11            GPIO_PIN_DATA(2, 11) /*!< Specify PC.11 Pin Data Input/Output */
#define PC12            GPIO_PIN_DATA(2, 12) /*!< Specify PC.12 Pin Data Input/Output */
#define PC13            GPIO_PIN_DATA(2, 13) /*!< Specify PC.13 Pin Data Input/Output */
#define PC14            GPIO_PIN_DATA(2, 14) /*!< Specify PC.14 Pin Data Input/Output */
#define PC15            GPIO_PIN_DATA(2, 15) /*!< Specify PC.15 Pin Data Input/Output */
#define PD0             GPIO_PIN_DATA(3, 0 ) /*!< Specify PD.0 Pin Data Input/Output */
#define PD1             GPIO_PIN_DATA(3, 1 ) /*!< Specify PD.1 Pin Data Input/Output */
#define PD2             GPIO_PIN_DATA(3, 2 ) /*!< Specify PD.2 Pin Data Input/Output */
#define PD3             GPIO_PIN_DATA(3, 3 ) /*!< Specify PD.3 Pin Data Input/Output */
#define PD4             GPIO_PIN_DATA(3, 4 ) /*!< Specify PD.4 Pin Data Input/Output */
#define PD5             GPIO_PIN_DATA(3, 5 ) /*!< Specify PD.5 Pin Data Input/Output */
#define PD6             GPIO_PIN_DATA(3, 6 ) /*!< Specify PD.6 Pin Data Input/Output */
#define PD7             GPIO_PIN_DATA(3, 7 ) /*!< Specify PD.7 Pin Data Input/Output */
#define PD8             GPIO_PIN_DATA(3, 8 ) /*!< Specify PD.8 Pin Data Input/Output */
#define PD9             GPIO_PIN_DATA(3, 9 ) /*!< Specify PD.9 Pin Data Input/Output */
#define PD10            GPIO_PIN_DATA(3, 10) /*!< Specify PD.10 Pin Data Input/Output */
#define PD11            GPIO_PIN_DATA(3, 11) /*!< Specify PD.11 Pin Data Input/Output */
#define PD12            GPIO_PIN_DATA(3, 12) /*!< Specify PD.12 Pin Data Input/Output */
#define PD13            GPIO_PIN_DATA(3, 13) /*!< Specify PD.13 Pin Data Input/Output */
#define PD14            GPIO_PIN_DATA(3, 14) /*!< Specify PD.14 Pin Data Input/Output */
#define PD15            GPIO_PIN_DATA(3, 15) /*!< Specify PD.15 Pin Data Input/Output */
#define PE0             GPIO_PIN_DATA(4, 0 ) /*!< Specify PE.0 Pin Data Input/Output */
#define PE1             GPIO_PIN_DATA(4, 1 ) /*!< Specify PE.1 Pin Data Input/Output */
#define PE2             GPIO_PIN_DATA(4, 2 ) /*!< Specify PE.2 Pin Data Input/Output */
#define PE3             GPIO_PIN_DATA(4, 3 ) /*!< Specify PE.3 Pin Data Input/Output */
#define PE4             GPIO_PIN_DATA(4, 4 ) /*!< Specify PE.4 Pin Data Input/Output */
#define PE5             GPIO_PIN_DATA(4, 5 ) /*!< Specify PE.5 Pin Data Input/Output */
#define PE6             GPIO_PIN_DATA(4, 6 ) /*!< Specify PE.6 Pin Data Input/Output */
#define PE7             GPIO_PIN_DATA(4, 7 ) /*!< Specify PE.7 Pin Data Input/Output */
#define PE8             GPIO_PIN_DATA(4, 8 ) /*!< Specify PE.8 Pin Data Input/Output */
#define PE9             GPIO_PIN_DATA(4, 9 ) /*!< Specify PE.9 Pin Data Input/Output */
#define PE10            GPIO_PIN_DATA(4, 10) /*!< Specify PE.10 Pin Data Input/Output */
#define PE11            GPIO_PIN_DATA(4, 11) /*!< Specify PE.11 Pin Data Input/Output */
#define PE12            GPIO_PIN_DATA(4, 12) /*!< Specify PE.12 Pin Data Input/Output */
#define PE13            GPIO_PIN_DATA(4, 13) /*!< Specify PE.13 Pin Data Input/Output */
#define PE14            GPIO_PIN_DATA(4, 14) /*!< Specify PE.14 Pin Data Input/Output */
#define PE15            GPIO_PIN_DATA(4, 15) /*!< Specify PE.15 Pin Data Input/Output */
#define PF0             GPIO_PIN_DATA(5, 0 ) /*!< Specify PF.0 Pin Data Input/Output */
#define PF1             GPIO_PIN_DATA(5, 1 ) /*!< Specify PF.1 Pin Data Input/Output */
#define PF2             GPIO_PIN_DATA(5, 2 ) /*!< Specify PF.2 Pin Data Input/Output */
#define PF3             GPIO_PIN_DATA(5, 3 ) /*!< Specify PF.3 Pin Data Input/Output */
        

/*---------------------------------------------------------------------------------------------------------*/
/*  PMD Constant Definitions                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_PMD_INPUT              0x0UL                  /*!< Input Mode */
#define GPIO_PMD_OUTPUT             0x1UL                  /*!< Output Mode */
#define GPIO_PMD_OPEN_DRAIN         0x2UL                  /*!< Open-Drain Mode */
#define GPIO_PMD_QUASI              0x3UL                  /*!< Quasi-bidirectional Mode */
#define GPIO_PMD_MODE(pin, mode)    ((mode) << ((pin)<<1)) /*!< Generate the PMD mode setting for each pin  */

#define GPIO_PMD_PMD0_INPUT         0x00000000UL /*!< PMD Setting of Pin 0 for Input Mode */
#define GPIO_PMD_PMD0_OUTPUT        0x00000001UL /*!< PMD Setting of Pin 0 for Output Mode */
#define GPIO_PMD_PMD0_OPEN_DRAIN    0x00000002UL /*!< PMD Setting of Pin 0 for Open-Drain Mode */
#define GPIO_PMD_PMD0_QUASI         0x00000003UL /*!< PMD Setting of Pin 0 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD1_INPUT         0x00000000UL /*!< PMD Setting of Pin 1 for Input Mode */
#define GPIO_PMD_PMD1_OUTPUT        0x00000004UL /*!< PMD Setting of Pin 1 for Output Mode */
#define GPIO_PMD_PMD1_OPEN_DRAIN    0x00000008UL /*!< PMD Setting of Pin 1 for Open-Drain Mode */
#define GPIO_PMD_PMD1_QUASI         0x0000000CUL /*!< PMD Setting of Pin 1 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD2_INPUT         0x00000000UL /*!< PMD Setting of Pin 2 for Input Mode */
#define GPIO_PMD_PMD2_OUTPUT        0x00000010UL /*!< PMD Setting of Pin 2 for Output Mode */
#define GPIO_PMD_PMD2_OPEN_DRAIN    0x00000020UL /*!< PMD Setting of Pin 2 for Open-Drain Mode */
#define GPIO_PMD_PMD2_QUASI         0x00000030UL /*!< PMD Setting of Pin 2 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD3_INPUT         0x00000000UL /*!< PMD Setting of Pin 3 for Input Mode */
#define GPIO_PMD_PMD3_OUTPUT        0x00000040UL /*!< PMD Setting of Pin 3 for Output Mode */
#define GPIO_PMD_PMD3_OPEN_DRAIN    0x00000080UL /*!< PMD Setting of Pin 3 for Open-Drain Mode */
#define GPIO_PMD_PMD3_QUASI         0x000000C0UL /*!< PMD Setting of Pin 3 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD4_INPUT         0x00000000UL /*!< PMD Setting of Pin 4 for Input Mode */
#define GPIO_PMD_PMD4_OUTPUT        0x00000100UL /*!< PMD Setting of Pin 4 for Output Mode */
#define GPIO_PMD_PMD4_OPEN_DRAIN    0x00000200UL /*!< PMD Setting of Pin 4 for Open-Drain Mode */
#define GPIO_PMD_PMD4_QUASI         0x00000300UL /*!< PMD Setting of Pin 4 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD5_INPUT         0x00000000UL /*!< PMD Setting of Pin 5 for Input Mode */
#define GPIO_PMD_PMD5_OUTPUT        0x00000400UL /*!< PMD Setting of Pin 5 for Output Mode */
#define GPIO_PMD_PMD5_OPEN_DRAIN    0x00000800UL /*!< PMD Setting of Pin 5 for Open-Drain Mode */
#define GPIO_PMD_PMD5_QUASI         0x00000C00UL /*!< PMD Setting of Pin 5 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD6_INPUT         0x00000000UL /*!< PMD Setting of Pin 6 for Input Mode */
#define GPIO_PMD_PMD6_OUTPUT        0x00001000UL /*!< PMD Setting of Pin 6 for Output Mode */
#define GPIO_PMD_PMD6_OPEN_DRAIN    0x00002000UL /*!< PMD Setting of Pin 6 for Open-Drain Mode */
#define GPIO_PMD_PMD6_QUASI         0x00003000UL /*!< PMD Setting of Pin 6 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD7_INPUT         0x00000000UL /*!< PMD Setting of Pin 7 for Input Mode */
#define GPIO_PMD_PMD7_OUTPUT        0x00004000UL /*!< PMD Setting of Pin 7 for Output Mode */
#define GPIO_PMD_PMD7_OPEN_DRAIN    0x00008000UL /*!< PMD Setting of Pin 7 for Open-Drain Mode */
#define GPIO_PMD_PMD7_QUASI         0x0000C000UL /*!< PMD Setting of Pin 7 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD8_INPUT         0x00000000UL /*!< PMD Setting of Pin 8 for Input Mode */
#define GPIO_PMD_PMD8_OUTPUT        0x00010000UL /*!< PMD Setting of Pin 8 for Output Mode */
#define GPIO_PMD_PMD8_OPEN_DRAIN    0x00020000UL /*!< PMD Setting of Pin 8 for Open-Drain Mode */
#define GPIO_PMD_PMD8_QUASI         0x00030000UL /*!< PMD Setting of Pin 8 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD9_INPUT         0x00000000UL /*!< PMD Setting of Pin 9 for Input Mode */
#define GPIO_PMD_PMD9_OUTPUT        0x00040000UL /*!< PMD Setting of Pin 9 for Output Mode */
#define GPIO_PMD_PMD9_OPEN_DRAIN    0x00080000UL /*!< PMD Setting of Pin 9 for Open-Drain Mode */
#define GPIO_PMD_PMD9_QUASI         0x000C0000UL /*!< PMD Setting of Pin 9 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD10_INPUT        0x00000000UL /*!< PMD Setting of Pin 10 for Input Mode */
#define GPIO_PMD_PMD10_OUTPUT       0x00100000UL /*!< PMD Setting of Pin 10 for Output Mode */
#define GPIO_PMD_PMD10_OPEN_DRAIN   0x00200000UL /*!< PMD Setting of Pin 10 for Open-Drain Mode */
#define GPIO_PMD_PMD10_QUASI        0x00300000UL /*!< PMD Setting of Pin 10 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD11_INPUT        0x00000000UL /*!< PMD Setting of Pin 11 for Input Mode */
#define GPIO_PMD_PMD11_OUTPUT       0x00400000UL /*!< PMD Setting of Pin 11 for Output Mode */
#define GPIO_PMD_PMD11_OPEN_DRAIN   0x00800000UL /*!< PMD Setting of Pin 11 for Open-Drain Mode */
#define GPIO_PMD_PMD11_QUASI        0x00C00000UL /*!< PMD Setting of Pin 11 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD12_INPUT        0x00000000UL /*!< PMD Setting of Pin 12 for Input Mode */
#define GPIO_PMD_PMD12_OUTPUT       0x01000000UL /*!< PMD Setting of Pin 12 for Output Mode */
#define GPIO_PMD_PMD12_OPEN_DRAIN   0x02000000UL /*!< PMD Setting of Pin 12 for Open-Drain Mode */
#define GPIO_PMD_PMD12_QUASI        0x03000000UL /*!< PMD Setting of Pin 12 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD13_INPUT        0x00000000UL /*!< PMD Setting of Pin 13 for Input Mode */
#define GPIO_PMD_PMD13_OUTPUT       0x04000000UL /*!< PMD Setting of Pin 13 for Output Mode */
#define GPIO_PMD_PMD13_OPEN_DRAIN   0x08000000UL /*!< PMD Setting of Pin 13 for Open-Drain Mode */
#define GPIO_PMD_PMD13_QUASI        0x0C000000UL /*!< PMD Setting of Pin 13 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD14_INPUT        0x00000000UL /*!< PMD Setting of Pin 14 for Input Mode */
#define GPIO_PMD_PMD14_OUTPUT       0x10000000UL /*!< PMD Setting of Pin 14 for Output Mode */
#define GPIO_PMD_PMD14_OPEN_DRAIN   0x20000000UL /*!< PMD Setting of Pin 14 for Open-Drain Mode */
#define GPIO_PMD_PMD14_QUASI        0x30000000UL /*!< PMD Setting of Pin 14 for Quasi-bidirectional Mode */
#define GPIO_PMD_PMD15_INPUT        0x00000000UL /*!< PMD Setting of Pin 15 for Input Mode */
#define GPIO_PMD_PMD15_OUTPUT       0x40000000UL /*!< PMD Setting of Pin 15 for Output Mode */
#define GPIO_PMD_PMD15_OPEN_DRAIN   0x80000000UL /*!< PMD Setting of Pin 15 for Open-Drain Mode */
#define GPIO_PMD_PMD15_QUASI        0xC0000000UL /*!< PMD Setting of Pin 15 for Quasi-bidirectional Mode */
                                            

/*---------------------------------------------------------------------------------------------------------*/
/*  IMD Constant Definitions                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_IMD_EDGE               0UL               /*!< IMD Setting for Edge Trigger Mode */
#define GPIO_IMD_LEVEL              1UL               /*!< IMD Setting for Edge Level Mode */
#define GPIO_IMD_MODE(pin, mode)    ((mode) << (pin)) /*!< Generate IMD Mode Setting for Pin */
                                                        
#define GPIO_IMD_IMD0_EDGE          0x0000UL /*!< IMD Setting of Pin 0 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD1_EDGE          0x0000UL /*!< IMD Setting of Pin 1 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD2_EDGE          0x0000UL /*!< IMD Setting of Pin 2 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD3_EDGE          0x0000UL /*!< IMD Setting of Pin 3 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD4_EDGE          0x0000UL /*!< IMD Setting of Pin 4 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD5_EDGE          0x0000UL /*!< IMD Setting of Pin 5 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD6_EDGE          0x0000UL /*!< IMD Setting of Pin 6 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD7_EDGE          0x0000UL /*!< IMD Setting of Pin 7 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD8_EDGE          0x0000UL /*!< IMD Setting of Pin 8 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD9_EDGE          0x0000UL /*!< IMD Setting of Pin 9 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD10_EDGE         0x0000UL /*!< IMD Setting of Pin 10 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD11_EDGE         0x0000UL /*!< IMD Setting of Pin 11 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD12_EDGE         0x0000UL /*!< IMD Setting of Pin 12 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD13_EDGE         0x0000UL /*!< IMD Setting of Pin 13 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD14_EDGE         0x0000UL /*!< IMD Setting of Pin 14 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD15_EDGE         0x0000UL /*!< IMD Setting of Pin 15 for Edge Trigger Mode */ 
#define GPIO_IMD_IMD0_LEVEL         0x0001UL /*!< IMD Setting of Pin 0 for Level Trigger Mode */ 
#define GPIO_IMD_IMD1_LEVEL         0x0002UL /*!< IMD Setting of Pin 1 for Level Trigger Mode */ 
#define GPIO_IMD_IMD2_LEVEL         0x0004UL /*!< IMD Setting of Pin 2 for Level Trigger Mode */ 
#define GPIO_IMD_IMD3_LEVEL         0x0008UL /*!< IMD Setting of Pin 3 for Level Trigger Mode */ 
#define GPIO_IMD_IMD4_LEVEL         0x0010UL /*!< IMD Setting of Pin 4 for Level Trigger Mode */ 
#define GPIO_IMD_IMD5_LEVEL         0x0020UL /*!< IMD Setting of Pin 5 for Level Trigger Mode */ 
#define GPIO_IMD_IMD6_LEVEL         0x0040UL /*!< IMD Setting of Pin 6 for Level Trigger Mode */ 
#define GPIO_IMD_IMD7_LEVEL         0x0080UL /*!< IMD Setting of Pin 7 for Level Trigger Mode */ 
#define GPIO_IMD_IMD8_LEVEL         0x0100UL /*!< IMD Setting of Pin 8 for Level Trigger Mode */ 
#define GPIO_IMD_IMD9_LEVEL         0x0200UL /*!< IMD Setting of Pin 9 for Level Trigger Mode */ 
#define GPIO_IMD_IMD10_LEVEL        0x0400UL /*!< IMD Setting of Pin 10 for Level Trigger Mode */ 
#define GPIO_IMD_IMD11_LEVEL        0x0800UL /*!< IMD Setting of Pin 11 for Level Trigger Mode */ 
#define GPIO_IMD_IMD12_LEVEL        0x1000UL /*!< IMD Setting of Pin 12 for Level Trigger Mode */ 
#define GPIO_IMD_IMD13_LEVEL        0x2000UL /*!< IMD Setting of Pin 13 for Level Trigger Mode */ 
#define GPIO_IMD_IMD14_LEVEL        0x4000UL /*!< IMD Setting of Pin 14 for Level Trigger Mode */ 
#define GPIO_IMD_IMD15_LEVEL        0x8000UL /*!< IMD Setting of Pin 15 for Level Trigger Mode */ 

                                    
/*---------------------------------------------------------------------------------------------------------*/
/*  IEN Constant Definitions                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_IEN_IF_EN(pin)         (1UL << (pin))      /*!< Generate IEN Setting of Specified Pin for Enable Falling/Low Level Interrupt */ 
#define GPIO_IEN_IR_EN(pin)         (1UL << ((pin)+16)) /*!< Generate IEN Setting of Specified Pin for Enable Rising/High Level Interrupt */ 

#define GPIO_IEN_IF_EN0             0x00000001UL /*!< IEN Setting of Pin 0 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN1             0x00000002UL /*!< IEN Setting of Pin 1 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN2             0x00000004UL /*!< IEN Setting of Pin 2 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN3             0x00000008UL /*!< IEN Setting of Pin 3 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN4             0x00000010UL /*!< IEN Setting of Pin 4 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN5             0x00000020UL /*!< IEN Setting of Pin 5 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN6             0x00000040UL /*!< IEN Setting of Pin 6 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN7             0x00000080UL /*!< IEN Setting of Pin 7 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN8             0x00000100UL /*!< IEN Setting of Pin 8 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN9             0x00000200UL /*!< IEN Setting of Pin 9 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN10            0x00000400UL /*!< IEN Setting of Pin 10 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN11            0x00000800UL /*!< IEN Setting of Pin 11 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN12            0x00001000UL /*!< IEN Setting of Pin 12 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN13            0x00002000UL /*!< IEN Setting of Pin 13 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN14            0x00004000UL /*!< IEN Setting of Pin 14 for Eanble Falling/Low Level Interrupt */ 
#define GPIO_IEN_IF_EN15            0x00008000UL /*!< IEN Setting of Pin 15 for Eanble Falling/Low Level Interrupt */ 
                                    
#define GPIO_IEN_IR_EN0             0x00010000UL /*!< IEN Setting of Pin 0 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN1             0x00020000UL /*!< IEN Setting of Pin 1 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN2             0x00040000UL /*!< IEN Setting of Pin 2 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN3             0x00080000UL /*!< IEN Setting of Pin 3 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN4             0x00100000UL /*!< IEN Setting of Pin 4 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN5             0x00200000UL /*!< IEN Setting of Pin 5 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN6             0x00400000UL /*!< IEN Setting of Pin 6 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN7             0x00800000UL /*!< IEN Setting of Pin 7 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN8             0x01000000UL /*!< IEN Setting of Pin 8 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN9             0x02000000UL /*!< IEN Setting of Pin 9 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN10            0x04000000UL /*!< IEN Setting of Pin 10 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN11            0x08000000UL /*!< IEN Setting of Pin 11 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN12            0x10000000UL /*!< IEN Setting of Pin 12 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN13            0x20000000UL /*!< IEN Setting of Pin 13 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN14            0x40000000UL /*!< IEN Setting of Pin 14 for Eanble Rising/High Level Interrupt */ 
#define GPIO_IEN_IR_EN15            0x80000000UL /*!< IEN Setting of Pin 15 for Eanble Rising/High Level Interrupt */ 


/*---------------------------------------------------------------------------------------------------------*/
/*  ISRC Constant Definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_ISRC_ISRC0             0x0001UL /*!< ISRC Setting of Pin 0 for Indicates Pin 0 generate an interrupt */ 
#define GPIO_ISRC_ISRC1             0x0002UL /*!< ISRC Setting of Pin 1 for Indicates Pin 1 generate an interrupt */ 
#define GPIO_ISRC_ISRC2             0x0004UL /*!< ISRC Setting of Pin 2 for Indicates Pin 2 generate an interrupt */ 
#define GPIO_ISRC_ISRC3             0x0008UL /*!< ISRC Setting of Pin 3 for Indicates Pin 3 generate an interrupt */ 
#define GPIO_ISRC_ISRC4             0x0010UL /*!< ISRC Setting of Pin 4 for Indicates Pin 4 generate an interrupt */
#define GPIO_ISRC_ISRC5             0x0020UL /*!< ISRC Setting of Pin 5 for Indicates Pin 5 generate an interrupt */ 
#define GPIO_ISRC_ISRC6             0x0040UL /*!< ISRC Setting of Pin 6 for Indicates Pin 6 generate an interrupt */ 
#define GPIO_ISRC_ISRC7             0x0080UL /*!< ISRC Setting of Pin 7 for Indicates Pin 7 generate an interrupt */ 
#define GPIO_ISRC_ISRC8             0x0100UL /*!< ISRC Setting of Pin 8 for Indicates Pin 0 generate an interrupt */ 
#define GPIO_ISRC_ISRC9             0x0200UL /*!< ISRC Setting of Pin 9 for Indicates Pin 1 generate an interrupt */ 
#define GPIO_ISRC_ISRC10            0x0400UL /*!< ISRC Setting of Pin 10 for Indicates Pin 2 generate an interrupt */ 
#define GPIO_ISRC_ISRC11            0x0800UL /*!< ISRC Setting of Pin 11 for Indicates Pin 3 generate an interrupt */ 
#define GPIO_ISRC_ISRC12            0x1000UL /*!< ISRC Setting of Pin 12 for Indicates Pin 4 generate an interrupt */
#define GPIO_ISRC_ISRC13            0x2000UL /*!< ISRC Setting of Pin 13 for Indicates Pin 5 generate an interrupt */ 
#define GPIO_ISRC_ISRC14            0x4000UL /*!< ISRC Setting of Pin 14 for Indicates Pin 6 generate an interrupt */ 
#define GPIO_ISRC_ISRC15            0x8000UL /*!< ISRC Setting of Pin 15 for Indicates Pin 7 generate an interrupt */ 


/*---------------------------------------------------------------------------------------------------------*/
/*  DBNCECON Constant Definitions                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_DBNCECON_ICLK_ON           0x00000020UL /*!< DBNCECON setting for all IO pins edge detection circuit is always active after reset */ 
#define GPIO_DBNCECON_ICLK_OFF          0x00000000UL /*!< DBNCECON setting for edge detection circuit is active only if IO pin corresponding GPIOx_IEN bit is set to 1 */ 

#define GPIO_DBNCECON_DBCLKSRC_IRC10K   0x00000010UL /*!< DBNCECON setting for de-bounce counter clock source is the internal 10 kHz */ 
#define GPIO_DBNCECON_DBCLKSRC_HCLK     0x00000000UL /*!< DBNCECON setting for de-bounce counter clock source is the internal HCLK */ 

#define GPIO_DBNCECON_DBCLKSEL_1        0x00000000UL /*!< DBNCECON setting for sampling cycle = 1 clocks */
#define GPIO_DBNCECON_DBCLKSEL_2        0x00000001UL /*!< DBNCECON setting for sampling cycle = 2 clocks */
#define GPIO_DBNCECON_DBCLKSEL_4        0x00000002UL /*!< DBNCECON setting for sampling cycle = 4 clocks */
#define GPIO_DBNCECON_DBCLKSEL_8        0x00000003UL /*!< DBNCECON setting for sampling cycle = 8 clocks */
#define GPIO_DBNCECON_DBCLKSEL_16       0x00000004UL /*!< DBNCECON setting for sampling cycle = 16 clocks */
#define GPIO_DBNCECON_DBCLKSEL_32       0x00000005UL /*!< DBNCECON setting for sampling cycle = 32 clocks */
#define GPIO_DBNCECON_DBCLKSEL_64       0x00000006UL /*!< DBNCECON setting for sampling cycle = 64 clocks */
#define GPIO_DBNCECON_DBCLKSEL_128      0x00000007UL /*!< DBNCECON setting for sampling cycle = 128 clocks */
#define GPIO_DBNCECON_DBCLKSEL_256      0x00000008UL /*!< DBNCECON setting for sampling cycle = 256 clocks */
#define GPIO_DBNCECON_DBCLKSEL_512      0x00000009UL /*!< DBNCECON setting for sampling cycle = 512 clocks */
#define GPIO_DBNCECON_DBCLKSEL_1024     0x0000000AUL /*!< DBNCECON setting for sampling cycle = 1024 clocks */
#define GPIO_DBNCECON_DBCLKSEL_2048     0x0000000BUL /*!< DBNCECON setting for sampling cycle = 2048 clocks */
#define GPIO_DBNCECON_DBCLKSEL_4096     0x0000000CUL /*!< DBNCECON setting for sampling cycle = 4096 clocks */
#define GPIO_DBNCECON_DBCLKSEL_8192     0x0000000DUL /*!< DBNCECON setting for sampling cycle = 8192 clocks */
#define GPIO_DBNCECON_DBCLKSEL_16384    0x0000000EUL /*!< DBNCECON setting for sampling cycle = 16384 clocks */
#define GPIO_DBNCECON_DBCLKSEL_32768    0x0000000FUL /*!< DBNCECON setting for sampling cycle = 32768 clocks */


/*---------------------------------------------------------------------------------------------------------*/
/*  DBEN Constant Definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_DBEN_ENABLE(pin)       (1UL << (pin)) /*!< DBEN setting for enable specified pin de-bounce function */      


/*---------------------------------------------------------------------------------------------------------*/
/*  DMASK Constant Definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_DMASK_ENABLE(pin)      (1UL << (pin)) /*!< DMASK setting for mask specified pin DOUT function */      


/*---------------------------------------------------------------------------------------------------------*/
/*  OFFD Constant Definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_OFFD_ENABLE(pin)       (1UL << ((pin)+16)) /*!< OFFD setting for disable specified pin I/O digital input path */      


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Interrupt Type Constant Definitions                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INT_RISING             0x00010000UL /*!< Interrupt enable by Input Rising Edge */
#define GPIO_INT_FALLING            0x00000001UL /*!< Interrupt enable by Input Falling Edge */
#define GPIO_INT_BOTH_EDGE          0x00010001UL /*!< Interrupt enable by both Rising Edge and Falling Edge */
#define GPIO_INT_HIGH               0x01010000UL /*!< Interrupt enable by Level-High */    
#define GPIO_INT_LOW                0x01000001UL /*!< Interrupt enable by Level-Level */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Macro Definitions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set GPIO Pin Mode
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 * @param[in]   mode        The pin mode of specified GPIO pin. It could be GPIO_PMD_INPUT, GPIO_PMD_OUTPUT, GPIO_PMD_OPEN_DRAIN or GPIO_PMD_QUASI.
 *
 * @return      None
 *
 * @details     Set the pin mode of specified GPIO pin.
 */
#define _GPIO_SET_PIN_MODE(PORT, pin, mode)     ((PORT)->PMD = ((PORT)->PMD & ~GPIO_PMD_MODE(pin, GPIO_PMD_QUASI)) | GPIO_PMD_MODE(pin, mode))


/**
 * @brief       Enable I/O Digital Input Path
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Enable I/O digital input path of specified GPIO pin.
 */
#define _GPIO_ENABLE_DIGITAL_PATH(PORT, pin)    ((PORT)->OFFD &= ~GPIO_OFFD_ENABLE(pin))


/**
 * @brief       Disable I/O Digital Input Path
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Disable I/O digital input path of specified GPIO pin.
 */
#define _GPIO_DISABLE_DIGITAL_PATH(PORT, pin)   ((PORT)->OFFD |= GPIO_OFFD_ENABLE(pin))


/**
 * @brief       Enable Pin De-bounce Function
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Enable the interrupt de-bounce function of specified GPIO pin.
 */
#define _GPIO_ENABLE_DEBOUNCE(PORT, pin)         ((PORT)->DBEN |= GPIO_DBEN_ENABLE(pin))


/**
 * @brief       Disable Pin De-bounce Function
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Disable the interrupt de-bounce function of specified GPIO pin.
 */
#define _GPIO_DISABLE_DEBOUNCE(PORT, pin)       ((PORT)->DBEN &= ~GPIO_DBEN_ENABLE(pin))


/**
 * @brief       Set De-bounce Sampling Cycle Time
 *
 * @param[in]   clksrc      The de-bounce counter clock source. It could be GPIO_DBNCECON_DBCLKSRC_HCLK or GPIO_DBNCECON_DBCLKSRC_IRC10K.
 * @param[in]   clksel      The de-bounce sampling cycle selectionn. It could be \n
 *                              GPIO_DBNCECON_DBCLKSEL_1, GPIO_DBNCECON_DBCLKSEL_2, GPIO_DBNCECON_DBCLKSEL_4, GPIO_DBNCECON_DBCLKSEL_8, \n
 *                              GPIO_DBNCECON_DBCLKSEL_16, GPIO_DBNCECON_DBCLKSEL_32, GPIO_DBNCECON_DBCLKSEL_64, GPIO_DBNCECON_DBCLKSEL_128, \n
 *                              GPIO_DBNCECON_DBCLKSEL_256, GPIO_DBNCECON_DBCLKSEL_512, GPIO_DBNCECON_DBCLKSEL_1024, GPIO_DBNCECON_DBCLKSEL_2048, \n
 *                              GPIO_DBNCECON_DBCLKSEL_4096, GPIO_DBNCECON_DBCLKSEL_8192, GPIO_DBNCECON_DBCLKSEL_16384, GPIO_DBNCECON_DBCLKSEL_32768.
 *
 * @return      None
 *
 * @details     Set the interrupt de-bounce sampling cycle time based on the debounce counter clock source. \n
 *              Example: _GPIO_SET_DEBOUNCE_TIME(GPIO_DBNCECON_DBCLKSRC_IRC10K, GPIO_DBNCECON_DBCLKSEL_4). \n
 *              It's meaning the De-debounce counter clock source is internal 10 KHz and sampling cycle selection is 4. \n
 *              Then the target de-bounce sampling cycle time is (2^4)*(1/(10*1000)) s = 16*0.0001 s = 1600 us,
 *              and system will sampling interrupt input once per 1600 us.
 */
#define _GPIO_SET_DEBOUNCE_TIME(clksrc, clksel)  (GPIO->DBNCECON = (GPIO_DBNCECON_ICLK_ON_Msk | clksrc | clksel))


/**
 * @brief       Get GPIO Pin Interrupt Status
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @retval      0           No interrupt at specified GPIO pin
 * @retval      1           The specified GPIO pin generate an interrupt
 *
 * @details     Get the interrupt status of specified GPIO pin.
 */
#define _GPIO_GET_INT_STATUS(PORT, pin)          ((((PORT)->ISRC & (1<<pin)) == (1<<pin))? 1:0)


/**
 * @brief       Clear GPIO Pin Interrupt Status
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   pin         The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     Clear the interrupt status of specified GPIO pin.
 */
#define _GPIO_CLEAR_INT_STATUS(PORT, pin)          ((PORT)->ISRC = (1<<pin))


/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Enable GPIO interrupt
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
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
    PORT->IMD |= (_GET_BYTE3(u32IntAttribs) << u32Pin);
    PORT->IEN |= ((u32IntAttribs & 0xFFFFFFUL) << u32Pin);
}


/**
 * @brief       Disable GPIO interrupt
 *
 * @param[in]   PORT        GPIO port. It could be PA, PB, PC, PD, PE and PF.
 * @param[in]   u32Pin      The pin of specified GPIO port. It could be 0 ~ 15.
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
static __INLINE void GPIO_DisableInt(GPIO_T *PORT, uint32_t u32Pin)
{
    PORT->IMD &= ~((BIT0) << u32Pin);
    PORT->IEN &= ~((0x00010001UL) << u32Pin);
}



/**
  * @} End of GPIO Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 

#endif  //__GPIO_H__
