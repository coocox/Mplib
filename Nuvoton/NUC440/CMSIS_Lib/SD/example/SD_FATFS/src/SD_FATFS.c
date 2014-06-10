/******************************************************************************
 * @file     SD_FATFS.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 14/01/14 10:15a $
 * @brief    SD sample program for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include <string.h>

#include "NUC400Series.h"
#include "SYS.h"
#include "CLK.h"
#include "SD.h"
#include "diskio.h"
#include <ff.h>



/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

static UINT blen = 16*1024;
volatile UINT Timer = 0;        /* Performance timer (1kHz increment) */
DWORD acc_size;             /* Work register for fs command */
WORD acc_files, acc_dirs;
FILINFO Finfo;
FATFS FatFs[_VOLUMES];      /* File system object for logical drive */
char Line[256];             /* Console input buffer */
#if _USE_LFN
char Lfname[512];
#endif
BYTE Buff[1024] ;       /* Working buffer */

BYTE SD_Drv = 0; // select SD0

void Delay(uint32_t delayCnt);
int xatoi (         /* 0:Failed, 1:Successful */
    TCHAR **str,    /* Pointer to pointer to the string */
    long *res       /* Pointer to a variable to store the value */
);
void put_dump (
    const unsigned char* buff,  /* Pointer to the byte array to be dumped */
    unsigned long addr,         /* Heading address value */
    int cnt                     /* Number of bytes to be dumped */
);
static
FRESULT scan_files (
    char* path      /* Pointer to the path name working buffer */
);
void put_rc (FRESULT rc);
void get_line (char *buff, int len);
void SYS_Init(void);
unsigned long get_fattime (void);
//extern int  SD_InitDevice(int cardSel);



uint8_t Read_Buf[1024];
uint8_t Write_Buf[1024];


