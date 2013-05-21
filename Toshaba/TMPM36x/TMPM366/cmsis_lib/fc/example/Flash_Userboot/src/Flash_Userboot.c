/**
 *******************************************************************************
 * @file    Flash_Userboot.c
 * @brief   main function of Flash demo(user boot mode) for TMPM366FDFG
 * @version V0.100
 * @date    2011/03/08
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

#include "tmpm366_cg.h"
#include "tmpm366_fc.h"
#include "tmpm366_gpio.h"

/* Private define ------------------------------------------------------------*/
#define USER_BOOT_MODE          ((uint8_t)0x01)
#define NORMAL_MODE             ((uint8_t)0x00)

#if defined ( __CC_ARM   )      /* RealView Compiler */
#define CODE_START              ((void (*)(void))0x81df)
#define FLASH_API_ROM           ((uint32_t *)__Get_FLASHSWAP_Store_Base())
#elif defined ( __ICCARM__ )    /* IAR Compiler */
#define CODE_START              ((void (*)(void))0x88dbU)       /* code start address */
#define FLASH_API_ROM           ((uint32_t *)0x200)
#endif

#define DEMO_A_FLASH            ((uint32_t *)0x00008000)
#define DEMO_B_FLASH            ((uint32_t *)0x00010000)

#define RAM_BUFFER_START        ((uint32_t)0x20000800)
#define FLASH_API_RAM           ((uint32_t *)(RAM_BUFFER_START))
#define DEMO_A_RAM              ((uint32_t *)(RAM_BUFFER_START + 0x1000U))
#define DEMO_B_RAM              ((uint32_t *)(RAM_BUFFER_START + 0x2000U))

#define SIZE_FLASH_API          (0x800U)
#define SIZE_DEMO_A             (3500U)
#define SIZE_DEMO_B             (3500U)

#define PAGE_SIZE               (512U)

#define LED1 (1U<<0U)
#define LED2 (1U<<1U)
#define LED3 (1U<<2U)
#define LED4 (1U<<3U)
#define LED5 (1U<<4U)
#define LED6 (1U<<5U)
#define LED7 (1U<<6U)
#define LED8 (1U<<7U)

#define LED_DATA_PORT   GPIO_PA


void (*startup) (void);
void Copy_Routine(uint32_t * dest, uint32_t * source, uint32_t size);
uint8_t Flash_Swap(void);
uint8_t Mode_Judgement(void);
uint8_t Write_Flash(uint32_t * addr_dest, uint32_t * addr_source, uint32_t len);
void delay(uint32_t time);
void Status_Display(uint8_t nChar);
void LEDInit(void);


void LedOff(uint8_t led);
void LedOn(uint8_t led);

void delay(uint32_t time);

#if defined ( __CC_ARM   )      /* RealView Compiler */
/**
  * @brief  Get store base of "FLASHSWAP" section
  * @param  None.
  * @retval The base.
  */
__ASM unsigned int __Get_FLASHSWAP_Store_Base(void)
{ 
    IMPORT ||Load$$FLASHSWAP_RAM$$Base|| 
    LDR R0, =||Load$$FLASHSWAP_RAM$$Base|| 
    BX LR
}

/**
  * @brief  Get run base of "FLASHSWAP" section
  * @param  None.
  * @retval The base.
  */
__ASM unsigned int __Get_FLASHSWAP_Run_Base(void)
{
    IMPORT ||Image$$FLASHSWAP_RAM$$RO$$Base|| 
    LDR R0, =||Image$$FLASHSWAP_RAM$$RO$$Base|| 
    BX LR
}

/**
  * @brief  Get run limit of "FLASHSWAP" section
  * @param  None.
  * @retval The limit.
  */
__ASM unsigned int __Get_FLASHSWAP_Run_Limit(void)
{
    IMPORT ||Image$$FLASHSWAP_RAM$$RO$$Limit||
    LDR R0, =||Image$$FLASHSWAP_RAM$$RO$$Limit|| 
    BX LR
}

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
#endif


