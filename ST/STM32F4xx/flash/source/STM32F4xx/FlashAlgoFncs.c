/**
 *******************************************************************************
 * @file       FlashAlgoFncs.c
 * @version    V0.1
 * @date       2012.03.12
 * @brief      Flash  Algorithm For STM32F4xx
 *******************************************************************************
 * @copy
 *
 * <h2><center>&copy; COPYRIGHT 2012 CooCox </center></h2>
 *******************************************************************************
 */ 
 
#include <FlashAlgorithm.h>


typedef volatile unsigned char    vu8;
typedef          unsigned char     u8;
typedef volatile unsigned short   vu16;
typedef          unsigned short    u16;
typedef volatile unsigned long    vu32;
typedef          unsigned long     u32;

#define M8(adr)  (*((vu8  *) (adr)))
#define M16(adr) (*((vu16 *) (adr)))
#define M32(adr) (*((vu32 *) (adr)))

// Peripheral Memory Map
#define IWDG_BASE         0x40003000
#define FLASH_BASE        0x40023C00

#define IWDG            ((IWDG_TypeDef *) IWDG_BASE)
#define FLASH           ((FLASH_TypeDef*) FLASH_BASE)

// Independent WATCHDOG
typedef struct {
  vu32 KR;
  vu32 PR;
  vu32 RLR;
  vu32 SR;
} IWDG_TypeDef;

// Flash Registers
typedef struct {
  vu32 ACR;
  vu32 KEYR;
  vu32 OPTKEYR;
  vu32 SR;
  vu32 CR;
  vu32 OPTCR;
} FLASH_TypeDef;


// Flash Keys
#define RDPRT_KEY       0x00A5
#define FLASH_KEY1      0x45670123
#define FLASH_KEY2      0xCDEF89AB
#define FLASH_OPTKEY1   0x08192A3B
#define FLASH_OPTKEY2   0x4C5D6E7F

// Flash Control Register definitions
#define FLASH_PG                ((unsigned int)0x00000001)
#define FLASH_SER               ((unsigned int)0x00000002)
#define FLASH_MER               ((unsigned int)0x00000004)
#define FLASH_MER1              ((unsigned int)0x00008000)
#define FLASH_SNB_POS           ((unsigned int)0x00000003)
#define FLASH_SNB_MSK           ((unsigned int)0x00000078)
#define FLASH_PSIZE_POS         ((unsigned int)0x00000008)
#define FLASH_PSIZE_MSK         ((unsigned int)0x00000300)
#define FLASH_STRT              ((unsigned int)0x00010000)
#define FLASH_LOCK              ((unsigned int)0x80000000)

// Flash Option Control Register definitions
#define FLASH_OPTLOCK           ((unsigned int)0x00000001)
#define FLASH_OPTSTRT           ((unsigned int)0x00000002)


#define FLASH_PSIZE_Byte        ((unsigned int)0x00000000)
#define FLASH_PSIZE_HalfWord    ((unsigned int)0x00000100)
#define FLASH_PSIZE_Word        ((unsigned int)0x00000200)
#define FLASH_PSIZE_DoubleWord  ((unsigned int)0x00000300)


// Flash Status Register definitions
#define FLASH_EOP               ((unsigned int)0x00000001)
#define FLASH_OPERR             ((unsigned int)0x00000002)
#define FLASH_WRPERR            ((unsigned int)0x00000010)
#define FLASH_PGAERR            ((unsigned int)0x00000020)
#define FLASH_PGPERR            ((unsigned int)0x00000040)
#define FLASH_PGSERR            ((unsigned int)0x00000080)
#define FLASH_BSY               ((unsigned int)0x00010000)

#define FLASH_PGERR             (FLASH_PGSERR | FLASH_PGPERR | FLASH_PGAERR | FLASH_WRPERR)


/**
 *******************************************************************************
 * @brief      Get Sector Number 
 * @param[in]  addr     Sector Address
 * @param[out] None  
 * @retval     Sector Number		 
 *
 *******************************************************************************
 */
