
/**************************************************************************//**
 * @file     pac5xxx_Memory.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX Memory Controller
 * @version  V0.2
 * @date     17 May 2012
 *
 * @note
 * Copyright (C) 2012 Active Semiconductor. All rights reserved.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/
 
/*------------- Memory Controller (MEMCTL) -----------------------------------*/
/** @addtogroup PAC5XXX_MEMCTL PAC5XXX FLASH Memory Controller (MEMCTL)
  @{
*/

#define FLASH_LOCK_ALLOW_FLASHWRITE_KEY   0xAAAAAAAA          /*!< Allow write to any FLASH pages not protected by RW bits                  */
#define FLASH_LOCK_ALLOW_PERASE_KEY       0xA5A55A5A          /*!< Allow write to FLASHPERASE register to erase FLASH pages                 */
#define FLASH_LOCK_ALLOW_MPERASE_KEY      0xFACE1956          /*!< Allow write to FLASHMPERASE register to mass erase FLASH pages           */
#define FLASH_LOCK_ALLOW_FLASHDBG_KEY     0x06BD1556          /*!< Allow write to FLASHDBG register to allow SWR access at device reset     */
#define FLASH_LOCK_ALLOW_FLASHWSTATE_KEY  0x12345678          /*!< Allow write to FLASHWSTATE register to configure FLASH wait states       */
#define FLASH_LOCK_ALLOW_BWRITE_KEY  	  0xCA726B18		  /*!< Allow buffered write                                                     */

#define FLASH_CTL_READ_ACTIVE_BIT         0x00000010          /*!< FLASHCTL read active bit                                                 */
#define FLASH_CTL_WRITE_ACTIVE_BIT        0x00000020          /*!< FLASHCTL write active bit                                                */
#define FLASH_CTL_PERASE_ACTIVE_BIT       0x00000040          /*!< FLASHCTL page erase active bit                                           */
#define FLASH_CTL_MPERASE_ACTIVE_BIT      0x00000100          /*!< FLASHCTL mass page erase active bit                                      */

#define FLASH_DBG_SWR_POR_EN              0xFFFF              /*!< SWR signals enabled at POR                                               */
#define FLASH_DBG_SWR_POR_DIS             0x6969              /*!< SWR signals disabled at POR                                              */

typedef enum {
  FLASH_WSTATE_HCLK_LTE_25MHZ = 0,                            /*!< FLASHWSTATE value for HCLK <= 25MHz                                      */
  FLASH_WSTATE_25MHZ_LT_HCLK_LTE_50MHZ = 1,                   /*!< FLASHWSTATE value for 25MHz < HCLK <= 50MHz                              */
  FLASH_WSTATE_50MHZ_LT_HCLK_LTE_75MHZ = 2,                   /*!< FLASHWSTATE value for 50MHz < HCLK <= 75MHz                              */
  FLASH_WSTATE_75MHZ_LT_HCLK_LTE_100MHZ = 3,                  /*!< FLASHWSTATE value for 75MHz < HCLK <= 100MHz                             */
} MEMCTL_WaitState;

typedef struct
{
  /*!< FLASHLOCK: Offset: 0x0000   FLASH Lock Register                                           */
  __IO uint32_t FLASHLOCK;                   /*!< Lock value to allow FLASH modifications        */
  
  /*!< FLASHCTL: Offset: 0x0004   FLASH Control Register                                         */
  union {
     __IO uint32_t w;
    struct {
      __IO uint32_t s              : 16;
           uint32_t                : 16;
    };
    struct {
	  __IO uint32_t b              : 8;
           uint32_t                : 24;
    };
    struct {
      __I  uint32_t WRITE          : 1;   	    /*!< Buffered write active                          */
      __I  uint32_t PERASE         : 1;         /*!< Page erase active                              */
           uint32_t                : 30;
    };
  } FLASHCTL;
  
  /*!< FLASHPAGE: Offset: 0x0008   FLASH PAGE Register                                         */
  union {
     __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
      __IO uint32_t b               : 8;
           uint32_t                 : 24;
    };
    struct {
      __IO uint32_t PAGE            : 5;       /*!< FLASH page to select for erase                */
           uint32_t                 : 27;
  	};
  } FLASHPAGE;
  
  __I uint32_t RESERVED1[2];
  
  /*!< FLASHPERASE: Offset: 0x0014 FLASH page erase */
  __IO uint32_t FLASHPERASE;                 /*!< FLASH segment erase (1)                          */
  
  __I uint32_t RESERVED3[3];
  
  /*!< SWDACCESS:     Offset: 0x0024 FLASH lock debug register */
  struct {
    __IO uint32_t VAL              : 16;      /*!< FLASH debug access value                     */
         uint32_t                  : 16;
  } SWDACCESS;
  
  /*!< FLASHWSTATE:  Offset: 0x0028 FLASH Wait state register */
  struct {
    __IO uint32_t VAL              : 2;       /*!< FLASH wait state value                       */
         uint32_t                  : 30;
  } FLASHWSTATE;

  /*!< FLASHBWRITE:  Offset: 0x002C Buffered FLASH write                                        */
  __IO uint32_t FLASHBWRITE;

  /*!< FLASHBWDATA: Offset: 0x0030  Buffered FLASH write data									*/
  struct {
	  __IO uint32_t DATA            : 16;		/*!< Data to write 								*/
	  __IO uint32_t ADDRESS			: 9;		/*!< Relative half-word address within page 	*/
	  __IO uint32_t PAGE			: 5;		/*!< page that contains data to write			*/
	       uint32_t                 : 2;
  } FLASHBWRITEDATA;
 
} PAC5XXX_MEMCTL_TypeDef;

/*@}*/ /* end of group PAC5XXX_MEMCTL */


