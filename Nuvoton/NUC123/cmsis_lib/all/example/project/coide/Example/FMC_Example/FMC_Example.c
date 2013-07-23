

/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    Main function of this demo is to test FMC.
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "CLOCK.h"
#include "SYS.h"
#include "UART.h"
#include "FMC.h"
#include "GPIO.h"


#define PAGE_SIZE               512
#define APROM_START_ADDRESS     0x00002000
#define LDROM_START_ADDRESS     0x00100000
#define CONFIG_START_ADDRESS    0x00300000
#define APROM_SIZE              0x00010000
#define LDROM_SIZE              0x00001000

void SYS_Init(void);
void UART0_Init(void);
void LDROM_Erase(void);
void LDROM_Program(uint32_t ulDATA);
void LDROM_Program_Verify(uint32_t ulDATA);
void APROM_Erase(void);
void APROM_Program(uint32_t ulDATA);
void APROM_Program_Verify(uint32_t ulDATA);
void CONFIG_Erase(void);
void CONFIG0_Program(uint32_t ulDATA);
void CONFIG1_Program(uint32_t ulDATA);
uint32_t CONFIG0_Read(void);
uint32_t CONFIG1_Read(void);
void LDROM_Erase_Verify(void);
void APROM_Erase_Verify(void);


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int FMC_Example(void)
{
    uint32_t u32Data[3];

    SYS_Init();
    UART0_Init();

    SYS_UnlockReg();                                              //中:解锁被保护的寄存器位，以便用户访问//en:Unlock protected register bits for user to access
    FMC_ENABLE_ISP();

    printf("APROM access to LDROM\n");

    LDROM_Erase();
    LDROM_Erase_Verify();
    LDROM_Program(0x55555555);
    LDROM_Program_Verify(0x55555555);

    FMC_ENABLE_AP_UPDATE();
    printf("APROM access to APROM\n");
    APROM_Erase();
    APROM_Erase_Verify();
    APROM_Program(0x33333333);
    APROM_Program_Verify(0x33333333);

    printf("config area Program\n");
    CONFIG_Erase();
    CONFIG0_Program(0xF8FFFFFF);
    CONFIG1_Program(0xEFFFFFFF);

    printf("Read UID\n");
    DrvFMC_ReadUID(0, &u32Data[0]);
    DrvFMC_ReadUID(1, &u32Data[1]);
    DrvFMC_ReadUID(2, &u32Data[2]);
    printf("UID %x %x %x\n", u32Data[0], u32Data[1], u32Data[2]);

    FMC_DISABLE_ISP();
    SYS_LockReg();                                                //中:重新锁被保护的寄存器位//en:Lock protected register bits again

    printf("ISP test is successful\n");

    return 0;
}



/**
 * @brief       System init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init system clock
 */
void SYS_Init(void)
{
    SYS_UnlockReg();                                        //En:Unlock protected registers
    GPIO_XT1();
    CLK_HXT_ENABLE();                                    //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB));                  //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                      //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock
    SYS_LockReg();                                          //En:Lock protected registers
}

/**
 * @brief       UART0 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set UART0 8n1, 115200bps
 */
void UART0_Init(void)
{
    STR_UART_T sParam;

    GPIO_UART0();				//En: Set UART0 all pins to PB0=RX,PB1=TX,PB2=RTS,PB3=CTS

    /* UART Setting */
    sParam.u32ClkSrc			= CLK_UART_HXT;
    sParam.u32ClkDiv			= 1;
    sParam.u32ClkFreq			= __XTAL;			//HXT/1 == __XTAL
    sParam.u32BaudRate 			= 115200;
    sParam.u32cDataBits 		= UART_WORD_LEN_8;
    sParam.u32cStopBits 		= UART_STOP_BIT_1;
    sParam.u32cParity 			= UART_PARITY_NONE;
    sParam.u32cRxTriggerLevel	= UART_FCR_RFITL_14BYTES;
    sParam.u32BaudMode    		= UART_BAUD_MODE2;
    sParam.u8RxTimeOut			= 200;

    /* Set UART Configuration */
    DrvUART_Init(UART0,&sParam);
    /* Enable UART Interrupt */
    DrvUART_EnableInt(UART0, UART_IER_RDA_IEN|UART_IER_RTO_IEN|UART_IER_TIMEOUT_COUNTER_EN);

}

/**
 * @brief       Erase LDROM
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Erase LDROM
 */
