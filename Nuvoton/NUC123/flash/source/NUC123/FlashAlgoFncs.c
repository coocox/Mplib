
/**
 *******************************************************************************
 * @file       FlashAlgoFncs.c
 * @version    V0.3
 * @date       2010.12.02
 * @brief      Flash  Algorithm For NUC1xx with 128/64/32KB Flash Rom	
 *******************************************************************************
 * @copy
 *
 * INTERNAL FILE,DON'T PUBLIC.
 * 
 * <h2><center>&copy; COPYRIGHT 2009 CooCox </center></h2>
 *******************************************************************************
 */ 
 
#include <FlashAlgorithm.h>

typedef volatile unsigned long    vu32;
typedef          unsigned long     u32;

#define M32(adr) (*((vu32 *) (adr)))

// Flash Memory Map
#define APROM_BASE        (0x00000000)
#define LDROM_BASE        (0x00100000)
#define CFG_BASE          (0x00300000)

// Peripheral Memory Map
#define GCR_BASE          (0x50000000)
#define CLK_BASE          (0x50000200)
#define FMC_BASE          (0x5000C000)

#define GCR               ((GCR_TypeDef *) GCR_BASE)
#define CLK               ((CLK_TypeDef *) CLK_BASE)
#define FMC               ((FMC_TypeDef *) FMC_BASE)


// System Manager Control Registers
typedef struct {
  vu32 RESERVED0[1];
  vu32 RSTSRC;               // offset 0x004 R/W System Reset Source Register
  vu32 IPRSTC1;              // offset 0x008 R/W IP Reset Control Resister1
  vu32 IPRSTC2;              // offset 0x00C R/W IP Reset Control Resister2
  vu32 RESERVED1[2];
  vu32 BODCR;                // offset 0x018 R/W Brown Out Detector Control Register
  vu32 RESERVED2[5];
  vu32 GPA_MFP;              // offset 0x030 R/W GPIOA multiple function and input type control register
  vu32 GPB_MFP;              // offset 0x034 R/W GPIOB multiple function and input type control register
  vu32 GPC_MFP;              // offset 0x038 R/W GPIOC multiple function and input type control register
  vu32 GPD_MF;               // offset 0x03C R/W GPIOD multiple function and input type control register
  vu32 GPE_MFP;              // offset 0x040 R/W GPIOE input type control register
  vu32 RESERVED3[3];
  vu32 USPI_MFP;             // offset 0x050 R/W Multiple function pin for USPI control register
  vu32 RESERVED4[43];
  vu32 RegLockAddr;          // offset 0x100 R/W Register Lock Key address
  vu32 RESERVED5[3];
  vu32 RCADJ;                // offset 0x110 R/W RC Adjustment Value
} GCR_TypeDef;

// Clock Control Registers
typedef struct {
  vu32 PWRCON;               // offset 0x000 R/W System Power Down Control Register
  vu32 AHBCLK;               // offset 0x004 R/W AHB Devices Clock Enable Control Register
  vu32 APBCLK;               // offset 0x008 (R/W APB Devices Clock Enable Control Register
  vu32 RESERVED0[1];
  vu32 CLKSEL0;              // offset 0x010 R/W Clock Source Select Control Register 0
  vu32 CLKSEL1;              // offset 0x014 R/W Clock Source Select Control Register 1
  vu32 CLKDIV;               // offset 0x018 R/W Clock Divider Number Register
  vu32 RESERVED1[1];
  vu32 PLLCON;               // offset 0x020 R/W PLL Control Register
} CLK_TypeDef;

// FLASH MEMORY CONTROLLER (FMC) Registers
typedef struct {
  vu32 ISPCON;               // offset 0x000 R/W ISP Control Register
  vu32 ISPADR;               // offset 0x004 R/W ISP Address Register
  vu32 ISPDAT;               // offset 0x008 R/W ISP Data Register
  vu32 ISPCMD;               // offset 0x00C R/W ISP Command Register
  vu32 ISPTRG;               // offset 0x010 R/W ISP Trigger Register
  vu32 DFBADR;               // offset 0x014 R Data Flash Start Address
  vu32 FATCON;               // offset 0x018 R/W Flash Access Window Control Register
  vu32 ICPCON;               // offset 0x01C R/W ??
  vu32 RMPCON;               // offset 0x020 R/W ??
} FMC_TypeDef;