int32_t SD_FATFS(void)
{
    char *ptr, *ptr2;
    long p1, p2, p3;
    BYTE *buf;
    FATFS *fs;              /* Pointer to file system object */
    FRESULT res;

    DIR dir;                /* Directory object */
    FIL file1, file2;       /* File objects */
    UINT s1, s2, cnt;
    static const BYTE ft[] = {0, 12, 16, 32};
    DWORD ofs = 0, sect = 0;

    SYS_Init();

    printf("\n\nNUC470 SD FATFS TEST!\n");
    printf("rc=%d\n", (WORD)disk_initialize(SD_Drv));
    disk_read(SD_Drv, Buff, 2, 1);
    f_mount(0, &FatFs[0]);

    for (;;) {
        printf(_T(">"));
        ptr = Line;
        get_line(ptr, sizeof(Line));
        switch (*ptr++) {

        case 'q' :  /* Exit program */
            return 0;

        case 'd' :
            switch (*ptr++) {
            case 'd' :  /* dd [<lba>] - Dump sector */
                if (!xatoi(&ptr, &p2)) p2 = sect;
                res = (FRESULT)disk_read(SD_Drv, Buff, p2, 1);
                if (res) {
                    printf("rc=%d\n", (WORD)res);
                    break;
                }
                sect = p2 + 1;
                printf("Sector:%lu\n", p2);
                for (buf=(unsigned char*)Buff, ofs = 0; ofs < 0x200; buf+=16, ofs+=16)
                    put_dump(buf, ofs, 16);
                break;

            case 'i' :  /* di - Initialize disk */
                printf("rc=%d\n", (WORD)disk_initialize(SD_Drv));
                break;


            }
            break;

        case 'b' :
            switch (*ptr++) {
            case 'd' :  /* bd <addr> - Dump R/W buffer */
                if (!xatoi(&ptr, &p1)) break;
                for (ptr=(char*)&Buff[p1], ofs = p1, cnt = 32; cnt; cnt--, ptr+=16, ofs+=16)
                    put_dump((BYTE*)ptr, ofs, 16);
                break;

            case 'e' :  /* be <addr> [<data>] ... - Edit R/W buffer */
                if (!xatoi(&ptr, &p1)) break;
                if (xatoi(&ptr, &p2)) {
                    do {
                        Buff[p1++] = (BYTE)p2;
                    } while (xatoi(&ptr, &p2));
                    break;
                }
                for (;;) {
                    printf("%04X %02X-", (WORD)p1, Buff[p1]);
                    get_line(Line, sizeof(Line));
                    ptr = Line;
                    if (*ptr == '.') break;
                    if (*ptr < ' ') {
                        p1++;
                        continue;
                    }
                    if (xatoi(&ptr, &p2))
                        Buff[p1++] = (BYTE)p2;
                    else
                        printf("???\n");
                }
                break;

            case 'r' :  /* br <sector> [<n>] - Read disk into R/W buffer */
                if (!xatoi(&ptr, &p2)) break;
                if (!xatoi(&ptr, &p3)) p3 = 1;
                printf("rc=%u\n", disk_read(SD_Drv, Buff, p2, p3));
                break;

            case 'w' :  /* bw <sector> [<n>] - Write R/W buffer into disk */
                if (!xatoi(&ptr, &p2)) break;
                if (!xatoi(&ptr, &p3)) p3 = 1;
                printf("rc=%u\n", disk_write(SD_Drv, Buff, p2, p3));
                break;

            case 'f' :  /* bf <n> - Fill working buffer */
                if (!xatoi(&ptr, &p1)) break;
                memset(Buff, (int)p1, sizeof(Buff));
                break;

            }
            break;



        case 'f' :
            switch (*ptr++) {
            case 'i' :  /* fi - Force initialized the logical drive */
                put_rc(f_mount(0, &FatFs[0]));
                break;

            case 's' :  /* fs - Show logical drive status */
                res = f_getfree("", (DWORD*)&p2, &fs);
                if (res) {
                    put_rc(res);
                    break;
                }
                printf("FAT type = FAT%u\nBytes/Cluster = %lu\nNumber of FATs = %u\n"
                       "Root DIR entries = %u\nSectors/FAT = %lu\nNumber of clusters = %lu\n"
                       "FAT start (lba) = %lu\nDIR start (lba,clustor) = %lu\nData start (lba) = %lu\n\n...",
                       ft[fs->fs_type & 3], fs->csize * 512UL, fs->n_fats,
                       fs->n_rootdir, fs->fsize, fs->n_fatent - 2,
                       fs->fatbase, fs->dirbase, fs->database
                      );
                acc_size = acc_files = acc_dirs = 0;
#if _USE_LFN
                Finfo.lfname = Lfname;
                Finfo.lfsize = sizeof(Lfname);
#endif
                res = scan_files(ptr);
                if (res) {
                    put_rc(res);
                    break;
                }
                printf("\r%u files, %lu bytes.\n%u folders.\n"
                       "%lu KB total disk space.\n%lu KB available.\n",
                       acc_files, acc_size, acc_dirs,
                       (fs->n_fatent - 2) * (fs->csize / 2), p2 * (fs->csize / 2)
                      );
                break;
            case 'l' :  /* fl [<path>] - Directory listing */
                while (*ptr == ' ') ptr++;
                res = f_opendir(&dir, ptr);
                if (res) {
                    put_rc(res);
                    break;
                }
                p1 = s1 = s2 = 0;
                for(;;) {
                    res = f_readdir(&dir, &Finfo);
                    if ((res != FR_OK) || !Finfo.fname[0]) break;
                    if (Finfo.fattrib & AM_DIR) {
                        s2++;
                    } else {
                        s1++;
                        p1 += Finfo.fsize;
                    }
                    printf("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9lu  %s",
                           (Finfo.fattrib & AM_DIR) ? 'D' : '-',
                           (Finfo.fattrib & AM_RDO) ? 'R' : '-',
                           (Finfo.fattrib & AM_HID) ? 'H' : '-',
                           (Finfo.fattrib & AM_SYS) ? 'S' : '-',
                           (Finfo.fattrib & AM_ARC) ? 'A' : '-',
                           (Finfo.fdate >> 9) + 1980, (Finfo.fdate >> 5) & 15, Finfo.fdate & 31,
                           (Finfo.ftime >> 11), (Finfo.ftime >> 5) & 63, Finfo.fsize, Finfo.fname);
#if _USE_LFN
                    for (p2 = strlen(Finfo.fname); p2 < 14; p2++)
                        putchar(' ');
                    printf("%s\n", Lfname);
#else
                    putchar('\n');
#endif
                }
                printf("%4u File(s),%10lu bytes total\n%4u Dir(s)", s1, p1, s2);
                if (f_getfree(ptr, (DWORD*)&p1, &fs) == FR_OK)
                    printf(", %10lu bytes free\n", p1 * fs->csize * 512);
                break;


            case 'o' :  /* fo <mode> <file> - Open a file */
                if (!xatoi(&ptr, &p1)) break;
                while (*ptr == ' ') ptr++;
                put_rc(f_open(&file1, ptr, (BYTE)p1));
                break;

            case 'c' :  /* fc - Close a file */
                put_rc(f_close(&file1));
                break;

            case 'e' :  /* fe - Seek file pointer */
                if (!xatoi(&ptr, &p1)) break;
                res = f_lseek(&file1, p1);
                put_rc(res);
                if (res == FR_OK)
                    printf("fptr=%lu(0x%lX)\n", file1.fptr, file1.fptr);
                break;

            case 'd' :  /* fd <len> - read and dump file from current fp */
                if (!xatoi(&ptr, &p1)) break;
                ofs = file1.fptr;
                while (p1) {
                    if ((UINT)p1 >= 16) {
                        cnt = 16;
                        p1 -= 16;
                    } else                {
                        cnt = p1;
                        p1 = 0;
                    }
                    res = f_read(&file1, Buff, cnt, &cnt);
                    if (res != FR_OK) {
                        put_rc(res);
                        break;
                    }
                    if (!cnt) break;
                    put_dump(Buff, ofs, cnt);
                    ofs += 16;
                }
                break;

            case 'r' :  /* fr <len> - read file */
                if (!xatoi(&ptr, &p1)) break;
                p2 = 0;
                Timer = 0;
                while (p1) {
                    if ((UINT)p1 >= blen) {
                        cnt = blen;
                        p1 -= blen;
                    } else {
                        cnt = p1;
                        p1 = 0;
                    }
                    res = f_read(&file1, Buff, cnt, &s2);
                    if (res != FR_OK) {
                        put_rc(res);
                        break;
                    }
                    p2 += s2;
                    if (cnt != s2) break;
                }
                printf("%lu bytes read with %lu kB/sec.\n", p2, p2 / Timer);
                break;

            case 'w' :  /* fw <len> <val> - write file */
                if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2)) break;
                //memset(Buff, (BYTE)p2, blen);
                memset(Buff, (BYTE)p2, sizeof(Buff));
                p2 = 0;
                Timer = 0;
                while (p1) {
                    if ((UINT)p1 >= blen) {
                        cnt = blen;
                        p1 -= blen;
                    } else {
                        cnt = p1;
                        p1 = 0;
                    }
                    res = f_write(&file1, Buff, cnt, &s2);
                    if (res != FR_OK) {
                        put_rc(res);
                        break;
                    }
                    p2 += s2;
                    if (cnt != s2) break;
                }
                printf("%lu bytes written with %lu kB/sec.\n", p2, p2 / Timer);
                break;

            case 'n' :  /* fn <old_name> <new_name> - Change file/dir name */
                while (*ptr == ' ') ptr++;
                ptr2 = strchr(ptr, ' ');
                if (!ptr2) break;
                *ptr2++ = 0;
                while (*ptr2 == ' ') ptr2++;
                put_rc(f_rename(ptr, ptr2));
                break;

            case 'u' :  /* fu <name> - Unlink a file or dir */
                while (*ptr == ' ') ptr++;
                put_rc(f_unlink(ptr));
                break;

            case 'v' :  /* fv - Truncate file */
                put_rc(f_truncate(&file1));
                break;

            case 'k' :  /* fk <name> - Create a directory */
                while (*ptr == ' ') ptr++;
                put_rc(f_mkdir(ptr));
                break;

            case 'a' :  /* fa <atrr> <mask> <name> - Change file/dir attribute */
                if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2)) break;
                while (*ptr == ' ') ptr++;
                put_rc(f_chmod(ptr, p1, p2));
                break;

            case 't' :  /* ft <year> <month> <day> <hour> <min> <sec> <name> - Change timestamp */
                if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
                Finfo.fdate = (WORD)(((p1 - 1980) << 9) | ((p2 & 15) << 5) | (p3 & 31));
                if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
                Finfo.ftime = (WORD)(((p1 & 31) << 11) | ((p1 & 63) << 5) | ((p1 >> 1) & 31));
                put_rc(f_utime(ptr, &Finfo));
                break;

            case 'x' : /* fx <src_name> <dst_name> - Copy file */
                while (*ptr == ' ') ptr++;
                ptr2 = strchr(ptr, ' ');
                if (!ptr2) break;
                *ptr2++ = 0;
                while (*ptr2 == ' ') ptr2++;
                printf("Opening \"%s\"", ptr);
                res = f_open(&file1, ptr, FA_OPEN_EXISTING | FA_READ);
                putchar('\n');
                if (res) {
                    put_rc(res);
                    break;
                }
                printf("Creating \"%s\"", ptr2);
                res = f_open(&file2, ptr2, FA_CREATE_ALWAYS | FA_WRITE);
                putchar('\n');
                if (res) {
                    put_rc(res);
                    f_close(&file1);
                    break;
                }
                printf("Copying...");
                p1 = 0;
                for (;;) {
                    res = f_read(&file1, Buff, sizeof(Buff), &s1);
                    if (res || s1 == 0) break;   /* error or eof */
                    res = f_write(&file2, Buff, s1, &s2);
                    p1 += s2;
                    if (res || s2 < s1) break;   /* error or disk full */
                }
                printf("\n%lu bytes copied.\n", p1);
                f_close(&file1);
                f_close(&file2);
                break;
