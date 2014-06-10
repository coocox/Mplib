/*************************************************************************//**
 * @file     sys.c
 * @version  V1.00
 * $Revision: 7 $
 * $Date: 13/11/10 9:32a $
 * @brief    NUC400 series SYS driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include  "sys.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_SYS_Driver SYS Driver
  @{
*/


/** @addtogroup NUC400_SYS_EXPORTED_FUNCTIONS SYS Exported Functions
  @{
*/

/**
  * @brief  This function clear the selected system reset source
  * @param  u32Src is system reset source
  * @return None
  */
void SYS_ClearResetSrc(uint32_t u32Src)
{
    SYS->RSTSRC |= u32Src;
}

/**
  * @brief  This function get Brown-out detector output status
  * @return 0: System voltage is higher than BOD_VL setting or BOD_EN is 0.
  *         1: System voltage is lower than BOD_VL setting.
  *         Note : If the BOD_EN is 0, this function always return 0.
  */
uint32_t SYS_GetBODStatus()
{
    return (SYS->BODCR & SYS_BODCR_BOD_OUT_Msk);
}

/**
  * @brief  This function get the system reset source register value
  * @return Reset source
  */
uint32_t SYS_GetResetSrc(void)
{
    return (SYS->RSTSRC);
}

/**
  * @brief  This function check register write-protection bit setting
  * @return 0: Write-protection function is disabled.
  *         1: Write-protection function is enabled.
  */
uint32_t SYS_IsRegLocked(void)
{
    return (SYS->REGWRPROT & SYS_REGWRPROT_REGPROTDIS_Msk);
}

/**
  * @brief  This function enable register write-protection function
  * @return None
  * @details To lock the protected register to forbid write access
  */
void SYS_LockReg(void)
{
    SYS->REGWRPROT = 0;
}


/**
  * @brief  This function disable register write-protection function
  * @return None
  * @details To unlock the protected register to allow write access
  */
void SYS_UnlockReg(void)
{
    while(SYS->REGWRPROT != SYS_REGWRPROT_REGPROTDIS_Msk) {
        SYS->REGWRPROT = 0x59;
        SYS->REGWRPROT = 0x16;
        SYS->REGWRPROT = 0x88;
    }
}

/**
  * @brief  This function get product ID.
  * @return Product ID
  */
uint32_t  SYS_ReadPDID(void)
{
    return SYS->PDID;
}

/**
  * @brief  This function reset chip.
  * @return None
  */
void SYS_ResetChip(void)
{
    SYS->IPRSTC1 |= SYS_IPRSTC1_CHIP_RST_Msk;
}

/**
  * @brief  This function reset CPU.
  * @return None
  */
void SYS_ResetCPU(void)
{
    SYS->IPRSTC1 |= SYS_IPRSTC1_CPU_RST_Msk;
}

/**
  * @brief  This function reset selected modules.
  * @param  u32ModuleIndex is module index. Including :
  * - \ref CHIP_RST
  * - \ref CPU_RST
  * - \ref PDMA_RST
  * - \ref EBI_RST
  * - \ref UHC_RST
  * - \ref EMAC_RST
  * - \ref SDIO_RST
  * - \ref CRC_RST
  * - \ref CAP_RST
  * - \ref SPACC_RST
  * - \ref GPIO_RST
  * - \ref TMR0_RST
  * - \ref TMR1_RST
  * - \ref TMR2_RST
  * - \ref TMR3_RST
  * - \ref ACMP_RST
  * - \ref I2C0_RST
  * - \ref I2C1_RST
  * - \ref I2C2_RST
  * - \ref I2C3_RST
  * - \ref SPI0_RST
  * - \ref SPI1_RST
  * - \ref SPI2_RST
  * - \ref SPI3_RST
  * - \ref UART0_RST
  * - \ref UART1_RST
  * - \ref UART2_RST
  * - \ref UART3_RST
  * - \ref UART4_RST
  * - \ref UART5_RST
  * - \ref CAN0_RST
  * - \ref CAN1_RST
  * - \ref OTG_RST
  * - \ref USBD_RST
  * - \ref ADC_RST
  * - \ref I2S_RST
  * - \ref I2S1_RST
  * - \ref PS2_RST
  * - \ref SC0_RST
  * - \ref SC1_RST
  * - \ref SC2_RST
  * - \ref SC3_RST
  * - \ref SC4_RST
  * - \ref SC5_RST
  * - \ref I2C4_RST
  * - \ref PWM0_RST
  * - \ref PWM1_RST
  * - \ref QEI0_RST
  * - \ref QEI1_RST
  * @return None
  */
void SYS_ResetModule(uint32_t u32ModuleIndex)
{
    *(volatile uint32_t *)((uint32_t)&(SYS->IPRSTC1) + (u32ModuleIndex>>24)) |= 1<<(u32ModuleIndex & 0x00ffffff);
    *(volatile uint32_t *)((uint32_t)&(SYS->IPRSTC1) + (u32ModuleIndex>>24)) &= ~(1<<(u32ModuleIndex & 0x00ffffff));
}

/**
  * @brief  This function configure BOD function.
  *         Configure BOD reset or interrupt mode and set Brown-out voltage level.
  *         Enable Brown-out function
  * @param  i32Mode is reset or interrupt mode. Including :
  *         - \ref SYS_BODCR_BOD_RSTEN
  *         - \ref SYS_BODCR_BOD_INTEN
  * @param  u32BODLevel is Brown-out voltage level. Including :
  *         - \ref SYS_BODCR_BOD_VL_2_2V
  *         - \ref SYS_BODCR_BOD_VL_2_7V
  *         - \ref SYS_BODCR_BOD_VL_3_8V
  *         - \ref SYS_BODCR_BOD_VL_4_5V
  *
  * @return None
  */
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel)
{
    SYS->BODCR &= ~(SYS_BODCR_BOD_VL_Msk|SYS_BODCR_BOD_RSTEN_Msk);
    SYS->BODCR |=(i32Mode|u32BODLevel|SYS_BODCR_BOD_EN_Msk);
}

/**
  * @brief  This function disable BOD function.
  * @return None
  */
void SYS_DisableBOD(void)
{
    SYS->BODCR  &= ~SYS_BODCR_BOD_EN_Msk;
}



/*@}*/ /* end of group NUC400_SYS_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_SYS_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/

