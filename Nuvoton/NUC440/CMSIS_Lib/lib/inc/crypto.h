/**************************************************************************//**
 * @file     crypto.h
 * @version  V1.10
 * $Revision: 7 $
 * $Date: 13/11/06 5:53p $
 * @brief    NUC400 Cryptographic Accelerator driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __CRYPTO_H__
#define __CRYPTO_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_CRYPTO_Driver CRYPTO Driver
  @{
*/


/** @addtogroup NUC400_CRYPTO_EXPORTED_CONSTANTS CRYPTO Exported Constants
  @{
*/

#define PRNG_KEY_SIZE_64        0       /*!< Select to generate 64-bit random key   */
#define PRNG_KEY_SIZE_128       1       /*!< Select to generate 128-bit random key  */
#define PRNG_KEY_SIZE_192       2       /*!< Select to generate 192-bit random key  */
#define PRNG_KEY_SIZE_256       3       /*!< Select to generate 256-bit random key  */

#define PRNG_SEED_CONT          0       /*!< PRNG using current seed                */
#define PRNG_SEED_RELOAD        1       /*!< PRNG reload new seed                   */

#define AES_KEY_SIZE_128        0       /*!< AES select 128-bit key length          */
#define AES_KEY_SIZE_192        1       /*!< AES select 192-bit key length          */
#define AES_KEY_SIZE_256        2       /*!< AES select 256-bit key length          */

#define AES_MODE_ECB            0       /*!< AES select ECB mode                    */
#define AES_MODE_CBC            1       /*!< AES select CBC mode                    */
#define AES_MODE_CFB            2       /*!< AES select CFB mode                    */
#define AES_MODE_OFB            3       /*!< AES select OFB mode                    */
#define AES_MODE_CTR            4       /*!< AES select CTR mode                    */
#define AES_MODE_CBC_CS1        0x10    /*!< AES select CBC CS1 mode                */
#define AES_MODE_CBC_CS2        0x11    /*!< AES select CBC CS2 mode                */
#define AES_MODE_CBC_CS3        0x12    /*!< AES select CBC CS3 mode                */

#define AES_NO_SWAP             0       /*!< AES do not swap input and output data  */
#define AES_OUT_SWAP            1       /*!< AES swap output data                   */
#define AES_IN_SWAP             2       /*!< AES swap input data                    */
#define AES_IN_OUT_SWAP         3       /*!< AES swap both input and output data    */

#define TDES_MODE_ECB           0       /*!< TDES select ECB mode                   */
#define TDES_MODE_CBC           1       /*!< TDES select CBC mode                   */
#define TDES_MODE_CFB           2       /*!< TDES select CFB mode                   */
#define TDES_MODE_OFB           3       /*!< TDES select OFB mode                   */
#define TDES_MODE_CTR           4       /*!< TDES select CTR mode                   */

#define TDES_NO_SWAP            0       /*!< TDES do not swap data                      */
#define TDES_WHL_SWAP           1       /*!< TDES swap high-low word                    */
#define TDES_OUT_SWAP           2       /*!< TDES swap output data                      */
#define TDES_OUT_WHL_SWAP       3       /*!< TDES swap output data and high-low word    */
#define TDES_IN_SWAP            4       /*!< TDES swap input data                       */
#define TDES_IN_WHL_SWAP        5       /*!< TDES swap input data and high-low word     */
#define TDES_IN_OUT_SWAP        6       /*!< TDES swap both input and output data       */
#define TDES_IN_OUT_WHL_SWAP    7       /*!< TDES swap input, output and high-low word  */

#define SHA_MODE_SHA1           0       /*!< SHA select SHA-1 160-bit               */
#define SHA_MODE_SHA224         5       /*!< SHA select SHA-224 224-bit             */
#define SHA_MODE_SHA256         4       /*!< SHA select SHA-256 256-bit             */