#if _FS_RPATH
            case 'g' :  /* fg <path> - Change current directory */
                while (*ptr == ' ') ptr++;
                put_rc(f_chdir(ptr));
                break;

            case 'j' :  /* fj <drive#> - Change current drive */
                if (xatoi(&ptr, &p1)) {
                    put_rc(f_chdrive((BYTE)p1));
                }
                break;
#endif
#if _USE_MKFS
            case 'm' :  /* fm <partition rule> <sect/clust> - Create file system */
                if (!xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
                printf("The memory card will be formatted. Are you sure? (Y/n)=");
                get_line(ptr, sizeof(Line));
                if (*ptr == 'Y')
                    put_rc(f_mkfs(0, (BYTE)p2, (WORD)p3));
                break;
#endif
            case 'z' :  /* fz [<rw size>] - Change R/W length for fr/fw/fx command */
                if (xatoi(&ptr, &p1) && p1 >= 1 && (size_t)p1 <= sizeof(Buff))
                    blen = p1;
                printf("blen=%u\n", blen);
                break;
            }
            break;
        case '?':       /* Show usage */
            printf(
                _T("dd [<lba>] - Dump sector\n")
                _T("di - Initialize disk\n")
                //_T("ds <pd#> - Show disk status\n")
                _T("\n")
                _T("bd <ofs> - Dump working buffer\n")
                _T("be <ofs> [<data>] ... - Edit working buffer\n")
                _T("br <pd#> <sect> [<num>] - Read disk into working buffer\n")
                _T("bw <pd#> <sect> [<num>] - Write working buffer into disk\n")
                _T("bf <val> - Fill working buffer\n")
                _T("\n")
                _T("fi - Force initialized the logical drive\n")
                _T("fs - Show volume status\n")
                _T("fl [<path>] - Show a directory\n")
                _T("fo <mode> <file> - Open a file\n")
                _T("fc - Close the file\n")
                _T("fe <ofs> - Move fp in normal seek\n")
                //_T("fE <ofs> - Move fp in fast seek or Create link table\n")
                _T("fd <len> - Read and dump the file\n")
                _T("fr <len> - Read the file\n")
                _T("fw <len> <val> - Write to the file\n")
                _T("fn <object name> <new name> - Rename an object\n")
                _T("fu <object name> - Unlink an object\n")
                _T("fv - Truncate the file at current fp\n")
                _T("fk <dir name> - Create a directory\n")
                _T("fa <atrr> <mask> <object name> - Change object attribute\n")
                _T("ft <year> <month> <day> <hour> <min> <sec> <object name> - Change timestamp of an object\n")
                _T("fx <src file> <dst file> - Copy a file\n")
                _T("fg <path> - Change current directory\n")
                _T("fj <ld#> - Change current drive\n")
                _T("fm <ld#> <rule> <cluster size> - Create file system\n")
                _T("\n")
            );
            break;
        }
    }

}


