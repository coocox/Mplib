/**************************************************************************//**
 * @file     clk.c
 * @version  V1.00
 * $Revision: 19 $
 * $Date: 14/01/13 1:43p $
 * @brief    NUC400 series CLK driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include  "clk.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_CLK_Driver CLK Driver
  @{
*/


/** @addtogroup NUC400_CLK_EXPORTED_FUNCTIONS CLK Exported Functions
  @{
*/

/**
  * @brief  This function disable frequency output function.
  * @return None
  */
void CLK_DisableCKO(void)
{
    /* Disable CKO clock source */
    CLK->APBCLK0 &= (~CLK_APBCLK0_FDIV_EN_Pos);
}

/**
  * @brief  This function enable frequency divider module clock,
  *         enable frequency divider clock function and configure frequency divider.
  * @param  u32ClkSrc is frequency divider function clock source
  *         - \ref CLK_CLKSEL1_FRQDIV_S_HXT
  *         - \ref CLK_CLKSEL1_FRQDIV_S_LXT
  *         - \ref CLK_CLKSEL1_FRQDIV_S_HCLK
  *         - \ref CLK_CLKSEL1_FRQDIV_S_HIRC
  * @param  u32ClkDiv is system reset source
  * @param  u32ClkDivBy1En is frequency divided by one enable.
  * @return None
  *
  * @details    Output selected clock to CKO. The output clock frequency is divided by u32ClkDiv.
  *             The formula is:
  *                 CKO frequency = (Clock source frequency) / 2^(u32ClkDiv + 1)
  *             This function is just used to set CKO clock.
  *             User must enable I/O for CKO clock output pin by themselves.
  */
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv, uint32_t u32ClkDivBy1En)
{
    /* CKO = clock source / 2^(u32ClkDiv + 1) */
    CLK->FRQDIV = CLK_FRQDIV_DIVIDER_EN_Msk | u32ClkDiv | u32ClkDivBy1En<<CLK_FRQDIV_DIVIDER1_Pos;

    /* Enable CKO clock source */
    CLK->APBCLK0 |= CLK_APBCLK0_FDIV_EN_Msk;

    /* Select CKO clock source */
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_FRQDIV_S_Msk)) | u32ClkSrc;
}

/**
  * @brief  This function let system enter to Power-down mode.
  * @return None
  */
void CLK_PowerDown(void)
{
    SCB->SCR = SCB_SCR_SLEEPDEEP_Msk;
    CLK->PWRCON |= (CLK_PWRCON_PWR_DOWN_EN_Msk | CLK_PWRCON_PD_WU_DLY_Msk );
    __WFI();
}

/**
  * @brief  This function let system enter to Idle mode
  * @return None
  */
void CLK_Idle(void)
{
    CLK->PWRCON |= (CLK_PWRCON_PWR_DOWN_EN_Msk );
    __WFI();
}


/**
  * @brief  This function get PCLK frequency. The frequency unit is Hz.
  * @return PCLK frequency
  */
uint32_t CLK_GetPCLKFreq(void)
{
    SystemCoreClockUpdate();
    if(CLK->CLKSEL0 & CLK_CLKSEL0_PCLK_S_Msk)
        return SystemCoreClock/2;
    else
        return SystemCoreClock;
}
/**
  * @brief  This function get external high frequency crystal frequency. The frequency unit is Hz.
  * @return None
  */
uint32_t CLK_GetHXTFreq(void)
{
    if(CLK->PWRCON & CLK_PWRCON_HXT_EN_Msk )
        return __HXT;
    else
        return 0;
}

/**
  * @brief  This function get external low frequency crystal frequency. The frequency unit is Hz.
  * @return LXT frequency
  */
uint32_t CLK_GetLXTFreq(void)
{
    if(CLK->PWRCON & CLK_PWRCON_LXT_EN_Msk )
        return __LXT;
    else
        return 0;
}

/**
  * @brief  This function get HCLK frequency. The frequency unit is Hz.
  * @return HCLK frequency
  */
uint32_t CLK_GetHCLKFreq(void)
{
    SystemCoreClockUpdate();
    return SystemCoreClock;
}

/**
  * @brief  This function get CPU frequency. The frequency unit is Hz.
  * @return CPU frequency
  */
uint32_t CLK_GetCPUFreq(void)
{
    SystemCoreClockUpdate();
    return SystemCoreClock;
}

/**
  * @brief  This function get PLL frequency. The frequency unit is Hz.
  * @return PLL frequency
  */
