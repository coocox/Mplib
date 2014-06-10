#include  <stdio.h>
#include  <string.h>
#include "nuc400series.h"
#include "ebi.h"
int32_t EbiButterfly(uint8_t eBank, uint32_t u32Size)
{
    uint32_t rdata;
    uint32_t addr1,addr2,midsize;
    uint32_t data[7]= {0,0x55555555,0xaaaaaaaa,0xffffffff,0xaaaaaaaa,0x55555555,0};
    uint32_t i;
    uint32_t BankStartAddr = EBI0_BASE_ADDR + eBank*0x4000000;
    uint32_t BankEndAddr = BankStartAddr+u32Size;

    addr1=(uint32_t)BankStartAddr;
    addr2=(uint32_t)BankEndAddr;
    midsize=(addr2-addr1)/2;
    printf("0x%x --> 0x%x <-- 0x%x\r\n", addr1, addr1+midsize, addr2);

    //------------------------------------------------------------------
    printf("Butterfly test 1...");

    for(i=0; i<midsize; i+=4) {
        *((volatile uint32_t *)(addr1+i))=data[((i>>2)%4)];
        rdata=*((volatile uint32_t *)(addr1+i));
        if(rdata!=data[((i>>2)%4)]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", addr1+i, rdata, data[((i>>2)%4)]);
            return -1;
        }
    }
    for(i=0; i<midsize; i+=4) {
        *((volatile uint32_t *)(addr2-i-4))=data[((i>>2)%4)];
        rdata=*((volatile uint32_t *)(addr2-i-4));
        if(rdata!=data[((i>>2)%4)]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", addr2-i-4, rdata, data[((i>>2)%4)]);
            return -1;
        }
    }

    for(i=0; i<midsize; i+=4) {
        rdata=*((volatile uint32_t *)(addr1+i));
        if(rdata!=data[((i>>2)%4)]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", addr1+i, rdata, data[((i>>2)%4)]);
            return -1;
        }
    }
    for(i=0; i<midsize; i+=4) {
        rdata=*((volatile uint32_t *)(addr2-i-4));
        if(rdata!=data[((i>>2)%4)]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", (addr2-i-4), rdata, data[((i>>2)%4)]);
            return -1;
        }
    }
    printf(" Pass\r\n");

    //------------------------------------------------------------------
    printf("Butterfly test 2...");
    for(i=0; i<midsize; i+=4)
        *((volatile uint32_t *)(addr1+midsize-i-4)) = data[((i>>2)%4)+1];
    for(i=0; i<midsize; i+=4)
        *((volatile uint32_t *)(addr2-midsize+i)) = data[((i>>2)%4)+1];
    for(i=0; i<midsize; i+=4) {
        rdata=*((volatile uint32_t *)(addr1+midsize-i-4));
        if(rdata!=data[((i>>2)%4)+1]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", (addr1+midsize-i-4), rdata, (data[((i>>2)%4)+1]));
            return -1;
        }
    }
    for(i=0; i<midsize; i+=4) {
        rdata=*((volatile uint32_t *)(addr2-midsize+i));
        if(rdata!=data[((i>>2)%4)+1]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", (addr2-midsize+i), rdata, (data[((i>>2)%4)+1]));
            return -1;
        }
    }
    printf(" Pass\r\n");

    //------------------------------------------------------------------
    printf("Butterfly test 3...");
    for(i=0; i<midsize; i+=4) {
        *((volatile uint32_t *)(addr1+midsize-i-4))=data[((i>>2)%4)+2];
        *((volatile uint32_t *)(addr2-midsize+i))=data[((i>>2)%4)+2];
    }
    for(i=0; i<midsize; i+=4) {
        rdata=*((volatile uint32_t *)(addr1+midsize-i-4));
        if(rdata!=data[((i>>2)%4)+2]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", (addr1+midsize-i-4), rdata, (data[((i>>2)%4)+2]));
            return -1;
        }

        rdata=*((volatile uint32_t *)(addr2-midsize+i));
        if(rdata!=data[((i>>2)%4)+2]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", (addr2-midsize+i), rdata, (data[((i>>2)%4)+2]));
            return -1;
        }
    }
    printf(" Pass\r\n");

    //------------------------------------------------------------------
    printf("Butterfly test 4...");
    for(i=0; i<midsize; i+=4) {
        *((volatile uint32_t *)(addr1+i))=data[((i>>2)%4)+3];
        *((volatile uint32_t *)(addr2-i-4))=data[((i>>2)%4)+3];
    }
    for(i=0; i<midsize; i+=4) {
        rdata=*((volatile uint32_t *)(addr1+i));
        if(rdata!=data[((i>>2)%4)+3]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", (addr1+i), rdata, (data[((i>>2)%4)+3]));
            return -1;
        }
        rdata=*((volatile uint32_t *)(addr2-i-4));
        if(rdata!=data[((i>>2)%4)+3]) {
            printf("\r\nerr: addr(0x%x) 0x%x != 0x%x\r\n", (addr2-i-4), rdata, (data[((i>>2)%4)+3]));
            return -1;
        }
    }
    printf(" Pass\r\n");

    return 0;
}

