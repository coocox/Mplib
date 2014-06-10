/** 
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of UART_Retarget demo for the TOSHIBA
 *          'TMPM341' Device Series 
 * @version V0.100
 * @date    2011/01/25
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
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

void UART_Retarget(void);


/**
  * @brief  main  function
  * @param  None
  * @retval None
  */

/*int main(void)*/
void UART_Retarget(void)
{
    uint8_t TSW_info;
    uint8_t wait_TSW1 = 1U;


    /* Initialize system */
    TSW_Configuration();        /*Toggle Switch Configration */    
    SIO_Configuration(UART0);
    SIO_ChInit();

    /* enable SIO0 trx int */
    NVIC_EnableIRQ(INTTX0_IRQn);

    printf("OK, TMPM341 UART is initial ok!\n\r");
    printf("Please Press User key SW1 on TPMP341-SK board\n\r");

    while (1) {
        while (wait_TSW1) {
            /* read Toggle Switch input */
            TSW_info = GPIO_ReadData(TSW_PORT) & TSWBITS;

            if (TSW_info == TSW1) {
                /* wait for TSW1 released */
                do {
                    wait_TSW1 = 0U;
                    TSW_info = GPIO_ReadData(TSW_PORT) & TSWBITS;
                } while (TSW_info != TSWRELEASE);
            }
        }

        printf("The Key has been press!\n\r");

        while (fSIOTxOK == NO) {        /* wait for UART0 finish snd */
            /* do nothing */
        }
        fSIOTxOK = NO;
        wait_TSW1 = 1U;
    }
}


/**
  * @brief  Key Configuration.
  * @param  None
  * @retval None
  */
void TSW_Configuration(void)
{
#ifdef M341_SK_BOARD
    GPIO_SetPullUp(TSW_PORT, GPIO_BIT_3, ENABLE);
    GPIO_SetInputEnableReg(TSW_PORT, GPIO_BIT_3, ENABLE);
#else  
    GPIO_SetPullUp(TSW_PORT, GPIO_BIT_0, ENABLE);
    GPIO_SetInputEnableReg(TSW_PORT, GPIO_BIT_0, ENABLE);
#endif    
}

/**
  * @brief  Deal with the error parameter
  * @param  file: Pointer to the file where the error parameter locates
  * @param  line: Number of the line in which the error parameter locates
  * @retval None
  */
#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