uint32_t CLK_GetPLLClockFreq(void)
{
    uint32_t u32Freq =0, u32PLLSrc;
    uint32_t u32NO,u32NF,u32NR,u32PllReg;

    u32PllReg = CLK->PLLCON;

    if((u32PllReg & CLK_PLLCON_PLL_remap_Msk))
        return 0;

    if(u32PllReg & CLK_PLLCON_PLL_SRC_Msk)
        u32PLLSrc = __HIRC;
    else
        u32PLLSrc = __HXT;

    u32NO=(u32PllReg & CLK_PLLCON_OUT_DV_Msk)>>CLK_PLLCON_OUT_DV_Pos;
    switch(u32NO) {
    case 0:
        u32NO=1;
        break;
    case 1:
    case 2:
        u32NO=2;
        break;
    case 3:
        u32NO=4;
        break;
    }

    u32NF = (u32PllReg & CLK_PLLCON_FB_DV_Msk) + 2;
    u32NR = ( (u32PllReg & CLK_PLLCON_IN_DV_Msk)>>CLK_PLLCON_IN_DV_Pos ) + 2;

    u32Freq = u32PLLSrc * u32NF / u32NR / u32NO ;

    return u32Freq;
}

/**
  * @brief  This function set HCLK frequency. The frequency unit is Hz. The range of u32Hclk is 24 ~ 96 MHz
  * @param  u32Hclk is HCLK frequency
  * @return None
  */
uint32_t CLK_SetCoreClock(uint32_t u32Hclk)
{
    uint32_t u32ClkSrc,u32NR, u32NF,u32Register;
    u32ClkSrc = CLK->CLKSEL0 & CLK_CLKSEL0_HCLK_S_Msk;

    if(u32Hclk < FREQ_24MHZ)
        u32Hclk =FREQ_24MHZ;

    if(CLK->PWRCON & CLK_PWRCON_HXT_EN_Msk) {
        u32Register = 0<<CLK_PLLCON_PLL_SRC_Pos;
        u32ClkSrc = __HXT;
    } else {
        u32Register = 1<<CLK_PLLCON_PLL_SRC_Pos;
        u32ClkSrc = __HIRC;
    }

    if(u32Hclk<FREQ_50MHZ)  {
        u32Hclk <<=2;
        u32Register |= (0x3<<CLK_PLLCON_OUT_DV_Pos);
    } else {
        u32Hclk <<=1;
        u32Register |= (0x1<<CLK_PLLCON_OUT_DV_Pos);
    }
    u32NF = u32Hclk / 1000000;
    u32NR = u32ClkSrc / 1000000;
    while( u32NR>(0xF+2) || u32NF>(0xFF+2) ) {
        u32NR = u32NR>>1;
        u32NF = u32NF>>1;
    }
    CLK->PLLCON = u32Register | ((u32NR - 2)<<9) | (u32NF - 2) ;
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Update System Core Clock */
    SystemCoreClockUpdate();

    return SystemCoreClock;
}

/**
  * @brief  This function set HCLK clock source and HCLK clock divider
  * @param  u32ClkSrc is HCLK clock source. Including :
  *         - \ref CLK_CLKSEL0_HCLK_S_HXT
  *         - \ref CLK_CLKSEL0_HCLK_S_LXT
  *         - \ref CLK_CLKSEL0_HCLK_S_PLL
  *         - \ref CLK_CLKSEL0_HCLK_S_LIRC
  *         - \ref CLK_CLKSEL0_HCLK_S_HIRC
  * @param  u32ClkDiv is HCLK clock divider. Including :
  *         - \ref CLK_CLKDIV0_HCLK(x)
  * @return None
  */
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_HCLK_S_Msk) | u32ClkSrc;
    CLK->CLKDIV0 = (CLK->CLKDIV0 & ~CLK_CLKDIV0_HCLK_N_Msk) | u32ClkDiv;
    SystemCoreClockUpdate();
}

