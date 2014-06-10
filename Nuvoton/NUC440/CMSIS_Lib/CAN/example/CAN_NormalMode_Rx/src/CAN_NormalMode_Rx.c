/******************************************************************************
 * @file     CAN_NormalMode_Rx.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 14/01/14 10:15a $
 * @brief    Sample program for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "uart.h"
#include "can.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000

extern char GetChar(void);

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
STR_CANMSG_T rrMsg;

void CAN_ShowMsg(STR_CANMSG_T* Msg);
void CAN_MsgInterrupt(CAN_T *tCAN, uint32_t u32IIDR);
void SYS_Init(void);
void UART0_Init();
void CAN_Init(CAN_T  *tCAN);
void CAN_STOP(CAN_T  *tCAN);
void Note_Configure();
void SelectCANSpeed(CAN_T  *tCAN);
void CAN_ShowMsg(STR_CANMSG_T* Msg);
void Test_NormalMode_Rx(CAN_T *tCAN);


int CAN_NormalMode_Rx()
{
    CAN_T *tCAN;

    tCAN = (CAN_T *) CAN0;

    SYS_Init();
    UART0_Init();

    /* Select CAN Multi-Function */
    CAN_Init(tCAN);
    Note_Configure();
    SelectCANSpeed(tCAN);

    printf("\n");
    printf("+------------------------------------------------------------------ +\n");
    printf("|  Nuvoton CAN BUS DRIVER DEMO                                      |\n");
    printf("+-------------------------------------------------------------------+\n");
    printf("|  Receive a message by normal mode                                 |\n");
    printf("+-------------------------------------------------------------------+\n");

    printf("Press any key to continue ...\n\n");
    GetChar();
    Test_NormalMode_Rx(tCAN);

    while(1) ;

}


