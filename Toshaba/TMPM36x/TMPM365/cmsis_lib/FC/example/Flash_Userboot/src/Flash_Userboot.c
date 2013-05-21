/**
 *******************************************************************************
 * @file    Flash_Userboot.c
 * @brief   Flash_Userboot function of Flash demo(user boot mode)
 * @version V0.100
 * @date    2012/07/31
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
#include "tmpm365_fc.h"
#include "tmpm365_gpio.h"

#define LED0 (1U<<0U)
#define LED1 (1U<<1U)
#define LED2 (1U<<2U)
#define LED3 (1U<<3U)

#define LED_ALL  (LED0|LED1|LED2|LED3)
#define LED_DATA_PORT   GPIO_PA
#define LED_ON  1U
#define LED_OFF  0U

#define USER_BOOT_MODE          ((uint8_t)0x01)
#define NORMAL_MODE             ((uint8_t)0x00)

#if defined ( __CC_ARM   )      /* RealView Compiler */
#define FLASH_API_ROM           (uint32_t *)&Load$$FLASH_CODE_RAM$$Base

#define FLASH_API_RAM           (uint32_t *)&Image$$FLASH_CODE_RAM$$Base
#define SIZE_FLASH_API          (uint32_t)&Load$$FLASH_CODE_RAM$$Length

#define DEMO_A_FLASH            (uint32_t *)&Image$$FLASH_DEMO_A$$Base
#define DEMO_B_FLASH            (uint32_t *)&Image$$FLASH_DEMO_B$$Base

#define DEMO_A_RAM              (uint32_t *)&Image$$RAM_DEMO_A$$Base
#define DEMO_B_RAM              (uint32_t *)&Image$$RAM_DEMO_B$$Base

#define SIZE_DEMO_A           	(uint32_t)&Image$$FLASH_DEMO_A$$ZI$$Length
#define SIZE_DEMO_B           	(uint32_t)&Image$$FLASH_DEMO_B$$ZI$$Length

#elif defined ( __ICCARM__ )    /* IAR Compiler */
#define FLASH_API_ROM           ((uint32_t *)__section_begin("FLASH_CODE_ROM"))

#define FLASH_API_RAM           ((uint32_t *)__section_begin("FLASH_CODE_RAM"))
#define SIZE_FLASH_API          ((uint32_t)__section_size("FLASH_CODE_ROM"))

#define DEMO_A_FLASH            ((uint32_t *)__section_begin("FLASH_DEMO_A"))
#define DEMO_B_FLASH            ((uint32_t *)__section_begin("FLASH_DEMO_B"))

#define DEMO_A_RAM              ((uint32_t *)__section_begin("RAM_DEMO_A"))
#define DEMO_B_RAM              ((uint32_t *)__section_begin("RAM_DEMO_B"))

#define SIZE_DEMO_A             ((uint32_t)__section_size("FLASH_DEMO_A"))
#define SIZE_DEMO_B             ((uint32_t)__section_size("FLASH_DEMO_B"))
#endif
#define DEMO_START_ADDR         ((uint32_t)DEMO_A_FLASH)
#define CODE_START              ((void (*)(void))(*(uint32_t *)(DEMO_START_ADDR + 4U)))

#define SW0         (1U<<4U)
#define SW1         (1U<<5U)
#define SW_ALL      (SW0|SW1)
#define TSB_SW          TSB_PB


void (*startup) (void);
uint8_t Flash_Swap(void);
uint8_t Write_Flash(uint32_t * addr_dest, uint32_t * addr_source, uint32_t len);

void Copy_Routine(uint32_t * dest, uint32_t * source, uint32_t size);
uint8_t Flash_Swap(void);
uint8_t Mode_Judgement(void);
uint8_t Write_Flash(uint32_t * addr_dest, uint32_t * addr_source, uint32_t len);
void delay(uint32_t time);

void SW_Init(void);
uint8_t SW_Get(uint8_t SW);

