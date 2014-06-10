/**
 *******************************************************************************
 * @file       FlashAlgoFncs.c
 * @version    V0.3
 * @date       2010.12.02
 * @brief      Flash  Algorithm For TMPM37x with 128KB Flash Rom
 *******************************************************************************
 * @copy
 *
 * INTERNAL FILE,DON'T PUBLIC.
 * 
 * <h2><center>&copy; COPYRIGHT 2009 CooCox </center></h2>
 *******************************************************************************
 */ 
 
#include <FlashAlgorithm.h>

#define M8(adr)  (*((volatile unsigned char  *)(adr)))
#define M16(adr) (*((volatile unsigned short *)(adr)))
#define M32(adr) (*((volatile unsigned long  *)(adr)))

#define STACK_SIZE     64      // Stack Size


// Watchdog Timer Registers
#define WDMOD    (*((volatile unsigned char  *)0x40040000))
#define WDCR     (*((volatile unsigned char  *)0x40040004))


// Flash Control/Status Register
#define FLCSF   (*((volatile unsigned long  *)0x41FFF020))
#define FLCS_RDY  0x00000001

#if defined ( TMPM37x_64 )

#define MACRO_ADD1(add) (0x000550)
#define MACRO_ADD2(add) (0x000AA0)
#define PAGE_SIZE     128      // Page Size
#else
#define MACRO_ADD1(add) (0x005400)
#define MACRO_ADD2(add) (0x00AA00)

#if defined ( TMPM37x_512 )
#define PAGE_SIZE     512      // Page Size
#else
#define PAGE_SIZE     256      // Page Size
#endif

#endif

unsigned long base_adr;

/**
 *******************************************************************************
 * @brief      Initialize before Flash Programming/Erase Functions 
 * @param[in]  baseAddr     Flash device base address.
 * @param[in]  clk     			Flash program clock.
 * @param[in]  operateFuc   Init for what operation
 														(FLASH_OPT_ERASECHIP/FLASH_OPT_ERASESECTORS/FLASH_OPT_PROGRAMPAGE/
 														 FLASH_OPT_VERIFY/ FLASH_OPT_BLANKCHECK).
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details    This function is called before flash programming/erase. 
 * @note 
 *******************************************************************************
 */
int FlashInit (unsigned long baseAddr,unsigned long clk, unsigned long operateFuc)
{
  // Disable Watchdog
  WDMOD = 0x00;
  WDCR  = 0xB1;

  base_adr = baseAddr;
  return (0);
}


/**
 *******************************************************************************
 * @brief      Un-Init after Flash Programming/Erase Functions  
 * @param[in]  operateFuc   Init for what operation
 														(FLASH_OPT_ERASECHIP/FLASH_OPT_ERASESECTORS/FLASH_OPT_PROGRAMPAGE/
 														 FLASH_OPT_VERIFY/FLASH_OPT_BLANKCHECK).
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details    This function is called after flash programming/erase. 
 * @note 
 *******************************************************************************
 */
int FlashUnInit(unsigned long operateFuc)
{
  return (0);
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
int FlashEraseChip (void)
{
  // Start Chip Erase Command
  M32(base_adr + MACRO_ADD1(0)) = 0xAA;
  M32(base_adr + MACRO_ADD2(0)) = 0x55;
  M32(base_adr + MACRO_ADD1(0)) = 0x80;
  M32(base_adr + MACRO_ADD1(0)) = 0xAA;
  M32(base_adr + MACRO_ADD2(0)) = 0x55;
  M32(base_adr + MACRO_ADD1(0)) = 0x10;

  while ((FLCSF & FLCS_RDY) != FLCS_RDY);     // Wait until completed

  return (0);
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
  
  // Start Block Erase Command
  M32(base_adr + MACRO_ADD1(sectorAddr)) = 0xAA;
  M32(base_adr + MACRO_ADD2(sectorAddr)) = 0x55;
  M32(base_adr + MACRO_ADD1(sectorAddr)) = 0x80;
  M32(base_adr + MACRO_ADD1(sectorAddr)) = 0xAA;
  M32(base_adr + MACRO_ADD2(sectorAddr)) = 0x55;

  M32(sectorAddr) = 0x30;

  while ((FLCSF & FLCS_RDY) != FLCS_RDY);     // Wait until completed

  return (0);                 
}



/**
 *******************************************************************************
 * @brief      Proram a page. 
 * @param[in]  pageAddr     Page's start address.
 * @param[in]  size			    Page size
 * @param[in]  buf   			  Source buf point.
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details     
 * @note 
 *******************************************************************************
 */ 
int FlashProgramPage (unsigned long pageAddr, unsigned long size, unsigned char *buf)
{
   int i;

  // Start Page Programming Command
   M32(base_adr + MACRO_ADD1(pageAddr)) = 0xAA;
   M32(base_adr + MACRO_ADD2(pageAddr)) = 0x55;
   M32(base_adr + MACRO_ADD1(pageAddr)) = 0xA0;

  // Write Page Data
  // !!!Import: Must write the full page, Even if the actual size < PageSize
  //
  for (i = 0; i < (PAGE_SIZE/4); i++) {
    M32(pageAddr) = *((unsigned long *)buf);
    buf += 4;
  }

  while ((FLCSF & FLCS_RDY) != FLCS_RDY);     // Wait until completed
  
  return (0);
}
