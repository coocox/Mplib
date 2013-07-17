/**************************************************************************//**
 * @file     FMC.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/24 1:45p $
 * @brief    NUC123 Series Flash Memory Controller Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __FMC_H__
#define __FMC_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup FMC_MACRO FMC Macro
  * @{
  */

/** @addtogroup FMC_MACRO_CONTANT FMC Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/* FMC ISPCON constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define FMC_ISPCON_ISPFF         (1ul << FMC_ISPCON_ISPFF_Pos)	  /*!< ISP Fail Flag (Write-protection Bit)       */
#define FMC_ISPCON_LDUEN         (1ul << FMC_ISPCON_LDUEN_Pos)	  /*!< LDROM Update Enable (Write-protection Bit)      */
#define FMC_ISPCON_CFGUEN        (1ul << FMC_ISPCON_CFGUEN_Pos)	  /*!< Enable Config-bits Update by ISP (Write-protection Bit)      */
#define FMC_ISPCON_APUEN         (1ul << FMC_ISPCON_APUEN_Pos)	  /*!< APROM Update Enable (Write-protection Bit)  */
#define FMC_ISPCON_BS            (1ul << FMC_ISPCON_BS_Pos)		  /*!< Boot Select (Write-protection Bit)       */
#define FMC_ISPCON_ISPEN         (1ul << FMC_ISPCON_ISPEN_Pos)	  /*!< ISP Enable (Write-protection Bit)      */
/*---------------------------------------------------------------------------------------------------------*/
/* FMC ISPCMD constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define FMC_ISPCMD_READ        0x00     /*!< ISP Command: Read Flash       */
#define FMC_ISPCMD_PROGRAM     0x21     /*!< ISP Command: Program Flash    */
#define FMC_ISPCMD_PAGE_ERASE  0x22     /*!< ISP Command: Page Erase Flash */
#define FMC_ISPCMD_READ_UID    0x04     /*!< ISP Command: Read Unique ID   */
/*---------------------------------------------------------------------------------------------------------*/
/* FMC ISPTRG constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define FMC_ISPTRG_GO         (1ul << FMC_ISPTRG_ISPGO_Pos)	  /*!< ISP Start Trigger     */
/*---------------------------------------------------------------------------------------------------------*/
/* FMC FATCON constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define FMC_FATCON_MFOM         (1ul << FMC_FATCON_MFOM_Pos)   /*!< Middle Frequency Optimization Mode (Write-protection Bit)     */
#define FMC_FATCON_LFOM         (1ul << FMC_FATCON_LFOM_Pos)   /*!< Low Frequency Optimization Mode (Write-protection Bit)   */

/*@}*/ /* end of group FMC_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup FMC_MACRO_FUNC FMC Macro Func
  @{
*/
   
/**
 * @brief      ISP Fail Flag 
 *
 * @param[in]  None
 *
 * @retval     0 =  ISP Succeed  
 * @retval     !0 =  ISP Fail   
 *                                                           
 * @details    Read ISP Fail Flag .\n                                              
 *             Example: FMC_READ_ISPFF()
 *
 */  
static __INLINE uint8_t FMC_READ_FAIL_FLAG(void)
{
    return (FMC->ISPCON & FMC_ISPCON_ISPFF_Msk);
}
/**
 * @brief      ISP Fail Flag 
 *
 * @param[in]  None
 *
 * @return     None 
 *                                                           
 * @details    Clear ISP Fail Flag .\n                                              
 *             Example: FMC_CLEAR_ISPFF()
 *
 */  
static __INLINE void FMC_CLEAR_FAIL_FLAG(void)     
{
    (FMC->ISPCON |= FMC_ISPCON_ISPFF);
}
/**
 * @brief      Eanble LDROM Update
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Eanble LDROM Update .\n                                              
 *             Example: FMC_ENABLE_LD_UPDATE()
 *
 */  
static __INLINE void FMC_ENABLE_LD_UPDATE(void)
{
    (FMC->ISPCON |=  FMC_ISPCON_LDUEN);  /*!< Enable LDROM Update Function   */
}
/**
 * @brief      Disable LDROM Update
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable LDROM Update .\n                                              
 *             Example: FMC_DISABLE_LD_UPDATE()
 *
 */  