void LED_Init(void);
void LED_Off(uint8_t led);
void LED_On(uint8_t led);


#if defined ( __CC_ARM )        /* RealView Compiler */
extern uint32_t Load$$FLASH_CODE_RAM$$Base;
extern uint32_t Image$$FLASH_CODE_RAM$$Base;
extern uint32_t Load$$FLASH_CODE_RAM$$Length;
extern uint32_t Image$$FLASH_DEMO_A$$Base;
extern uint32_t Image$$FLASH_DEMO_B$$Base;
extern uint32_t Image$$RAM_DEMO_A$$Base;
extern uint32_t Image$$RAM_DEMO_B$$Base;
extern uint32_t Image$$FLASH_DEMO_A$$ZI$$Length;
extern uint32_t Image$$FLASH_DEMO_B$$ZI$$Length;

/**
  * @brief  Reset SP
  * @param  None.
  * @retval None.
  */
__ASM void ResetSP(void)
{
    MOV R0,#0
    LDR SP,[R0]
}
#elif defined ( __ICCARM__ )    /* IAR Compiler */
#pragma section = "FLASH_CODE_RAM"
#pragma section = "FLASH_CODE_ROM"
#pragma section = "FLASH_DEMO_A"
#pragma section = "FLASH_DEMO_B"
#pragma section = "RAM_DEMO_A"
#pragma section = "RAM_DEMO_B"
#endif

/**
  * @brief  delay some time
  * @param  delay time
  * @retval None.
  */
void delay(uint32_t time)
{
    uint32_t i;
    for (i = 0U; i < time; i++) {
        /* Do nothing */
    }
}

/**
  * @brief  judge current mode is USER_BOOT_MODE or NORMAL_MODE
  * @param  None.
  * @retval None.
  */
uint8_t Mode_Judgement(void)
{
    return (SW_Get(SW0) == 1U) ? USER_BOOT_MODE : NORMAL_MODE;
}

/**
  * @brief  copy 32-bit data from source to dest
  * @param  the address of source and dast, the data size
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
  * @brief  swap two code in flash, and runs at RAM, then software reset
  * @param  None.
  * @retval ERROR or SUCCESS.
  */
#if defined ( __CC_ARM   )      /* RealView Compiler */
#pragma arm section code="FLASH_ROM"
#elif defined ( __ICCARM__ )    /* IAR Compiler */
#pragma location = "FLASH_ROM"
#endif
uint8_t Flash_Swap(void)
{
    Copy_Routine(DEMO_A_RAM, DEMO_A_FLASH, SIZE_DEMO_A);        /* copy A to RAM */
    Copy_Routine(DEMO_B_RAM, DEMO_B_FLASH, SIZE_DEMO_B);        /* copy B to RAM */

    if (FC_SUCCESS == FC_EraseBlock((uint32_t) DEMO_A_FLASH)) { /* erase A */
        /* Do nothing */
    } else {
        return ERROR;
    }

    if (FC_SUCCESS == Write_Flash(DEMO_A_FLASH, DEMO_B_RAM, SIZE_DEMO_B)) {     /* write B to A */
        /* Do nothing */
    } else {
        return ERROR;
    }

    if (FC_SUCCESS == FC_EraseBlock((uint32_t) DEMO_B_FLASH)) { /* erase B */
        /* Do nothing */
    } else {
        return ERROR;
    }

    if (FC_SUCCESS == Write_Flash(DEMO_B_FLASH, DEMO_A_RAM, SIZE_DEMO_A)) {     /* write A to B */
        /* Do nothing */
    } else {
        return ERROR;
    }

    delay(0x7FFFFF);

    LED_On(LED2);

    /* wait for Key SW0 to release */
    while (SW_Get(SW0) == 1U) {
    }


    NVIC_SystemReset();
    return SUCCESS;
}

/**
  * @brief  write flash
  * @param  destination address, source address, lenth of data.
  * @retval ERROR or SUCCESS.
  */