/**
  * @brief  This function set selected module clock source and module clock divider
  * @param  u32ModuleIdx is module index.
  * @param  u32ClkSrc is module clock source.
  * @param  u32ClkDiv is module clock divider.
  * @return None
  * @details Valid parameter combinations listed in following table:
  *
  * |Module index          |Clock source                        |Divider                       |
  * | :------------------- | :-------------------------------   | :-------------------------   |
  * |\ref PDMA_MODULE      | x                                  | x                            |
  * |\ref ISP_MODULE       | x                                  | x                            |
  * |\ref EBI_MODULE       | x                                  | x                            |
  * |\ref USBH_MODULE      |\ref CLK_CLKSEL0_USB_S_PLL          |\ref CLK_CLKDIV0_USB(x)       |
  * |\ref USBH_MODULE      |\ref CLK_CLKSEL0_USB_S_PLL2         |\ref CLK_CLKDIV0_USB(x)       |
  * |\ref EMAC_MODULE      |\ref CLK_CLKSEL0_EMAC_S_HXT         |\ref CLK_CLKDIV3_EMAC_MDCLK(x)|
  * |\ref EMAC_MODULE      |\ref CLK_CLKSEL0_EMAC_S_PLL         |\ref CLK_CLKDIV3_EMAC_MDCLK(x)|
  * |\ref SDHOST_MODULE    |\ref CLK_CLKSEL0_SDHOST_S_HXT       |\ref CLK_CLKDIV0_SDHOST(x)    |
  * |\ref SDHOST_MODULE    |\ref CLK_CLKSEL0_SDHOST_S_PLL       |\ref CLK_CLKDIV0_SDHOST(x)    |
  * |\ref SDHOST_MODULE    |\ref CLK_CLKSEL0_SDHOST_S_HCLK      |\ref CLK_CLKDIV0_SDHOST(x)    |
  * |\ref SDHOST_MODULE    |\ref CLK_CLKSEL0_SDHOST_S_HIRC      |\ref CLK_CLKDIV0_SDHOST(x)    |
  * |\ref CRC_MODULE       | x                                  | x                            |
  * |\ref CAP_MODULE       |\ref CLK_CLKSEL0_CAP_S_HXT          |\ref CLK_CLKDIV3_CAP(x)       |
  * |\ref CAP_MODULE       |\ref CLK_CLKSEL0_CAP_S_PLL2         |\ref CLK_CLKDIV3_CAP(x)       |
  * |\ref CAP_MODULE       |\ref CLK_CLKSEL0_CAP_S_HCLK         |\ref CLK_CLKDIV3_CAP(x)       |
  * |\ref CAP_MODULE       |\ref CLK_CLKSEL0_CAP_S_HIRC         |\ref CLK_CLKDIV3_CAP(x)       |
  * |\ref SENCLK_MODULE    | x                                  | x                            |
  * |\ref UDC20_MODULE     | x                                  | x                            |
  * |\ref IPSEC_MODULE     | x                                  | x                            |
  * |\ref ECAP1_MODULE     | x                                  | x                            |
  * |\ref ECAP0_MODULE     | x                                  | x                            |
  * |\ref EADC_MODULE      | x                                  | x                            |
  * |\ref OPA_MODULE       | x                                  | x                            |
  * |\ref TAMPER_MODULE    | x                                  | x                            |
  * |\ref TAMPER_MODULE    | x                                  | x                            |
  * |\ref QEI1_MODULE      | x                                  | x                            |
  * |\ref QEI0_MODULE      | x                                  | x                            |
  * |\ref PWM1CH45_MODULE    |\ref CLK_CLKSEL2_PWM1CH45_S_HXT       | x                            |
  * |\ref PWM1CH45_MODULE    |\ref CLK_CLKSEL2_PWM1CH45_S_LXT       | x                            |
  * |\ref PWM1CH45_MODULE    |\ref CLK_CLKSEL2_PWM1CH45_S_PCLK      | x                            |
  * |\ref PWM1CH45_MODULE    |\ref CLK_CLKSEL2_PWM1CH45_S_LIRC      | x                            |
  * |\ref PWM1CH45_MODULE    |\ref CLK_CLKSEL2_PWM1CH45_S_HIRC      | x                            |
  * |\ref PWM1CH23_MODULE    |\ref CLK_CLKSEL2_PWM1CH23_S_HXT       | x                            |
  * |\ref PWM1CH23_MODULE    |\ref CLK_CLKSEL2_PWM1CH23_S_LXT       | x                            |
  * |\ref PWM1CH23_MODULE    |\ref CLK_CLKSEL2_PWM1CH23_S_PCLK      | x                            |
  * |\ref PWM1CH23_MODULE    |\ref CLK_CLKSEL2_PWM1CH23_S_LIRC      | x                            |
  * |\ref PWM1CH23_MODULE    |\ref CLK_CLKSEL2_PWM1CH23_S_HIRC      | x                            |
  * |\ref PWM1CH01_MODULE    |\ref CLK_CLKSEL2_PWM1CH01_S_HXT       | x                            |
  * |\ref PWM1CH01_MODULE    |\ref CLK_CLKSEL2_PWM1CH01_S_LXT       | x                            |
  * |\ref PWM1CH01_MODULE    |\ref CLK_CLKSEL2_PWM1CH01_S_PCLK      | x                            |
  * |\ref PWM1CH01_MODULE    |\ref CLK_CLKSEL2_PWM1CH01_S_LIRC      | x                            |
  * |\ref PWM1CH01_MODULE    |\ref CLK_CLKSEL2_PWM1CH01_S_HIRC      | x                            |
  * |\ref PWM0CH45_MODULE    |\ref CLK_CLKSEL2_PWM0CH45_S_HXT       | x                            |
  * |\ref PWM0CH45_MODULE    |\ref CLK_CLKSEL2_PWM0CH45_S_LXT       | x                            |
  * |\ref PWM0CH45_MODULE    |\ref CLK_CLKSEL2_PWM0CH45_S_PCLK      | x                            |
  * |\ref PWM0CH45_MODULE    |\ref CLK_CLKSEL2_PWM0CH45_S_LIRC      | x                            |
  * |\ref PWM0CH45_MODULE    |\ref CLK_CLKSEL2_PWM0CH45_S_HIRC      | x                            |
  * |\ref PWM0CH23_MODULE    |\ref CLK_CLKSEL2_PWM0CH23_S_HXT       | x                            |
  * |\ref PWM0CH23_MODULE    |\ref CLK_CLKSEL2_PWM0CH23_S_LXT       | x                            |
  * |\ref PWM0CH23_MODULE    |\ref CLK_CLKSEL2_PWM0CH23_S_PCLK      | x                            |
  * |\ref PWM0CH23_MODULE    |\ref CLK_CLKSEL2_PWM0CH23_S_LIRC      | x                            |
  * |\ref PWM0CH23_MODULE    |\ref CLK_CLKSEL2_PWM0CH23_S_HIRC      | x                            |
  * |\ref PWM0CH01_MODULE    |\ref CLK_CLKSEL2_PWM0CH01_S_HXT       | x                            |
  * |\ref PWM0CH01_MODULE    |\ref CLK_CLKSEL2_PWM0CH01_S_LXT       | x                            |
  * |\ref PWM0CH01_MODULE    |\ref CLK_CLKSEL2_PWM0CH01_S_PCLK      | x                            |
  * |\ref PWM0CH01_MODULE    |\ref CLK_CLKSEL2_PWM0CH01_S_LIRC      | x                            |
  * |\ref PWM0CH01_MODULE    |\ref CLK_CLKSEL2_PWM0CH01_S_HIRC      | x                            |
  * |\ref I2C4_MODULE      | x                                  | x                            |
  * |\ref SC5_MODULE       | x                                  | x                            |
  * |\ref SC4_MODULE       | x                                  | x                            |
  * |\ref SC3_MODULE       | x                                  | x                            |
  * |\ref SC2_MODULE       | x                                  | x                            |
  * |\ref SC5_MODULE       |\ref CLK_CLKSEL3_SC5_S_HXT          |\ref CLK_CLKDIV2_SC5(x)       |
  * |\ref SC5_MODULE       |\ref CLK_CLKSEL3_SC5_S_PLL          |\ref CLK_CLKDIV2_SC5(x)       |
  * |\ref SC5_MODULE       |\ref CLK_CLKSEL3_SC5_S_PCLK         |\ref CLK_CLKDIV2_SC5(x)       |
  * |\ref SC5_MODULE       |\ref CLK_CLKSEL3_SC5_S_HIRC         |\ref CLK_CLKDIV2_SC5(x)       |
  * |\ref SC4_MODULE       |\ref CLK_CLKSEL3_SC4_S_HXT          |\ref CLK_CLKDIV2_SC4(x)       |
  * |\ref SC4_MODULE       |\ref CLK_CLKSEL3_SC4_S_PLL          |\ref CLK_CLKDIV2_SC4(x)       |
  * |\ref SC4_MODULE       |\ref CLK_CLKSEL3_SC4_S_PCLK         |\ref CLK_CLKDIV2_SC4(x)       |
  * |\ref SC4_MODULE       |\ref CLK_CLKSEL3_SC4_S_HIRC         |\ref CLK_CLKDIV2_SC4(x)       |
  * |\ref SC3_MODULE       |\ref CLK_CLKSEL3_SC3_S_HXT          |\ref CLK_CLKDIV1_SC3(x)       |
  * |\ref SC3_MODULE       |\ref CLK_CLKSEL3_SC3_S_PLL          |\ref CLK_CLKDIV1_SC3(x)       |
  * |\ref SC3_MODULE       |\ref CLK_CLKSEL3_SC3_S_PCLK         |\ref CLK_CLKDIV1_SC3(x)       |
  * |\ref SC3_MODULE       |\ref CLK_CLKSEL3_SC3_S_HIRC         |\ref CLK_CLKDIV1_SC3(x)       |
  * |\ref SC2_MODULE       |\ref CLK_CLKSEL3_SC2_S_HXT          |\ref CLK_CLKDIV1_SC2(x)       |
  * |\ref SC2_MODULE       |\ref CLK_CLKSEL3_SC2_S_PLL          |\ref CLK_CLKDIV1_SC2(x)       |
  * |\ref SC2_MODULE       |\ref CLK_CLKSEL3_SC2_S_PCLK         |\ref CLK_CLKDIV1_SC2(x)       |
  * |\ref SC2_MODULE       |\ref CLK_CLKSEL3_SC2_S_HIRC         |\ref CLK_CLKDIV1_SC2(x)       |
  * |\ref SC1_MODULE       |\ref CLK_CLKSEL3_SC1_S_HXT          |\ref CLK_CLKDIV1_SC1(x)       |
  * |\ref SC1_MODULE       |\ref CLK_CLKSEL3_SC1_S_PLL          |\ref CLK_CLKDIV1_SC1(x)       |
  * |\ref SC1_MODULE       |\ref CLK_CLKSEL3_SC1_S_PCLK         |\ref CLK_CLKDIV1_SC1(x)       |
  * |\ref SC1_MODULE       |\ref CLK_CLKSEL3_SC1_S_HIRC         |\ref CLK_CLKDIV1_SC1(x)       |
  * |\ref SC0_MODULE       |\ref CLK_CLKSEL3_SC0_S_HXT          |\ref CLK_CLKDIV1_SC0(x)       |
  * |\ref SC0_MODULE       |\ref CLK_CLKSEL3_SC0_S_PLL          |\ref CLK_CLKDIV1_SC0(x)       |
  * |\ref SC0_MODULE       |\ref CLK_CLKSEL3_SC0_S_PCLK         |\ref CLK_CLKDIV1_SC0(x)       |
  * |\ref SC0_MODULE       |\ref CLK_CLKSEL3_SC0_S_HIRC         |\ref CLK_CLKDIV1_SC0(x)       |
  * |\ref PS2_MODULE       | x                                  | x                            |
  * |\ref I2S1_MODULE      | x                                  | x                            |
  * |\ref I2S0_MODULE      | x                                  | x                            |
  * |\ref ADC_MODULE       |\ref CLK_CLKSEL1_ADC_S_HXT          |\ref CLK_CLKDIV0_ADC(x)       |
  * |\ref ADC_MODULE       |\ref CLK_CLKSEL1_ADC_S_PLL          |\ref CLK_CLKDIV0_ADC(x)       |
  * |\ref ADC_MODULE       |\ref CLK_CLKSEL1_ADC_S_PCLK         |\ref CLK_CLKDIV0_ADC(x)       |
  * |\ref ADC_MODULE       |\ref CLK_CLKSEL1_ADC_S_HIRC         |\ref CLK_CLKDIV0_ADC(x)       |
  * |\ref OTG_MODULE       | x                                  | x                            |
  * |\ref CAN1_MODULE      | x                                  | x                            |
  * |\ref CAN0_MODULE      | x                                  | x                            |
  * |\ref UART5_MODULE     |\ref CLK_CLKSEL1_UART_S_HXT         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART5_MODULE     |\ref CLK_CLKSEL1_UART_S_PLL         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART5_MODULE     |\ref CLK_CLKSEL1_UART_S_HIRC        |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART4_MODULE     |\ref CLK_CLKSEL1_UART_S_HXT         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART4_MODULE     |\ref CLK_CLKSEL1_UART_S_PLL         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART4_MODULE     |\ref CLK_CLKSEL1_UART_S_HIRC        |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART3_MODULE     |\ref CLK_CLKSEL1_UART_S_HXT         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART3_MODULE     |\ref CLK_CLKSEL1_UART_S_PLL         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART3_MODULE     |\ref CLK_CLKSEL1_UART_S_HIRC        |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART2_MODULE     |\ref CLK_CLKSEL1_UART_S_HXT         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART2_MODULE     |\ref CLK_CLKSEL1_UART_S_PLL         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART2_MODULE     |\ref CLK_CLKSEL1_UART_S_HIRC        |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART1_MODULE     |\ref CLK_CLKSEL1_UART_S_HXT         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART1_MODULE     |\ref CLK_CLKSEL1_UART_S_PLL         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART1_MODULE     |\ref CLK_CLKSEL1_UART_S_HIRC        |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART0_MODULE     |\ref CLK_CLKSEL1_UART_S_HXT         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART0_MODULE     |\ref CLK_CLKSEL1_UART_S_PLL         |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref UART0_MODULE     |\ref CLK_CLKSEL1_UART_S_HIRC        |\ref CLK_CLKDIV0_UART(x)      |
  * |\ref SPI3_MODULE      |\ref CLK_CLKSEL1_SPI3_S_PLL         | x                            |
  * |\ref SPI3_MODULE      |\ref CLK_CLKSEL1_SPI3_S_PCLK        | x                            |
  * |\ref SPI2_MODULE      |\ref CLK_CLKSEL1_SPI2_S_PLL         | x                            |
  * |\ref SPI2_MODULE      |\ref CLK_CLKSEL1_SPI2_S_PCLK        | x                            |
  * |\ref SPI1_MODULE      |\ref CLK_CLKSEL1_SPI1_S_PLL         | x                            |
  * |\ref SPI1_MODULE      |\ref CLK_CLKSEL1_SPI1_S_PCLK        | x                            |
  * |\ref SPI0_MODULE      |\ref CLK_CLKSEL1_SPI0_S_PLL         | x                            |
  * |\ref SPI0_MODULE      |\ref CLK_CLKSEL1_SPI0_S_PCLK        | x                            |
  * |\ref I2C3_MODULE      | x                                  | x                            |
  * |\ref I2C2_MODULE      | x                                  | x                            |
  * |\ref I2C1_MODULE      | x                                  | x                            |
  * |\ref I2C0_MODULE      | x                                  | x                            |
  * |\ref ACMP_MODULE      | x                                  | x                            |
  * |\ref FDIV_MODULE      |\ref CLK_CLKSEL1_FRQDIV_S_HXT       | x                            |
  * |\ref FDIV_MODULE      |\ref CLK_CLKSEL1_FRQDIV_S_LXT       | x                            |
  * |\ref FDIV_MODULE      |\ref CLK_CLKSEL1_FRQDIV_S_HCLK      | x                            |
  * |\ref FDIV_MODULE      |\ref CLK_CLKSEL1_FRQDIV_S_HIRC      | x                            |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3_S_HXT         | x                            |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3_S_LXT         | x                            |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3_S_PCLK        | x                            |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3_S_LIRC        | x                            |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3_S_EXT         | x                            |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3_S_HIRC        | x                            |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2_S_HXT         | x                            |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2_S_LXT         | x                            |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2_S_PCLK        | x                            |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2_S_LIRC        | x                            |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2_S_EXT         | x                            |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2_S_HIRC        | x                            |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1_S_HXT         | x                            |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1_S_LXT         | x                            |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1_S_PCLK        | x                            |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1_S_LIRC        | x                            |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1_S_EXT         | x                            |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1_S_HIRC        | x                            |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0_S_HXT         | x                            |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0_S_LXT         | x                            |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0_S_PCLK        | x                            |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0_S_LIRC        | x                            |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0_S_EXT         | x                            |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0_S_HIRC        | x                            |
  * |\ref RTC_MODULE       | x                                  | x                            |
  * |\ref WWDT_MODULE      |\ref CLK_CLKSEL1_WWDT_S_HCLK_DIV2048| x                            |
  * |\ref WWDT_MODULE      |\ref CLK_CLKSEL1_WWDT_S_LIRC        | x                            |
  * |\ref WDT_MODULE       |\ref CLK_CLKSEL1_WDT_S_LXT          | x                            |
  * |\ref WDT_MODULE       |\ref CLK_CLKSEL1_WDT_S_HCLK_DIV2048 | x                            |
  * |\ref WDT_MODULE       |\ref CLK_CLKSEL1_WDT_S_LIRC         | x                            |
  *
  */