int32_t EbiDataTypeAccess(uint8_t eBank, uint32_t u32Size)
{
    uint8_t *pu8ptr;
    uint16_t *pu16ptr;
    uint32_t *pu32ptr, *pu32Tmp;
    uint32_t u32idx;
    uint32_t BankStartAddr = EBI0_BASE_ADDR + eBank*0x4000000;

    //------------------------------------------------------------------
    printf("\nByte Test (Bank-%d) ... ", eBank);

    pu8ptr = (uint8_t *)(BankStartAddr);
    for(u32idx=0; u32idx<u32Size; u32idx=u32idx+1) {
        uint8_t u8data = (uint8_t)((uint8_t)u32idx+ (uint8_t)(u32idx>>8)+(uint8_t)(u32idx>>16));
        *pu8ptr++ = u8data;
    }


    pu8ptr = (uint8_t *)BankStartAddr;
    for(u32idx=0; u32idx<u32Size; u32idx=u32idx+1) {
        if(*pu8ptr!= (uint8_t)((uint8_t)u32idx+ (uint8_t)(u32idx>>8)+(uint8_t)(u32idx>>16))) {
            printf("Error: [0x%x] R=0x%x, W=0x%x\n", (uint32_t)pu8ptr, *pu8ptr, (uint8_t)((uint8_t)u32idx+ (uint8_t)(u32idx>>8)+(uint8_t)(u32idx>>16)));
            return -1;
        }
        pu8ptr++;
    }
    printf("PASS\n");


    //------------------------------------------------------------------
    printf("Short Test (Bank-%d) ... ", eBank);
    pu16ptr = (uint16_t *)(BankStartAddr);
    for(u32idx=0; u32idx<u32Size; u32idx=u32idx+2) {
        *pu16ptr++ = ((uint16_t)u32idx+ (uint16_t)(u32idx>>8)+(uint16_t)(u32idx>>16));
    }
    pu16ptr = (uint16_t *)BankStartAddr;
    for(u32idx=0; u32idx<u32Size; u32idx=u32idx+2) {
        if(*pu16ptr!= (uint16_t)((uint16_t)u32idx+ (uint16_t)(u32idx>>8)+(uint16_t)(u32idx>>16))) {
            printf("Error: [0x%x] R=0x%x, W=0x%x\n",(uint32_t)pu16ptr, *pu16ptr, (uint16_t)(((uint16_t)u32idx+ (uint16_t)(u32idx>>8)+(uint16_t)(u32idx>>16))) );
            return -1;
        }
        pu16ptr++;
    }
    printf("PASS\n");


    //------------------------------------------------------------------
    printf("Word Test (Bank-%d) ... ", eBank);
    pu32ptr = (uint32_t *)(BankStartAddr);
    pu32Tmp = (uint32_t *)(BankStartAddr+u32Size+4);
    for(u32idx=0; u32idx<u32Size; u32idx=u32idx+4) {
        *pu32Tmp = 0;   /* Write another position */
        *pu32ptr++ = (uint32_t)(u32idx*0xFFFF+0x5678);
    }
    pu32ptr = (uint32_t *)BankStartAddr;
    for(u32idx=0; u32idx<u32Size; u32idx = u32idx+4) {
        if(*pu32ptr != ((uint32_t)(u32idx*0xFFFF+0x5678))) {
            printf("Error: [0x%x] R=0x%x, W=0x%x\n",(uint32_t)pu32ptr, *pu32ptr, (uint32_t)((u32idx*0xFFFF+0x5678)) );
            return -1;
        }
        pu32ptr++;
    }
    printf("PASS\n");

    return 0;
}
