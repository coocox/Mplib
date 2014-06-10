/****************************************************************************
 * @file     LIN_Master.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/07/18 2:32p $
 * @brief    NUC200 Series UART Interface Controller Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "SYS.h"
#include "GPIO.h"
#include "UART.h"

/* CheckSum Method */
#define MODE_CLASSIC    2
#define MODE_ENHANCED   1

#define RXBUFSIZE 1024
/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
extern volatile int32_t g_i32pointer;
extern volatile int32_t g_bWait;
extern uint8_t g_u8SendData[12] ;
extern uint8_t g_u8RecData[RXBUFSIZE];

/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
extern char uart_getchar(void);
void LIN_MasterTest(uint32_t u32id,uint32_t u32ModeSel);
void LIN_MasterTestUsingLinCtlReg(uint32_t u32id,uint32_t u32ModeSel);
void LIN_SendHeader(uint32_t u32id);
void LIN_SendHeaderUsingLinCtlReg(uint32_t u32id, uint32_t u32HeaderSel);
void LIN_SendResponse(int32_t checkSumOption,uint32_t *pu32TxBuf);
void LIN_SendResponseWithByteCnt(int32_t checkSumOption,uint32_t *pu32TxBuf, uint32_t u32ByteCnt);
uint32_t GetCheckSumValue(uint8_t *pu8Buf, uint32_t u32ModeSel);
uint8_t ComputeChksumValue(uint8_t *pu8Buf, uint32_t u32ByteCnt);