void Delay(uint32_t delayCnt)
{
    while(delayCnt--) {
        __NOP();
        __NOP();
    }
}


/*--------------------------------------------------------------------------*/
/* Monitor                                                                  */

/*----------------------------------------------*/
/* Get a value of the string                    */
/*----------------------------------------------*/
/*  "123 -5   0x3ff 0b1111 0377  w "
        ^                           1st call returns 123 and next ptr
           ^                        2nd call returns -5 and next ptr
                   ^                3rd call returns 1023 and next ptr
                          ^         4th call returns 15 and next ptr
                               ^    5th call returns 255 and next ptr
                                  ^ 6th call fails and returns 0
*/

int xatoi (         /* 0:Failed, 1:Successful */
    TCHAR **str,    /* Pointer to pointer to the string */
    long *res       /* Pointer to a variable to store the value */
)
{
    unsigned long val;
    unsigned char r, s = 0;
    TCHAR c;


    *res = 0;
    while ((c = **str) == ' ') (*str)++;    /* Skip leading spaces */

    if (c == '-') {     /* negative? */
        s = 1;
        c = *(++(*str));
    }

    if (c == '0') {
        c = *(++(*str));
        switch (c) {
        case 'x':       /* hexadecimal */
            r = 16;
            c = *(++(*str));
            break;
        case 'b':       /* binary */
            r = 2;
            c = *(++(*str));
            break;
        default:
            if (c <= ' ') return 1; /* single zero */
            if (c < '0' || c > '9') return 0;   /* invalid char */
            r = 8;      /* octal */
        }
    } else {
        if (c < '0' || c > '9') return 0;   /* EOL or invalid char */
        r = 10;         /* decimal */
    }

    val = 0;
    while (c > ' ') {
        if (c >= 'a') c -= 0x20;
        c -= '0';
        if (c >= 17) {
            c -= 7;
            if (c <= 9) return 0;   /* invalid char */
        }
        if (c >= r) return 0;       /* invalid char for current radix */
        val = val * r + c;
        c = *(++(*str));
    }
    if (s) val = 0 - val;           /* apply sign if needed */

    *res = val;
    return 1;
}


