/**************************************************************************//**
 * @file     fmc.c
 * @version  V1.10
 * $Revision: 5 $
 * $Date: 13/11/10 9:32a $
 * @brief    NUC400 FMC driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

//* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "fmc.h"


/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_FMC_Driver FMC Driver
  @{
*/


/** @addtogroup NUC400_FMC_EXPORTED_FUNCTIONS FMC Exported Functions
  @{
*/


/**
  * @brief    Set boot source of next software reset
  * @param    i32BootSrc     1: will boot from LDROM; 0: will boot from APROM
  * @retval   None
  */
void FMC_SetBootSource (int32_t i32BootSrc)
{
    if (i32BootSrc == 1)
        FMC->ISPCON |= FMC_ISPCON_BS_Msk;
    else
        FMC->ISPCON &= ~FMC_ISPCON_BS_Msk;
}


/**
  * @brief    Disable all FMC functions
  */
void FMC_Close(void)
{
    FMC->ISPCON &= ~FMC_ISPCON_ISPEN_Msk;
}


/**
  * @brief    Disable APROM update function
  */
void FMC_DisableAPUpdate(void)
{
    FMC->ISPCON &= ~FMC_ISPCON_APUEN_Msk;
}


/**
  * @brief    Disable User Configuration update function
  */
void FMC_DisableConfigUpdate(void)
{
    FMC->ISPCON &= ~FMC_ISPCON_CFGUEN_Msk;
}


/**
  * @brief    Disable LDROM update function
  */
void FMC_DisableLDUpdate(void)
{
    FMC->ISPCON &= ~FMC_ISPCON_LDUEN_Msk;
}


/**
  * @brief    Enable APROM update function
  */
void FMC_EnableAPUpdate(void)
{
    FMC->ISPCON |= FMC_ISPCON_APUEN_Msk;
}


/**
  * @brief    Enable User Configuration update function
  */
void FMC_EnableConfigUpdate(void)
{
    FMC->ISPCON |= FMC_ISPCON_CFGUEN_Msk;
}


/**
  * @brief    Enable LDROM update function
  */
void FMC_EnableLDUpdate(void)
{
    FMC->ISPCON |= FMC_ISPCON_LDUEN_Msk;
}


/**
  * @brief    Erase a page. The page size is 512 bytes.
  * @param    u32PageAddr: Flash page address. Must be a 512-byte aligned address.
  * @retval   0: Success
  * @retval   -1: Erase failed
  */
int32_t FMC_Erase(uint32_t u32PageAddr)
{
    FMC->ISPCMD = FMC_ISPCMD_PAGE_ERASE;
    FMC->ISPADR = u32PageAddr;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;

    if (FMC->ISPCON & FMC_ISPCON_ISPFF_Msk) {
        FMC->ISPCON = FMC_ISPCON_ISPFF_Msk;
        return -1;
    }
    return 0;
}


/**
  * @brief    get the current boot source
  * @retval   0: This chip is currently booting from APROM
  * @retval   1: This chip is currently booting from LDROM
  */
int32_t FMC_GetBootSource (void)
{
    if (FMC->ISPCON & FMC_ISPCON_BS_Msk)
        return 1;
    else
        return 0;
}


/**
  * @brief    Enable FMC ISP function
  */
void FMC_Open(void)
{
    FMC->ISPCON |=  FMC_ISPCON_ISPEN_Msk;
}


/**
  * @brief    Read a word from specified flash address.
  * @param    u32Addr: Flash word address. Must be a word aligned address.
  * @retval   The word data stored in the flash address "u32Addr".
  */
uint32_t FMC_Read(uint32_t u32Addr)
{
    FMC->ISPCMD = FMC_ISPCMD_READ;
    FMC->ISPADR = u32Addr;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;

    return FMC->ISPDAT;
}


/**
  * @brief    Read two word from specified flash address.
  * @param    u32Addr:  Flash word address. Must be a double word aligned address.
  * @param    u32Data0: The first word output.
  * @param    u32Data1: The second word output.
  * @retval   None
  */
void FMC_Read_64(uint32_t u32Addr, uint32_t *u32Data0, uint32_t *u32Data1)
{
    FMC->ISPCMD = FMC_ISPCMD_READ_64;
    FMC->ISPADR = u32Addr;
    FMC->ISPDAT = 0x0;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

    while (FMC->ISPSTA & FMC_ISPSTA_ISPGO_Msk) ;

    *u32Data0 = FMC->ISPDAT0;
    *u32Data1 = FMC->ISPDAT1;
}


/**
  * @brief    Read company ID.
  * @retval   The company ID.
  */
uint32_t FMC_ReadCID(void)
{
    FMC->ISPCMD = FMC_ISPCMD_READ_CID;
    FMC->ISPADR = 0x0;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;
    return FMC->ISPDAT;
}


/**
  * @brief    Read device ID.
  * @retval   The device ID.
  */
uint32_t FMC_ReadDID(void)
{
    FMC->ISPCMD = FMC_ISPCMD_READ_DID;
    FMC->ISPADR = 0;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;
    return FMC->ISPDAT;
}


/**
  * @brief    Read product ID.
  * @retval   The product ID.
  */
uint32_t FMC_ReadPID(void)
{
    FMC->ISPCMD = FMC_ISPCMD_READ_DID;
    FMC->ISPADR = 0x04;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;
    return FMC->ISPDAT;
}


