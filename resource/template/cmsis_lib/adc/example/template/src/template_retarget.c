/*********************************************************************************************************//**
 * @file    holtek_retarget.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   Retarget layer for target-dependent low level functions.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"
#include "ht32f175x_275x_usart.h"
#include <stdio.h>

#if defined   ( __CC_ARM   )
  #include <rt_misc.h>
#endif

/* Private typedef -----------------------------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------------------------------------*/
#if defined   ( __CC_ARM   )
  #pragma import(__use_no_semihosting_swi)
#endif

/* Private macro -------------------------------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------------------------------------*/
#define RETARGET_USART0     1
#define RETARGET_USART1     2
#define RETARGET_ITM        3

/* RETARGET definition to use USART function by C Library                                                   */
/*
//  <e0> Enable Retarget
//  <o1> Retarget port
//      <1=> USART0
//      <2=> USART1
//      <3=> ITM
//  </e>
*/
#define _RETARGET            1
#define RETARGET_PORT        1

#if (RETARGET_PORT == RETARGET_USART0)
  #define RETARGET_USART_PORT       USART0
  #define RETARGET_COM_PORT         COM1
#elif (RETARGET_PORT == RETARGET_USART1)
  #define RETARGET_USART_PORT       USART1
  #define RETARGET_COM_PORT         COM2
#endif

#if (RETARGET_PORT == RETARGET_ITM)
#define ITM_PORT8(n)    (*((vu8 *)(0xE0000000 + 4 * n)))
#define ITM_PORT16(n)   (*((vu16 *)(0xE0000000 + 4 * n)))
#define ITM_PORT32(n)   (*((vu32 *)(0xE0000000 + 4 * n)))

#define DEMCR           (*((vu32 *)(0xE000EDFC)))
#define TRCENA          (0x01000000)
#endif

/* Private function prototypes -----------------------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------------------------------------*/
#if ( (RETARGET_PORT == RETARGET_USART0) || (RETARGET_PORT == RETARGET_USART1) )

/* Private typedef -----------------------------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------------------------------------*/

/*********************************************************************************************************//**
 * @brief  Put char to USART.
 * @param  ch: The char put to USART.
 * @retval The char put to USART.
 ************************************************************************************************************/
u16 SERIAL_PutChar(u16 ch)
{
  USART_SendData(RETARGET_USART_PORT, (u8)ch);
  while (USART_GetLineStatus(RETARGET_USART_PORT, USART_LSR_TE) == RESET)
  {
  }
  return ch;
}

/*********************************************************************************************************//**
 * @brief  Get char from USART.
 * @retval The char got from USART.
 ************************************************************************************************************/
u16 SERIAL_GetChar(void)
{
  while (USART_GetLineStatus(RETARGET_USART_PORT, USART_LSR_RFDR) == RESET)
  {
  }
  return USART_ReceiveData(RETARGET_USART_PORT);
}
#endif

#if defined (__CC_ARM)
struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;
#endif

int __backspace(FILE *stream)
{
  return 0;
}

int fputc (int ch, FILE *f)
{
  #if (RETARGET_PORT == RETARGET_ITM)
  if (DEMCR & TRCENA)
  {
    while (ITM_PORT32(0) == 0);
    ITM_PORT8(0) = ch;
  }
  return (ch);
  #else
  return (SERIAL_PutChar(ch));
  #endif
}

int fgetc (FILE *f)
{
  #if (RETARGET_PORT == RETARGET_ITM)
  return 0;
  #else
  return (SERIAL_GetChar());
  #endif
}

int ferror(FILE *f) {
  /* Your implementation of ferror                                                                          */
  return EOF;
}

void _ttywrch(int ch)
{
  #if (RETARGET_PORT == RETARGET_ITM)
  if (DEMCR & TRCENA)
  {
    while (ITM_PORT32(0) == 0);
    ITM_PORT8(0) = ch;
  }
  #else
  SERIAL_PutChar(ch);
  #endif
}

void _sys_exit(int return_code)
{
label:  goto label;  /* endless loop                                                                        */
}


