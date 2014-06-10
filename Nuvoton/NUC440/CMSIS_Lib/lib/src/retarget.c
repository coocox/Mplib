/**************************************************************************//**
 * @file     retarget.c
 * @version  V1.00
 * $Revision: 5 $
 * $Date: 13/11/10 9:32a $
 * @brief    NUC400 Series Debug Port and Semihost Setting Source File
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include<stdio.h>

#include "NUC400Series.h"

#if defined ( __CC_ARM   )
#if (__ARMCC_VERSION < 400000)
#else
/* Insist on keeping widthprec, to avoid X propagation by benign code in C-lib    */
#pragma import _printf_widthprec
#endif
#endif

/* Un-comment this line to disable all printf and getchar. getchar() will always return 0x00*/
//#define DISABLE_UART

/*---------------------------------------------------------------------------------------------------------   */
/* Global variables                                                                                           */
/*---------------------------------------------------------------------------------------------------------   */
#if !(defined(__ICCARM__) && (__VER__ >= 6010000))
struct __FILE {
    int handle; /* Add whatever you need here */
};
#endif
FILE __stdout;
FILE __stdin;

#if defined(DEBUG_ENABLE_SEMIHOST)
/* The static buffer is used to speed up the semihost    */
static char g_buf[16];
static char g_buf_len = 0;

/* The function to process semihosted command    */
extern int SH_DoCommand(int n32In_R0, int n32In_R1, int *pn32Out_R0);
#endif

#define DEBUG_PORT   UART0

/**
  * @brief  Write a char to UART.
  * @param  ch The character sent to UART.
  * @return None
  */
void SendChar_ToUART(int ch)
{
#ifndef DISABLE_UART
    while((DEBUG_PORT->FSR & UART_FSR_TX_FULL_Msk)); //waits for TX_FULL bit is clear
    DEBUG_PORT->THR = ch;
    if(ch == '\n') {
        while((DEBUG_PORT->FSR & UART_FSR_TX_FULL_Msk)); //waits for TX_FULL bit is clear
        DEBUG_PORT->THR = '\r';
    }
#endif
}


/**
  * @brief  Write a char to debug console.
  * @param  ch The character sent to debug console
  * @return None
  */
void SendChar(int ch)
{
#if defined(DEBUG_ENABLE_SEMIHOST)
    g_buf[g_buf_len++] = ch;
    g_buf[g_buf_len] = '\0';
    if(g_buf_len + 1 >= sizeof(g_buf) || ch == '\n' || ch == '\0') {

        /* Send the char */
        if(SH_DoCommand(0x04, (int)g_buf, NULL) != 0) {
            g_buf_len = 0;
            return;
        } else {
            int i;

            for(i=0; i<g_buf_len; i++)
                SendChar_ToUART(g_buf[i]);
            g_buf_len = 0;
        }
    }
#else
    SendChar_ToUART(ch);
#endif
}



/**
  * @brief  Read a char from debug console.
  * @param  None
  * @return Received character from debug console
  * @note   This API waits until UART debug port or semihost input a character
  */
char GetChar(void)
{
#if defined(DEBUG_ENABLE_SEMIHOST)
# if defined ( __CC_ARM   )
    int nRet;
    while(SH_DoCommand(0x101, 0, &nRet) != 0) {
        if(nRet != 0) {
            SH_DoCommand(0x07, 0, &nRet);
            return (char)nRet;
        }
    }
# else
    int nRet;
    while(SH_DoCommand(0x7, 0, &nRet) != 0) {
        if(nRet != 0)
            return (char)nRet;
    }
# endif
#endif

#ifndef DISABLE_UART
    while (1) {
        if((DEBUG_PORT->FSR & UART_FSR_RX_EMPTY_Msk) == 0 ) {
            return (DEBUG_PORT->RBR);

        }
    }
#else
    return(0);
#endif
}


/**
  * @brief  Check whether UART receive FIFO is empty or not.
  * @param  None
  * @return UART Rx FIFO empty status
  * @retval 1 Indicates at least one character is available in UART Rx FIFO
  * @retval 0 UART Rx FIFO is empty
  */
int kbhit(void)
{
#ifndef DISABLE_UART
    return !(DEBUG_PORT->FSR & UART_FSR_RX_EMPTY_Msk);
#else
    return(0);
#endif
}

/**
  * @brief  Check whether UART transmit FIFO is empty or not.
  * @param  None
  * @return UART Tx FIFO empty status
  * @retval 1 UART Tx FIFO is empty
  * @retval 0 UART Tx FIFO is not empty
  */
int IsDebugFifoEmpty(void)
{
#ifndef DISABLE_UART
    return (DEBUG_PORT->FSR & UART_FSR_TE_FLAG_Msk);
#else
    return(1);
#endif
}

/**
  * @brief    C library retargetting
  * @param    ch Character to send out
  * @return  None
  * @details  Check if message finished (FIFO empty of debug port)
  */

void _ttywrch(int ch)
{
    SendChar(ch);
    return;
}

/**
  * @brief      Write character to stream
  * @param[in]  ch       Character to be written. The character is passed as its int promotion.
  * @param[in]  stream   Pointer to a FILE object that identifies the stream where the character is to be written.
  * @return    If there are no errors, the same character that has been written is returned.
  *             If an error occurs, EOF is returned and the error indicator is set (see ferror).
  * @details    Writes a character to the stream and advances the position indicator.\n
  *             The character is written at the current position of the stream as indicated \n
  *             by the internal position indicator, which is then advanced one character.
  * @note       The above descriptions are copied from http://www.cplusplus.com/reference/clibrary/cstdio/fputc/.
  *
  */
// we can use printf.c file of C library, the function of fputc is repeated define,
// so we remark it. Operator: zhou xiong
//int fputc(int ch, FILE *stream)
//{
//    SendChar(ch);
//    return ch;
//}


/**
  * @brief      Get character from UART debug port or semihosting input
  * @param[in]  stream   Pointer to a FILE object that identifies the stream on which the operation is to be performed.
  * @return    The character read from UART debug port or semihosting
  * @details    For get message from debug port or semihosting.
  *
  */
int fgetc(FILE *stream)
{
    return (GetChar());
}
// This function can not pass compile. There is not any effect, after deleting the function
// Operator:zhou xiong
//int ferror(FILE *pfile)
//{
//    return EOF;
//}


#ifdef DEBUG_ENABLE_SEMIHOST
# ifdef __ICCARM__
void __exit(int return_code)
{

    /* Check if link with ICE    */
    if(SH_DoCommand(0x18, 0x20026, NULL) == 0) {
        /* Make sure all message is print out    */
        while(IsDebugFifoEmpty() == 0);
    }
label:
    goto label;  /* endless loop    */
}
# else
void _sys_exit(int return_code)
{

    /* Check if link with ICE    */
    if(SH_DoCommand(0x18, 0x20026, NULL) == 0) {
        /* Make sure all message is print out    */
        while(IsDebugFifoEmpty() == 0);
    }
label:
    goto label;  /* endless loop    */
}
# endif
#endif

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
