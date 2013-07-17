/******************************************************************************
 * @file     nano1xx_i2c.c
 * @brief    NANO1xx I2C driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
//* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "NUC123Series.h"
#include "I2C.h"
#include "CLOCK.h"
#include "SYS.h"



/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvI2C_FUNC I2C Driver API
  * @{
  */

/**
  * @brief  Set I2C control bit.
  * @param  I2cPort: I2C port handler
  *         start: Set I2C START bit.
  *			stop: Set I2C STOP bit.
  *			ack: set I2C ACK bit.
  * @retval None.
  * example: Set Start: DrvI2C_Ctrl(I2C0, 1, 0, 0, 0);
  */

void DrvI2C_Ctrl(I2C_T *I2cPort, uint8_t start, uint8_t stop, uint8_t si, uint8_t ack)
{
    
    uint32_t Reg = 0;
        
    if (start)
        Reg |= I2C_CON_STA;
    if (stop)
        Reg |= I2C_CON_STO;
    if (si)
        Reg |= I2C_CON_SI;
    if (ack)
        Reg |= I2C_CON_AA;

	I2cPort->I2CON = (I2cPort->I2CON & ~0x3C) | Reg;
}

/**
  * @brief  Enable I2C function and set clock divider. I2C clock = PCLK / (4x(divider+1)).
  * @param  I2cPort: I2C port handler
  *			u32BusClock: I2C bus clock frequency (Hz)  
  * @retval None.
  */
void DrvI2C_Init(I2C_T *I2cPort, uint32_t u32BusClock, uint8_t EnableInt)
{
    uint32_t divider;     
 		
    divider = (uint32_t) (((CLK_GetHCLKFreq()*10)/(u32BusClock * 4) + 5) / 10 - 1);	/* Compute proper divider for I2C clock */
	
    if((uint32_t)I2cPort == I2C1_BASE)
    {		
        SYS_RESET_IP2(SYS_RST_I2C1);                        //中:复位I2C模块//en:Reset I2C IP module		
        APBCLK_ENABLE(CLK_I2C1);                            //中:使能I2C时钟//en:Enable I2C0 clock
    }
    else
    {		
        SYS_RESET_IP2(SYS_RST_I2C0);                        //中:复位I2C模块//en:Reset I2C IP module
        APBCLK_ENABLE(CLK_I2C0);                            //中:使能I2C时钟//en:Enable I2C0 clock
    }
	
    I2C_SET_DIVIDER(I2cPort, divider);
    if(EnableInt)
    {
        I2C_ENABLE_I2C_INT(I2cPort);
        if((uint32_t)I2cPort == I2C0_BASE)	
            NVIC_EnableIRQ(I2C0_IRQn);
        else if((uint32_t)I2cPort == I2C1_BASE)	
            NVIC_EnableIRQ(I2C1_IRQn);	
    }
    I2C_ENABLE_I2C(I2cPort);
}

/**
  * @brief  Disable I2C function and clock source.
  * @param  I2cPort: I2C port handler  
  * @retval 0: None
  */
void DrvI2C_DeInit(I2C_T *I2cPort)
{
    I2C_DISABLE_I2C_INT(I2cPort);
    I2C_DISABLE_I2C(I2cPort);
    if((uint32_t)I2cPort == I2C0_BASE)	
        NVIC_DisableIRQ(I2C0_IRQn);
    else if((uint32_t)I2cPort == I2C1_BASE)	
        NVIC_DisableIRQ(I2C1_IRQn);
}

/**
  * @brief  Get I2C bit rate.
  * @param  I2cPort: I2C port handler   
  * @retval I2C Bus Clock Frequency
  */
uint32_t DrvI2C_GetClockFreq(I2C_T *I2cPort)
{
    uint32_t divider;     
 
    divider = I2cPort->I2CLK;
    return ( CLK_GetHCLKFreq() / ((divider+1)<<2) );
}

/**
  * @brief  Enable I2C interrupt and NVIC corresponding to I2C.
  * @param  I2cPort: I2C port handler  
  * @retval 0: None.
  */
void DrvI2C_EnableInt(I2C_T *I2cPort)
{	
    I2C_ENABLE_I2C_INT(I2cPort);
		
    if((uint32_t)I2cPort == I2C0_BASE)	
        NVIC_EnableIRQ(I2C0_IRQn);
    else if((uint32_t)I2cPort == I2C1_BASE)	
        NVIC_EnableIRQ(I2C1_IRQn);	
}

/**
  * @brief  Disable I2C interrupt and NVIC corresponding to I2C.
  * @param  I2cPort: I2C port handler  
  * @retval 0: None.
  */
void DrvI2C_DisableInt(I2C_T *I2cPort)
{
    I2C_DISABLE_I2C_INT(I2cPort);
	
    if((uint32_t)I2cPort == I2C0_BASE)	
        NVIC_DisableIRQ(I2C0_IRQn);
    else if((uint32_t)I2cPort == I2C1_BASE)	
        NVIC_DisableIRQ(I2C1_IRQn);   
}

/**
  * @brief  Set 2 7-bit slave addresses and enable General Call function.
  * @param  I2cPort: I2C port handler
  *			SlaveNo: There are 4 slave addrss. The slaveNo is 0/1/2/3.
  *			salve_addr: 7-bit data
  *			GC_Flag: Enable/Disable GC function
  * @retval 0: Success.
  *			<0: Failed.
  */
int32_t DrvI2C_SetAddress(I2C_T *I2cPort, uint8_t slaveNo, uint8_t slave_addr, uint8_t GC_Flag)
{	
    switch (slaveNo)
    {
        case 0:
            I2C_SET_ADDRESS0(I2cPort,(slave_addr << 1) | GC_Flag);
            break;
        case 1:
            I2C_SET_ADDRESS1(I2cPort,(slave_addr << 1) | GC_Flag);
            break;			
        case 2:
            I2C_SET_ADDRESS2(I2cPort,(slave_addr << 1) | GC_Flag);
            break;
        case 3:
            I2C_SET_ADDRESS3(I2cPort,(slave_addr << 1) | GC_Flag);
            break;
       default:
            return -1;
    }

    return 1;
}

/**
  * @brief  Set 2 7-bit slave address mask. The corresponding address bit is "Don't Care".
  * @param  I2cPort: I2C port handler
  *			SlaveNo: There are 4 slave addrss. The slaveNo is 0/1/2/3.
  *			slaveAddrMask: 7-bit data  
  * @retval 0: Success.
  *			<0: Failed.
  */
int32_t DrvI2C_SetAddressMask(I2C_T *I2cPort, uint8_t slaveNo, uint8_t slaveAddrMask)
{
    switch (slaveNo)
    {
        case 0:
            I2C_SET_ADDRESS_MASK0(I2cPort, slaveAddrMask << 1);
            break;
        case 1:
            I2C_SET_ADDRESS_MASK1(I2cPort, slaveAddrMask << 1);
            break;
        case 2:
            I2C_SET_ADDRESS_MASK2(I2cPort, slaveAddrMask << 1);
            break;			
        case 3:
            I2C_SET_ADDRESS_MASK3(I2cPort, slaveAddrMask << 1);
            break;	
        default:
            return -1;
    }
	
    return 0;
}


/*@}*/ /* end of group DrvI2C_FUNC */

/*@}*/ /* end of group NUC123_FUNC */


/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/