void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
    uint32_t u32tmp=0,u32sel=0,u32div=0;

    if(MODULE_CLKSEL_Msk(u32ModuleIdx)!=MODULE_NoMsk) {
        u32sel = (uint32_t)&CLK->CLKSEL0+((MODULE_CLKSEL(u32ModuleIdx))*4);
        u32tmp = *(volatile uint32_t *)(u32sel);
        u32tmp = ( u32tmp & ~(MODULE_CLKSEL_Msk(u32ModuleIdx)<<MODULE_CLKSEL_Pos(u32ModuleIdx)) ) | u32ClkSrc;
        *(volatile uint32_t *)(u32sel) = u32tmp;
    }

    if(MODULE_CLKDIV_Msk(u32ModuleIdx)!=MODULE_NoMsk) {
        u32div =(uint32_t)&CLK->CLKDIV0+((MODULE_CLKDIV(u32ModuleIdx))*4);
        u32tmp = *(volatile uint32_t *)(u32div);
        u32tmp = ( u32tmp & ~(MODULE_CLKDIV_Msk(u32ModuleIdx)<<MODULE_CLKDIV_Pos(u32ModuleIdx)) ) | u32ClkDiv;
        *(volatile uint32_t *)(u32div) = u32tmp;
    }
}

/**
  * @brief  This function enable clock source
  * @param  u32ClkMask is clock source mask. Including:
  *         - \ref CLK_PWRCON_HXT_EN_Msk
  *         - \ref CLK_PWRCON_LXT_EN_Msk
  *         - \ref CLK_PWRCON_HIRC_EN_Msk
  *         - \ref CLK_PWRCON_LIRC_EN_Msk
  * @return None
  */