/*----------------------------------------------*/
/* Dump a block of byte array                   */

void put_dump (
    const unsigned char* buff,  /* Pointer to the byte array to be dumped */
    unsigned long addr,         /* Heading address value */
    int cnt                     /* Number of bytes to be dumped */
)
{
    int i;


    printf(_T("%08lX "), addr);

    for (i = 0; i < cnt; i++)
        printf(_T(" %02X"), buff[i]);

    putchar(' ');
    for (i = 0; i < cnt; i++)
        putchar((TCHAR)((buff[i] >= ' ' && buff[i] <= '~') ? buff[i] : '.'));

    putchar('\n');
}


/*--------------------------------------------------------------------------*/
/* Monitor                                                                  */
/*--------------------------------------------------------------------------*/

static
FRESULT scan_files (
    char* path      /* Pointer to the path name working buffer */
)
{
    DIR dirs;
    FRESULT res;
    BYTE i;
    char *fn;


    if ((res = f_opendir(&dirs, path)) == FR_OK) {
        i = strlen(path);
        while (((res = f_readdir(&dirs, &Finfo)) == FR_OK) && Finfo.fname[0]) {
            if (_FS_RPATH && Finfo.fname[0] == '.') continue;
#if _USE_LFN
            fn = *Finfo.lfname ? Finfo.lfname : Finfo.fname;
#else
            fn = Finfo.fname;
#endif
            if (Finfo.fattrib & AM_DIR) {
                acc_dirs++;
                *(path+i) = '/';
                strcpy(path+i+1, fn);
                res = scan_files(path);
                *(path+i) = '\0';
                if (res != FR_OK) break;
            } else {
                /*              printf("%s/%s\n", path, fn); */
                acc_files++;
                acc_size += Finfo.fsize;
            }
        }
    }

    return res;
}



