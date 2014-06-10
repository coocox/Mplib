/**
 *******************************************************************************
 * @file       FlashAlgorithm.h
 * @version    V0.3
 * @date       2009.10.21
 * @brief      Flash Algorithm Framework.
 *******************************************************************************
 * @copy
 *
 * INTERNAL FILE,DON'T PUBLIC.
 * 
 * <h2><center>&copy; COPYRIGHT 2009 CooCox </center></h2>
 *******************************************************************************
 */       
#ifndef _FLASH_ALGORITHM_H
#define _FLASH_ALGORITHM_H



#define FLASH_FRAMEWORK_VERSION 0x0030                  // Framework Version(0.3)


// Flash Type
#define FLASH_TYPE_UNKNOWN        0                     // Unknown
#define FLASH_TYPE_ONCHIP         1                     // On-chip Flash Memory

// Flash Operation Function ( used when writting the Init/UnInit function )
#define FLASH_OPT_UNDEFINED       0                     // Undefined Operation
#define FLASH_OPT_ERASECHIP       1                     // Erase Full Chip
#define FLASH_OPT_ERASESECTORS    2                     // Erase Sectors
#define FLASH_OPT_PROGRAMPAGE     3                     // Program Page
#define FLASH_OPT_VERIFY          4                     // Verify Page
#define FLASH_OPT_BLANKCHECK      5                     // Blank Check Page

#define FLASH_SECTOR_END 0xFFFFFFFF, 0xFFFFFFFF

#define FLASH_SECTORS_NUM         512                   // Max Sectors Number
#define FLASH_ALGO_DESC_SIZE      128                   // Max Description String Len

struct FlashSector {
  unsigned long size;                                   // Sector Size in Bytes
  unsigned long addr;                                   // Address of Sector
};

//  Flash Device Info
struct FlashDevice {
  unsigned long type;                                   // Flash Device Type
  unsigned long baseAddr;                               // Flash Device Base Address
  unsigned long totalSize;                              // Flash Device Total Size(Bytes)
  unsigned long pageSize;                               // Page Size(Bytes)
  unsigned char initialVal;                             // Initial Vaule of Erased Memory
  struct FlashSector sectors[FLASH_SECTORS_NUM];        // Sectors 
};


struct FlashAlgorithm {
  unsigned long version;                                // Algorithm Version (FLASH_FRAMEWORK_VERSION << 16 | YourVersion)
  char description[FLASH_ALGO_DESC_SIZE];               // Description of the Algorithm
  struct FlashDevice deviceInfo;
  unsigned long timeoutComm;												// Time Out of FlashInit/FlashUnInit/FlashVerify/FlashBlankCheck function (in msec)
  unsigned long timeoutProg;    											// Time Out of FlashProgramage  Function (in msec)
  unsigned long timeoutEraseSector;  										// Time Out of FlashEraseSector Function (in msec)
  unsigned long timeoutEraseChip;  											// Time Out of FlashEraseChip   Function (in msec)
};


extern int FlashInit        (unsigned long baseAddr,     // Initialize Flash Before Various Flash Operation
                             unsigned long clk,
                             unsigned long operateFuc);
extern int FlashUnInit      (unsigned long operateFuc);  // UnInit Flash After Various Flash Operation

extern int FlashEraseChip   (void);                      // Erase Complete Device
extern int FlashEraseSector (unsigned long sectorAddr);  // Erase Sector Function
extern int FlashProgramPage (unsigned long pageAddr,     // Program Page Function
                             unsigned long size,
                             unsigned char *buf);   
extern int FlashVerify      (unsigned long verifyAddr,   // Page Verify Function
                             unsigned long size,
                             unsigned char *buf);

extern int FlashBlankCheck (unsigned long checkAddr,     // Page Blank Check Function
                            unsigned long size);  

#endif

