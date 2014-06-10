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


#define M8(adr)  (*((volatile unsigned char  *)(adr)))
#define M16(adr) (*((volatile unsigned short *)(adr)))
#define M32(adr) (*((volatile unsigned long  *)(adr)))

#define PAGE_SIZE     128      // Page Size

// Watchdog Timer Registers
#define WDMOD    (*((volatile unsigned char  *)0x400F2000))
#define WDCR     (*((volatile unsigned char  *)0x400F2004))


// Flash Control/Status Register
#define FLCSF   (*((volatile unsigned long  *)0x41FFF020))
#define FLCS_RDY  0x00000001

//
#define MACRO_ADD1(add) (0x000550)
#define MACRO_ADD2(add) (0x000AA0)

//unsigned long 0;


int
FlashInit(unsigned long basevcvAddr, unsigned long clk,
		      unsigned long operateFuc)
{
	  // Disable Watchdog
	  WDMOD = 0x00;
	  WDCR  = 0xB1;

//	  0 = basevcvAddr;

	  return (0);
}


int
FlashUnInit(unsigned long operateFuc)
{
	return (0);
}



int
FlashEraseSector(unsigned long sectorAddr)
{
	 // Start Block Erase Command
	  M32(0 + MACRO_ADD1(sectorAddr)) = 0xAA;
	  M32(0 + MACRO_ADD2(sectorAddr)) = 0x55;
	  M32(0 + MACRO_ADD1(sectorAddr)) = 0x80;
	  M32(0 + MACRO_ADD1(sectorAddr)) = 0xAA;
	  M32(0 + MACRO_ADD2(sectorAddr)) = 0x55;

	  M32(sectorAddr) = 0x30;

	  while ((FLCSF & FLCS_RDY) != FLCS_RDY);     // Wait until completed

	  return (0);                                  // Finished without Errors
}




int FlashEraseChip   (void)
{
	 // Start Chip Erase Command
	  M32(0 + 0x0550) = 0xAA;
	  M32(0 + 0x0AA0) = 0x55;
	  M32(0 + 0x0550) = 0x80;
	  M32(0 + 0x0550) = 0xAA;
	  M32(0 + 0x0AA0) = 0x55;
	  M32(0 + 0x0550) = 0x10;

	  while ((FLCSF & FLCS_RDY) != FLCS_RDY);     // Wait until completed

	  return (0);                                  // Finished without Errors
}


int
FlashProgramPage(unsigned long pageAddr, unsigned long size, unsigned char *buf)
{
	int i;

	  // Start Page Programming Command
	  M32(0 + MACRO_ADD1(pageAddr)) = 0xAA;
	  M32(0 + MACRO_ADD2(pageAddr)) = 0x55;
	  M32(0 + MACRO_ADD1(pageAddr)) = 0xA0;

	  // Write Page Data
	  for (i = 0; i < (PAGE_SIZE/4); i++) {

	    M32(pageAddr) = *((unsigned long *)buf);

	    buf += 4;
	  }

	  while ((FLCSF & FLCS_RDY) != FLCS_RDY);     // Wait until completed

	  return (0);                                  // Finished without Errors
}