static __INLINE void FMC_DISABLE_LD_UPDATE(void)
{
    (FMC->ISPCON &= ~FMC_ISPCON_LDUEN);  /*!< Disable LDROM Update Function  */
}
/**
 * @brief      Enable Config-bits Update by ISP
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Enable Config-bits Update by ISP .\n                                              
 *             Example: FMC_ENABLE_CFG_UPDATE()
 *
 */ 
static __INLINE void FMC_ENABLE_CFG_UPDATE(void)
{
    (FMC->ISPCON |=  FMC_ISPCON_CFGUEN); /*!< Enable CONFIG Update Function  */
}
/**
 * @brief      Disable Config-bits Update by ISP
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable Config-bits Update by ISP .\n                                              
 *             Example: FMC_DISABLE_CFG_UPDATE()
 *
 */ 
static __INLINE void FMC_DISABLE_CFG_UPDATE(void)
{
    (FMC->ISPCON &= ~FMC_ISPCON_CFGUEN); /*!< Disable CONFIG Update Function */
}
/**
 * @brief      Enable APROM Update by ISP
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Enable APROM Update by ISP .\n                                              
 *             Example: FMC_ENABLE_AP_UPDATE()
 *
 */ 
static __INLINE void FMC_ENABLE_AP_UPDATE(void)
{
    (FMC->ISPCON |=  FMC_ISPCON_APUEN);  /*!< Enable APROM Update Function   */
}
/**
 * @brief      Disable APROM Update by ISP
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable APROM Update by ISP .\n                                              
 *             Example: FMC_DISABLE_AP_UPDATE()
 *
 */ 
static __INLINE void FMC_DISABLE_AP_UPDATE(void)
{
    (FMC->ISPCON &= ~FMC_ISPCON_APUEN);  /*!< Disable APROM Update Function  */
}
/**
 * @brief      Boot Select
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Boot from LDROM .\n                                              
 *             Example: FMC_BOOT_FROM_LDROM()
 *
 */ 
static __INLINE void FMC_BOOT_FROM_LDROM(void)
{
   (FMC->ISPCON |= FMC_ISPCON_BS);
}
/**
 * @brief      Boot Select
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Boot from APROM .\n                                              
 *             Example: FMC_BOOT_FROM_APROM()
 *
 */ 
static __INLINE void FMC_BOOT_FROM_APROM(void)
{
   (FMC->ISPCON &= ~FMC_ISPCON_BS);
}
/**
 * @brief      Read boot status
 *
 * @param[in]  None
 *
 * @retval     0 =  Boot from APROM  
 * @retval     !0 =  Boot from LDROM   
 *                                                           
 * @details    Read boot status .\n                                              
 *             Example: FMC_GET_BOOT_STATUS()
 *
 */ 
static __INLINE uint8_t FMC_GET_BOOT_STATUS(void)
{
    return (FMC->ISPCON & FMC_ISPCON_BS_Msk); /*!< Get MCU Booting Status */
}

/**
 * @brief      Eanble ISP
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Eanble ISP .\n                                              
 *             Example: FMC_ENABLE_ISP()
 *
 */  
static __INLINE void FMC_ENABLE_ISP(void)   
{
    (FMC->ISPCON |=  FMC_ISPCON_ISPEN);  /*!< Enable ISP Function  */
}
/**
 * @brief      Disable ISP
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable ISP .\n                                              
 *             Example: FMC_DISABLE_ISP()
 *
 */
static __INLINE void FMC_DISABLE_ISP(void) 
{
    (FMC->ISPCON &= ~FMC_ISPCON_ISPEN);  /*!< Disable ISP Function */
}
/**
 * @brief      Set ISP address
 *
 * @param[in]  add  Address For Program
 *
 * @return     None
 *                                                           
 * @details    Set ISP address .\n                                              
 *             Example: FMC_SET_ADDRESS(FMC_LDROM_BASE)
 *
 */
static __INLINE void FMC_SET_ADDRESS(uint32_t add)    
{
    (FMC->ISPADR = (add));  
}
/**
 * @brief      Set ISP data
 *
 * @param[in]  Data	For Program
 *
 * @return     None
 *                                                           
 * @details    Set ISP data .\n                                              
 *             Example: FMC_SET_DATA(0x55555555)
 *
 */
