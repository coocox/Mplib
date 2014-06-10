/**************************************************************************//**
 * @file     cap.h
 * @version  V0.10
 * $Revision: 11 $
 * $Date: 13/11/10 11:00a $
 * @brief    NUC470 series Image Capture Driver Header File
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __CAP_H__
#define __CAP_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_CAP_Driver CAP Driver
  @{
*/

/** @addtogroup NUC400_CAP_EXPORTED_CONSTANTS CAP Exported Constants
  @{
*/

/*---------------------------------------------------------------------------------------------------------*/
/* VINCTRL constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define CAP_CAPCTL_VINEN      (1ul<<CAP_CAPCTL_CAPEN_Pos)     /*!< VINCTRL setting for enabling capture engine mode */
#define CAP_CAPCTL_PKEN       (1ul<<CAP_CAPCTL_PKEN_Pos)      /*!< VINCTRL setting for enabling packet output mode */
#define CAP_CAPCTL_PNEN       (1ul<<CAP_CAPCTL_PNEN_Pos)      /*!< VINCTRL setting for enabling planar output mode */
#define CAP_CAPCTL_SHUTTER    (1ul<<CAP_CAPCTL_SHUTTER_Pos)   /*!< VINCTRL setting for enabling shutter mode */
#define CAP_CAPCTL_UPDATE     (1ul<<CAP_CAPCTL_UPDATE_Pos)    /*!< VINCTRL setting for enabling update register at new frame */
#define CAP_CAPCTL_RESET      (1ul<<CAP_CAPCTL_VPRST_Pos)     /*!< VINCTRL setting for capture reset */

/*---------------------------------------------------------------------------------------------------------*/
/* CAPPAR constant definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define CAP_CAPPAR_INFMT_YUV422 (0ul<<CAP_CAPPAR_INFMT_Pos)         /*!< CAPPAR setting for Sensor Input Data YUV422 Format  */
#define CAP_CAPPAR_INFMT_RGB565 (1ul<<CAP_CAPPAR_INFMT_Pos)         /*!< CAPPAR setting for Sensor Input Data RGB565 Format  */

#define CAP_CAPPAR_SNRTYPE_CCIR601  (0ul<<CAP_CAPPAR_SNRTYPE_Pos)   /*!< CAPPAR setting for Sensor Input CCIR601 Type  */
#define CAP_CAPPAR_SNRTYPE_CCIR656  (1ul<<CAP_CAPPAR_SNRTYPE_Pos)   /*!< CAPPAR setting for Sensor Input CCIR656 Type  */

#define CAP_CAPPAR_PDORD_YUYV   (0x0ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, YUYV */
#define CAP_CAPPAR_PDORD_YVYU   (0x1ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, YVYU */
#define CAP_CAPPAR_PDORD_UYVY   (0x2ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, UYVY */
#define CAP_CAPPAR_PDORD_VYUY   (0x3ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, VYUY */

#define CAP_CAPPAR_PDORD_RGGB   (0x0ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, 0byte: R[0:4] G[5:8], 1byte G[0:2] R[3:8] */
#define CAP_CAPPAR_PDORD_BGGR   (0x1ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, 0byte: b[0:4] G[5:8], 1byte G[0:2] R[3:8] */
#define CAP_CAPPAR_PDORD_GBRG   (0x2ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, 0byte: G[0:3] G[4:8], 1byte G[0:4] G[5:8] */
#define CAP_CAPPAR_PDORD_GRBG   (0x3ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAPPAR setting for Sensor Input Data Order, 0byte: G[0:3] G[4:8], 1byte G[0:4] G[5:8] */

#define CAP_CAPPAR_OUTFMT_YUV422 (0x0ul<<CAP_CAPPAR_OUTFMT_Pos)     /*!< CAPPAR setting for Image Data YUV422 Format Output to System Memory */
#define CAP_CAPPAR_OUTFMT_ONLY_Y (0x1ul<<CAP_CAPPAR_OUTFMT_Pos)     /*!< CAPPAR setting for Image Data ONLY_Y Format Output to System Memory */
#define CAP_CAPPAR_OUTFMT_RGB555 (0x2ul<<CAP_CAPPAR_OUTFMT_Pos)     /*!< CAPPAR setting for Image Data RGB555 Format Output to System Memory */
#define CAP_CAPPAR_OUTFMT_RGB565 (0x3ul<<CAP_CAPPAR_OUTFMT_Pos)     /*!< CAPPAR setting for Image Data RGB565 Format Output to System Memory */

#define CAP_CAPPAR_PNFMT_YUV422 (0x0ul<<CAP_CAPPAR_PNFMT_Pos)       /*!< CAPPAR setting for Planar Output YUV422 Format */
#define CAP_CAPPAR_PNFMT_YUV420 (0x1ul<<CAP_CAPPAR_PNFMT_Pos)       /*!< CAPPAR setting for Planar Output YUV420 Format */

