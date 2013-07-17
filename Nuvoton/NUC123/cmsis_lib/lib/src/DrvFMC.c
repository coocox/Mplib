/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2010 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "NUC123Series.h"
#include "FMC.h"
#include "CLOCK.h"
#include "SYS.h"

#define E_DRVFMC_ERR_ISP_FAIL   0xFFFF0010

/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvFMC_FUNC FMC Driver API
  * @{
  */
  
/**
 * @brief      Program 32-bit data into specified address of flash
 * 
 * @param[in]  u32addr  Flash address include APROM, LDROM, Data Flash, and CONFIG
 * @param[in]  u32data  32-bit Data to program
 *
 * @details    To program word data into Flash include APROM, LDROM, Data Flash, and CONFIG.
 *             The corresponding functions in CONFIG are listed in FMC section of TRM.
 *
 * @note   
 *             Please make sure that Register Write-Protection Function has been disabled 
 */
int32_t DrvFMC_Write(uint32_t u32addr, uint32_t u32data)
{
    FMC_SET_COMMAND(FMC_ISPCMD_PROGRAM);
    FMC_SET_ADDRESS(u32addr);
    FMC_SET_DATA(u32data);
    FMC_SET_ISPTRG_GO();
    __ISB();
    while (FMC_GET_ISPTRG_GO());

    if (FMC_READ_FAIL_FLAG())
    {
        FMC_CLEAR_FAIL_FLAG();
        return E_DRVFMC_ERR_ISP_FAIL;
    }
	
    return 0;
}

/**
 * @brief       Read 32-bit Data from specified address of flash
 * 
 * @param[in]   u32addr  Flash address include APROM, LDROM, Data Flash, and CONFIG
 * @param[out]  u32data  32-bit Data Buffer
 *
 * @return      E_DRVFMC_ERR_ISP_FAIL if error; else return 0
 *
 * @details     To read word data from Flash include APROM, LDROM, Data Flash, and CONFIG.
 *
 * @note   
 *              Please make sure that Register Write-Protection Function has been disabled 
 */
int32_t DrvFMC_Read(uint32_t u32addr, uint32_t * u32data)
{ 
    FMC_SET_COMMAND(FMC_ISPCMD_READ);
    FMC_SET_ADDRESS(u32addr);
    FMC_SET_DATA(0);
    FMC_SET_ISPTRG_GO();
    __ISB();
    while (FMC_GET_ISPTRG_GO());

    if (FMC_READ_FAIL_FLAG())
    {
        FMC_CLEAR_FAIL_FLAG();
        return E_DRVFMC_ERR_ISP_FAIL;
    }
    
    *u32data = FMC_GET_DATA(); 
    return 0;
}

/**
 * @brief      Flash page erase
 * 
 * @param[in]  u32addr  Flash address including APROM, LDROM, Data Flash, and CONFIG
 *
 * @details    To do flash page erase. The target address could be APROM, LDROM, Data Flash, or CONFIG. 
 *             The page size is 512 bytes.
 *
 * @note   
 *             Please make sure that Register Write-Protection Function has been disabled 
 */
int32_t DrvFMC_Erase(uint32_t u32addr)
{
    FMC_SET_COMMAND(FMC_ISPCMD_PAGE_ERASE);
    FMC_SET_ADDRESS(u32addr);
    FMC_SET_ISPTRG_GO();
    __ISB();
    while (FMC_GET_ISPTRG_GO());

    if (FMC_READ_FAIL_FLAG())
    {
        FMC_CLEAR_FAIL_FLAG();
        return E_DRVFMC_ERR_ISP_FAIL;
    }
	
    return 0;
}


/**
 * @brief       Read Unique ID
 * 
 * @param[in]   index  UID index. 0 = UID[0:31], 1 = UID[32:63], 2 = UID[64:95]
 * @param[out]  u32data  32-bit Data Buffer
 *
 * @return      The 32-bit unique ID data of specified UID index
 *
 * @details     To read out 96-bit Unique ID.
 *
 * @note   
 *              Please make sure that Register Write-Protection Function has been disabled 
 */
int32_t DrvFMC_ReadUID(int index, uint32_t * u32data)
{
    FMC_SET_COMMAND(FMC_ISPCMD_READ_UID);
    FMC_SET_ADDRESS(index << 2);
    FMC_SET_DATA(0);
    FMC_SET_ISPTRG_GO();
    __ISB();
    while (FMC_GET_ISPTRG_GO());

    if (FMC_READ_FAIL_FLAG())
    {
        FMC_CLEAR_FAIL_FLAG();
        return E_DRVFMC_ERR_ISP_FAIL;
    }
    
    *u32data = FMC_GET_DATA(); 
    return 0;
}

/*@}*/ /* end of group DrvFMC_FUNC */
/*@}*/ /* end of group NUC123_FUNC */