unsigned long GetSecNum (unsigned long addr) 
{
  unsigned long n;

  n = (addr >> 12) & 0x000FF;                            // only bits 12..19

  if (n >= 0x20) 
  {
    n = 4 + (n >> 5);                                    // 128kB Sector
  }
  else if (n >= 0x10) 
  {
    n = 3 + (n >> 4);                                    //  64kB Sector
  }
  else                
  {
    n = 0 + (n >> 2);                                    //  16kB Sector
  }
  if (addr & 0x00100000)
    n |=0x00000010;

  return (n);                                            // Sector Number
}

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
  if((FLASH->CR & FLASH_LOCK) != 0) 
  {
  	FLASH->KEYR = FLASH_KEY1;                           // Unlock Flash
  	FLASH->KEYR = FLASH_KEY2;
  }

  FLASH->ACR  = 0x00000000;                             // Zero Wait State, no Cache, no Prefetch
  FLASH->SR  |= FLASH_PGERR;                            // Reset Error Flags

  if ((FLASH->OPTCR & 0x20) == 0x00)                    // Test if IWDG is running (IWDG in HW mode)
  {                  
    // Set IWDG time out to ~32.768 second
    IWDG->KR  = 0x5555;                                 // Enable write access to IWDG_PR and IWDG_RLR     
    IWDG->PR  = 0x06;                                   // Set prescaler to 256  
    IWDG->RLR = 4095;                                   // Set reload value to 4095
  }

  return (0);
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
  FLASH->CR |=  FLASH_LOCK;                             // Lock Flash

  return (0);

  return 0;
}

int FlashEraseChip (void) 
{

  FLASH->CR |=  FLASH_MER;                              // Mass Erase Enabled (sectors  0..11)
#ifdef STM32F4xx_2048
  FLASH->CR |=  FLASH_MER1;                             // Mass Erase Enabled (sectors 12..23)
#endif
  FLASH->CR |=  FLASH_STRT;                             // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                                  // Reload IWDG
  }

  FLASH->CR &= ~FLASH_MER;                              // Mass Erase Disabled
#ifdef STM32F4xx_2048
  FLASH->CR &= ~FLASH_MER1;                             // Mass Erase Disabled
#endif

  return (0);                                           // Done
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
  unsigned long n;

  n = GetSecNum(sectorAddr);                            // Get Sector Number

  FLASH->SR |= FLASH_PGERR;                             // Reset Error Flags

  FLASH->CR  =  FLASH_SER;                              // Sector Erase Enabled 
  FLASH->CR |=  ((n << FLASH_SNB_POS) & FLASH_SNB_MSK); // Sector Number
  FLASH->CR |=  FLASH_STRT;                             // Start Erase

  while (FLASH->SR & FLASH_BSY) 
  {
    IWDG->KR = 0xAAAA;                                  // Reload IWDG
  }

  FLASH->CR &= ~FLASH_SER;                              // Page Erase Disabled 

  if (FLASH->SR & FLASH_PGERR)                          // Check for Error
  {                        
    FLASH->SR |= FLASH_PGERR;                           // Reset Error Flags
    return (1);                                         // Failed
  }

  return (0);                                           // Done
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
  
  size = (size + 3) & ~3;                               // Adjust size for Words
  
  FLASH->SR |= FLASH_PGERR;                             // Reset Error Flags
  FLASH->CR  =  0;                                      // reset CR 

  while (size) 
  {
    FLASH->CR |= (FLASH_PG |                            // Programming Enabled
                  FLASH_PSIZE_Word);                    // Programming Enabled (Word)

    M32(pageAddr) = *((u32 *)buf);                      // Program Double Word
    while (FLASH->SR & FLASH_BSY);

    FLASH->CR &= ~FLASH_PG;                             // Programming Disabled

    if (FLASH->SR & FLASH_PGERR)                        // Check for Error
    {                      
      FLASH->SR |= FLASH_PGERR;                         // Reset Error Flags
      return (1);                                       // Failed
    }

    pageAddr += 4;                                      // Go to next Word
    buf      += 4;
    size     -= 4;
  }

  return (0);                                           // Done
}