void CLK_EnableXtalRC(uint32_t u32ClkMask)
{
    CLK->PWRCON |= u32ClkMask;
}

/**
  * @brief  This function disable clock source
  * @param  u32ClkMask is clock source mask. Including:
  *         - \ref CLK_PWRCON_HXT_EN_Msk
  *         - \ref CLK_PWRCON_LXT_EN_Msk
  *         - \ref CLK_PWRCON_HIRC_EN_Msk
  *         - \ref CLK_PWRCON_LIRC_EN_Msk
  * @return None
  */
void CLK_DisableXtalRC(uint32_t u32ClkMask)
{
    CLK->PWRCON &= ~u32ClkMask;
}

/**
  * @brief  This function enable module clock
  * @param  u32ModuleIdx is module index. Including :
  *   - \ref PDMA_MODULE
  *   - \ref ISP_MODULE
  *   - \ref EBI_MODULE
  *   - \ref USBH_MODULE
  *   - \ref EMAC_MODULE
  *   - \ref SDHOST_MODULE
  *   - \ref CRC_MODULE
  *   - \ref CAP_MODULE
  *   - \ref SENCLK_MODULE
  *   - \ref UDC20_MODULE
  *   - \ref IPSEC_MODULE
  *   - \ref WDT_MODULE
  *   - \ref WWDT_MODULE
  *   - \ref RTC_MODULE
  *   - \ref TMR0_MODULE
  *   - \ref TMR1_MODULE
  *   - \ref TMR2_MODULE
  *   - \ref TMR3_MODULE
  *   - \ref FDIV_MODULE
  *   - \ref ACMP_MODULE
  *   - \ref I2C0_MODULE
  *   - \ref I2C1_MODULE
  *   - \ref I2C2_MODULE
  *   - \ref I2C3_MODULE
  *   - \ref SPI0_MODULE
  *   - \ref SPI1_MODULE
  *   - \ref SPI2_MODULE
  *   - \ref SPI3_MODULE
  *   - \ref UART0_MODULE
  *   - \ref UART1_MODULE
  *   - \ref UART2_MODULE
  *   - \ref UART3_MODULE
  *   - \ref UART4_MODULE
  *   - \ref UART5_MODULE
  *   - \ref CAN0_MODULE
  *   - \ref CAN1_MODULE
  *   - \ref OTG_MODULE
  *   - \ref ADC_MODULE
  *   - \ref I2S0_MODULE
  *   - \ref I2S1_MODULE
  *   - \ref PS2_MODULE
  *   - \ref SC0_MODULE
  *   - \ref SC1_MODULE
  *   - \ref SC2_MODULE
  *   - \ref SC3_MODULE
  *   - \ref SC4_MODULE
  *   - \ref SC5_MODULE
  *   - \ref I2C4_MODULE
  *   - \ref PWM0CH01_MODULE
  *   - \ref PWM0CH23_MODULE
  *   - \ref PWM0CH45_MODULE
  *   - \ref PWM1CH01_MODULE
  *   - \ref PWM1CH23_MODULE
  *   - \ref PWM1CH45_MODULE
  *   - \ref QEI0_MODULE
  *   - \ref QEI1_MODULE
  *   - \ref TAMPER_MODULE
  *   - \ref ECAP0_MODULE
  *   - \ref ECAP1_MODULE
  *   - \ref EPWM0_MODULE
  *   - \ref EPWM1_MODULE
  *   - \ref OPA_MODULE
  *   - \ref EADC_MODULE
  * @return None
  */
