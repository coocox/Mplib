/******************************************************************************
 * @file     EMAC_TxRx.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 13/11/10 9:33a $
 * @brief    EMAC sample program for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "SYS.h"
#include "CLK.h"
#include "UART.h"
#include "EMAC.h"
#include "net.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_XTAL
#define PLL_CLOCK           84000000

// Our MAC address
uint8_t g_au8MacAddr[6] = {0x00, 0x00, 0x00, 0x59, 0x16, 0x88};
// Our IP address
uint8_t g_au8IpAddr[4] = {0, 0, 0, 0};
uint8_t auPkt[1514];
uint32_t u32PktLen;

// Descriptor pointers holds current Tx and Rx used by IRQ handler here.
uint32_t u32CurrentTxDesc, u32CurrentRxDesc;

void SYS_Init(void);


// This sample application can response to ICMP ECHO packets (ping)
// IP address is configure with DHCP, but if a lease cannot be acquired, a static IP will be used.
int EMAC_TxRx(void)
{

    SYS_Init();
    UART_Open(UART0, 115200);


    // Select RMII interface by default
    EMAC_Open(g_au8MacAddr);

    NVIC_EnableIRQ(EMAC_TX_IRQn);
    NVIC_EnableIRQ(EMAC_RX_IRQn);

    EMAC_ENABLE_RX();
    EMAC_ENABLE_TX();

    if (dhcp_start() < 0) {
        // Cannot get a DHCP lease, use static IP.
        printf("DHCP failed, use static IP 192.168.10.10\n");
        g_au8IpAddr[0] = 0xC0;
        g_au8IpAddr[1] = 0xA8;
        g_au8IpAddr[2] = 0x0A;
        g_au8IpAddr[3] = 0x0A;
    }
    while(1);

}


/**
  * @brief  EMAC Tx interrupt handler.
  * @param  None
  * @return None
  */
void EMAC_TX_IRQHandler(void)
{
    // Clean up Tx resource occupied by previous sent packet(s)
    EMAC_SendPktDone();
}

/**
  * @brief  EMAC Rx interrupt handler.
  * @param  None
  * @return None
  */
void EMAC_RX_IRQHandler(void)
{

    while(1) {
        // Check if there's any packets available
        if(EMAC_RecvPkt(auPkt, &u32PktLen) == 0)
            break;
        // Process receive packet
        process_rx_packet(auPkt, u32PktLen);
        // Clean up Rx resource occupied by previous received packet
        EMAC_RecvPktDone();
    }
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

    /* Switch HCLK clock source to HXT */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON |= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = CLK_PLLCON_84MHz_HXT;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(EMAC_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV0_UART(1));

    // Configure MDC clock rate to HCLK / (127 + 1) = 656 kHz if system is running at 84 MHz
    CLK_SetModuleClock(EMAC_MODULE, CLK_CLKSEL0_EMAC_S_PLL, CLK_CLKDIV3_EMAC_MDCLK(127));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();


    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;
    // Configure RMII pins
    SYS->GPC_MFPL = SYS_GPC_MFPL_PC0_MFP_EMAC_REFCLK |
                    SYS_GPC_MFPL_PC1_MFP_EMAC_MII_RXERR |
                    SYS_GPC_MFPL_PC2_MFP_EMAC_MII_RXDV |
                    SYS_GPC_MFPL_PC3_MFP_EMAC_MII_RXD1 |
                    SYS_GPC_MFPL_PC4_MFP_EMAC_MII_RXD0 |
                    SYS_GPC_MFPL_PC6_MFP_EMAC_MII_TXD0 |
                    SYS_GPC_MFPL_PC7_MFP_EMAC_MII_TXD1;


    SYS->GPC_MFPH = SYS_GPC_MFPH_PC8_MFP_EMAC_MII_TXEN;
    // Enable high slew rate on all RMII pins
    PC->HS |= 0x1DF;

    // Configure MDC, MDIO at PB14 & PB15
    SYS->GPB_MFPH = SYS_GPB_MFPH_PB14_MFP_EMAC_MII_MDC | SYS_GPB_MFPH_PB15_MFP_EMAC_MII_MDIO;

    /* Lock protected registers */
    SYS_LockReg();

}

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
