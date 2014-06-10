/******************************************************************************
 * @file     SDGlue.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 14/01/14 10:15a $
 * @brief    SD glue functions for FATFS
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NUC400Series.h"
#include "diskio.h"     /* FatFs lower layer API */
#include "SD.h"

#define SUPPORT_SD

extern int sd0_ok;
extern int sd1_ok;

extern uint8_t pSD0_offset;
extern uint8_t pSD1_offset;

extern DISK_DATA_T SD_DiskInfo0;
extern DISK_DATA_T SD_DiskInfo1;

int SD_Open_(uint32_t cardSel);
void SD_Close_(uint32_t cardSel);

int SD_Open_(uint32_t cardSel)
{
    SD_Open(cardSel);
    SD_Probe(cardSel & 0x00ff);

    return SD_GET_CARD_CAPACITY(SD_PORT0);
}

void SD_Close_(uint32_t cardSel)
{
    if (cardSel == 0) {
        sd0_ok = 0;
        memset(&SD0, 0, sizeof(SD_INFO_T));
    } else if(cardSel == 1) {
        sd1_ok = 0;
        memset(&SD1, 0, sizeof(SD_INFO_T));
    }

}

