/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2010 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#ifndef _WAU8822_H

#define WAU8822_INIT_MASTER      0x1
#define WAU8822_INIT_SLAVE       0x2
#define WAU8822_INIT_IN_LINE_L   0x4    
#define WAU8822_INIT_IN_LINE_R   0x8
#define WAU8822_INIT_IN_MIC_L    0x10
#define WAU8822_INIT_IN_MIC_R    0x20
#define WAU8822_INIT_IN_AUX_L    0x40
#define WAU8822_INIT_IN_AUX_R    0x80
#define WAU8822_INIT_OUT_HP_L    0x100
#define WAU8822_INIT_OUT_HP_R    0x200
#define WAU8822_INIT_OUT_AUX1    0x400
#define WAU8822_INIT_OUT_AUX2    0x800

#define WAU8822_INIT_SR8000     0x1000
#define WAU8822_INIT_SR12000    0x2000
#define WAU8822_INIT_SR16000    0x4000
#define WAU8822_INIT_SR24000    0x8000
#define WAU8822_INIT_SR32000    0x10000
#define WAU8822_INIT_SR48000    0x20000



extern void WAU8822_Write(uint32_t u32Addr, uint16_t u16Data);
extern void WAU8822_Init(uint32_t u32Option);

#endif // end of _WAU8822_H