void CLK_EnableModuleClock(uint32_t u32ModuleIdx)
{
    *(volatile uint32_t *)((uint32_t)&CLK->AHBCLK+(MODULE_AHPBCLK(u32ModuleIdx)*4))  |= 1<<MODULE_IP_EN_Pos(u32ModuleIdx);
}

/**
  * @brief  This function disable module clock
  * @param  u32ModuleIdx is module index. Including :
  *   - \ref PDMA_MODULE
  *   - \ref ISP_MODULE
  *   - \ref EBI_MODULE
  *   - \ref USBH_MODULE
  *   - \ref EMAC_MODULE
  *   - \ref SDHOST_MODULE
  *   - \ref CRC_MODULE
  *   - \ref CAP_MODULE
  *   - \ref SENCLK_MODULE
  *   - \ref UDC20_MODULE
  *   - \ref IPSEC_MODULE
  *   - \ref WDT_MODULE
  *   - \ref WWDT_MODULE
  *   - \ref RTC_MODULE
  *   - \ref TMR0_MODULE
  *   - \ref TMR1_MODULE
  *   - \ref TMR2_MODULE
  *   - \ref TMR3_MODULE
  *   - \ref FDIV_MODULE
  *   - \ref ACMP_MODULE
  *   - \ref I2C0_MODULE
  *   - \ref I2C1_MODULE
  *   - \ref I2C2_MODULE
  *   - \ref I2C3_MODULE
  *   - \ref SPI0_MODULE
  *   - \ref SPI1_MODULE
  *   - \ref SPI2_MODULE
  *   - \ref SPI3_MODULE
  *   - \ref UART0_MODULE
  *   - \ref UART1_MODULE
  *   - \ref UART2_MODULE
  *   - \ref UART3_MODULE
  *   - \ref UART4_MODULE
  *   - \ref UART5_MODULE
  *   - \ref CAN0_MODULE
  *   - \ref CAN1_MODULE
  *   - \ref OTG_MODULE
  *   - \ref ADC_MODULE
  *   - \ref I2S0_MODULE
  *   - \ref I2S1_MODULE
  *   - \ref PS2_MODULE
  *   - \ref SC0_MODULE
  *   - \ref SC1_MODULE
  *   - \ref SC2_MODULE
  *   - \ref SC3_MODULE
  *   - \ref SC4_MODULE
  *   - \ref SC5_MODULE
  *   - \ref I2C4_MODULE
  *   - \ref PWM0CH01_MODULE
  *   - \ref PWM0CH23_MODULE
  *   - \ref PWM0CH45_MODULE
  *   - \ref PWM1CH01_MODULE
  *   - \ref PWM1CH23_MODULE
  *   - \ref PWM1CH45_MODULE
  *   - \ref QEI0_MODULE
  *   - \ref QEI1_MODULE
  *   - \ref TAMPER_MODULE
  *   - \ref ECAP0_MODULE
  *   - \ref ECAP1_MODULE
  *   - \ref EPWM0_MODULE
  *   - \ref EPWM1_MODULE
  *   - \ref OPA_MODULE
  *   - \ref EADC_MODULE
  * @return None
  */