#define SHA_NO_SWAP             0       /*!< SHA do not swap input and output data  */
#define SHA_OUT_SWAP            1       /*!< SHA swap output data                   */
#define SHA_IN_SWAP             2       /*!< SHA swap input data                    */
#define SHA_IN_OUT_SWAP         3       /*!< SHA swap both input and output data    */

#define CRYPTO_DMA_ONE_SHOT     0x5     /*!< Do one shot encrypt/decrypt with DMA     */
#define CRYPTO_DMA_CONTINUE     0x6     /*!< Do one continuous encrypt/decrypt with DMA*/
#define CRYPTO_DMA_LAST         0x6     /*!< Do last encrypt/decrypt with DMA         */

/*@}*/ /* end of group NUC400_CRYPTO_EXPORTED_CONSTANTS */


/** @addtogroup NUC400_CRYPTO_EXPORTED_FUNCTIONS CRYPTO Exported Functions
  @{
*/

/*---------------------------------------------------------------------------------------------------------*/
/*  Macros                                                                                      */
/*---------------------------------------------------------------------------------------------------------*/

#define PRNG_ENABLE_INT()       (CRYPTO->CRYPTO_INT_EN |= CRYPTO_PRNG_INT_EN_Msk)   /*!< Enable PRNG interrupt     */
#define PRNG_DISABLE_INT()      (CRYPTO->CRYPTO_INT_EN &= ~CRYPTO_PRNG_INT_EN_Msk)  /*!< Disable PRNG interrupt    */
#define PRNG_GET_INT_FLAG()     (CRYPTO->CRYPTO_INT_FLAG & CRYPTO_PRNG_INT_FLAG_Msk)/*!< Get PRNG interrupt flag   */
#define PRNG_CLR_INT_FLAG()     (CRYPTO->CRYPTO_INT_FLAG = CRYPTO_PRNG_INT_FLAG_Msk)/*!< Clear PRNG interrupt flag */
#define AES_ENABLE_INT()        (CRYPTO->CRYPTO_INT_EN |= (CRYPTO_AES_INT_EN_Msk|CRYPTO_AES_ERR_EN_Msk))        /*!< Enable AES interrupts      */
#define AES_DISABLE_INT()       (CRYPTO->CRYPTO_INT_EN &= ~(CRYPTO_AES_INT_EN_Msk|CRYPTO_AES_ERR_EN_Msk))       /*!< Disable AES interrupts     */
#define AES_GET_INT_FLAG()      (CRYPTO->CRYPTO_INT_FLAG & (CRYPTO_AES_INT_FLAG_Msk|CRYPTO_AES_ERR_FLAG_Msk))   /*!< Get AES interrupt flag     */
#define AES_CLR_INT_FLAG()      (CRYPTO->CRYPTO_INT_FLAG = (CRYPTO_AES_INT_FLAG_Msk|CRYPTO_AES_ERR_FLAG_Msk))   /*!< Clear AES interrupt flag   */
#define AES_ENABLE_KEY_PROTECT()  (CRYPTO->AES_CTL |= CRYPTO_AES_KEY_PROTECT_Msk)   /*!< Protect AES key           */
#define AES_DISABLE_KEY_PROTECT() (CRYPTO->AES_CTL = (CRYPTO->AES_CTL & ~CRYPTO_AES_KEY_PROTECT_Msk) | (0x16<<CRYPTO_AES_KEY_PROTECT_Pos)) /*!< Un-protect AES key. AES keys will be cleared.  */
#define TDES_ENABLE_INT()       (CRYPTO->CRYPTO_INT_EN |= (CRYPTO_TDES_INT_EN_Msk|CRYPTO_TDES_ERR_EN_Msk))      /*!< Enable TDES interrupts     */
#define TDES_DISABLE_INT()      (CRYPTO->CRYPTO_INT_EN &= ~(CRYPTO_TDES_INT_EN_Msk|CRYPTO_TDES_ERR_EN_Msk))     /*!< Disable TDES interrupts    */
#define TDES_GET_INT_FLAG()     (CRYPTO->CRYPTO_INT_FLAG & (CRYPTO_TDES_INT_FLAG_Msk|CRYPTO_TDES_ERR_FLAG_Msk)) /*!< Get TDES interrupt flag    */
#define TDES_CLR_INT_FLAG()     (CRYPTO->CRYPTO_INT_FLAG = (CRYPTO_TDES_INT_FLAG_Msk|CRYPTO_TDES_ERR_FLAG_Msk)) /*!< Clear TDES interrupt flag  */
#define TDES_ENABLE_KEY_PROTECT()  (CRYPTO->TDES_CTL |= CRYPTO_TDES_KEY_PROTECT_Msk)    /*!< Protect TDES key           */
#define TDES_DISABLE_KEY_PROTECT() (CRYPTO->TDES_CTL = (CRYPTO->TDES_CTL & ~CRYPTO_TDES_KEY_PROTECT_Msk) | (0x16<<CRYPTO_TDES_KEY_PROTECT_Pos)) /*!< Un-protect TDES key. TDES keys will be cleared.  */
#define SHA_ENABLE_INT()        (CRYPTO->CRYPTO_INT_EN |= (CRYPTO_SHA_INT_EN_Msk|CRYPTO_SHA_ERR_EN_Msk))        /*!< Enable SHA interrupts      */
#define SHA_DISABLE_INT()       (CRYPTO->CRYPTO_INT_EN &= ~(CRYPTO_SHA_INT_EN_Msk|CRYPTO_SHA_ERR_EN_Msk))       /*!< Disable SHA interrupts     */
#define SHA_GET_INT_FLAG()      (CRYPTO->CRYPTO_INT_FLAG & (CRYPTO_SHA_INT_FLAG_Msk|CRYPTO_SHA_ERR_FLAG_Msk))   /*!< Get SHA interrupt flag     */
#define SHA_CLR_INT_FLAG()      (CRYPTO->CRYPTO_INT_FLAG = (CRYPTO_SHA_INT_FLAG_Msk|CRYPTO_SHA_ERR_FLAG_Msk))   /*!< Clear SHA interrupt flag   */