static __INLINE void FMC_SET_DATA(uint32_t data)    
{
    (FMC->ISPDAT  = (data));  
}
/**
 * @brief      Get ISP data
 *
 * @param[in]  None
 *
 * @return     ISP DATA
 *                                                           
 * @details    Get ISP data .\n                                              
 *             Example: FMC_GET_DATA()
 *
 */
static __INLINE uint32_t FMC_GET_DATA(void)   
{
    return (FMC->ISPDAT);
}
/**
 * @brief      Set ISP command
 *
 * @param[in]  Command	For Program
 *			   -FMC_ISPCMD_READ
 *			   -FMC_ISPCMD_PROGRAM
 *			   -FMC_ISPCMD_PAGE_ERASE
 *			   -FMC_ISPCMD_READ_UID
 * @return     None
 *                                                           
 * @details    Set ISP command .\n                                              
 *             Example: FMC_SET_COMMAND(FMC_ISPCMD_READ)
 *
 */
static __INLINE void FMC_SET_COMMAND(uint32_t command)
{
    (FMC->ISPCMD = (command));
}
/**
 * @brief      Triger ISP 
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Triger ISP .\n                                              
 *             Example: FMC_SET_ISPTRG_GO()
 *
 */
static __INLINE void FMC_SET_ISPTRG_GO(void) 
{
    (FMC->ISPTRG |= FMC_ISPTRG_GO);
}
/**
 * @brief      Triger ISP 
 *
 * @param[in]  None
 *
 * @retval     0 =  ISP operation is finished  
 * @retval     1 =  ISP is progressed.  
 *                                                           
 * @details    Triger ISP .\n                                              
 *             Example: FMC_GET_ISPTRG_GO()
 *
 */
static __INLINE uint8_t FMC_GET_ISPTRG_GO(void) 
{
    return (FMC->ISPTRG);
}
/**
 * @brief      Read data flash baseaddress 
 *
 * @param[in]  None
 *
 * @return     Data flash baseaddress
 *                                                           
 * @details    Read data flash baseaddress .\n                                              
 *             Example: FMC_READ_DATAFLASH_BASEADDRESS()
 *
 */
static __INLINE uint32_t FMC_READ_DATAFLASH_BASEADDRESS(void)  
{
    return (FMC->DFBADR);
}		  
/**
 * @brief      Middle Frequency Optimization Mode
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    When chip operation frequency is lower than 50 MHz, chip can work more efficiently by setting this bit to 1 .\n                                              
 *             Example: FMC_ENABLE_MFOM()
 *
 */
static __INLINE void FMC_ENABLE_MFOM(void)    
{
    (FMC->FATCON |= FMC_FATCON_MFOM);
}
/**
 * @brief      Middle Frequency Optimization Mode
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable Middle Frequency Optimization Mode\n                                              
 *             Example: FMC_DISABLE_MFOM()
 *
 */
static __INLINE void FMC_DISABLE_MFOM(void)  
{
    (FMC->FATCON &= ~FMC_FATCON_MFOM);
}
/**
 * @brief      Low Frequency Optimization Mode
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    When chip operation frequency is lower than 25 MHz, chip can work more efficiently by setting this bit to 1 .\n                                              
 *             Example: FMC_ENABLE_LFOM()
 *
 */
static __INLINE void FMC_ENABLE_LFOM(void)     
{
    (FMC->FATCON |= FMC_FATCON_LFOM);
}
/**
 * @brief      Low Frequency Optimization Mode
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable Low Frequency Optimization Mode\n                                              
 *             Example: FMC_DISABLE_LFOM()
 *
 */
static __INLINE void FMC_DISABLE_LFOM(void)     
{
    (FMC->FATCON &= ~FMC_FATCON_LFOM);
}

/*@}*/ /* end of group FMC_MACRO_FUNC */
/*@}*/ /* end of group FMC_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

/*---------------------------------------------------------------------------------------------------------*/
/*  Function declaration                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
int32_t DrvFMC_Write(uint32_t u32addr, uint32_t u32data);
int32_t DrvFMC_Read(uint32_t u32addr, uint32_t * u32data);
int32_t DrvFMC_Erase(uint32_t u32addr);
int32_t DrvFMC_ReadUID(int index, uint32_t * u32data);



#endif

