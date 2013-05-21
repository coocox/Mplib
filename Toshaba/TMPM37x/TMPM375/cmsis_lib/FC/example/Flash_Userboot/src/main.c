/**
 *******************************************************************************
 * @file    main.c
 * @brief   main function of Flash demo
 * @version V0.100
 * @date    2013/03/22
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */
#include "main.h"
#if defined ( __CC_ARM   )      /* RealView Compiler */
extern uint32_t Load$$FLASH_CODE_RAM$$Base;
extern uint32_t Image$$FLASH_CODE_RAM$$Base;
extern uint32_t Load$$FLASH_CODE_RAM$$Length;

#elif defined ( __ICCARM__ )    /* IAR Compiler */
#pragma section = "FLASH_CODE_RAM"
#pragma section = "FLASH_CODE_ROM"
#endif

/**
  * @brief  delay function
  * @param  delay time.
  * @retval None.
  */
void delay(uint32_t DelayTime)
{
    uint32_t time;
    for (time = 0U; time < DelayTime; time++) {
    }
}

/**
  * @brief  main function of flash demo
  * @param  None.
  * @retval result to return to system.
  */
int main(void)
{
    #define ERROR_DELAY     1000000U
    #define SUCCESS_DELAY   4000000U
    Result tmp = ERROR;
    uint8_t Flag_1st = 0U;
    
    LED_Init();
    SW_Init();
    while (1U) {
        if(Flag_1st == 0U && SW_Get(SW0)) {   /* if SW0 is turned on 1st time*/ 
            Flag_1st = 1U;
            Copy_Routine(FLASH_API_RAM, FLASH_API_ROM, SIZE_FLASH_API);
            tmp = Flash_Write();
        } else {
        	 /* Do nothing */
        }
        if(tmp== SUCCESS)
        {
            LED_On(LED1);
            delay(SUCCESS_DELAY);
            LED_Off(LED1);
            delay(SUCCESS_DELAY);
        } else {
            LED_On(LED1);
            delay(ERROR_DELAY);
            LED_Off(LED1);
            delay(ERROR_DELAY);
        }
    }
}
/**
  * @brief  copy 32-bit data from source to dest
  * @param  the address of source and dest, the data size
  * @retval None.
  */
void Copy_Routine(uint32_t * dest, uint32_t * source, uint32_t size)
{
    uint32_t *dest_addr, *source_addr, tmpsize;
    uint32_t i, tmps, tmpd, mask;
     
    dest_addr = dest;
    source_addr = source;
    tmpsize = size >> 2U;

    for (i = 0U; i < tmpsize; i++) {    /* 32bits copy */
        *dest_addr = *source_addr;
        dest_addr++;
        source_addr++;
    }
    if (size & 0x00000003U) {   /* if the last data size is not 0(maybe 1,2 or 3), copy the last data */
        mask = 0xFFFFFF00U;
        i = size & 0x00000003U;
        tmps = *source_addr;
        tmpd = *dest_addr;
        while (i - 1U) {
            mask = mask << 8U;
            i--;
        }
        tmps = tmps & (~mask);
        tmpd = tmpd & (mask);
        *dest_addr = tmps + tmpd;       /* 32bits copy, but only change the bytes need to be changed */
    } else {
        /* Do nothing */
    }
}

/**
  * @brief  Erase the specified block£¬then write data and read, check the read data
  * @param  None.
  * @retval ERROR or SUCCESS.
  */
#if defined ( __CC_ARM   )      /* RealView Compiler */
#pragma arm section code="FLASH_ROM"
#elif defined ( __ICCARM__ )    /* IAR Compiler */
#pragma location = "FLASH_ROM"
#endif
Result Flash_Write(void)
{
    int i = 0U;
    uint32_t pagedata[FC_PAGE_SIZE];    
    Result tmp = ERROR; 
    uint32_t buffer[FC_PAGE_SIZE] = {0U};    
    if (FC_SUCCESS == FC_EraseBlock(FC_WRITE_ADDR)) {               /* erase this block which will be written */
        for (i = 0U; i < FC_PAGE_SIZE; i++) {
            pagedata[i] = 0x12345678U;
        }
        if (FC_WritePage(FC_WRITE_ADDR, pagedata) == FC_SUCCESS)      /* write data to block which was erased */
        {
            Copy_Routine(buffer, (uint32_t*)FC_WRITE_ADDR, FLASH_PAGE_SIZE);
            tmp = SUCCESS;
            LED_On(LED2); 
            for (i = 0U; i < FC_PAGE_SIZE; i++) {
                if(buffer[i] != pagedata[i]) {
                    tmp = ERROR;
                    LED_Off(LED2); 
                    break;
                }else {
                  /* Do nothing */
                }  
            }
        }else {
            /* Do nothing */
        }
    } else {
      /* Do nothing */
    }
    return tmp;
}



#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1U) {
        __NOP();
    }
}
#endif

/*************************** END OF FILE **************************************/
