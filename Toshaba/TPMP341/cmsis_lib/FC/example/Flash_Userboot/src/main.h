/**
 *******************************************************************************
 * @file    main.h
 * @brief   header file for main.c, included some address definition and
 *          function prototypes
 * @version V0.100
 * @date    2011/02/25
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

#ifndef MAIN_H
#define MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "tmpm341_cg.h"
#include "tmpm341_fc.h"
#include "led.h"

/* Private define ------------------------------------------------------------*/
#define M341_SK_BOARD

#define USER_BOOT_MODE          ((uint8_t)0x01)
#define NORMAL_MODE             ((uint8_t)0x00)

#if defined ( __CC_ARM   )      /* RealView Compiler */
#define CODE_START              ((void (*)(void))0x8233)
#define FLASH_API_ROM           ((uint32_t *)__Get_FLASHSWAP_Store_Base())
#elif defined ( __ICCARM__ )    /* IAR Compiler */
#define CODE_START              ((void (*)(void))0x88fbU)       /* code start address */
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

/* Private function prototypes -----------------------------------------------*/
void Copy_Routine(uint32_t * dest, uint32_t * source, uint32_t size);
uint8_t Flash_Swap(void);
uint8_t Mode_Judgement(void);
uint8_t Write_Flash(uint32_t * addr_dest, uint32_t * addr_source, uint32_t len);
void delay(uint32_t time);
void Status_Display(uint8_t nChar);
#endif
/*************************** END OF FILE **************************************/