#if defined ( __CC_ARM   )      /* RealView Compiler */
#pragma arm section code="FLASH_ROM"
#elif defined ( __ICCARM__ )    /* IAR Compiler */
#pragma location = "FLASH_ROM"
#endif
uint8_t Write_Flash(uint32_t * addr_dest, uint32_t * addr_source, uint32_t len)
{
    uint32_t size;
    uint32_t *source;
    uint32_t *dest;

    dest = addr_dest;
    source = addr_source;
    size = len;
    while (size > FLASH_PAGE_SIZE) {
        if (FC_SUCCESS == FC_WritePage((uint32_t) dest, source)) {      /* write one page every time */
            /* Do nothing */
        } else {
            return ERROR;
        }
        size = size - FLASH_PAGE_SIZE;
        dest = dest + FLASH_PAGE_SIZE / 4U;
        source = source + FLASH_PAGE_SIZE / 4U;
    }
    if (FC_SUCCESS == FC_WritePage((uint32_t) dest, source)) {  /* write the last data, no more than one page */
        /* Do nothing */
    } else {
        return ERROR;
    }
    return SUCCESS;
}


/**
  * @brief  Flash_Userboot function to run flash userboot mode demo
  * @param  None.
  * @retval result to return to system.
  */

void Flash_Userboot(void)
{

    LED_Init();
    SW_Init();

    if (Mode_Judgement() == USER_BOOT_MODE) {   /* if SW0 is turned on, enter user boot mode */

        LED_On(LED2);           /* enter user boot mode */

        Copy_Routine(FLASH_API_RAM, FLASH_API_ROM, SIZE_FLASH_API);     /* copy flash API to RAM */

        if (FC_SUCCESS == Flash_Swap()) {       /* swap the flash content */
            /* Do nothing */
        } else {
            LED_On(LED0 | LED1 | LED3); /* if have any error, turn on all leds */

        }

    } else {                    /* if SW1 is turned off, enter normal mode */
#if defined ( __CC_ARM   )      /* RealView Compiler */
        ResetSP();              /* reset SP */
#elif defined ( __ICCARM__ )    /* IAR Compiler */

        asm("MOV R0, #0");      /* reset SP */
        asm("LDR SP, [r0]");
#endif
        SCB->VTOR = DEMO_START_ADDR;    /* redirect vector table */
        startup = CODE_START;
        startup();              /* jump to code start address to run */

    }



}


/*******************************************************************************
* Function Name  : SW_Init
* Description    : Initialize the GPIO to SW 
* Input          : None 
* Return         : None.
*******************************************************************************/
void SW_Init(void)
{
    uint8_t reg = TSB_SW->IE;
    reg |= SW_ALL;
    TSB_SW->IE = reg;
}

/*******************************************************************************
* Function Name  : SW_Get
* Description    : Get SW Value
* Input          : SW (choose from SW0 ~ SW7).
* Return         : SW value.
*******************************************************************************/
uint8_t SW_Get(uint8_t sw)
{
    uint8_t tmp = TSB_SW->DATA & sw;

    if (tmp > 0U)
        tmp = 1U;
    return tmp;
}

/*************************************************************************
 * Function Name: LED_Init
 * Parameters:None
 *
 * Return:None  
 *
 * Description: Init LED ports
 *
 *************************************************************************/
void LED_Init(void)
{
    uint8_t led_off;
    led_off = (uint8_t) (~LED_ALL);
    GPIO_SetOutput(LED_DATA_PORT, LED_ALL);
    GPIO_WriteData(LED_DATA_PORT, led_off);

}

/*************************************************************************
 * Function Name: LED_Off
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LED_Off(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(LED_DATA_PORT);
    tmp &= (uint8_t) (~led);
    GPIO_WriteData(LED_DATA_PORT, tmp);
}

/*************************************************************************
 * Function Name: LED_On
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LED_On(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(LED_DATA_PORT);
    tmp |= led;
    GPIO_WriteData(LED_DATA_PORT, tmp);
}


/*************************** END OF FILE **************************************/