/*---------------------------------------------------------------------------------------------------------*/
/*  Functions                                                                                      */
/*---------------------------------------------------------------------------------------------------------*/

void PRNG_Open(uint32_t u32KeySize, uint32_t u32SeedReload, uint32_t u32Seed);
void PRNG_Start(void);
void PRNG_Read(uint32_t u32RandKey[]);
void AES_Open(uint32_t u32Channel, uint32_t u32EncDec, uint32_t u32OpMode, uint32_t u32KeySize, uint32_t u32SwapType);
void AES_Start(int32_t u32Channel, uint32_t u32DMAMode);
void AES_SetKey(uint32_t u32Channel, uint32_t au32Keys[], uint32_t u32KeySize);
void AES_SetInitVect(uint32_t u32Channel, uint32_t au32IV[]);
void AES_SetDMATransfer(uint32_t u32Channel, uint32_t u32SrcAddr, uint32_t u32DstAddr, uint32_t u32TransCnt);
void TDES_Open(uint32_t u32Channel, uint32_t u32EncDec, uint32_t u32OpMode, uint32_t u32SwapType);
void TDES_Start(int32_t u32Channel, uint32_t u32DMAMode);
void TDES_SetKey(uint32_t u32Channel, uint8_t au8Keys[3][8]);
void TDES_SetInitVect(uint32_t u32Channel, uint32_t u32IVH, uint32_t u32IVL);
void TDES_SetDMATransfer(uint32_t u32Channel, uint32_t u32SrcAddr, uint32_t u32DstAddr, uint32_t u32TransCnt);
void SHA_Open(uint32_t u32OpMode, uint32_t u32SwapType);
void SHA_Start(uint32_t u32DMAMode);
void SHA_SetDMATransfer(uint32_t u32SrcAddr, uint32_t u32TransCnt);
void SHA_Read(uint32_t u32Digest[]);


/*@}*/ /* end of group NUC400_CRYPTO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_CRYPTO_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif  // __CRYPTO_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/

