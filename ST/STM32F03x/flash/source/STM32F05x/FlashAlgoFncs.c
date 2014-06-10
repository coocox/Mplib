
/**
 *******************************************************************************
 * @file       FlashAlgoFncs.c
 * @version    V0.1
 * @date       2012.09.05
 * @brief      Flash  Algorithm For STM32F05x
 *******************************************************************************
 * @copy
 *
 * INTERNAL FILE,DON'T PUBLIC.
 * 
 * <h2><center>&copy; COPYRIGHT 2009 CooCox </center></h2>
 *******************************************************************************
 */ 
 
#include <FlashAlgorithm.h>

typedef volatile unsigned char  vu8;
typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;

#define M8(adr)  (*((vu8  *) (adr)))
#define M16(adr) (*((vu16 *) (adr)))
#define M32(adr) (*((vu32 *) (adr)))

// Peripheral Memory Map
#define IWDG_BASE       0x40003000
#define FLASH_BASE      0x40022000

#define IWDG            ((IWDG_TypeDef *) IWDG_BASE)
#define FLASH           ((FLASH_TypeDef*) FLASH_BASE)

// Independent WATCHDOG
typedef struct {
  vu32 KR;
  vu32 PR;
  vu32 RLR;
  vu32 SR;
  vu32 WINR;
} IWDG_TypeDef;

// Flash Registers
typedef struct {
  vu32 ACR;
  vu32 KEYR;
  vu32 OPTKEYR;
  vu32 SR;
  vu32 CR;
  vu32 AR;
  vu32 RESERVED;
  vu32 OBR;
  vu32 WRPR;
} FLASH_TypeDef;


// Flash Keys
#define FLASH_KEY1      0x45670123
#define FLASH_KEY2      0xCDEF89AB

// Flash Control Register definitions
#define FLASH_PG        0x00000001
#define FLASH_PER       0x00000002
#define FLASH_MER       0x00000004
#define FLASH_OPTPG     0x00000010
#define FLASH_OPTER     0x00000020
#define FLASH_STRT      0x00000040
#define FLASH_LOCK      0x00000080
#define FLASH_OPTWRE    0x00000200

// Flash Status Register definitions
#define FLASH_BSY       0x00000001
#define FLASH_PGERR     0x00000004
#define FLASH_WRPRTERR  0x00000010
#define FLASH_EOP       0x00000020

// Flash Option byte register definitions
#define FLASH_WDG_SW    0x00000100

/**
 *******************************************************************************
 * @brief      Initialize before Flash Programming/Erase Functions 
 * @param[in]  baseAddr     Flash device base address.
 * @param[in]  clk     			Flash program clock.
 * @param[in]  operateFuc   Init for what operation
 														(FLASH_OPT_ERASECHIP/FLASH_OPT_ERASESECTORS/FLASH_OPT_PROGRAMPAGE).
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details    This function is called before flash programming/erase. 
 * @note 
 *******************************************************************************
 */
int FlashInit (unsigned long baseAddr,
               unsigned long clk,
               unsigned long operateFuc)
{
  //*((volatile unsigned int *)0x40021004) = 0x00000000;
  //*((volatile unsigned int *)0x40021000) = 0x00010081;
  //*((volatile unsigned int *)0x40021008) = 0x00000000;

  // Unlock Flash 
  if((FLASH->CR & FLASH_LOCK) != 0)
  {    
    FLASH->KEYR = FLASH_KEY1;
    FLASH->KEYR = FLASH_KEY2;
  }
  
  // Zero Wait State
  FLASH->ACR  =  0x00000000;
  
  FLASH->CR   =  0x00000000;
  FLASH->SR   =  FLASH_EOP|FLASH_WRPRTERR|FLASH_PGERR;

  // Test if IWDG is running (IWDG in HW mode)
  if ((FLASH->OBR & FLASH_WDG_SW) == 0x00) {
    // Set IWDG time out to ~32.768 second
    IWDG->KR  = 0x5555; // Enable write access to IWDG_PR and IWDG_RLR     
    IWDG->PR  = 0x06;   // Set prescaler to 256  
    IWDG->RLR = 4095;   // Set reload value to 4095
  }  
                      
  return 0;
}


/**
 *******************************************************************************
 * @brief      Un-Init after Flash Programming/Erase Functions  
 * @param[in]  operateFuc   Init for what operation
 														(FLASH_OPT_ERASECHIP/FLASH_OPT_ERASESECTORS/FLASH_OPT_PROGRAMPAGE).
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details    This function is called after flash programming/erase. 
 * @note 
 *******************************************************************************
 */
int FlashUnInit (unsigned long operateFuc)
{
  // Lock Flash
  FLASH->CR |=  FLASH_LOCK;

  return 0;
}


/**
 *******************************************************************************
 * @brief      Erase the full chip.  
 * @param[in]  None.
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details     
 * @note 
 *******************************************************************************
 */
int FlashEraseChip   (void)
{
  FLASH->SR |= FLASH_PGERR;                     // Reset Error Flags
  
  FLASH->CR  =  FLASH_MER;                      // Mass Erase Enabled
  FLASH->CR |=  FLASH_STRT;                     // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                          // Reload IWDG
  }

  FLASH->CR &= ~FLASH_MER;                      // Mass Erase Disabled

  if (FLASH->SR & FLASH_PGERR)                  // Check for Error
  {                        
    FLASH->SR |= FLASH_PGERR;                   // Reset Error Flags
    return (1);                                // Failed
  }

  return 0;
}

/**
 *******************************************************************************
 * @brief      Erase the select Sector. 
 * @param[in]  sectorAddr   Sector's start address.
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details     
 * @note 
 *******************************************************************************
 */
int FlashEraseSector (unsigned long sectorAddr)
{
  FLASH->SR |= FLASH_PGERR;                     // Reset Error Flags

  FLASH->CR  =  FLASH_PER;                      // Page Erase Enabled 
  FLASH->AR  =  sectorAddr;                     // Page Address
  FLASH->CR |=  FLASH_STRT;                     // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                          // Reload IWDG
  }

  FLASH->CR &= ~FLASH_PER;                              // Page Erase Disabled 

  if (FLASH->SR & FLASH_PGERR)                          // Check for Error
  {                        
    FLASH->SR |= FLASH_PGERR;                           // Reset Error Flags
    return (1);                                         // Failed
  }

  return 0;
}


/**
 *******************************************************************************
 * @brief      Proram a page. 
 * @param[in]  pageAddr   Page's start address.
 * @param[in]  size			  Page size
 * @param[in]  buf   			source point.
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details     
 * @note 
 *******************************************************************************
 */ 
int FlashProgramPage (unsigned long pageAddr,     
                      unsigned long size,
                      unsigned char *buf)
{
  size = (size + 1) & ~1;                       // Adjust size for Half Words
  
  FLASH->SR |= FLASH_PGERR;                             // Reset Error Flags
  FLASH->CR  =  0;                                      // reset CR 
  
  while (size) {

    FLASH->CR  =  FLASH_PG;                     // Programming Enabled

    M16(pageAddr) = *((unsigned short *)buf);   // Program Half Word
    while (FLASH->SR & FLASH_BSY);

    FLASH->CR  = 0;                     // Programming Disabled

    // Check for Errors
    if (FLASH->SR & (FLASH_PGERR | FLASH_WRPRTERR)) {
      FLASH->SR |= FLASH_PGERR | FLASH_WRPRTERR;
      return (1);                               // Failed
    }

    // Go to next Half Word
    pageAddr += 2;
    buf += 2;
    size -= 2;
   
  }

  return 0;
}



