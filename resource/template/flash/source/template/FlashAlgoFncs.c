/**
 *******************************************************************************
 * @file       FlashAlgoFncs.c
 * @version    V0.3
 * @date       2010.12.02
 * @brief      Flash  Algorithm For SAM3U with 128KB Flash Rom	
 *******************************************************************************
 * @copy
 *
 * INTERNAL FILE,DON'T PUBLIC.
 * 
 * <h2><center>&copy; COPYRIGHT 2009 CooCox </center></h2>
 *******************************************************************************
 */ 
 
#include <FlashAlgorithm.h>


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
  switch (operateFuc)
  {
    case FLASH_OPT_ERASECHIP:
      // TODO: Initialization Before Erase Chip
      break;
    case FLASH_OPT_ERASESECTORS:
      // TODO: Initialization Before Erase Sectors
      break;
    case FLASH_OPT_PROGRAMPAGE:
      // TODO: Initialization Before Program Page
      break; 
//  case FLASH_OPT_VERIFY:
//    // TODO: Initialization Before Verify Pages
//    break;
//  case FLASH_OPT_BLANKCHECK:
//    // TODO: Initialization Before Check Pages
//    break;
  }
  
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
  switch (operateFuc)
  {
    case FLASH_OPT_ERASECHIP:
      // TODO: Un-Initialization After Erase Chip
      break;
    case FLASH_OPT_ERASESECTORS:
      // TODO: Un-Initialization After Erase Sectors
      break;
    case FLASH_OPT_PROGRAMPAGE:
      // TODO: Un-Initialization After Program Pages
      break; 
//  case FLASH_OPT_VERIFY:
//    // TODO: Un-Initialization After Verify Pages
//    break;
//  case FLASH_OPT_BLANKCHECK:
//    // TODO: Un-Initialization After Check Pages
//    break;
  }
  
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
  // TODO: your code for chip erase
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
  // TODO: your code for sector erase
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
  // TODO: your code for the page program
  return (0);
}


/**
 *******************************************************************************
 * @brief      Page Verify Function. 
 * @param[in]  verifyAddr   Verify Start Address(Usually page start address).
 * @param[in]  size			    Verify size
 * @param[in]  buf   			  Source buf point.
 * @param[out] None  
 * @retval     0   					Verify pass.
 * @retval     others       Some error occurs or verify failed..		 
 *
 * @par Description
 * @details   Optional function. When this function is absence, 
 *            the link will read flash memory directly to do verify.  
 * @note 
 *******************************************************************************
 */ 
//int FlashVerify(unsigned long verifyAddr,unsigned long size,unsigned char *buf)
//{
//  // TODO: your code for the page verify
//  return (0);
//}


/**
 *******************************************************************************
 * @brief      Page Blank Check Function. 
 * @param[in]  checkAddr    Check Start Address(Usually page start address).
 * @param[in]  size			    Check size
 * @param[out] None  
 * @retval     0   					Check pass.
 * @retval     others       Some error occurs or check failed.		 
 *
 * @par Description
 * @details   Optional function. When this function is absence, 
 *            the link will read flash memory directly to do verify.  
 * @note      Sector can be significant.We check the page rather than the sector,
 *            having regard to the actual size of the ram.
 *******************************************************************************
 */ 
//int FlashBlankCheck (unsigned long checkAddr,unsigned long size)
//{
//  // TODO: your code for the page check
//  return (0);
//}