/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle CAN interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void CAN_MsgInterrupt(CAN_T *tCAN, uint32_t u32IIDR)
{
    if(u32IIDR==1) {
        printf("Msg-0 INT and Callback\n");
        CAN_Receive(tCAN, 0,&rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
    if(u32IIDR==5+1) {
        printf("Msg-5 INT and Callback \n");
        CAN_Receive(tCAN, 5,&rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
    if(u32IIDR==31+1) {
        printf("Msg-31 INT and Callback \n");
        CAN_Receive(tCAN, 31,&rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
}


/**
  * @brief  CAN0_IRQ Handler.
  * @param  None.
  * @return None.
  */
void CAN0_IRQHandler(void)
{
    uint32_t u8IIDRstatus;

    u8IIDRstatus = CAN0->IIDR;

    if(u8IIDRstatus == 0x00008000) {      /* Check Status Interrupt Flag (Error status Int and Status change Int) */
        /**************************/
        /* Status Change interrupt*/
        /**************************/
        if(CAN0->STATUS & CAN_STATUS_RXOK_Msk) {
            CAN0->STATUS &= ~CAN_STATUS_RXOK_Msk;   /* Clear Rx Ok status*/

            printf("RX OK INT\n") ;
        }

        if(CAN0->STATUS & CAN_STATUS_TXOK_Msk) {
            CAN0->STATUS &= ~CAN_STATUS_TXOK_Msk;    /* Clear Tx Ok status*/

            printf("TX OK INT\n") ;
        }

        /**************************/
        /* Error Status interrupt */
        /**************************/
        if(CAN0->STATUS & CAN_STATUS_EWARN_Msk) {
            printf("EWARN INT\n") ;
        }

        if(CAN0->STATUS & CAN_STATUS_BOFF_Msk) {
            printf("BOFF INT\n") ;
        }
    } else if (u8IIDRstatus!=0) {
        printf("=> Interrupt Pointer = %d\n",CAN0->IIDR -1);

        CAN_MsgInterrupt(CAN0, u8IIDRstatus);

        CAN_CLR_INT_PENDING_BIT(CAN0, ((CAN0->IIDR) -1));      /* Clear Interrupt Pending */

    } else if(CAN0->WU_STATUS == 1) {
        printf("Wake up\n");

        CAN0->WU_STATUS = 0;                       /* Write '0' to clear */
    }

}



void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    // TODO: Configure system clock

    CLK->PWRCON |= CLK_PWRCON_HXT_EN_Msk;

    CLK_WaitClockReady(CLK_CLKSTATUS_HXT_STB_Msk);

    // HCLK select external 4~24 MHz high speed crystal clock
    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(CLK_CLKSEL0_HCLK_S_Msk));

    //uart clock source select external 4~24 MHz high speed crystal clock
    CLK->CLKSEL1  &= ~CLK_CLKSEL1_UART_S_Msk;

    // Enable IP clock
    CLK->APBCLK0 |= CLK_APBCLK0_UART3_EN_Msk | CLK_APBCLK0_TMR0_EN_Msk;
    CLK->APBCLK0 |= CLK_APBCLK0_UART0_EN_Msk; // UART0 Clock Enable


    /* Select IP clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_UART_S_Pos);// Clock source from external 12 MHz or 32 KHz crystal clock

    // Enable UART3 pin function (H11 & H12)
    //SYS->GPH_MFPH = (SYS->GPH_MFPH & ~(SYS_GPH_MFPH_PH11_MFP_Msk | SYS_GPH_MFPH_PH12_MFP_Msk)) | 0x00011000;
    /* Set PG multi-function pins for UART0 RXD, TXD */
    SYS->GPG_MFPL &= ~(SYS_GPG_MFPL_PG1_MFP_Msk | SYS_GPG_MFPL_PG2_MFP_Msk);
    SYS->GPG_MFPL |= (SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD);

    // Enable CAN0 pin function (B12 & B13)
    SYS->GPB_MFPH = (SYS->GPB_MFPH & ~(SYS_GPB_MFPH_PB12_MFP_Msk | SYS_GPB_MFPH_PB13_MFP_Msk)) | (0x33 << SYS_GPB_MFPH_PB12_MFP_Pos);

    /* Lock protected registers */
    SYS_LockReg();

}

void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    UART_Open(UART0, 115200);
}


/**
  * @brief      Init CAN driver
  */

void CAN_Init(CAN_T  *tCAN)
{
    if(tCAN == CAN0) {
        // Enable IP clock
        CLK->APBCLK0 |= CLK_APBCLK0_CAN0_EN_Msk;

        // Reset CAN0
        SYS->IPRSTC2 |= SYS_IPRSTC2_CAN0_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_CAN0_RST_Msk;
    } else if(tCAN == CAN1) {
        // Enable IP clock
        CLK->APBCLK0 |= CLK_APBCLK0_CAN1_EN_Msk;

        // Reset CAN1
        SYS->IPRSTC2 |= SYS_IPRSTC2_CAN1_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_CAN1_RST_Msk;
    }
}

/**
  * @brief      Disable CAN
  * @details    Reset and clear all CAN control and disable CAN IP
  */

void CAN_STOP(CAN_T  *tCAN)
{
    if(tCAN == CAN0) {
        /* Disable CAN0 Clock and Reset it */
        SYS->IPRSTC2 |= SYS_IPRSTC2_CAN0_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_CAN0_RST_Msk;
        CLK->APBCLK0 &= ~CLK_APBCLK0_CAN0_EN_Msk;
    } else if(tCAN == CAN1) {
        /* Disable CAN0 Clock and Reset it */
        SYS->IPRSTC2 |= SYS_IPRSTC2_CAN1_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_CAN1_RST_Msk;
        CLK->APBCLK0 &= ~CLK_APBCLK0_CAN1_EN_Msk;
    }
}

/*----------------------------------------------------------------------------*/
/*  Some description about how to create test environment                     */
/*----------------------------------------------------------------------------*/
void Note_Configure()
{
    printf("\n\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("|  About CAN sample code configure                                       |\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("|   The sample code provide a simple sample code for you study CAN       |\n");
    printf("|   Before execute it, please check description as below                 |\n");
    printf("|                                                                        |\n");
    printf("|   1.CAN_TX and CAN_RX should be connected to your CAN transceiver      |\n");
    printf("|   2.Using two module board and connect to the same CAN BUS             |\n");
    printf("|   3.Check the terminal resistor of bus is connected                    |\n");
    printf("|   4.Using UART0 as print message port(Both of NUC1xx module boards)    |\n");
    printf("|                                                                        |\n");
    printf("|  |--------|       |-----------|  CANBUS |-----------|       |--------| |\n");
    printf("|  |        |------>|           |<------->|           |<------|        | |\n");
    printf("|  |        |CAN_TX |   CAN     |  CAN_H  |   CAN     |CAN_TX |        | |\n");
    printf("|  | NUC4XX |       |Transceiver|         |Transceiver|       | NUC4XX | |\n");
    printf("|  |        |<------|           |<------->|           |------>|        | |\n");
    printf("|  |        |CAN_RX |           |  CAN_L  |           |CAN_RX |        | |\n");
    printf("|  |--------|       |-----------|         |-----------|       |--------| |\n");
    printf("|   |                                                           |        |\n");
    printf("|   |                                                           |        |\n");
    printf("|   V                                                           V        |\n");
    printf("| UART0                                                         UART0    |\n");
    printf("|(print message)                                          (print message)|\n");
    printf("+------------------------------------------------------------------------+\n");
}

void SelectCANSpeed(CAN_T  *tCAN)
{
    uint32_t unItem;
    int32_t i32Err =0;

    printf("Please select CAN speed you desired\n");
    printf("[0] 1000Kbps\n");
    printf("[1]  500Kbps\n");
    printf("[2]  250Kbps\n");
    printf("[3]  125Kbps\n");
    printf("[4]  100Kbps\n");
    printf("[5]   50Kbps\n");

    unItem = GetChar();
    printf("%c\n",unItem) ;
    if(unItem=='1')
        i32Err = CAN_Open(tCAN,  500000, CAN_NOTMAL_MODE);
    else if(unItem=='2')
        i32Err = CAN_Open(tCAN,  250000, CAN_NOTMAL_MODE);
    else if(unItem=='3')
        i32Err = CAN_Open(tCAN,  125000, CAN_NOTMAL_MODE);
    else if(unItem=='4')
        i32Err = CAN_Open(tCAN,  100000, CAN_NOTMAL_MODE);
    else if(unItem=='5')
        i32Err = CAN_Open(tCAN,   50000, CAN_NOTMAL_MODE);
    else
        i32Err = CAN_Open(tCAN, 1000000, CAN_NOTMAL_MODE);

    if(i32Err<0)
        printf("Set CAN bit rate is fail\n");
}

/*----------------------------------------------------------------------------*/
/*  Test Function                                                             */
/*----------------------------------------------------------------------------*/
void CAN_ShowMsg(STR_CANMSG_T* Msg)
{
    uint8_t i;
    printf("Read ID=%8X, Type=%s, DLC=%d,Data=",Msg->Id,Msg->IdType?"EXT":"STD",Msg->DLC);
    for(i=0; i<Msg->DLC; i++)
        printf("%02X,",Msg->Data[i]);
    printf("\n\n");
}

/*----------------------------------------------------------------------------*/
/*  Send Rx Msg by Normal Mode Function (With Message RAM)                    */
/*----------------------------------------------------------------------------*/

void Test_NormalMode_Rx(CAN_T *tCAN)
{
    if(CAN_SetRxMsg(tCAN, MSG(0),CAN_STD_ID, 0x7FF) == FALSE) {
        printf("Set Rx Msg Object failed\n");
        return;
    }

    if(CAN_SetRxMsg(tCAN, MSG(5),CAN_STD_ID, 0x7FF) == FALSE) {
        printf("Set Rx Msg Object failed\n");
        return;
    }

    if(CAN_SetRxMsg(tCAN, MSG(31),CAN_STD_ID, 0x7FF) == FALSE) {
        printf("Set Rx Msg Object failed\n");
        return;
    }
    /*Choose one mode to test*/
#if 1
    /* Polling Mode */
    while(1) {
        while(tCAN->IIDR ==0);            /* Wait IDR is changed */
        printf("IDR = %x\n",tCAN->IIDR);
        CAN_Receive(tCAN, tCAN->IIDR -1, &rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
#else
    /* INT Mode */
    CAN_EnableInt(tCAN, CAN_CON_IE_Msk);
    NVIC_SetPriority(CAN0_IRQn, (1<<__NVIC_PRIO_BITS) - 2);
    NVIC_EnableIRQ(CAN0_IRQn);
    printf("Wait Msg\n");
    printf("Enter any key to exit\n");
    GetChar();
#endif
}

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
