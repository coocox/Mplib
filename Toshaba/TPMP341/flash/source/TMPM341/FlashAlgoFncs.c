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
#ifdef TMPM341_256
#define PAGE_SIZE     256      // Page Size for TMPM341FYXBG
#else
#define PAGE_SIZE     512      // Page Size for TMPM341FDXBG
#endif


// Watchdog Timer Registers
#define WDMOD    (*((volatile unsigned long  *)0x400F2000))
#define WDCR     (*((volatile unsigned long  *)0x400F2004))

// Flash Control/Status Register
#define FLCSF    (*((volatile unsigned long  *)0x41FFF020))

#define FLCS_RDY  0x00000001


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
	  M8(base_adr + 0x5400) = 0xAA;
	  M8(base_adr + 0xAA00) = 0x55;
	  M8(base_adr + 0x5400) = 0x80;
	  M8(base_adr + 0x5400) = 0xAA;
	  M8(base_adr + 0xAA00) = 0x55;
	  M8(base_adr + 0x5400) = 0x10;

	  while ((FLCSF & FLCS_RDY) != FLCS_RDY);      // Wait until completed

	  return (0);                                  // Finished without Errors
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
	  M8(base_adr + 0x5400) = 0xAA;
	  M8(base_adr + 0xAA00) = 0x55;
	  M8(base_adr + 0x5400) = 0x80;
	  M8(base_adr + 0x5400) = 0xAA;
	  M8(base_adr + 0xAA00) = 0x55;
	  M8(sectorAddr) = 0x30;

	  while ((FLCSF & FLCS_RDY) != FLCS_RDY);      // Wait until completed

	  return (0);                                  // Finished without Errors
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
	  M8(base_adr + 0x5400) = 0xAA;
	  M8(base_adr + 0xAA00) = 0x55;
	  M8(base_adr + 0x5400) = 0xA0;

	  // Write Page Data
	  for (i = 0; i < (PAGE_SIZE/4); i++) {
	    M32(pageAddr) = *((unsigned long *)buf);
	    buf += 4;
	  }

	  while ((FLCSF & FLCS_RDY) != FLCS_RDY);      // Wait until completed

	  return (0);                                  // Finished without Errors
}
