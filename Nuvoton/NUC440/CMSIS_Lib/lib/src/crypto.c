/**************************************************************************//**
 * @file     crypto.c
 * @version  V1.10
 * $Revision: 5 $
 * $Date: 13/11/10 9:32a $
 * @brief    NUC400 Cryptographic Accelerator driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include <string.h>
#include "crypto.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_CRYPTO_Driver CRYPTO Driver
  @{
*/


/** @addtogroup NUC400_CRYPTO_EXPORTED_FUNCTIONS CRYPTO Exported Functions
  @{
*/

static uint32_t g_AES_CTL[4];
static uint32_t g_TDES_CTL[4];

/**
  * @brief  Open PRNG function
  * @param  u32KeySize is PRNG key size, including:
  *         - \ref PRNG_KEY_SIZE_64
  *         - \ref PRNG_KEY_SIZE_128
  *         - \ref PRNG_KEY_SIZE_192
  *         - \ref PRNG_KEY_SIZE_256
  * @param  u32SeedReload is PRNG seed reload or not, including:
  *         - \ref PRNG_SEED_CONT
  *         - \ref PRNG_SEED_RELOAD
  * @param  u32Seed:  The new seed. Only valid when u32SeedReload is PRNG_SEED_RELOAD.
  * @retval None.
  */
void PRNG_Open(uint32_t u32KeySize, uint32_t u32SeedReload, uint32_t u32Seed)
{
    if (u32SeedReload)
        CRYPTO->PRNG_SEED = u32Seed;

    CRYPTO->PRNG_CTL =  (u32KeySize << CRYPTO_PRNG_KEY_SIZE_Pos) |
                        (u32SeedReload << CRYPTO_PRNG_SEED_RELOAD_Pos);
}

/**
  * @brief  Start to generate one PRNG key.
  * @retval None.
  */
void PRNG_Start(void)
{
    CRYPTO->PRNG_CTL |= CRYPTO_PRNG_START_Msk;
}

/**
  * @brief  Read the PRNG key.
  * @param  u32RandKey: The key buffer to store PRNG key.
  * @retval None.
  */
void PRNG_Read(uint32_t u32RandKey[])
{
    int  i, wcnt;

    wcnt = (((CRYPTO->PRNG_CTL & CRYPTO_PRNG_KEY_SIZE_Msk)>>CRYPTO_PRNG_KEY_SIZE_Pos)+1)*2;
    for (i = 0; i < wcnt; i++)
        u32RandKey[i] = *(uint32_t *)((uint32_t)&(CRYPTO->PRNG_key0) + (i * 4));
}


/**
  * @brief  Open AES encrypt/decrypt function.
  * @param  u32Channel:  AES channel. Must be 0~3.
  * @param  u32EncDec:   1: AES encode; 0: AES decode
  * @param  u32OpMode:   AES operation mode, including:
  *         - \ref AES_MODE_ECB
  *         - \ref AES_MODE_CBC
  *         - \ref AES_MODE_CFB
  *         - \ref AES_MODE_OFB
  *         - \ref AES_MODE_CTR
  *         - \ref AES_MODE_CBC_CS1
  *         - \ref AES_MODE_CBC_CS2
  *         - \ref AES_MODE_CBC_CS3
  * @param  u32KeySize is AES key size, including:
  *         - \ref AES_KEY_SIZE_128
  *         - \ref AES_KEY_SIZE_192
  *         - \ref AES_KEY_SIZE_256
  * @param  u32SwapType is AES input/output data swap control, including:
  *         - \ref AES_NO_SWAP
  *         - \ref AES_OUT_SWAP
  *         - \ref AES_IN_SWAP
  *         - \ref AES_IN_OUT_SWAP
  * @retval None.
  */
void AES_Open(uint32_t u32Channel, uint32_t u32EncDec,
              uint32_t u32OpMode, uint32_t u32KeySize, uint32_t u32SwapType)
{
    CRYPTO->AES_CTL = (u32Channel << CRYPTO_AES_CHANNEL_Pos) |
                      (u32EncDec << CRYPTO_AES_E_D_Pos) |
                      (u32OpMode << CRYPTO_AES_OP_MODE_Pos) |
                      (u32KeySize << CRYPTO_AES_KEY_SIZE_Pos) |
                      (u32SwapType << CRYPTO_AES_OUT_SWAP_Pos);
    g_AES_CTL[u32Channel] = CRYPTO->AES_CTL;
}

/**
  * @brief  Start AES encrypt/decrypt
  * @param  u32Channel:  AES channel. Must be 0~3.
  * @param  u32DMAMode:  AES DMA control, including:
  *         - \ref CRYPTO_DMA_ONE_SHOT   One shop AES encrypt/decrypt.
  *         - \ref CRYPTO_DMA_CONTINUE   Continuous AES encrypt/decrypt.
  *         - \ref CRYPTO_DMA_LAST       Last AES encrypt/decrypt of a series of AES_Start.
  * @retval None.
  */
void AES_Start(int32_t u32Channel, uint32_t u32DMAMode)
{
    CRYPTO->AES_CTL = g_AES_CTL[u32Channel];
    CRYPTO->AES_CTL |= CRYPTO_AES_START_Msk | (u32DMAMode << CRYPTO_AES_LAST_Pos);
}