void LDROM_Erase(void)
{
    uint32_t ulCount;
    uint8_t ucPageCount;
    int32_t ret;

    FMC_ENABLE_LD_UPDATE();                             //中:使能更新LDROM功能//en:Enable update LDROM

    ucPageCount = (uint8_t)(LDROM_SIZE/PAGE_SIZE);         //中: 页数 //en: page number
    for(ulCount=0;ulCount<(uint32_t)ucPageCount;ulCount++)
    {
    	ret = DrvFMC_Erase(LDROM_START_ADDRESS + ulCount*PAGE_SIZE);  //中:擦除//en:erase
    	if(ret < 0)
    	{
            printf("LDROM Erase error\n");
    	    while(1);
    	}
    }
}

/**
 * @brief       LDROM Program
 *
 * @param       ulDATA: Data to be written to LDROM
 *
 * @return      None
 *
 * @details     LDROM Program
 */
void LDROM_Program(uint32_t ulDATA)
{
    uint32_t ulCount;
    int32_t ret;

    FMC_ENABLE_LD_UPDATE();                             //中:使能更新LDROM功能//en:Enable update LDROM

    for(ulCount=0;ulCount<(LDROM_SIZE/4);ulCount++)
    {
        ret = DrvFMC_Write(LDROM_START_ADDRESS + ulCount*4, ulDATA);          //中:写地址//en:Write address
        if(ret < 0)
    	{
            printf("Program error\n");
            while(1);
    	}
    	ulDATA = ~ulDATA;
    }
}

/**
 * @brief       Verify LDROM erase succeed or not
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Verify LDROM erase succeed or not
 */
void LDROM_Erase_Verify(void)
{
    uint32_t ulCount, u32Data;
    int32_t ret;


    for(ulCount=0;ulCount<(LDROM_SIZE/4);ulCount++)
    {
        ret = DrvFMC_Read(LDROM_START_ADDRESS + ulCount*4, &u32Data);          //中:写地址//en:Write address
        if(ret < 0)
        {
            printf("LDROM Erase Verify Read Error\n");
            while(1);
        }
        if(u32Data != 0xFFFFFFFF)                           //中:验证擦除操作是否成功//en:Verify the ERASE operation success or not
        {
            printf("Error when Erasing LDROM\n");
            while(1);
        }
    }
}

/**
 * @brief       Verify LDROM Program succeed or not
 *
 * @param       ulDATA: Data to be compared with programmed LDROM data.
 *
 * @return      None
 *
 * @details     Verify LDROM Program succeed or not
 */
void LDROM_Program_Verify(uint32_t ulDATA)
{
    uint32_t ulCount, u32Data;
    int32_t ret;

    for(ulCount=0;ulCount<(LDROM_SIZE/4);ulCount++)
    {
        ret = DrvFMC_Read(LDROM_START_ADDRESS+ulCount*4, &u32Data);          //中:写地址//en:Write address
        if(ret < 0)
    	{
            printf("Program Verity read error\n");
            while(1);
    	}
        if(FMC->ISPDAT != ulDATA)                               //中:验证编程操作是否成功//en:Verify the PROGRAM operation success or not
        {
            printf("LDROM Program Verity Error\n");
            while(1);
        }
        ulDATA = ~ulDATA;
    }
}
/**
 * @brief       APROM Erase
 *
 * @param       None
 *
 * @return      None
 *
 * @details     APROM Erase
 */
void APROM_Erase(void)
{
    uint32_t ulCount;
    uint16_t uiPageCount;
    int32_t ret;

    uiPageCount = (uint16_t)((APROM_SIZE-APROM_START_ADDRESS)/PAGE_SIZE);        //中:1024*16/512=32 pages//en:1024*16/512=32 pages
    for(ulCount=0;ulCount<(uint32_t)uiPageCount;ulCount++)
    {
        ret = DrvFMC_Erase(APROM_START_ADDRESS + ulCount*PAGE_SIZE);  //中:写地址//en:Write address
        if(ret < 0)
    	{
            printf("APROM Erase error\n");
            while(1);
    	}
    }
}

/**
 * @brief       APROM Program
 *
 * @param       ulDATA: Data to be written to APROM
 *
 * @return      None
 *
 * @details     APROM Program
 */
