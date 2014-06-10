/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2010 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "NUC200Series.h"
#include "WAU8822.h"
#include "I2C.h"
#include "I2S.h"
#include "SYS.h"

//#define DBG_PRINTF  printf
#define DBG_PRINTF(...)

#define WAU8822_WRITE_ADDR      0x34

/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* FUNCTION                                                                                                */
/*      WAU8822_Write()	          	                                               			           */
/*                                                                                                         */
/* DESCRIPTION                                                                                             */
/*      The function is to write 9-bit data to 7-bit address register of WAU8822 with I2C interface. 	   */
/*                                                                                                         */
/* INPUTS                                                                                                  */
/*      None                                                                                               */
/*                                                                                                         */
/* OUTPUTS                                                                                                 */
/*      None                            				                                                   */
/*                                                                                                         */
/* RETURN                                                                                                  */
/*      None                                                                                               */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#if 0 // Implement I2C by GPIO

// The I/O for I2C must be in qusi-bidirectional mode
#define SCK     PA11           
#define SDA     PA10


#define DELAY   SYS_SysTickDelay(10)
#define DATA0   SDA = 1;DELAY;SCK = 1;DELAY;SCK = 0;DELAY;
#define DATA1   SDA = 1;DELAY;SCK = 1;DELAY;SCK = 0;DELAY;
#define IDLE1   SCK = 1;DELAY;SDA = 1;DELAY;
#define IDLE0   SCK = 0;DELAY;SDA = 0;DELAY;
#define START   SCK = 1;DELAY;SDA = 0;DELAY;SCK = 0;DELAY; SDA = 0;DELAY;
#define STOP    SCK = 1;DELAY;SDA = 0;DELAY;SCK = 1;DELAY; SDA = 1;DELAY;

int32_t SendData(uint8_t u8Data)
{
    int32_t i;
    int32_t i32Ack;
    
    for(i=7;i>=0;i--)
    {
        SDA = (u8Data >> i) & 1;DELAY;
        SCK = 1;DELAY;
        SCK = 0;DELAY;
    }

    SDA = 1;DELAY;
    SCK = 1;DELAY;
    i32Ack = SDA;DELAY;
    SCK = 0;DELAY;
    
    return i32Ack;

}

void WAU8822_Write(uint32_t u32Addr, uint16_t u16Data)
{
    int32_t i32Err;
    int32_t i32Ack;

    do
    {
        i32Err = 0;
        // Start
        IDLE1;
        START;
        
        i32Ack = SendData(WAU8822_WRITE_ADDR);
        if(i32Ack == 0)
        {
            i32Ack = SendData(((u32Addr & 0x7FUL) << 1) | ((u16Data >> 8) & 1));
            if(i32Ack == 0)
            {
                i32Ack = SendData(u16Data & 0xFFUL);
                if(i32Ack == 0)
                {
                    printf("i2C test ok!\n");
                }
                else
                    i32Err = -1;
            }
            else
                i32Err = -1;
        }
        else
            i32Err = -1;
        
        // Stop
        STOP;
    }while(i32Err);
    
}
#else

#define I2C_PORT    I2C0
void WAU8822_Write(uint32_t u32Addr, uint16_t u16Data)
{
    int32_t i32Err;

    do 
    {
        i32Err = 0;
        /* Send start */
        _I2C_START(I2C_PORT);
        _I2C_WAIT_READY(I2C_PORT);
        /* Send control byte */
        _I2C_WRITE(I2C_PORT, WAU8822_WRITE_ADDR);
        _I2C_WAIT_READY(I2C_PORT);

        if(I2C_PORT->I2CSTATUS == 0x18)
        {
            /* ACK */
    
            /* Send address */
            _I2C_WRITE(I2C_PORT, ((u32Addr & 0x7FUL) << 1) | ((u16Data >> 8) & 1)); // address & D8
            _I2C_WAIT_READY(I2C_PORT);
            if(I2C_PORT->I2CSTATUS == 0x28)
            {
                /* ACK */
    
                _I2C_WRITE(I2C_PORT, u16Data & 0xFFUL); // [D8:D0]
                _I2C_WAIT_READY(I2C_PORT);
                if(I2C_PORT->I2CSTATUS == 0x28)
                {
                    /* ACK */
                    /* Send stop */
                    _I2C_STOP(I2C_PORT);

                }
                else
                {
                    /* NACK */
                      /* Send D8..D0 error */
                    i32Err = -3;
              
                }
            }
            else
            {
                /* NACK */
            
                /* Send address & D8 error */
                i32Err = -2;
            }
        }
        else
        {
            /* NACK */    
        
            /* Send control byte error */
            i32Err = -1;
        }

        if(i32Err)
        {

            /* Send stop */
            _I2C_STOP(I2C_PORT);

            SYS_SysTickDelay(100);
        }

    }while(i32Err);
    
    DBG_PRINTF("I2C %d 0x%x\n", u32Addr, u16Data);

}
#endif