/**
  * @brief  Set AES keys
  * @param  u32Channel:  AES channel. Must be 0~3.
  * @param  au32Keys:    An word array contains AES keys.
  * @param  u32KeySize is AES key size, including:
  *         - \ref AES_KEY_SIZE_128
  *         - \ref AES_KEY_SIZE_192
  *         - \ref AES_KEY_SIZE_256
  * @retval None.
  */
void AES_SetKey(uint32_t u32Channel, uint32_t au32Keys[], uint32_t u32KeySize)
{
    int       i, wcnt;
    uint32_t  *key_ptr;

    key_ptr = (uint32_t *)((uint32_t)&CRYPTO->AES0_KEY_0 + (u32Channel * 0x3C));
    wcnt = 4 + u32KeySize*2;
    for (i = 0; i < wcnt; i++, key_ptr++)
        *key_ptr = au32Keys[i];
}

/**
  * @brief  Set AES initial vectors
  * @param  u32Channel:  AES channel. Must be 0~3.
  * @param  au32IV:      A four entry word array contains AES initial vectors.
  * @retval None.
  */
void AES_SetInitVect(uint32_t u32Channel, uint32_t au32IV[])
{
    int       i;
    uint32_t  *key_ptr;

    key_ptr = (uint32_t *)((uint32_t)&CRYPTO->AES0_IV0 + (u32Channel * 0x3C));
    for (i = 0; i < 4; i++, key_ptr++)
        *key_ptr = au32IV[i];
}

/**
  * @brief  Set AES DMA transfer
  * @param  u32Channel:  AES channel. Must be 0~3.
  * @param  u32SrcAddr:  AES DMA source address
  * @param  u32DstAddr:  AES DMA destination address
  * @param  u32TransCnt: AES DMA transfer byte count
  * @retval None.
  */
void AES_SetDMATransfer(uint32_t u32Channel, uint32_t u32SrcAddr,
                        uint32_t u32DstAddr, uint32_t u32TransCnt)
{
    *(uint32_t *)((uint32_t)&CRYPTO->AES0_SADR + (u32Channel * 0x3C)) = u32SrcAddr;
    *(uint32_t *)((uint32_t)&CRYPTO->AES0_DADR + (u32Channel * 0x3C)) = u32DstAddr;
    *(uint32_t *)((uint32_t)&CRYPTO->AES0_CNT + (u32Channel * 0x3C)) = u32TransCnt;
}

/**
  * @brief  Open TDES encrypt/decrypt function.
  * @param  u32Channel:  TDES channel. Must be 0~3.
  * @param  u32EncDec:   1: TDES encode; 0: AES decode
  * @param  u32OpMode:   TDES operation mode, including:
  *         - \ref TDES_MODE_ECB
  *         - \ref TDES_MODE_CBC
  *         - \ref TDES_MODE_CFB
  *         - \ref TDES_MODE_OFB
  *         - \ref TDES_MODE_CTR
  * @param  u32SwapType is TDES input/output data swap control and word swap control, including:
  *         - \ref TDES_NO_SWAP
  *         - \ref TDES_WHL_SWAP
  *         - \ref TDES_OUT_SWAP
  *         - \ref TDES_OUT_WHL_SWAP
  *         - \ref TDES_IN_SWAP
  *         - \ref TDES_IN_WHL_SWAP
  *         - \ref TDES_IN_OUT_SWAP
  *         - \ref TDES_IN_OUT_WHL_SWAP
  * @retval None.
  */
void TDES_Open(uint32_t u32Channel, uint32_t u32EncDec, uint32_t u32OpMode, uint32_t u32SwapType)
{
    CRYPTO->TDES_CTL = (u32Channel << CRYPTO_TDES_CHANNEL_Pos) |
                       (u32EncDec << CRYPTO_TDES_E_D_Pos) |
                       (u32OpMode << CRYPTO_TDES_OP_MODE_Pos) |
                       (u32SwapType << CRYPTO_TDES_BLK_FMT_Pos);
    g_TDES_CTL[u32Channel] = CRYPTO->TDES_CTL;
}

/**
  * @brief  Start TDES encrypt/decrypt
  * @param  u32Channel:  TDES channel. Must be 0~3.
  * @param  u32DMAMode:  TDES DMA control, including:
  *         - \ref CRYPTO_DMA_ONE_SHOT   One shop TDES encrypt/decrypt.
  *         - \ref CRYPTO_DMA_CONTINUE   Continuous TDES encrypt/decrypt.
  *         - \ref CRYPTO_DMA_LAST       Last TDES encrypt/decrypt of a series of TDES_Start.
  * @retval None.
  */
void TDES_Start(int32_t u32Channel, uint32_t u32DMAMode)
{
    CRYPTO->TDES_CTL = g_TDES_CTL[u32Channel];
    CRYPTO->TDES_CTL |= CRYPTO_TDES_START_Msk | (u32DMAMode << CRYPTO_TDES_LAST_START_Pos);
}