// ISP Control Register (ISPCON) definitions
#define FMC_ISPFF             ((unsigned int)0x00000040)
#define FMC_LDUEN             ((unsigned int)0x00000020)
#define FMC_ISPEN             ((unsigned int)0x00000001)

// ICP Control Register (ICPCON) definitions
#define FMC_ICPEN             ((unsigned int)0x00000001)

// ISP Command (ISPCMD) definitions
#define FMC_STANDBY             ((unsigned int)0x00000030)
#define FMC_READ                ((unsigned int)0x00000000)
#define FMC_PROGRAM             ((unsigned int)0x00000021)
#define FMC_PAGE_ERASE          ((unsigned int)0x00000022)
#define FMC_READ_CID            ((unsigned int)0x0000000B)
#define FMC_READ_DID            ((unsigned int)0x0000000C)

// ISP Trigger Control Register (ISPTRG) definitions
#define FMC_ISPGO               ((unsigned int)0x00000001)


#if defined  NUC1xx_128 
#define      SECTOR_NUM            256
#endif

#if defined  NUC1xx_64 
#define      SECTOR_NUM            128
#endif

#if defined  NUC1xx_32 
#define      SECTOR_NUM             64
#endif

#if defined  NUC1xx_LDROM 
#define      SECTOR_NUM             8
#endif

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
  
  int delay = 100;

  GCR->RegLockAddr = 0x59;                              // Unlock System Control Registers
  GCR->RegLockAddr = 0x16;                              
  GCR->RegLockAddr = 0x88;                              

  if (!(GCR->RegLockAddr & 0x01))
    return 1;                                           // Not able to unlock 

  CLK->PWRCON |= (1 << 2);                              // enable internal OSC22MHz 
  while (delay--);

  FMC->ISPCON |= (FMC_ISPEN | FMC_LDUEN);               // Enable ISP function
  FMC->ICPCON |= (FMC_ICPEN);                           // Enable ICP functions ?

  if (!(FMC->ISPCON & FMC_ISPEN))
 	{
    return 1;                                           // ISP not enabled 
  }

  FMC->ISPCON |= FMC_ISPFF;                             // Reset Error Flag
   
                         
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
	unsigned long offs;                                   // Flash Offset
	unsigned long adr;
	int i;
	
#ifdef NUC1xx_LDROM
  offs = 0x00100000;
#else
  offs = 0x00000000;