void put_rc (FRESULT rc)
{
    const TCHAR *p =
        _T("OK\0DISK_ERR\0INT_ERR\0NOT_READY\0NO_FILE\0NO_PATH\0INVALID_NAME\0")
        _T("DENIED\0EXIST\0INVALID_OBJECT\0WRITE_PROTECTED\0INVALID_DRIVE\0")
        _T("NOT_ENABLED\0NO_FILE_SYSTEM\0MKFS_ABORTED\0TIMEOUT\0LOCKED\0")
        _T("NOT_ENOUGH_CORE\0TOO_MANY_OPEN_FILES\0");

    uint32_t i;
    for (i = 0; (i != (UINT)rc) && *p; i++) {
        while(*p++) ;
    }
    printf(_T("rc=%u FR_%s\n"), (UINT)rc, p);
}

/*----------------------------------------------*/
/* Get a line from the input                    */
/*----------------------------------------------*/

void get_line (char *buff, int len)
{
    TCHAR c;
    int idx = 0;



    for (;;) {
        c = getchar();
        putchar(c);
        if (c == '\r') break;
        if ((c == '\b') && idx) idx--;
        if ((c >= ' ') && (idx < len - 1)) buff[idx++] = c;
    }
    buff[idx] = 0;

    putchar('\n');

}


#ifdef _SD_USE_INT_
extern void SD_Close_(uint32_t cardSel);

void SD0_Handler(void)
{
    unsigned int volatile isr;
    unsigned int volatile ier;

    // FMI data abort interrupt
    if (SD->FMIISR & SD_FMIISR_DTA_IE_Msk) {
        /* ResetAllEngine() */
        SD->FMICR |= SD_FMICR_SW_RST_Msk;
        SD->FMIISR = SD_FMIISR_DTA_IE_Msk;
    }

    //----- SD interrupt status
    isr = SD->SDISR;
    if (isr & SD_SDISR_BLKD_IF_Msk) {   // block down
        extern uint8_t volatile _sd_SDDataReady;
        _sd_SDDataReady = TRUE;
        SD->SDISR = SD_SDISR_BLKD_IF_Msk;
    }

    if (isr & SD_SDISR_CD0_IF_Msk) { // port 0 card detect
        //----- SD interrupt status
        // it is work to delay 50 times for SD_CLK = 200KHz
        {
            volatile int i;         // delay 30 fail, 50 OK
            for (i=0; i<500; i++);  // delay to make sure got updated value from REG_SDISR.
            isr = SD->SDISR;
        }

#ifdef _USE_DAT3_DETECT_
        if (!(isr & SD_SDISR_CDPS0_Msk)) {
            SD0.IsCardInsert = FALSE;
            SD_Close_(0);
        } else {
            disk_initialize(SD_Drv);
        }
#else
        if (isr & SD_SDISR_CDPS0_Msk) {
            SD0.IsCardInsert = FALSE;   // SDISR_CD_Card = 1 means card remove for GPIO mode
            SD_Close_(0);
        } else {
            disk_initialize(SD_Drv);
        }
#endif

        SD->SDISR = SD_SDISR_CD0_IF_Msk;
    }

    // CRC error interrupt
    if (isr & SD_SDISR_CRC_IF_Msk) {
        if (!(isr & SD_SDISR_CRC_16_Msk)) {
            //printf("***** ISR sdioIntHandler(): CRC_16 error !\n");
            // handle CRC error
        } else if (!(isr & SD_SDISR_CRC_7_Msk)) {
            extern uint32_t _sd_uR3_CMD;
            if (! _sd_uR3_CMD) {
                //printf("***** ISR sdioIntHandler(): CRC_7 error !\n");
                // handle CRC error
            }
        }
        SD->SDISR = SD_SDISR_CRC_IF_Msk;      // clear interrupt flag
    }


}