void CLK_DisableModuleClock(uint32_t u32ModuleIdx)
{
    *(volatile uint32_t *)((uint32_t)&CLK->AHBCLK+(MODULE_AHPBCLK(u32ModuleIdx)*4))  &= ~(1<<MODULE_IP_EN_Pos(u32ModuleIdx));
}

/**
  * @brief  This function set PLL frequency
  * @param  u32PllClkSrc is PLL clock source. Including :
  *         - \ref CLK_PLLCON_PLL_SRC_HIRC
  *         - \ref CLK_PLLCON_PLL_SRC_HXT
  * @param  u32PllFreq is PLL frequency
  * @return None
  */
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq)
{
    uint32_t u32Register,u32ClkSrc,u32NF,u32NR;

    if(u32PllClkSrc==CLK_PLLCON_PLL_SRC_HIRC) {
        CLK->PLLCON = (CLK->PLLCON & ~CLK_PLLCON_PD_Msk) | (CLK_PLLCON_PLL_SRC_HIRC);
        u32Register = 1<<CLK_PLLCON_PLL_SRC_Pos;
        u32ClkSrc = __HIRC;
    } else {
        CLK->PLLCON = (CLK->PLLCON & ~CLK_PLLCON_PD_Msk);
        u32Register = 0<<CLK_PLLCON_PLL_SRC_Pos;
        u32ClkSrc = __HXT;
    }

    if(u32PllFreq<FREQ_50MHZ) {
        u32PllFreq <<=2;
        u32Register |= (0x3<<CLK_PLLCON_OUT_DV_Pos);
    } else {
        u32PllFreq <<=1;
        u32Register |= (0x1<<CLK_PLLCON_OUT_DV_Pos);
    }
    u32NF = u32PllFreq / 1000000;
    u32NR = u32ClkSrc / 1000000;
    while( u32NR>(0xF+2) || u32NF>(0xFF+2) ) {
        u32NR = u32NR>>1;
        u32NF = u32NF>>1;
    }
    CLK->PLLCON = u32Register | ((u32NR - 2)<<9) | (u32NF - 2) ;
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    return CLK_GetPLLClockFreq();
}