/**
  * @brief  Set TDES keys
  * @param  u32Channel:  TDES channel. Must be 0~3.
  * @param  au8Keys:     The TDES keys.
  * @retval None.
  */
void TDES_SetKey(uint32_t u32Channel, uint8_t au8Keys[3][8])
{
    int         i;
    uint8_t     *pu8TKey;

    pu8TKey = (uint8_t *)((uint32_t)&CRYPTO->TDES0_KEY1H + (0x40 * u32Channel));
    for (i = 0; i < 3; i++, pu8TKey+=8)
        memcpy(pu8TKey, &au8Keys[i][0], 8);
}

/**
  * @brief  Set TDES initial vectors
  * @param  u32Channel:  TDES channel. Must be 0~3.
  * @param  u32IVH:      TDES initial vector high word.
  * @param  u32IVL:      TDES initial vector low word.
  * @retval None.
  */
void TDES_SetInitVect(uint32_t u32Channel, uint32_t u32IVH, uint32_t u32IVL)
{
    *(uint32_t *)((uint32_t)&CRYPTO->TDES0_IVH + 0x40 * u32Channel) = u32IVH;
    *(uint32_t *)((uint32_t)&CRYPTO->TDES0_IVL + 0x40 * u32Channel) = u32IVL;
}

/**
  * @brief  Set TDES DMA transfer
  * @param  u32Channel:  TDES channel. Must be 0~3.
  * @param  u32SrcAddr:  TDES DMA source address
  * @param  u32DstAddr:  TDES DMA destination address
  * @param  u32TransCnt: TDES DMA transfer byte count
  * @retval None.
  */
void TDES_SetDMATransfer(uint32_t u32Channel, uint32_t u32SrcAddr,
                         uint32_t u32DstAddr, uint32_t u32TransCnt)
{
    *(uint32_t *)((uint32_t)&CRYPTO->TDES0_SADR + (u32Channel * 0x40)) = u32SrcAddr;
    *(uint32_t *)((uint32_t)&CRYPTO->TDES0_DADR + (u32Channel * 0x40)) = u32DstAddr;
    *(uint32_t *)((uint32_t)&CRYPTO->TDES0_CNT + (u32Channel * 0x40)) = u32TransCnt;
}

/**
  * @brief  Open SHA encrypt function.
  * @param  u32OpMode:   SHA operation mode, including:
  *         - \ref SHA_MODE_SHA1
  *         - \ref SHA_MODE_SHA224
  *         - \ref SHA_MODE_SHA256
  * @param  u32SwapType is SHA input/output data swap control, including:
  *         - \ref SHA_NO_SWAP
  *         - \ref SHA_OUT_SWAP
  *         - \ref SHA_IN_SWAP
  *         - \ref SHA_IN_OUT_SWAP
  * @retval None.
  */
void SHA_Open(uint32_t u32OpMode, uint32_t u32SwapType)
{
    CRYPTO->SHA_CTL = (u32OpMode << CRYPTO_SHA_OP_MODE_Pos) |
                      (u32SwapType << CRYPTO_SHA_OUT_SWAP_Pos);
}

/**
  * @brief  Start SHA encrypt
  * @param  u32DMAMode:  TDES DMA control, including:
  *         - \ref CRYPTO_DMA_ONE_SHOT   One shop SHA encrypt.
  *         - \ref CRYPTO_DMA_CONTINUE   Continuous SHA encrypt.
  *         - \ref CRYPTO_DMA_LAST       Last SHA encrypt of a series of SHA_Start.
  * @retval None.
  */
void SHA_Start(uint32_t u32DMAMode)
{
    CRYPTO->SHA_CTL &= ~(0x7 << CRYPTO_SHA_LAST_Pos);
    CRYPTO->SHA_CTL |= CRYPTO_SHA_START_Msk | (u32DMAMode << CRYPTO_SHA_LAST_Pos);
}

/**
  * @brief  Set SHA DMA transfer
  * @param  u32SrcAddr:  SHA DMA source address
  * @param  u32TransCnt: SHA DMA transfer byte count
  * @retval None.
  */
void SHA_SetDMATransfer(uint32_t u32SrcAddr, uint32_t u32TransCnt)
{
    CRYPTO->SHA_SADR = u32SrcAddr;
    CRYPTO->SHA_DMA_CNT = u32TransCnt;
}

/**
  * @brief  Read the SHA digest.
  * @param  u32Digest: The SHA encrypt output digest.
  * @retval None.
  */
void SHA_Read(uint32_t u32Digest[])
{
    uint32_t  i, wcnt;

    i = (CRYPTO->SHA_CTL & CRYPTO_SHA_OP_MODE_Msk) >> CRYPTO_SHA_OP_MODE_Pos;
    if (i == SHA_MODE_SHA1)
        wcnt = 5;
    else if (i == SHA_MODE_SHA224)
        wcnt = 7;
    else
        wcnt = 8;

    for (i = 0; i < wcnt; i++)
        u32Digest[i] = *(uint32_t *)((uint32_t)&(CRYPTO->SHA_H0) + (i * 4));
}


/*@}*/ /* end of group NUC400_CRYPTO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_CRYPTO_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/

