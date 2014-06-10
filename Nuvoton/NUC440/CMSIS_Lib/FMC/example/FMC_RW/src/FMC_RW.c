/**************************************************************************//**
 * @file     FMC_RW.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 13/11/10 9:33a $
 * @brief    FMC flash read/write sample program for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "fmc.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000

uint32_t PllClock         = PLL_CLOCK;


#define USING_WRITE_64
#define USING_READ_64

#define APROM_TEST_BASE             0x10000
#define DATA_FLASH_TEST_BASE        0x18000
#define DATA_FLASH_TEST_END         0x20000

#define TEST_PATTERN                0xA5A5A5A5

int32_t  flash_test(uint32_t u32StartAddr, uint32_t u32EndAddr, uint32_t u32Pattern);
int32_t  verify_data(uint32_t u32StartAddr, uint32_t u32EndAddr, uint32_t u32Pattern);
int32_t fill_data_pattern(uint32_t u32StartAddr, uint32_t u32EndAddr, uint32_t u32Pattern);
static int  set_data_flash_base(uint32_t u32DFBA);
void UART0_Init(void);
void SYS_Init(void);


int FMC_RW()
{
    uint32_t u32Data, au32Config[4];

    /* Lock protected registers */
    if (SYS->REGWRPROT == 1) // In end of main function, program issued CPU reset and write-protection will be disabled.
        SYS_LockReg();

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART0 for printf */
    UART0_Init();

    /* Enable FMC ISP function */
    SYS_UnlockReg();
    FMC_Open();

    /* Read Company ID */
    u32Data = FMC_ReadCID();
    if (u32Data != 0xda) {
        printf("Wrong CID: 0x%x\n", u32Data);
        goto lexit;
    }

    /*
     *  Enable Data Flash and set Data Flash base address as DATA_FLASH_TEST_BASE.
     */
    if (set_data_flash_base(DATA_FLASH_TEST_BASE) < 0) {
        printf("Failed to set Data Flash base address!\n");
        goto lexit;
    }

    printf("\n\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("|            NUC4xx Flash Memory Controller Driver Sample Code           |\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("  NOTE: This sample must be applied to NUC4xx series.\n");

    /* Read BS */
    printf("  Boot Mode .................................. ");
    if (FMC_GetBootSource() == IS_BOOT_FROM_APROM)
        printf("[APROM]\n");
    else {
        printf("[LDROM]\n");
        printf("  WARNING: The driver sample code must execute in AP mode!\n");
        goto lexit;
    }

    u32Data = FMC_ReadCID();
    printf("  Company ID ................................. [0x%08x]\n", u32Data);

    u32Data = FMC_ReadDID();
    printf("  Device ID .................................. [0x%08x]\n", u32Data);

    u32Data = FMC_ReadPID();
    printf("  Product ID ................................. [0x%08x]\n", u32Data);

    u32Data = FMC_ReadUID(0);
    printf("  Unique ID 0 ................................ [0x%08x]\n", u32Data);

    u32Data = FMC_ReadUID(1);
    printf("  Unique ID 1 ................................ [0x%08x]\n", u32Data);

    u32Data = FMC_ReadUID(2);
    printf("  Unique ID 2 ................................ [0x%08x]\n", u32Data);

    u32Data = FMC_ReadUCID(0);
    printf("  Unique Customer ID 0 ....................... [0x%08x]\n", u32Data);

    u32Data = FMC_ReadUCID(1);
    printf("  Unique Customer ID 1 ....................... [0x%08x]\n", u32Data);

    u32Data = FMC_ReadUCID(2);
    printf("  Unique Customer ID 2 ....................... [0x%08x]\n", u32Data);

    u32Data = FMC_ReadUCID(3);
    printf("  Unique Customer ID 3 ....................... [0x%08x]\n", u32Data);

    /* Read Data Flash base address */
    u32Data = FMC_ReadDataFlashBaseAddr();
    printf("  Data Flash Base Address .................... [0x%08x]\n", u32Data);

    FMC_ReadConfig(au32Config, 3);
    printf("  User Config 0 .............................. [0x%08x]\n", au32Config[0]);
    printf("  User Config 1 .............................. [0x%08x]\n", au32Config[1]);
    printf("  User Config 2 .............................. [0x%08x]\n", au32Config[2]);

    printf("  ISPSTA...................................... [0x%08x]\n", FMC->ISPSTA);

    printf("\n\nLDROM test =>\n");
    FMC_EnableLDUpdate();
    if (flash_test(FMC_LDROM_BASE, FMC_LDROM_END, TEST_PATTERN) < 0) {
        printf("\n\nLDROM test failed!\n");
        goto lexit;
    }
    FMC_DisableLDUpdate();

    printf("\n\nAPROM test =>\n");
    FMC_EnableAPUpdate();
    if (flash_test(APROM_TEST_BASE, DATA_FLASH_TEST_BASE, TEST_PATTERN) < 0) {
        printf("\n\nAPROM test failed!\n");
        goto lexit;
    }
    FMC_DisableAPUpdate();

    printf("\n\nData Flash test =>\n");
    if (flash_test(DATA_FLASH_TEST_BASE, DATA_FLASH_TEST_END, TEST_PATTERN) < 0) {
        printf("\n\nUHB test failed!\n");
        goto lexit;
    }

lexit:

    /* Disable FMC ISP function */
    FMC_Close();

    /* Lock protected registers */
    SYS_LockReg();

    printf("\nFMC Sample Code Completed.\n");

    while (1);
}