void Flash_Userboot(void)
{
    CG_SetFcSrc(CG_FC_SRC_FOSC);        /* Select fosc */
    CG_SetPLL(DISABLE);         /* Disable PLL */
    GPIO_SetInput(GPIO_PD, GPIO_BIT_0); /* set port D to input */

    LEDInit();                  /* LED initialization */

    if (Mode_Judgement() == USER_BOOT_MODE) {   /* if switch is low, enter user boot mode */

        Status_Display(0x08U);   /* status 1: enter user boot mode */
        Copy_Routine(FLASH_API_RAM, FLASH_API_ROM, SIZE_FLASH_API);     /* copy flash API to RAM */
        Status_Display(0x04U);   /* status 2: RAM transfering */

        if (FC_SUCCESS == Flash_Swap()) {       /* swap the flash content */
            /* Do nothing */
        } else {
            Status_Display(0x00U);       /* if have any error, display E */
        }

    } else {                    /* if switch is high, enter normal mode */

#if defined ( __CC_ARM   )      /* RealView Compiler */
        ResetSP();              /* reset SP */
#elif defined ( __ICCARM__ )    /* IAR Compiler */
        asm("MOV R0, #0");      /* reset SP */
        asm("LDR SP, [r0]");
#endif

        startup = CODE_START;
        startup();              /* jump to code start address to run */
    }

}

/**
  * @brief  judge current mode is USER_BOOT_MODE or NORMAL_MODE
  * @param  None.
  * @retval None.
  */
uint8_t Mode_Judgement(void)
{
    return (GPIO_ReadDataBit(GPIO_PD, GPIO_BIT_0) ==
            GPIO_BIT_VALUE_0) ? USER_BOOT_MODE : NORMAL_MODE;
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
    uint32_t reg_value = 0U;
    FC_Result tmp = FC_ERROR_PROTECTED;

    Copy_Routine(DEMO_A_RAM, DEMO_A_FLASH, SIZE_DEMO_A);        /* copy A to RAM */
    Copy_Routine(DEMO_B_RAM, DEMO_B_FLASH, SIZE_DEMO_B);        /* copy B to RAM */

    Status_Display(0x02U);       /* status 2: swap the demo */

    tmp = FC_EraseBlock((uint32_t) DEMO_A_FLASH);

    if (FC_SUCCESS == tmp) {    /* erase A */
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

    Status_Display(0x0CU);       /* status 3: complete and restart */

    while (GPIO_ReadDataBit(GPIO_PD, GPIO_BIT_0) == GPIO_BIT_VALUE_0) { /* wait for switch change to high */
    }

    reg_value = SCB->AIRCR;     /* software reset */
    reg_value = (uint32_t) 0x05FA0001;
    SCB->AIRCR = reg_value;

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
    while (size > PAGE_SIZE) {
        if (FC_SUCCESS == FC_WritePage((uint32_t) dest, source)) {      /* write one page every time */
            /* Do nothing */
        } else {
            return ERROR;
        }
        size = size - PAGE_SIZE;
        dest = dest + PAGE_SIZE / 4U;
        source = source + PAGE_SIZE / 4U;
    }
    if (FC_SUCCESS == FC_WritePage((uint32_t) dest, source)) {  /* write the last data, no more than one page */
        /* Do nothing */
    } else {
        return ERROR;
    }
    return SUCCESS;
}

/**
  * @brief  display the status on LED
  * @param  character to display
  * @retval None
  */
void Status_Display(uint8_t nChar)
{
    LedOff(0xFFU);  /* status 3: complete and restart */
    LedOn(nChar);
    delay(0xFFFFFU);
}

void delay(uint32_t time)
{
    volatile uint32_t i;
    for (i = 0U; i < time; i++) {
        /* Do nothing */
    }
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
void LEDInit(void)
{
    GPIO_SetOutput(LED_DATA_PORT,0xFFU);    
    GPIO_WriteData(LED_DATA_PORT,0xFFU); 
    
}
/*************************************************************************
 * Function Name: LedOff
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LedOff(uint8_t led)
{
    uint8_t reg;
    reg = GPIO_ReadData(LED_DATA_PORT);
    reg &= (uint8_t)(~led);
    GPIO_WriteData(LED_DATA_PORT,reg);
}

/*************************************************************************
 * Function Name: LedOn
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LedOn(uint8_t led)
{
    GPIO_WriteData(LED_DATA_PORT,led);
}

/*************************** END OF FILE **************************************/
