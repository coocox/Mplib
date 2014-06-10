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

typedef volatile unsigned long vu32;
typedef unsigned long u32;

#define M32(adr) (*((vu32 *) (adr)))

// Flash Memory Map
#define APROM_BASE        (0x00000000)
#define LDROM_BASE        (0x00100000)
#define CFG_BASE          (0x00300000)

// Peripheral Memory Map
#define GCR_BASE          (0x40000000)
#define CLK_BASE          (0x40000200)
#define FMC_BASE          (0x4000C000)

#define GCR               ((GCR_TypeDef *) GCR_BASE)
#define CLK               ((CLK_TypeDef *) CLK_BASE)
#define FMC               ((FMC_TypeDef *) FMC_BASE)

// System Manager Control Registers
typedef struct {
	vu32 RESERVED0[1];
	vu32 RSTSRC; // offset 0x004 R/W System Reset Source Register
	vu32 IPRSTC1; // offset 0x008 R/W IP Reset Control Resister1
	vu32 IPRSTC2; // offset 0x00C R/W IP Reset Control Resister2
	vu32 RESERVED1[2];
	vu32 BODCR; // offset 0x018 R/W Brown Out Detector Control Register
	vu32 RESERVED2[5];
	vu32 GPA_MFP; // offset 0x030 R/W GPIOA multiple function and input type control register
	vu32 GPB_MFP; // offset 0x034 R/W GPIOB multiple function and input type control register
	vu32 GPC_MFP; // offset 0x038 R/W GPIOC multiple function and input type control register
	vu32 GPD_MF; // offset 0x03C R/W GPIOD multiple function and input type control register
	vu32 GPE_MFP; // offset 0x040 R/W GPIOE input type control register
	vu32 RESERVED3[3];
	vu32 USPI_MFP; // offset 0x050 R/W Multiple function pin for USPI control register
	vu32 RESERVED4[43];
	vu32 RegLockAddr; // offset 0x100 R/W Register Lock Key address
	vu32 RESERVED5[3];
	vu32 RCADJ; // offset 0x110 R/W RC Adjustment Value
} GCR_TypeDef;

// Clock Control Registers
typedef struct {
	vu32 PWRCON; // offset 0x000 R/W System Power Down Control Register
	vu32 AHBCLK; // offset 0x004 R/W AHB Devices Clock Enable Control Register
	vu32 APBCLK; // offset 0x008 (R/W APB Devices Clock Enable Control Register
	vu32 RESERVED0[1];
	vu32 CLKSEL0; // offset 0x010 R/W Clock Source Select Control Register 0
	vu32 CLKSEL1; // offset 0x014 R/W Clock Source Select Control Register 1
	vu32 CLKDIV; // offset 0x018 R/W Clock Divider Number Register
	vu32 RESERVED1[1];
	vu32 PLLCON; // offset 0x020 R/W PLL Control Register
} CLK_TypeDef;

// FLASH MEMORY CONTROLLER (FMC) Registers
typedef struct {
	vu32 ISPCON; // offset 0x000 R/W ISP Control Register
	vu32 ISPADR; // offset 0x004 R/W ISP Address Register
	vu32 ISPDAT; // offset 0x008 R/W ISP Data Register
	vu32 ISPCMD; // offset 0x00C R/W ISP Command Register
	vu32 ISPTRG; // offset 0x010 R/W ISP Trigger Register
	vu32 DFBADR; // offset 0x014 R Data Flash Start Address
	vu32 FATCON; // offset 0x018 R/W Flash Access Window Control Register
    vu32 FBWP;   // offset 0x01C R/W Flash Block Write Protect Control Register
} FMC_TypeDef;

/*
 ------------------+---------------------+-----------------+-------------------
 |ISPCMD               | ISPADR          |ISPDAT
 ISP Mode          +---------------------+-----------------+-------------------
 |FOEN FCEN FCTRL[3:0] | A21 A20 A[19:0] | D[31:0]
 ------------------+---------------------+-----------------+-------------------
 Standby             1    1    X            x   x   x         x
 Read Company ID     0    0    1011         x   x   x        Data out D[31:0] = 0x000000DA
 Read Device ID      0    0    1100         x   x   0        Data out D[31:0] = 0x00000E80 (device ID depends on ROMMAP settings)
 FLASH Page Erase    1    0    0010         0  A20 A[19:0]    x
 FLASH Program       1    0    0001         0  A20 A[19:0]   Data in  D[31:0]
 FLASH Read          0    0    0000         0  A20 A[19:0]   Data out D[31:0]
 CONFIG Page Erase   1    0    0010         1   1  A[19:0]    x
 CONFIG Program      1    0    0001         1   1  A[19:0]   Data in  D[31:0]
 CONFIG Read         0    0    0000         1   1  A[19:0]   Data out D[31:0]
 */

// ISP Control Register (ISPCON) definitions
#define FMC_ISPFF             ((unsigned int)0x00000040)
#define FMC_LDUEN             ((unsigned int)0x00000020)
#define FMC_ISPEN             ((unsigned int)0x00000001)

// ISP Command (ISPCMD) definitions
#define FMC_STANDBY             ((unsigned int)0x00000030)
#define FMC_READ                ((unsigned int)0x00000000)
#define FMC_PROGRAM             ((unsigned int)0x00000021)
#define FMC_PAGE_ERASE          ((unsigned int)0x00000022)
#define FMC_READ_CID            ((unsigned int)0x0000000B)
#define FMC_READ_DID            ((unsigned int)0x0000000C)

// ISP Trigger Control Register (ISPTRG) definitions
#define FMC_ISPGO               ((unsigned int)0x00000001)

#if defined  NUC4xx_256
#define      SECTOR_NUM            512
#endif