#define CAP_CAPPAR_VSP_LOW      (0x0ul<<CAP_CAPPAR_VSP_Pos)         /*!< CAPPAR setting for Sensor Vsync Polarity */
#define CAP_CAPPAR_VSP_HIGH     (0x1ul<<CAP_CAPPAR_VSP_Pos)         /*!< CAPPAR setting for Sensor Vsync Polarity */
#define CAP_CAPPAR_HSP_LOW      (0x0ul<<CAP_CAPPAR_HSP_Pos)         /*!< CAPPAR setting for Sensor Hsync Polarity */
#define CAP_CAPPAR_HSP_HIGH     (0x1ul<<CAP_CAPPAR_HSP_Pos)         /*!< CAPPAR setting for Sensor Hsync Polarity */
#define CAP_CAPPAR_PCLKP_LOW    (0x0ul<<CAP_CAPPAR_PCLKP_Pos)       /*!< CAPPAR setting for Sensor Pixel Clock Polarity */
#define CAP_CAPPAR_PCLKP_HIGH   (0x1ul<<CAP_CAPPAR_PCLKP_Pos)       /*!< CAPPAR setting for Sensor Pixel Clock Polarity */

/*---------------------------------------------------------------------------------------------------------*/
/* VININT constant definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define CAP_VININT_VINT_ENABLE        (0x1ul<<CAP_VININT_VINTEN_Pos)        /*!< VININT setting for Frame End Interrupt enable */
#define CAP_VININT_MEINT_ENABLE       (0x1ul<<CAP_VININT_MEINTEN_Pos)       /*!< VININT setting for Bus Master Transfer Error Interrupt enable */
#define CAP_VININT_ADDRMINT_ENABLE    (0x1ul<<CAP_VININT_ADDRMEN_Pos)       /*!< VININT setting for Memory Address Match Interrupt enable */
#define CAP_VININT_MDINT_ENABLE       (0x1ul<<CAP_VININT_MDINTEN_Pos)       /*!< VININT setting for Motion Detection Output Finish Interrupt Enable enable */


static uint32_t u32EscapeFrame = 0;
/*---------------------------------------------------------------------------------------------------------*/
/*  Define Error Code                                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
#define CAP_INVALID_INT               ((int32_t)(0xFFFFFFFF-1))
#define CAP_INVALID_BUF               ((int32_t)(0xFFFFFFFF-2))
#define CAP_INVALID_PIPE              ((int32_t)(0xFFFFFFFF-3))


/*@}*/ /* end of group NUC400_CAP_EXPORTED_CONSTANTS */



/** @addtogroup NUC400_CAP_EXPORTED_FUNCTIONS CAP Exported Functions
  @{
*/

/**
 * @brief     Is CAP module Enable
 *
 * @return   FALSE(Enable) or TRUE(Disable)
 *
 * @details   Check Image Capture Interface module Enable or Disable
 */
#define CAP_IS_STOPPED()  ((CAP->CAPCTL & CAP_CAPCTL_CAPEN_Msk)?0:1)

/**
 * @brief     Clear CAP flag
 *
 * @param[in] u32IntMask interrupt flags settings. It could be
 *                   - \ref CAP_CAPINT_VINT_Msk
 *                   - \ref CAP_CAPINT_MEINT_Msk
 *                   - \ref CAP_CAPINT_ADDRMINT_Msk
 *                   - \ref CAP_CAPINT_MDINT_Msk
 *
 * @return    TRUE(Enable) or FALSE(Disable)
 *
 * @details   Clear Image Capture Interface interrupt flag
 */
#define CAP_CLR_INT_FLAG(u32IntMask) (CAP->CAPINT |=u32IntMask)

/**
 * @brief     Get CAP Interrupt status
 *
 * @return    TRUE(Enable) or FALSE(Disable)
 *
 * @details   Get Image Capture Interface interrupt status.
 */
#define CAP_GET_INT_STS() (CAP->CAPINT)

void CAP_Open(uint32_t u32InFormat, uint32_t u32OutFormet);
void CAP_SetCroppingWindow(uint32_t u32VStart,uint32_t u32HStart, uint32_t u32Height, uint32_t u32Width);
void CAP_SetPacketBuf(uint32_t  u32Address );
void CAP_SetPlanarBuf(uint32_t u32YAddr, uint32_t u32UAddr, uint32_t u32VAddr);
void CAP_Close(void);
void CAP_EnableInt(uint32_t u32IntMask);
void CAP_DisableInt(uint32_t u32IntMask);
void CAP_Start(void);
void CAP_Stop(uint32_t u32FrameComplete);
void CAP_SetPacketScaling(uint32_t u32VNumerator, uint32_t u32VDenominator, uint32_t u32HNumerator, uint32_t u32HDenominator);
void CAP_SetPlanarScaling(uint32_t u32VNumerator, uint32_t u32VDenominator, uint32_t u32HNumerator, uint32_t u32HDenominator);
void CAP_SetPacketStride(uint32_t u32Stride );
void CAP_SetPlanarStride(uint32_t u32Stride );
void CAP_EnableMotionDet(uint32_t u32Freq, uint32_t u32BlockSize, uint32_t u32Format, uint32_t u32Threshold,  uint32_t u32YDetAddr, uint32_t u32DetAddr);
void CAP_DisableMotionDet(void);

/*@}*/ /* end of group NUC400_CAP_EXPORTED_FUNCTIONS */



/*@}*/ /* end of group NUC400_CAP_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__CAP_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