void SD_IRQHandler(void)
{

    if( ((SD->SDCR & SD_SDCR_SDPORT_Msk) >> (SD_SDCR_SDPORT_Pos)) == 0 ) {
        SD0_Handler();
    } else if( ((SD->SDCR & SD_SDCR_SDPORT_Msk) >> (SD_SDCR_SDPORT_Pos)) == 1 ) {
        //SD1_Handler();
    }

}
#endif

void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();


    CLK->PWRCON |= CLK_PWRCON_HXT_EN_Msk;

    // init_pll 84M Hz
    CLK->PLLCON = 0x401a;   // 84 MHz
    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(CLK_CLKSEL0_HCLK_S_Msk)) | (0x2 << CLK_CLKSEL0_HCLK_S_Pos);


    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(CLK_CLKSEL0_SDHOST_S_Msk)); // SD clock from XTL(12MHz)


    SYS->GPF_MFPL = (SYS->GPF_MFPL & ~(SYS_GPF_MFPL_PF2_MFP_Msk)) | (0x4 << SYS_GPF_MFPL_PF2_MFP_Pos); // SD0_CD: GPE_5
    SYS->GPF_MFPL = (SYS->GPF_MFPL & ~(SYS_GPF_MFPL_PF3_MFP_Msk)) | (0x4 << SYS_GPF_MFPL_PF3_MFP_Pos); // SD0_CMD: GPE_6
    SYS->GPF_MFPL = (SYS->GPF_MFPL & ~(SYS_GPF_MFPL_PF4_MFP_Msk)) | (0x4 << SYS_GPF_MFPL_PF4_MFP_Pos); // SD0_CLK: GPE_7
    SYS->GPF_MFPL = (SYS->GPF_MFPL & ~(SYS_GPF_MFPL_PF5_MFP_Msk)) | (0x4 << SYS_GPF_MFPL_PF5_MFP_Pos); // SD0_DAT3: GPE_8
    SYS->GPF_MFPL = (SYS->GPF_MFPL & ~(SYS_GPF_MFPL_PF6_MFP_Msk)) | (0x4 << SYS_GPF_MFPL_PF6_MFP_Pos); // SD0_DAT2: GPE_9
    SYS->GPF_MFPL = (SYS->GPF_MFPL & ~(SYS_GPF_MFPL_PF7_MFP_Msk))| (0x4 << SYS_GPF_MFPL_PF7_MFP_Pos); // SD0_DAT1: GPE_10
    SYS->GPF_MFPH = (SYS->GPF_MFPH & ~(SYS_GPF_MFPH_PF8_MFP_Msk))| (0x4 << SYS_GPF_MFPH_PF8_MFP_Pos); // SD0_DAT0: GPE_11


    /* Enable IP clock */
    CLK->APBCLK0 |= CLK_APBCLK0_UART0_EN_Msk; // UART0 Clock Enable

    /* Select IP clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_UART_S_Pos);// Clock source from external 12 MHz or 32 KHz crystal clock

    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();

    /* Set PG multi-function pins for UART0 RXD, TXD */
    SYS->GPG_MFPL &= ~(SYS_GPG_MFPL_PG1_MFP_Msk | SYS_GPG_MFPL_PG2_MFP_Msk);
    SYS->GPG_MFPL |= (SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD);


    UART0->LCR |=0x07;
    UART0->BAUD = 0x30000067; /* 12MHz reference clock input, for 115200 */


    /* Lock protected registers */
    SYS_LockReg();

}


/*---------------------------------------------------------*/
/* User Provided RTC Function for FatFs module             */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support an RTC.                     */
/* This function is not required in read-only cfg.         */

unsigned long get_fattime (void)
{
    unsigned long tmr;

    tmr=0x00000;

    return tmr;
}
/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