/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* FUNCTION                                                                                                */
/*      WAU8822_Setup()	          	                                                  			           */
/*                                                                                                         */
/* DESCRIPTION                                                                                             */
/*      The function is to configure CODEC WAU8822 with I2C interface. 									   */
/*                                                                                                         */
/* INPUTS                                                                                                  */
/*      None                                                                                               */
/*                                                                                                         */
/* OUTPUTS                                                                                                 */
/*      None                            				                                                   */
/*                                                                                                         */
/* RETURN                                                                                                  */
/*      None                                                                                               */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


void WAU8822_Init(uint32_t u32Option)
{
    uint32_t u32Reg;
    
	WAU8822_Write(0, 0x000);//Reset 
	
    u32Reg = 0x00B;
    if(u32Option & WAU8822_INIT_MASTER)
        u32Reg |= 0x020; // Enable PLL in Master mode
    if(u32Option & WAU8822_INIT_OUT_AUX1)
        u32Reg |= 0x084; // For AUX1 Output
    if(u32Option & WAU8822_INIT_OUT_AUX2)
        u32Reg |= 0x044; // For AUX2 Output
    if(u32Option & (WAU8822_INIT_IN_MIC_L | WAU8822_INIT_IN_MIC_R))
        u32Reg |= 0x010; // For MIC Bias output
	WAU8822_Write(1, u32Reg);
    
    u32Reg = 0;
    if(u32Option & WAU8822_INIT_OUT_HP_L)
        u32Reg |= 0x080; // Enable Headphone Left output
    if(u32Option & WAU8822_INIT_OUT_HP_R)
        u32Reg |= 0x100; // Enable Headphone Right output
    if(u32Option & (WAU8822_INIT_IN_LINE_L | WAU8822_INIT_IN_MIC_L | WAU8822_INIT_IN_AUX_L))
        u32Reg |= 0x011; // Enable LADC Mix/Boost & Left ADC
    if(u32Option & (WAU8822_INIT_IN_LINE_R | WAU8822_INIT_IN_MIC_R | WAU8822_INIT_IN_AUX_R))
        u32Reg |= 0x022; // Enable RADC Mix/Boost & Right ADC
    if(u32Option & WAU8822_INIT_IN_MIC_L)
        u32Reg |= 0x004; // Enable Left PGA
    if(u32Option & WAU8822_INIT_IN_MIC_R)
        u32Reg |= 0x008; // Enable Right PGA
	WAU8822_Write(2, u32Reg);

    u32Reg = 0;
    if(u32Option & WAU8822_INIT_OUT_AUX1)
        u32Reg |= 0x102; // Enable AUX1 & RDAC
    if(u32Option & WAU8822_INIT_OUT_AUX2)
        u32Reg |= 0x081; // Enable AUX2 & LDAC
    if(u32Option & WAU8822_INIT_OUT_HP_L)
        u32Reg |= 0x005; // Eanble LMIX & LDAC
    if(u32Option & WAU8822_INIT_OUT_HP_R)
        u32Reg |= 0x00A; // Eanble RMIX & RDAC
	WAU8822_Write(3, u32Reg);
	
	WAU8822_Write(4,  0x010);// I2S 16-bit format
	
	WAU8822_Write(10,  0x000);

	WAU8822_Write(5,  0x000);//R5 companding ctrl and loop back mode (all disable)

    if(u32Option & WAU8822_INIT_MASTER)
    {
        // Codec works as an Master
        
        // MCLK = 6MHz
        WAU8822_Write(36, 0x008);
        WAU8822_Write(37, 0x00C);
        WAU8822_Write(38, 0x093);
        WAU8822_Write(39, 0x0E9);
        if(u32Option & WAU8822_INIT_SR8000)
        {
            WAU8822_Write(6 , 0x1AD);
            WAU8822_Write(7 , 0x00A);
        }
        else if(u32Option & WAU8822_INIT_SR12000)
        {
            WAU8822_Write(6 , 0x18D);
            WAU8822_Write(7 , 0x008);
        }
        else if(u32Option & WAU8822_INIT_SR16000)
        {
            WAU8822_Write(6 , 0x16D);
            WAU8822_Write(7 , 0x006);
        }
        else if(u32Option & WAU8822_INIT_SR24000)
        {
            WAU8822_Write(6 , 0x14D);
            WAU8822_Write(7 , 0x004);
        }
        else if(u32Option & WAU8822_INIT_SR32000)
        {
            WAU8822_Write(6 , 0x12D);
            WAU8822_Write(7 , 0x002);
        }
        else if(u32Option & WAU8822_INIT_SR48000)
        {
            WAU8822_Write(6 , 0x10D);
            WAU8822_Write(7 , 0x000);
        }
    }
    else
    {
        WAU8822_Write(6 , 0x000);
        if(u32Option & WAU8822_INIT_SR8000)
        {
            WAU8822_Write(7 , 0x00A);
        }
        else if(u32Option & WAU8822_INIT_SR16000)
        {
            WAU8822_Write(7 , 0x006);
        }
        else if(u32Option & WAU8822_INIT_SR24000)
        {
            WAU8822_Write(7 , 0x004);
        }
        else if(u32Option & WAU8822_INIT_SR32000)
        {
            WAU8822_Write(7 , 0x002);
        }
        else if(u32Option & WAU8822_INIT_SR48000)
        {
            WAU8822_Write(7 , 0x000);
        }
    }
    
    WAU8822_Write(8 , 0x034);

	WAU8822_Write(59, 0x000);
	WAU8822_Write(60, 0x020);
	WAU8822_Write(61, 0x000);

	WAU8822_Write(10, 0x009);//R10 DAC control (softmute disable, oversample select 128x) 
	WAU8822_Write(43, 0x020);//speaker mute

    u32Reg = 0;
    if(u32Option & WAU8822_INIT_IN_MIC_L)
        u32Reg |= 0x003; // Connect LMICP, LMICN to LPGA
    if(u32Option & WAU8822_INIT_IN_MIC_R)
        u32Reg |= 0x030; // Connect RMICP, RMICN to RPGA
    WAU8822_Write(44, u32Reg);
    
//
// MIC input gain control
//    
    if(u32Option & WAU8822_INIT_IN_MIC_L)
        WAU8822_Write(45, 0x010); // MIC LPGA Gain 0dB
    else
        WAU8822_Write(45, 0x040); // MIC LPGA Mute

    if(u32Option & WAU8822_INIT_IN_MIC_R)
        WAU8822_Write(46, 0x110); // MIC RPGA Gain 0dB
    else
        WAU8822_Write(46, 0x140); // MIC RPGA Mute

//
// Line In gain control    
//
    u32Reg = 0;
    if(u32Option & WAU8822_INIT_IN_LINE_L)
        u32Reg |= 0x050; // LINE LPGA Gain 0dB
    if(u32Option & WAU8822_INIT_IN_AUX_L)
        u32Reg |= 0x005; // AUX LPGA Gain 0dB
    WAU8822_Write(47, u32Reg);

    u32Reg = 0;
    if(u32Option & WAU8822_INIT_IN_LINE_R)
        u32Reg |= 0x050; // LINE RPGA Gain 0dB
    if(u32Option & WAU8822_INIT_IN_AUX_R)
        u32Reg |= 0x005; // AUX RPGA Gain 0dB
    WAU8822_Write(48, u32Reg);


	WAU8822_Write(49, 0x01E);

	WAU8822_Write(50, 0x001);//R50 DACL2LMIX
	WAU8822_Write(51, 0x001);//R51 DACR2RMIX

//
// For Headphone Output
//

     // Left headphone volume/mute control
    if(u32Option & WAU8822_INIT_OUT_HP_L)
        WAU8822_Write(52, 0x039);
    else
        WAU8822_Write(52, 0x079);
    
     // Right headphone volume/mute control
    if(u32Option & WAU8822_INIT_OUT_HP_R)
        WAU8822_Write(53, 0x139);
    else
        WAU8822_Write(53, 0x179);

//
// For AUX output
//    
    if(u32Option & WAU8822_INIT_OUT_AUX2)
        WAU8822_Write(56, 0x001); // LDAC to AUX2
    else
        WAU8822_Write(56, 0x040); // AUX2 Mute

    if(u32Option & WAU8822_INIT_OUT_AUX1)
        WAU8822_Write(57, 0x001); // RDAC to AUX1
    else
        WAU8822_Write(57, 0x040);// AUX1 Mute
    
    WAU8822_Write(11, 0x0FF); // LDAC Volume
    WAU8822_Write(12, 0x1FF); // RDAC Volume

	WAU8822_Write(54, 0x040);
	WAU8822_Write(55, 0x140);

    // high pass eanble
    WAU8822_Write(14, 0x180);

	/* Disable EQ and 3D */
    WAU8822_Write(41, 0x000); // No 3D
    WAU8822_Write(18, 0x02C);
    WAU8822_Write(19, 0x02C);
    WAU8822_Write(20, 0x02C);
    WAU8822_Write(21, 0x02C);
    WAU8822_Write(22, 0x02C);

}