void LIN_TestItem()
{
//    printf("\n\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|     LIN Master Function Test                              |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| [1] Master send header with ID = 0x30                     |\n");
    printf("| [2] Master send header and response with classic checksum |\n");
    printf("| [3] Master send header and response with enhanced checksum|\n");
    printf("|                                                           |\n");
    printf("| To measure UART1_TXD(pin46) to check waveform ...         |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| Quit                                              - [ESC] |\n");
    printf("+-----------------------------------------------------------+\n\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  LIN Function Test                                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
void LIN_FunctionTest()
{
    uint32_t u32Item;
    /* LIN Max Speeed is 20K */
    UART1->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(50000000,20000);

    /* Switch back to LIN Function */
    _UART_SEL_FUNC(UART1,UART_FUNC_SEL_LIN);

    /* === CASE 1====
        The sample code will send a LIN header with a 12-bit break field,
        0x55 sync field and ID field is 0x30. Measurement the UART1 tx pin to check it.
    */

    /* === CASE 2====
        The sample code will send a LIN header with ID is 0x35 and response field.
        The response field with 8 data bytes and checksum without including ID.
        Measurement the UART1 tx pin to check it.
    */

    /* === CASE 3====
        The sample code will send a LIN header with ID is 0x12 and response field.
        The response field with 8 data bytes and checksum with including ID.
        Measurement the UART1 tx pin to check it.
    */

    do{
        LIN_TestItem();
        u32Item = uart_getchar();
        printf("%c\n",u32Item);
        switch(u32Item)
        {
            case '1':   LIN_SendHeader(0x30);               break;
            case '2':   LIN_MasterTest(0x35,MODE_CLASSIC);  break;
            case '3':   LIN_MasterTest(0x12,MODE_ENHANCED); break;
            default:    break;
        }
    }while(u32Item != 27);

    _UART_SEL_FUNC(UART1,UART_FUNC_SEL_UART);

    printf("\nLINSample Code End.\n");
}

/*---------------------------------------------------------------------------------------------------------*/
/*  LIN Function Test                                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
void LIN_FunctionTestUsingLinCtlReg(void)
{
    uint32_t u32Item;
    /* LIN Max Speeed is 20K */
    UART1->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(50000000,20000);

    /* Switch back to LIN Function */
    _UART_SEL_FUNC(UART1,UART_FUNC_SEL_LIN);

    /* === CASE 1====
        The sample code will send a LIN header with a 12-bit break field,
        0x55 sync field and ID field is 0x30. Measurement the UART1 tx pin to check it.
    */

    /* === CASE 2====
        The sample code will send a LIN header with ID is 0x35 and response field.
        The response field with 8 data bytes and checksum without including ID.
        Measurement the UART1 tx pin to check it.
    */

    /* === CASE 3====
        The sample code will send a LIN header with ID is 0x12 and response field.
        The response field with 8 data bytes and checksum with including ID.
        Measurement the UART1 tx pin to check it.
    */

    do{
        LIN_TestItem();
        u32Item = uart_getchar();
        printf("%c\n",u32Item);
        switch(u32Item)
        {
            case '1':   LIN_SendHeaderUsingLinCtlReg(0x30,UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC_ID); break;
            case '2':   LIN_MasterTestUsingLinCtlReg(0x35,MODE_CLASSIC);  break;
            case '3':   LIN_MasterTestUsingLinCtlReg(0x12,MODE_ENHANCED); break;
            default:    break;
        }
    }while(u32Item != 27);

    UART1->LIN_CTL&= ~UART_LIN_CTL_LIN_HEAD_SEL_Msk;
    _UART_SEL_FUNC(UART1,UART_FUNC_SEL_UART);

    printf("\nLINSample Code End.\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Master send header and response                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
void LIN_MasterTest(uint32_t u32id,uint32_t u32ModeSel)
{
    uint32_t testPattern[8] ={0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};

	/*Send ID=0x35 Header and Reponse TestPatten*/
	LIN_SendHeader(u32id);
	LIN_SendResponse(u32ModeSel,&testPattern[0]);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Master send header and response                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
void LIN_MasterTestUsingLinCtlReg(uint32_t u32id,uint32_t u32ModeSel)
{
    uint8_t au8TestPattern[9] ={0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x0}; // 8 data byte + 1 byte checksum
    uint32_t i;

    if(u32ModeSel == MODE_CLASSIC)
    {
    	/* Send break+sync+ID */
    	LIN_SendHeaderUsingLinCtlReg(u32id, UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC_ID);
        /* Compute checksun without ID and fill checksum value to  au8TestPattern[8] */
        au8TestPattern[8] = ComputeChksumValue(&au8TestPattern[0],8);
        UART_Write(UART1,&au8TestPattern[0],9);
    }
    else if(u32ModeSel == MODE_ENHANCED)
    {
    	/* Send break+sync+ID and fill ID value to g_u8SendData[0]*/
    	LIN_SendHeaderUsingLinCtlReg(u32id, UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC);
        /* Fill test pattern to g_u8SendData[1]~ g_u8SendData[8] */
        for(i=0; i<8; i++)
    	    g_u8SendData[g_i32pointer++] = au8TestPattern[i];
        /* Compute checksum value with ID and fill checksum value to g_u8SendData[9] */
        g_u8SendData[g_i32pointer++] = ComputeChksumValue(&g_u8SendData[0],9) ;
        UART_Write(UART1,&g_u8SendData[1],9);
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/* Compute Parity Value                                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t GetParityValue(uint32_t u32id)
{
    uint32_t u32Res = 0,ID[6],p_Bit[2],mask =0;

    for(mask=0;mask<6;mask++)
   	    ID[mask] = (u32id & (1<<mask))>>mask;

    p_Bit[0] = (ID[0] + ID[1] + ID[2] + ID[4])%2;
    p_Bit[1] = (!((ID[1] + ID[3] + ID[4] + ID[5])%2));

    u32Res = u32id + (p_Bit[0] <<6) + (p_Bit[1]<<7);
    return u32Res;
}

/*---------------------------------------------------------------------------------------------------------*/
/* Compute CheckSum Value , MODE_CLASSIC:(Not Include ID)    MODE_ENHANCED:(Include ID)                    */
/*---------------------------------------------------------------------------------------------------------*/
uint32_t GetCheckSumValue(uint8_t *pu8Buf, uint32_t u32ModeSel)
{
 	uint32_t i,CheckSum =0;

    for(i=u32ModeSel;i<=9;i++)
	{
		CheckSum+=pu8Buf[i];
	  	if (CheckSum>=256)
	  		CheckSum-=255;
	}
	return (255-CheckSum);
}
/*---------------------------------------------------------------------------------------------------------*/
/* Compute CheckSum Value                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t ComputeChksumValue(uint8_t *pu8Buf, uint32_t u32ByteCnt)
{
 	uint32_t i,CheckSum =0;

    for(i=0 ;i<u32ByteCnt;i++)
	{
		CheckSum+=pu8Buf[i];
	  	if (CheckSum>=256)
	  		CheckSum-=255;
	}
    return (uint8_t)(255-CheckSum);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Send LIN Header Field                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
/* @image      html         LIN_SendHeader0x30.JPG */

void LIN_SendHeader(uint32_t u32id)
{
	g_i32pointer =0 ;

    /* Switch back to LIN Function */
    _UART_SEL_FUNC(UART1,UART_FUNC_SEL_LIN);

    _UART_SET_LIN_TXMODE(UART1,11);
	g_u8SendData[g_i32pointer++] = 0x55 ;                  // SYNC Field
	g_u8SendData[g_i32pointer++] = GetParityValue(u32id);   // ID+Parity Field
    UART_Write(UART1,g_u8SendData,2);
}

/*-------------------------------------------------------------------------------------------------------------------------------*/
/*  Send LIN Header Field                                                                                                        */
/*  u32HeaderSel =  UART_LIN_CTL_LIN_HEAD_SEL_BREAK/UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC/UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC_ID */
/*-------------------------------------------------------------------------------------------------------------------------------*/


void LIN_SendHeaderUsingLinCtlReg(uint32_t u32id, uint32_t u32HeaderSel)
{
    g_i32pointer =0 ;

    /* Switch back to LIN Function */
    _UART_SEL_FUNC(UART1,UART_FUNC_SEL_LIN);

    /* Set LIN 1. PID as 0x30 [UART_LIN_CTL_LIN_LIN_PID(0x30)]
               2. Header select as includes "break field", "sync field" and "frame ID field".[UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC_ID]
               3. Break/Sync Delimiter Length as 1 bit time [UART_LIN_CTL_LIN_BS_LEN(1)]
               4. Break Field Length as 12 bit time [UART_LIN_CTL_LIN_BKFL(12)]
               5. ID Parity Enable. Hardware will calculate and fill P0/P1 automatically  [UART_LIN_CTL_LIN_IDPEN_Msk]
    */
    if(u32HeaderSel == UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC_ID)
    {
        UART1->LIN_CTL = UART_LIN_CTL_LIN_LIN_PID(u32id) | UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC_ID |
                         UART_LIN_CTL_LIN_BS_LEN(1) | UART_LIN_CTL_LIN_BKFL(12) | UART_LIN_CTL_LIN_IDPEN_Msk;
        /* LIN TX Send Header Enable */
        UART1->LIN_CTL|= UART_LIN_CTL_LIN_SHD_Msk;
        /* Wait until break field, sync field and ID field transfer completed */
        while((UART1->LIN_CTL&UART_LIN_CTL_LIN_SHD_Msk) == UART_LIN_CTL_LIN_SHD_Msk);
    }
    /* Set LIN 1. Header select as includes "break field" and "sync field".[UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC]
               2. Break/Sync Delimiter Length as 1 bit time [UART_LIN_CTL_LIN_BS_LEN(1)]
               3. Break Field Length as 12 bit time [UART_LIN_CTL_LIN_BKFL(12)]
    */
    else if(u32HeaderSel == UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC)
    {
        UART1->LIN_CTL = UART_LIN_CTL_LIN_HEAD_SEL_BREAK_SYNC | UART_LIN_CTL_LIN_BS_LEN(1) | UART_LIN_CTL_LIN_BKFL(12);
        /* LIN TX Send Header Enable */
        UART1->LIN_CTL|= UART_LIN_CTL_LIN_SHD_Msk;
        /* Wait until break field and sync field transfer completed */
        while((UART1->LIN_CTL&UART_LIN_CTL_LIN_SHD_Msk) == UART_LIN_CTL_LIN_SHD_Msk);

        /* Send ID field, g_u8SendData[0] is ID+parity field*/
    	g_u8SendData[g_i32pointer++] = GetParityValue(u32id);   // ID+Parity Field
        UART_Write(UART1,g_u8SendData,1);
    }
    /* Set LIN 1. Header select as includes "break field".[UART_LIN_CTL_LIN_HEAD_SEL_BREAK]
               2. Break/Sync Delimiter Length as 1 bit time [UART_LIN_CTL_LIN_BS_LEN(1)]
               3. Break Field Length as 12 bit time [UART_LIN_CTL_LIN_BKFL(12)]
    */
    else if(u32HeaderSel == UART_LIN_CTL_LIN_HEAD_SEL_BREAK)
    {
        UART1->LIN_CTL = UART_LIN_CTL_LIN_HEAD_SEL_BREAK | UART_LIN_CTL_LIN_BS_LEN(1) | UART_LIN_CTL_LIN_BKFL(12);
        /* LIN TX Send Header Enable */
        UART1->LIN_CTL|= UART_LIN_CTL_LIN_SHD_Msk;
        /* Wait until break field transfer completed */
        while((UART1->LIN_CTL&UART_LIN_CTL_LIN_SHD_Msk) == UART_LIN_CTL_LIN_SHD_Msk);

        /* Send sync field and ID field*/
    	g_u8SendData[g_i32pointer++] = 0x55 ;                  // SYNC Field
    	g_u8SendData[g_i32pointer++] = GetParityValue(u32id);   // ID+Parity Field
        UART_Write(UART1,g_u8SendData,2);
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Send LIN Response Field                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
void LIN_SendResponse(int32_t checkSumOption,uint32_t *pu32TxBuf)
{
	int32_t i32;

	for(i32=0;i32<8;i32++)
		g_u8SendData[g_i32pointer++] = pu32TxBuf[i32] ;

	g_u8SendData[g_i32pointer++] = GetCheckSumValue(g_u8SendData,checkSumOption) ;  //CheckSum Field

	UART_Write(UART1,g_u8SendData+2,9);
}
/*---------------------------------------------------------------------------------------------------------*/
/*  Send LIN Response Field                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
void LIN_SendResponseWithByteCnt(int32_t checkSumOption,uint32_t *pu32TxBuf, uint32_t u32ByteCnt)
{
	int32_t i32;

	for(i32=0;i32<u32ByteCnt;i32++)
		g_u8SendData[g_i32pointer++] = pu32TxBuf[i32] ;

    if(checkSumOption == MODE_CLASSIC)
	    g_u8SendData[g_i32pointer++] = GetCheckSumValue(&g_u8SendData[2], u32ByteCnt) ;  //CheckSum Field
    else if(checkSumOption == MODE_ENHANCED)
	    g_u8SendData[g_i32pointer++] = GetCheckSumValue(&g_u8SendData[1], (u32ByteCnt+1)) ;  //CheckSum Field

	UART_Write(UART1,g_u8SendData+2,9);
}