/**
  * @brief    This function reads one of the four UCID.
  * @param    u32Index: index of the UCID to read. u32Index must be 0, 1, 2, or 3.
  * @retval   The UCID.
  */
uint32_t FMC_ReadUCID(uint32_t u32Index)
{
    FMC->ISPCMD = FMC_ISPCMD_READ_UID;
    FMC->ISPADR = (0x04 * u32Index) + 0x10;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;

    return FMC->ISPDAT;
}


/**
  * @brief    This function reads one of the three UID.
  * @param    u32Index: index of the UID to read. u32Index must be 0, 1, or 2.
  * @retval   The UID.
  */
uint32_t FMC_ReadUID(uint32_t u32Index)
{
    FMC->ISPCMD = FMC_ISPCMD_READ_UID;
    FMC->ISPADR = 0x04 * u32Index;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;

    return FMC->ISPDAT;
}


/**
  * @brief    Get the base address of Data Flash if enabled.
  * @retval   The base address of Data Flash
  */
uint32_t FMC_ReadDataFlashBaseAddr(void)
{
    return FMC->DFBADR;
}


/**
  * @brief    This function will force re-map assigned flash page to CPU address 0x0.
  * @param    u32PageAddr:  address of the page to be mapped to CPU address 0x0.
  */
void FMC_SetVectorPageAddr(uint32_t u32PageAddr)
{
    FMC->ISPCMD = FMC_ISPCMD_VECMAP;
    FMC->ISPADR = u32PageAddr;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;
}


/**
  * @brief    Writes a word data to specified flash address.
  * @param    u32Addr: destination address
  * @param    u32Data: word data to be written
  */
void FMC_Write(uint32_t u32Addr, uint32_t u32Data)
{
    FMC->ISPCMD = FMC_ISPCMD_WRITE;
    FMC->ISPADR = u32Addr;
    FMC->ISPDAT = u32Data;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;
}


/**
  * @brief    Write two word data to specified flash address.
  * @param    u32Addr:  Destination address. It must be double word aligned.
  * @param    u32Data0: First word data to be written.
  * @param    u32Data1: Second word data to be written.
  */
void FMC_Write_64(uint32_t u32Addr, uint32_t u32Data0, uint32_t u32Data1)
{
    FMC->ISPCMD = FMC_ISPCMD_WRITE_64;
    FMC->ISPADR = u32Addr;
    FMC->ISPDAT0 = u32Data0;
    FMC->ISPDAT1 = u32Data0;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
    while (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) ;
}


/**
  * @brief        CRC8 Calculator
  * @param[in]    au32Data:  CRC8 input data words.
  * @param[in]    i32Count:  Number of words in au32Data[].
  * @retval       The CRC8 value.
  */
uint32_t FMC_CRC8(uint32_t au32Data[], int i32Count)
{
    int         i32ByteIdx;
    uint8_t     i, u8Cnt, u8InData;
    uint8_t     au8CRC[4] = { 0xff, 0xff, 0xff, 0xff };

    for (i32ByteIdx = 0; i32ByteIdx < 4; i32ByteIdx++) {
        for (u8Cnt = 0; u8Cnt < i32Count; u8Cnt++) {
            for (i = 0x80; i != 0; i /= 2) {
                if ((au8CRC[i32ByteIdx] & 0x80)!=0) {
                    au8CRC[i32ByteIdx] *= 2;
                    au8CRC[i32ByteIdx] ^= 7;
                } else
                    au8CRC[i32ByteIdx] *= 2;

                u8InData = (au32Data[u8Cnt] >> (i32ByteIdx * 8)) & 0xff;

                if ((u8InData & i) != 0)
                    au8CRC[i32ByteIdx]^=0x7;
            }
        }
    }
    return (au8CRC[0] | au8CRC[1] << 8 | au8CRC[2] << 16 | au8CRC[3] << 24);
}


/**
  * @brief    Read the User Configuration words.
  * @param    u32Config: The word array to store data.
  * @param    u32Count: Maximum length of "u32Config".
  * @retval   0:  Success
  * @retval   -1: User Configuration CRC check error
  */
int32_t FMC_ReadConfig(uint32_t *u32Config, uint32_t u32Count)
{
    int         i;

    for (i = 0; i < u32Count; i++) {
        u32Config[i] = FMC_Read(FMC_CONFIG_BASE + i*4);
    }

    if (FMC->ISPSTA & FMC_ISPSTA_CFGCRCF_Msk)
        return -1;

    return 0;
}


/**
  * @brief    Write User Configuration
  * @param    u32Config: The word array to store data. MUST be a four word array.
  * @param    u32Count: MUST be 4.
  * @retval   0:  Success
  * @retval   -1: Failed
  */
int32_t FMC_WriteConfig(uint32_t *u32Config, uint32_t u32Count)
{
    uint32_t  i, u32CRC, u32Data;

    FMC_Erase(FMC_CONFIG_BASE);

    u32CRC = FMC_CRC8(u32Config, 3);

    for (i = 0; i < 4; i++) {
        FMC_Write(FMC_CONFIG_BASE + i * 4, (i < 3) ? u32Config[i] : u32CRC);
    }

    for (i = 0; i < 4; i++) {
        u32Data = FMC_Read(FMC_CONFIG_BASE + i * 4);

        if (u32Data != ((i < 3) ? u32Config[i] : u32CRC))
            return -1;
    }
    return 0;
}


/*@}*/ /* end of group NUC400_FMC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_FMC_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/