/**
  * @brief  This function disable PLL
  * @return None
  */
void CLK_DisablePLL(void)
{
    CLK->PLLCON &= ~CLK_PLLCON_PD_Msk;
}

/**
  * @brief  This function set SysTick clock source
  * @param  u32ClkSrc is SysTick clock source. Including :
  *  - \ref CLK_CLKSEL0_STCLK_S_HXT
  *  - \ref CLK_CLKSEL0_STCLK_S_LXT
  *  - \ref CLK_CLKSEL0_STCLK_S_HXT_DIV2
  *  - \ref CLK_CLKSEL0_STCLK_S_HCLK_DIV2
  *  - \ref CLK_CLKSEL0_STCLK_S_HIRC_DIV2
  * @return None
  */
void CLK_SetSysTickClockSrc(uint32_t u32ClkSrc)
{
    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_STCLK_S_Msk) | u32ClkSrc ;
}
/**
  * @brief  This function execute delay function.
  * @param  us  Delay time. The Max value is 2^24 / CPU Clock(MHz). Ex:
  *                             50MHz => 335544us, 48MHz => 349525us, 28MHz => 699050us ...
  * @return None
  * @details    Use the SysTick to generate the delay time and the UNIT is in us.
  *             The SysTick clock source is from HCLK, i.e the same as system core clock.
  */
void CLK_SysTickDelay(uint32_t us)
{
    SysTick->LOAD = us * CyclesPerUs;
    SysTick->VAL  =  (0x00);
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    /* Waiting for down-count to zero */
    while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
}

/**
  * @brief  This function check selected clock source status
  * @param  u32ClkMask is selected clock source. Including
  *           - \ref CLK_CLKSTATUS_CLK_SW_FAIL_Msk
  *           - \ref CLK_CLKSTATUS_HIRC_STB_Msk
  *           - \ref CLK_CLKSTATUS_LIRC_STB_Msk
  *           - \ref CLK_CLKSTATUS_PLL_STB_Msk
  *           - \ref CLK_CLKSTATUS_LXT_STB_Msk
  *           - \ref CLK_CLKSTATUS_HXT_STB_Msk
  * @return None
  */
void CLK_WaitClockReady(uint32_t u32ClkMask)
{
    int32_t i32TimeOutCnt;

    i32TimeOutCnt = __HSI / 200; /* About 5ms */

    while((CLK->CLKSTATUS & u32ClkMask) != u32ClkMask) {
        if(i32TimeOutCnt-- <= 0)
            break;
    }
}


/*@}*/ /* end of group NUC400_CLK_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_CLK_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/

