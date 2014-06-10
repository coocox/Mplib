/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2013        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NUC400Series.h"
#include "diskio.h"     /* FatFs lower layer API */
#include "SD.h"


#define SUPPORT_SD


/* Definitions of physical drive number for each media */

#define DRV_SD0     0
#define DRV_SD1     1


extern DISK_DATA_T SD_DiskInfo0;
extern DISK_DATA_T SD_DiskInfo1;

extern int SD_Open_(uint32_t cardSel);
extern void SD_Close_(uint32_t cardSel);



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
    BYTE pdrv               /* Physical drive nmuber (0..) */
)
{
    switch (pdrv) {
#ifdef SUPPORT_SD
    case DRV_SD0 :
        SD_Open_(SD_PORT0 | CardDetect_From_GPIO);

        return 0;

    case DRV_SD1 :
        SD_Open_(SD_PORT0 | CardDetect_From_GPIO);

        return 0;
#endif
    }

    return RES_PARERR;
}


/*-----------------------------------------------------------------------*/
/* Get Disk Status                                                       */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
    BYTE pdrv       /* Physical drive nmuber (0..) */
)
{

    switch (pdrv) {
#ifdef SUPPORT_SD
    case DRV_SD0 :

        return RES_OK;

    case DRV_SD1 :

        return RES_OK;
#endif
    }
    return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
    BYTE pdrv,      /* Physical drive nmuber (0..) */
    BYTE *buff,     /* Data buffer to store read data */
    DWORD sector,   /* Sector address (LBA) */
    BYTE count      /* Number of sectors to read (1..128) */
)
{
    //int status;
    uint32_t status;

    switch (pdrv) {
#ifdef SUPPORT_SD
    case DRV_SD0 :

        SD->FMICR = SD_FMICR_SD_EN_Msk;
        //status = SD_Read_in(pSD0, sector, count, (unsigned int)buff);
        status = SD_Read(SD_PORT0, (uint8_t*)buff, sector, count);

        if (status != Successful)
            return RES_ERROR;

        return RES_OK;

    case DRV_SD1 :

        SD->FMICR = SD_FMICR_SD_EN_Msk;
        //status = SD_Read_in(pSD1, sector, count, (unsigned int)buff);
        status = SD_Read(SD_PORT1, (uint8_t*)buff, sector, count);

        if (status != Successful)
            return RES_ERROR;

        return RES_OK;

#endif
    }
    return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
    BYTE pdrv,          /* Physical drive nmuber (0..) */
    const BYTE *buff,   /* Data to be written */
    DWORD sector,       /* Sector address (LBA) */
    BYTE count          /* Number of sectors to write (1..128) */
)
{
    int status;

    switch (pdrv) {
#ifdef SUPPORT_SD
    case DRV_SD0 :

        SD->FMICR = SD_FMICR_SD_EN_Msk;
        //status = SD_Write_in(pSD0, sector, count, (unsigned int)buff);
        status = SD_Write(SD_PORT0, (uint8_t*)buff, sector, count);

        if (status != Successful)
            return RES_ERROR;

        return RES_OK;

    case DRV_SD1 :

        SD->FMICR = SD_FMICR_SD_EN_Msk;
        //status = SD_Write_in(pSD1, sector, count, (unsigned int)buff);
        status = SD_Write(SD_PORT1, (uint8_t*)buff, sector, count);

        if (status != Successful)
            return RES_ERROR;

        return RES_OK;

#endif
    }
    return RES_PARERR;
}
#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
    BYTE pdrv,      /* Physical drive nmuber (0..) */
    BYTE cmd,       /* Control code */
    void *buff      /* Buffer to send/receive control data */
)
{

    DRESULT res = RES_OK;

    switch (pdrv) {
#ifdef SUPPORT_SD
    case DRV_SD0 :
        switch(cmd) {
        case CTRL_SYNC:
            break;
        case GET_SECTOR_COUNT:
            *(DWORD*)buff = SD_DiskInfo0.totalSectorN;
            break;
        case GET_SECTOR_SIZE:
            *(WORD*)buff = SD_DiskInfo0.sectorSize;
            break;

        default:
            res = RES_PARERR;
            break;
        }
        break;

    case DRV_SD1 :
        switch(cmd) {
        case CTRL_SYNC:
            break;
        case GET_SECTOR_COUNT:
            *(DWORD*)buff = SD_DiskInfo1.totalSectorN;
            break;
        case GET_SECTOR_SIZE:
            *(WORD*)buff = SD_DiskInfo1.sectorSize;
            break;

        default:
            res = RES_PARERR;
            break;
        }
        break;
#endif

    default:
        res = RES_PARERR;
        break;

    }
    return res;
}
#endif