void APROM_Program(uint32_t ulDATA)
{
    uint32_t ulCount;
    int32_t ret;

    for(ulCount=0;ulCount<((APROM_SIZE-APROM_START_ADDRESS)/4);ulCount++)
    {
        ret = DrvFMC_Write(APROM_START_ADDRESS + ulCount*4, ulDATA);          //中:写地址//en:Write address
        if(ret < 0)
    	{
            printf("APROM Program error\n");
            while(1);
    	}
    	ulDATA = ~ulDATA;
    }
}

/**
 * @brief       Verify APROM erase succeed or not
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Verify APROM erase succeed or not
 */
void APROM_Erase_Verify(void)
{
    uint32_t ulCount, u32Data;
    int32_t ret;

    for(ulCount=0;ulCount<((APROM_SIZE-APROM_START_ADDRESS)/4);ulCount++)
    {
        ret =DrvFMC_Read(APROM_START_ADDRESS + ulCount*4, &u32Data);          //中:写地址//en:Write address
        if(ret < 0)
    	{
            printf("APROM Erase Verify Read error\n");
            while(1);
    	}
        if(u32Data != 0xFFFFFFFF)                           //中:验证擦除操作是否成功//en:Verify the ERASE operation success or not
        {
            printf("APROM Erase Verify Error\n");
            while(1);
        }
    }
}

/**
 * @brief       Verify APROM Program succeed or not
 *
 * @param       ulDATA: Data to be compared with programmed APROM data.
 *
 * @return      None
 *
 * @details     Verify APROM Program succeed or not
 */
void APROM_Program_Verify(uint32_t ulDATA)
{
    uint32_t ulCount, u32Data;
    int32_t ret;

    for(ulCount=0;ulCount<((APROM_SIZE-APROM_START_ADDRESS)/4);ulCount++)
    {
        ret =DrvFMC_Read(APROM_START_ADDRESS + ulCount*4, &u32Data);          //中:写地址//en:Write address
        if(ret < 0)
    	{
            printf("APROM Program Verify Read error\n");
            while(1);
    	}
        if(u32Data != ulDATA)                               //中:验证编程操作是否成功//en:Verify the PROGRAM operation success or not
        {
            printf("APROM Program Verify Error\n");
            while(1);
        }
        ulDATA = ~ulDATA;
    }
}
/**
 * @brief       Config Erase
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Erase Config0 and  Config1
 */
void CONFIG_Erase(void)
{
    int32_t ret;

    FMC_ENABLE_CFG_UPDATE();
    ret = DrvFMC_Erase(CONFIG_START_ADDRESS);
    if(ret < 0)
    {
        printf("Config Erase Error\n");
        while(1);
    }
}
/**
 * @brief       Program config0
 *
 * @param       ulDATA: Data to be written to CONFIG0
 *
 * @return      None
 *
 * @details     Program config0
 */
void CONFIG0_Program(uint32_t ulDATA)
{
    int32_t ret;

    FMC_ENABLE_CFG_UPDATE();
    ret = DrvFMC_Write(CONFIG_START_ADDRESS, ulDATA);
    if(ret < 0)
    {
    	printf("Config0 Program Error\n");
        while(1);
    }
}
/**
 * @brief       Program config1
 *
 * @param       ulDATA: Data to be written to CONFIG1
 *
 * @return      None
 *
 * @details     Program config1
 */
void CONFIG1_Program(uint32_t ulDATA)
{
    int32_t ret;

    FMC_ENABLE_CFG_UPDATE();
    ret = DrvFMC_Write(CONFIG_START_ADDRESS + 0x04, ulDATA);
    if(ret < 0)
    {
    	printf("Config1 Program Error\n");
        while(1);
    }
}
/**
 * @brief       Read config0
 *
 * @param       None
 *
 * @return      Config0	value
 *
 * @details     Read config0
 */
uint32_t CONFIG0_Read(void)
{
    uint32_t ulTmp;
    int32_t ret;

    ret = DrvFMC_Read(CONFIG_START_ADDRESS, &ulTmp);
    if(ret < 0)
    {
    	ulTmp = 0;
    	printf("Config0 Read Error\n");
        while(1);
    }
    return ulTmp;
}
/**
 * @brief       Read config1
 *
 * @param       None
 *
 * @return      Config1	value
 *
 * @details     Read config1
 */
uint32_t CONFIG1_Read(void)
{
    uint32_t ulTmp;
    int32_t ret;

    ret = DrvFMC_Read(CONFIG_START_ADDRESS + 0x04, &ulTmp);
    if(ret < 0)
    {
    	ulTmp = 0;
    	printf("Config1 Read Error\n");
        while(1);
    }
    return ulTmp;
}