#endif

	FMC->ISPCON |= FMC_ISPFF;                             // Reset Error Flags
	adr = 0;
	for(i = 0; i < SECTOR_NUM; i++)
	{
		
		FMC->ISPCMD = FMC_PAGE_ERASE;                       // Prepare Command
		FMC->ISPADR = ((adr + offs) & ~0x00000003);         // Prepare Address
		FMC->ISPTRG = FMC_ISPGO;                            // Exacute Command
		
		while (FMC->ISPTRG & FMC_ISPGO)                     // Wait until command is finished
		{
		/* reload Watdchdog */                              // Reload IWDG
		}
		
		if (FMC->ISPCON &  FMC_ISPFF)                       // Check for Error
		{
			FMC->ISPCON |= FMC_ISPFF;                       // Reset Error Flags
			return 1;                                       // Failed
		}
		
		adr += 512;
		
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
	unsigned long offs;                                   // Flash Offset

#ifdef NUC1xx_LDROM
	offs = 0x00100000;
#else
	offs = 0x00000000;
#endif
	
	FMC->ISPCON |= FMC_ISPFF;                             // Reset Error Flags
	
	FMC->ISPCMD = FMC_PAGE_ERASE;                         // Prepare Command
	FMC->ISPADR = ((sectorAddr + offs) & ~0x00000003);    // Prepare Address
	FMC->ISPTRG = FMC_ISPGO;                              // Exacute Command
	
	while (FMC->ISPTRG & FMC_ISPGO)                       // Wait until command is finished
	{
	  /* reload Watdchdog */                              // Reload IWDG
	}
	
	if (FMC->ISPCON &  FMC_ISPFF)                         // Check for Error
	{    
      FMC->ISPCON |= FMC_ISPFF;                           // Reset Error Flags
      return 1;                                           // Failed
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
	unsigned long offs;                                 	// Flash Offset
	unsigned long adr = pageAddr;
	unsigned long sz = size;
	
#ifdef NUC1xx_LDROM
	offs = 0x00100000;
#else
	offs = 0x00000000;
#endif
	
	sz = (sz + 3) & ~3;                                 	// Adjust size for Words
	
	FMC->ISPCON |= FMC_ISPFF;                           	// Reset Error Flags
	
	while (sz) 
	{
		FMC->ISPCMD = FMC_PROGRAM;                          // Prepare Command
		FMC->ISPADR = ((adr + offs) & ~0x00000003);         // Prepare Address
		FMC->ISPDAT	= *((u32 *)buf);                        // Prepare Data
		FMC->ISPTRG = FMC_ISPGO;                            // Exacute Command
		
		while (FMC->ISPTRG & FMC_ISPGO) 
		{                   																// Wait until command is finished
		  /* reload Watdchdog */                            // Reload IWDG
		}
		
		if (FMC->ISPCON &  FMC_ISPFF) 
	  {                     															// Check for Error
		    FMC->ISPCON |= FMC_ISPFF;                       // Reset Error Flags
		    return 1;                                       // Failed
		}
		
		adr += 4;                                           // Go to next Word
		buf += 4;
		sz  -= 4;
	}

  
  return 0;
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
int FlashVerify(unsigned long verifyAddr,unsigned long size,unsigned char *buf)
{
	unsigned long offs;                                 	// Flash Offset
	unsigned long adr = verifyAddr;
	unsigned long sz = size;
#ifdef NUC1xx_LDROM
	offs = 0x00100000;
#else
	offs = 0x00000000;
#endif


	sz = (sz + 3) & ~3;                                 	// Adjust size for Words
	
	FMC->ISPCON |= FMC_ISPFF;                           	// Reset Error Flags
	
	while (sz) 
	{
		FMC->ISPCMD = FMC_READ;                             // set command
		FMC->ISPADR = ((adr + offs) & ~0x00000003);         // Prepare Address
		FMC->ISPDAT	= 0x00000000;                           // Prepare Data
		FMC->ISPTRG = FMC_ISPGO;                            // Exacute Command
		
		while (FMC->ISPTRG & FMC_ISPGO)		                // Wait until command is finished
		{
		  /* reload Watdchdog */                            // Reload IWDG
		}
		
		if (FMC->ISPCON &  FMC_ISPFF) 
		{                                                   // Check for Error
		  FMC->ISPCON |= FMC_ISPFF;                         // Reset Error Flags
		  return 1;                                     	// Failed
		}
		
		if (FMC->ISPDAT	!= *((u32 *)buf)) 
		{                 									// Compare Data
		  return 1;
		}  
		
		adr += 4;                                           // Go to next Word
		buf += 4;
		sz  -= 4;
	}
	

  return 0;
}

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
int FlashBlankCheck (unsigned long checkAddr,unsigned long size)
{
  // TODO: your code for the page check
  unsigned long offs;                                   // Flash Offset
	unsigned long adr = checkAddr;
	unsigned long sz = size;
#ifdef NUC1xx_LDROM
	offs = 0x00100000;
#else
	offs = 0x00000000;
#endif

	sz = (sz + 3) & ~3;                                   // Adjust size for Words
	
	FMC->ISPCON |= FMC_ISPFF;                             // Reset Error Flags
	
	while (sz) 
	{
		FMC->ISPCMD = FMC_READ;                             // set command
		FMC->ISPADR = ((adr + offs) & ~0x00000003);         // Prepare Address
		FMC->ISPDAT	= 0x00000000;                           // Prepare Data
		FMC->ISPTRG = FMC_ISPGO;                            // Exacute Command
		
		while (FMC->ISPTRG & FMC_ISPGO) 
		{                   								// Wait until command is finished
		  /* reload Watdchdog */                            // Reload IWDG
		}
		
		if (FMC->ISPCON &  FMC_ISPFF) 
		{                                                   // Check for Error
		  FMC->ISPCON |= FMC_ISPFF;                         // Reset Error Flags
		  return 1;                                     	// Failed
		}
		
		if (FMC->ISPDAT	!= 0xFFFFFFFF) 
		{                 		                            // Compare Data
		  return 1;
		}  
		
		adr += 4;                                           // Go to next Word
		sz  -= 4;
	}
	

  return 0;
  
}