#if defined  NUC4xx_512
#define      SECTOR_NUM            1024
#endif

#if defined  NUC4xx_LDROM
#define      SECTOR_NUM             32
#endif




/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int FlashInit(unsigned long baseAddr, unsigned long clk,
		      unsigned long operateFuc) {
	int delay = 100;
	unsigned long *ptr = (unsigned long *) 0x4000C01C;

	GCR->RegLockAddr = 0x59; // Unlock System Control Registers
	GCR->RegLockAddr = 0x16;
	GCR->RegLockAddr = 0x88;

	if (!(GCR->RegLockAddr & 0x01))
		return (1); // Not able to unlock

	CLK->PWRCON |= (1 << 2); // enable internal OSC22MHz
	CLK->AHBCLK |= (1 << 2); // enable internal OSC22MHz
	while (delay--)
		;

	FMC->ISPCON |= (FMC_ISPEN | FMC_LDUEN); // Enable ISP function
	*ptr |= 0x00000001;

	if (!(FMC->ISPCON & FMC_ISPEN))
		return (1); // ISP not enabled

	FMC->ISPCON |= FMC_ISPFF; // Reset Error Flag

	/* check if Wadchdog is running */

	return (0);
}

/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
int
FlashUnInit(unsigned long operateFuc)
{

	unsigned long *ptr = (unsigned long *) 0x4000C01C;

	while (FMC->ISPTRG & FMC_ISPGO)
		; // Wait until command is finished

	FMC->ISPCON &= (~(FMC_ISPEN | FMC_LDUEN));
	*ptr &= (~0x00000001);

	return (0);
}

/*
 *  Blank Check Checks if Memory is Blank
 *    Parameter:      adr:  Block Start Address
 *                    size:   Block Size (in bytes)
 *                    pat:  Block Pattern
 *    Return Value:   0 - OK,  1 - Failed
 */

#if defined NUC4xx_LDROM || defined NUC4xx_CFG
int
FlashBlankCheck (unsigned long checkAddr, unsigned long size)
{

	/* for Flash User Configuration blankCheck is always Not OK*/
	return (1); /* force erase */
}
#endif

/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int
FlashEraseSector(unsigned long sectorAddr)
{
	while (FMC->ISPTRG & FMC_ISPGO)
		; // Wait until command is finished

	FMC->ISPCON |= FMC_ISPFF; // Reset Error Flags

	FMC->ISPCMD = FMC_PAGE_ERASE; // Prepare Command
	FMC->ISPADR = (sectorAddr & ~0x00000003); // Prepare Address
	FMC->ISPTRG = FMC_ISPGO; // Exacute Command


	while (FMC->ISPTRG & FMC_ISPGO) { // Wait until command is finished
		/* reload Watdchdog */// Reload IWDG
	}

	if (FMC->ISPCON & FMC_ISPFF) { // Check for Error
		FMC->ISPCON |= FMC_ISPFF; // Reset Error Flags
		return (1); // Failed
	}

	return (0); // Done
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

#ifdef NUC4xx_LDROM
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

/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    size:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int
FlashProgramPage(unsigned long pageAddr, unsigned long size, unsigned char *buf)
{
	size = (size + 3) & ~3; // Adjust size for Words

	while (FMC->ISPTRG & FMC_ISPGO)
		; // Wait until command is finished

	FMC->ISPCON |= FMC_ISPFF; // Reset Error Flags

	while (size) {
		FMC->ISPCMD = FMC_PROGRAM; // Prepare Command
		FMC->ISPADR = (pageAddr & ~0x00000003); // Prepare Address
		FMC->ISPDAT = *((u32 *) buf); // Prepare Data
		FMC->ISPTRG = FMC_ISPGO; // Exacute Command


		while (FMC->ISPTRG & FMC_ISPGO) { // Wait until command is finished
			/* reload Watdchdog */// Reload IWDG
		}

		if (FMC->ISPCON & FMC_ISPFF) { // Check for Error
			FMC->ISPCON |= FMC_ISPFF; // Reset Error Flags
			return (1); // Failed
		}

		pageAddr += 4; // Go to next Word
		buf += 4;
		size -= 4;
	}

	return (0); // Done
}

/*
 *  Verify Flash Contents
 *    Parameter:      adr:  Start Address
 *                    size:   Size (in bytes)
 *                    buf:  Data
 *    Return Value:   (adr+size) - OK, Failed Address
 */

//int
//FlashVerify(unsigned long verifyAddr, unsigned long size, unsigned char *buf)
//{
//	size = (size + 3) & ~3; // Adjust size for Words
//
//	while (FMC->ISPTRG & FMC_ISPGO)
//		; // Wait until command is finished
//
//	FMC->ISPCON |= FMC_ISPFF; // Reset Error Flags
//
//	while (size) {
//		FMC->ISPCMD = FMC_READ; // set command
//		FMC->ISPADR = (verifyAddr & ~0x00000003); // Prepare Address
//		FMC->ISPDAT = 0x00000000; // Prepare Data
//		FMC->ISPTRG = FMC_ISPGO; // Exacute Command
//
//
//		while (FMC->ISPTRG & FMC_ISPGO) { // Wait until command is finished
//			/* reload Watdchdog */// Reload IWDG
//		}
//
//		if (FMC->ISPCON & FMC_ISPFF) { // Check for Error
//			FMC->ISPCON |= FMC_ISPFF; // Reset Error Flags
//			return (1); // Failed
//		}
//
//		if (FMC->ISPDAT != *((u32 *) buf)) { // Compare Data
//			return (1); // Failed
//		}
//
//		verifyAddr += 4; // Go to next Word
//		buf += 4;
//		size -= 4;
//	}
//
//	return (0); // Done
//
//}