void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    CLK_EnableXtalRC(CLK_PWRCON_HXT_EN_Msk);

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON|= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK->CLKSEL0 = CLK_CLKSEL0_HCLK_S_PLL;

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE,CLK_CLKSEL1_UART_S_HXT,CLK_CLKDIV0_UART(1));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* Lock protected registers */
    SYS_LockReg();
}


void UART0_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset IP */
    SYS_ResetModule(UART0_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART0->LCR |=0x07;
    UART0->BAUD = 0x30000066;   /* 12MHz reference clock input, for 115200 */
}


static int  set_data_flash_base(uint32_t u32DFBA)
{
    uint32_t   au32Config[4];

    if (FMC_ReadConfig(au32Config, 4) < 0) {
        printf("\nRead User Config failed!\n");
        return -1;
    }

    if ((!(au32Config[0] & 0x1)) && (au32Config[1] == u32DFBA))
        return 0;

    FMC_EnableConfigUpdate();

    au32Config[0] &= ~0x1;
    au32Config[1] = u32DFBA;

    if (FMC_WriteConfig(au32Config, 4) < 0)
        return -1;

    // Perform chip reset to make new User Config take effect
    SYS->IPRSTC1 = SYS_IPRSTC1_CHIP_RST_Msk;
    return 0;
}


int32_t fill_data_pattern(uint32_t u32StartAddr, uint32_t u32EndAddr, uint32_t u32Pattern)
{
    uint32_t u32Addr;

#ifdef USING_WRITE_64
    for (u32Addr = u32StartAddr; u32Addr < u32EndAddr; u32Addr += 8) {
        FMC_Write_64(u32Addr, u32Pattern, u32Pattern);
    }
#else
    for (u32Addr = u32StartAddr; u32Addr < u32EndAddr; u32Addr += 4) {
        FMC_Write(u32Addr, u32Pattern);
    }
#endif
    return 0;
}


#ifdef USING_READ_64
int32_t  verify_data(uint32_t u32StartAddr, uint32_t u32EndAddr, uint32_t u32Pattern)
{
    uint32_t    u32Addr;
    uint32_t    u32data0, u32data1;

    for (u32Addr = u32StartAddr; u32Addr < u32EndAddr; u32Addr += 8) {
        u32data0 = u32data1 = 0;
        FMC_Read_64(u32Addr, &u32data0, &u32data1);
        if ((u32data0 != u32Pattern) || (u32data1 != u32Pattern)) {
            printf("\nFMC_Read_64 verify failed at address 0x%x, read=0x%x 0x%x, expect=0x%x!\n", u32Addr, u32data0, u32data1, u32Pattern);
            return -1;
        }
    }
    return 0;
}
#else
int32_t  verify_data(uint32_t u32StartAddr, uint32_t u32EndAddr, uint32_t u32Pattern)
{
    uint32_t    u32Addr;
    uint32_t    u32data;

    if (u32StartAddr == UHB_BASE)
        u32EndAddr = UHB_END;

    for (u32Addr = u32StartAddr; u32Addr < u32EndAddr; u32Addr += 4) {
        u32data = FMC_Read(u32Addr, &u32data);
        if (u32data != u32Pattern) {
            printf("\nFMC_Read data verify failed at address 0x%x, read=0x%x, expect=0x%x\n", u32Addr, u32data, u32Pattern);
            return -1;
        }
    }
    return 0;
}
#endif


int32_t  flash_test(uint32_t u32StartAddr, uint32_t u32EndAddr, uint32_t u32Pattern)
{
    uint32_t    u32Addr;

    for (u32Addr = u32StartAddr; u32Addr < u32EndAddr; u32Addr += FMC_FLASH_PAGE_SIZE) {
        printf("    Flash test address: 0x%x    \r", u32Addr);

        // Erase page
        if (FMC_Erase(u32Addr) < 0) {
            printf("\nPage 0x%x erase failed!\n", u32Addr);
            return -1;
        }

        // Verify if page contents are all 0xFFFFFFFF
        if (verify_data(u32Addr, u32Addr + FMC_FLASH_PAGE_SIZE, 0xFFFFFFFF) < 0) {
            printf("\nPage 0x%x erase verify failed!\n", u32Addr);
            return -1;
        }

        // Write test pattern to fill the whole page
        if (fill_data_pattern(u32Addr, u32Addr + FMC_FLASH_PAGE_SIZE, u32Pattern) < 0) {
            printf("Failed to write page 0x%x!\n", u32Addr);
            FMC_Erase(u32Addr);
            return -1;
        }

        // Verify if page contents are all equal to test pattern
        if (verify_data(u32Addr, u32Addr + FMC_FLASH_PAGE_SIZE, u32Pattern) < 0) {
            printf("\nData verify failed!\n ");
            FMC_Erase(u32Addr);
            return -1;
        }

        // Erase page
        if (FMC_Erase(u32Addr) < 0) {
            printf("\nPage 0x%x erase failed!\n", u32Addr);
            return -1;
        }

        // Verify if page contents are all 0xFFFFFFFF
        if (verify_data(u32Addr, u32Addr + FMC_FLASH_PAGE_SIZE, 0xFFFFFFFF) < 0) {
            printf("\nPage 0x%x erase verify failed!\n", u32Addr);
            return -1;
        }
    }
    printf("\r    Flash Test Passed.          \n");
    return 0;
}

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
