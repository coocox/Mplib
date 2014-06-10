/**************************************************************************//**
 * @file     cap.c
 * @version  V0.10
 * $Revision: 11 $
 * $Date: 13/11/27 11:53a $
 * @brief    NUC400 series CAP driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include  "cap.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_CAP_Driver CAP Driver
  @{
*/


/** @addtogroup NUC400_CAP_EXPORTED_FUNCTIONS CAP Exported Functions
  @{
*/

/**
 * @brief      Open engine clock and sensor clock
 *
 * @param[in]  u32InFormat  The bits corresponding VSP, HSP, PCLK, PDORD, INFMT, SNRTYPE, OUTFMT and PDORD
 *             VSP, It should be following addition of some :
 *                      - \ref CAP_CAPPAR_VSP_LOW
 *                      - \ref CAP_CAPPAR_VSP_HIGH
 *
 *             HSP, It should be following addition of some :
 *                      - \ref CAP_CAPPAR_HSP_LOW
 *                      - \ref CAP_CAPPAR_HSP_HIGH
 *
 *             PCLK, It should be following addition of some:
 *                      - \ref CAP_CAPPAR_PCLKP_LOW
 *                      - \ref CAP_CAPPAR_PCLKP_HIGH
 *
 *             INFMT, It should be following addition of some :
 *                      - \ref CAP_CAPPAR_INFMT_YUV422
 *                      - \ref CAP_CAPPAR_INFMT_RGB565
 *
 *             SNRTYPE, It should be following addition of some :
 *                      - \ref CAP_CAPPAR_SNRTYPE_CCIR601
 *                      - \ref CAP_CAPPAR_SNRTYPE_CCIR656
 *
 *             OUTFMT, It should be following addition of some :
 *                      - \ref CAP_CAPPAR_OUTFMT_YUV422
 *                      - \ref CAP_CAPPAR_OUTFMT_ONLY_Y
 *                      - \ref CAP_CAPPAR_OUTFMT_RGB555
 *                      - \ref CAP_CAPPAR_OUTFMT_RGB565
 *
 *             PDORD, It should be following addition of some :
 *                      - \ref CAP_CAPPAR_PDORD_YUYV
 *                      - \ref CAP_CAPPAR_PDORD_YVYU
 *                      - \ref CAP_CAPPAR_PDORD_UYVY
 *                      - \ref CAP_CAPPAR_PDORD_VYUY
 *                      - \ref CAP_CAPPAR_PDORD_RGGB
 *                      - \ref CAP_CAPPAR_PDORD_BGGR
 *                      - \ref CAP_CAPPAR_PDORD_GBRG
 *                      - \ref CAP_CAPPAR_PDORD_GRBG
 *
 *            PNFMT, It should be following addition of some :
 *                      - \ref CAP_CAPPAR_PNFMT_YUV422
 *                      - \ref CAP_CAPPAR_PNFMT_YUV420
 *
 * @param[in]  u32OutFormet
 *                      - \ref CAP_CAPCTL_PKEN
 *                      - \ref CAP_CAPCTL_PNEN
 *
 * @return     None
 *
 * @details    Initialize the Image Capture Interface. Register a call back for driver internal using
 */
void CAP_Open(uint32_t u32InFormat, uint32_t u32OutFormet)
{
    CAP->CAPPAR = (CAP->CAPPAR & ~0x000007BF) | u32InFormat;
    CAP->CAPCTL = (CAP->CAPCTL & ~0x00000060) | u32OutFormet;
}

/**
 * @brief Set Cropping Window Starting Address and Size
 *
 * @param[in] u32VStart: Cropping Window Vertical Starting Address. It should be 0 ~ 0x7FF.
 *
 * @param[in] u32HStart: Cropping Window Horizontal Starting Address. It should be 0 ~ 0x7FF.
 *
 * @param[in] u32Height: Cropping Window Height . It should be 0 ~ 0x7FF.
 *
 * @param[in] u32Width: Cropping Window Width. It should be 0 ~ 0x7FF.
 *
 * @return    None
 *
 * @details   Set Cropping Window Starting Address Register
 */
void CAP_SetCroppingWindow(uint32_t u32VStart,uint32_t u32HStart, uint32_t u32Height, uint32_t u32Width)
{
    CAP->CWSP = (CAP->CWSP & ~(CAP_CWSP_CWSPV_Msk | CAP_CWSP_CWSPH_Msk))
                | (((u32VStart << 16) | u32HStart));

    CAP->CWS = (CAP->CWS & ~(CAP_CWS_CWSH_Msk | CAP_CWS_CWSW_Msk))
               | ((u32Height << 16)| u32Width);
}


/**
 * @brief     Set System Memory Packet Base Address0 Register
 *
 * @param[in]  u32Address : set PACBA0 register, It should be 0x0 ~ 0xFFFFFFFF
 *
 * @return    None
 *
 * @details   Set System Memory Packet Base Address Register
 */
void CAP_SetPacketBuf(uint32_t  u32Address )
{
    CAP->PACBA0 = u32Address;
    CAP->CAPCTL |= CAP_CAPCTL_UPDATE_Msk;
}

/**
 * @brief     Set System Memory Planar Y, U and V Base Address Register.
 *
 * @param[in] u32YAddr : set YBA0 register, It should be 0x0 ~ 0xFFFFFFFF
 *
 * @param[in] u32UAddr : set UBA0 register, It should be 0x0 ~ 0xFFFFFFFF
 *
 * @param[in] u32VAddr : set VBA0 register, It should be 0x0 ~ 0xFFFFFFFF
 *
 * @return    None
 *
 * @details   Set System Memory Planar Y Base Address Register
 */
void CAP_SetPlanarBuf(uint32_t u32YAddr, uint32_t u32UAddr, uint32_t u32VAddr)
{
    CAP->YBA0 = u32YAddr;
    CAP->UBA0 = u32UAddr;
    CAP->VBA0 = u32VAddr;
    CAP->CAPCTL |= CAP_CAPCTL_UPDATE_Msk;
}


/**
 * @brief     Close Image Capture Interface
 *
 * @return    None
 */
void CAP_Close(void)
{
    CAP->CAPCTL &= ~CAP_CAPCTL_VINEN;
}


/**
 * @brief      Set CAP Interrupt
 *
 * @param[in]  u32IntMask   Interrupt settings. It could be
 *                           - \ref CAP_CAPINT_VINTEN_Msk
 *                           - \ref CAP_CAPINT_MEINTEN_Msk
 *                           - \ref CAP_CAPINT_ADDRMEN_Msk
 *                           - \ref CAP_CAPINT_MDINTEN_Msk
 * @return     None
 *
 * @details    Set Video Frame End Interrupt Enable,
 *                  System Memory Error Interrupt Enable,
 *                  Address Match Interrupt Enable,
 *                  Motion Detection Output Finish Interrupt Enable.
 */
void CAP_EnableInt(uint32_t u32IntMask)
{
    CAP->CAPINT = (CAP->CAPINT & ~(CAP_CAPINT_VINTEN_Msk | CAP_CAPINT_MEINTEN_Msk | CAP_CAPINT_ADDRMEN_Msk | CAP_CAPINT_MDINTEN_Msk ) )
                  | u32IntMask;
}

/**
 * @brief      Disable CAP Interrupt
 *
 * @param[in]  u32IntMask   Interrupt settings. It could be
 *                           - \ref CAP_CAPINT_VINT_Msk
 *                           - \ref CAP_CAPINT_MEINT_Msk
 *                           - \ref CAP_CAPINT_ADDRMINT_Msk
 *                           - \ref CAP_CAPINT_MDINT_Msk
 * @return     None
 *
 * @details    Disable Video Frame End Interrupt ,
 *                  System Memory Error Interrupt ,
 *                  Address Match Interrupt and
 *                  Motion Detection Output Finish Interrupt .
 */
void CAP_DisableInt(uint32_t u32IntMask)
{
    CAP->CAPINT = (CAP->CAPINT & ~(u32IntMask) ) ;
}

/**
 * @brief     Close Image Capture Interface
 *
 * @return    None
 */
void CAP_Start(void)
{
    CAP->CAPCTL |= CAP_CAPCTL_VINEN;
}

/**
 * @brief     Close Image Capture Interface
 *
 * @param[in]  u32FrameComplete :
 *             TRUE:  Capture module automatically disable the CAP module after a frame had been captured
 *             FALSE: Stop Capture module now
 * @return    None
 *
 * @details   if u32FrameComplete is set to TRUE then get a new frame and disable CAP module
 */
void CAP_Stop(uint32_t u32FrameComplete)
{
    if(u32FrameComplete==TRUE)
        CAP->CAPCTL &= ~CAP_CAPCTL_VINEN;
    else {
        CAP->CAPCTL |= CAP_CAPCTL_SHUTTER_Msk;
        while(CAP_IS_STOPPED());
    }
}

/**
 * @brief     Set Packet Scaling Vertical and Horizontal Factor Register
 *
 * @param[in] u32VNumerator: Packet Scaling Vertical Factor N. It should be 0 ~ FFFF.
 *
 * @param[in] u32VDenominator: Packet Scaling Vertical Factor M. It should be 0 ~ FFFF.
 *
 * @param[in] u32HNumerator: Packet Scaling Vertical Factor N. It should be 0 ~ FFFF.
 *
 * @param[in] u32HDenominator: Packet Scaling Vertical Factor M. It should be 0 ~ FFFF.
 *
 * @return    None
 *
 * @details   Set Packet Scaling Vertical Factor Register
 */
void CAP_SetPacketScaling(uint32_t u32VNumerator, uint32_t u32VDenominator, uint32_t u32HNumerator, uint32_t u32HDenominator)
{
    uint32_t u32NumeratorL, u32NumeratorH;
    uint32_t u32DenominatorL, u32DenominatorH;

    u32NumeratorL = u32VNumerator&0xFF;
    u32NumeratorH=u32VNumerator>>8;
    u32DenominatorL = u32VDenominator&0xFF;
    u32DenominatorH = u32VDenominator>>8;
    CAP->PKDSL = (CAP->PKDSL & ~(CAP_PKDSL_PKDSVNL_Msk | CAP_PKDSL_PKDSVML_Msk))
                 | ((u32NumeratorL << 24)| (u32DenominatorL << 16));
    CAP->PKDSH = (CAP->PKDSH & ~(CAP_PKDSH_PKDSVNH_Msk | CAP_PKDSH_PKDSVMH_Msk))
                 | ((u32NumeratorH << 24) | (u32DenominatorH << 16));

    u32NumeratorL = u32HNumerator&0xFF;
    u32NumeratorH=u32HNumerator>>8;
    u32DenominatorL = u32HDenominator&0xFF;
    u32DenominatorH = u32HDenominator>>8;
    CAP->PKDSL = (CAP->PKDSL & ~(CAP_PKDSL_PKDSHNL_Msk | CAP_PKDSL_PKDSHML_Msk))
                 | ((u32NumeratorL << 8)| u32DenominatorL);
    CAP->PKDSH = (CAP->PKDSH & ~(CAP_PKDSH_PKDSHNH_Msk | CAP_PKDSH_PKDSHMH_Msk))
                 | ((u32NumeratorH << 8) | u32DenominatorH);
}

/**
 * @brief     Set Planar Scaling Vertical and Horizontal Factor Register
 *
 * @param[in] u32VNumerator: Planar Scaling Vertical Factor N. It should be 0 ~ FFFF.
 *
 * @param[in] u32VDenominator: Planar Scaling Vertical Factor M. It should be 0 ~ FFFF.
 *
 * @param[in] u32HNumerator: Planar Scaling Vertical Factor N. It should be 0 ~ FFFF.
 *
 * @param[in] u32HDenominator: Planar Scaling Vertical Factor M. It should be 0 ~ FFFF.
 *
 * @return    None
 *
 * @details   Set Packet Scaling Vertical Factor Register
 */
void CAP_SetPlanarScaling(uint32_t u32VNumerator, uint32_t u32VDenominator, uint32_t u32HNumerator, uint32_t u32HDenominator)
{
    uint32_t u32NumeratorL, u32NumeratorH;
    uint32_t u32DenominatorL, u32DenominatorH;

    u32NumeratorL = u32VNumerator&0xFF;
    u32NumeratorH = u32VNumerator>>8;
    u32DenominatorL = u32VDenominator&0xFF;
    u32DenominatorH = u32VDenominator>>8;
    CAP->PNDSL = (CAP->PNDSL & ~(CAP_PNDSL_PNDSVNL_Msk | CAP_PNDSL_PNDSVML_Msk))
                 | ((u32NumeratorL << 24)| (u32DenominatorL << 16));
    CAP->PNDSH = (CAP->PNDSH & ~(CAP_PNDSH_PNDSVNH_Msk | CAP_PNDSH_PNDSVMH_Msk))
                 | ((u32NumeratorH << 24)| (u32DenominatorH << 16));

    u32NumeratorL = u32HNumerator&0xFF;
    u32NumeratorH = u32HNumerator>>8;
    u32DenominatorL = u32HDenominator&0xFF;
    u32DenominatorH = u32HDenominator>>8;
    CAP->PNDSL = (CAP->PNDSL & ~(CAP_PNDSL_PNDSHNL_Msk | CAP_PNDSL_PNDSHML_Msk))
                 | ((u32NumeratorL << 8)| u32DenominatorL);
    CAP->PNDSH = (CAP->PNDSH & ~(CAP_PNDSH_PNDSHNH_Msk | CAP_PNDSH_PNDSHMH_Msk))
                 | ((u32NumeratorH << 8)| u32DenominatorH);
}

/**
 * @brief     Set Packet Frame Output Pixel Stride Width.
 *
 * @param[in] u32Stride : set PKSTRIDE register, It should be 0x0 ~ 0x3FFF
 *
 * @return    None
 *
 * @details   Set Packet Frame Output Pixel Stride Width
 */
void CAP_SetPacketStride(uint32_t u32Stride )
{
    CAP->STRIDE = (CAP->STRIDE & ~CAP_STRIDE_PKSTRIDE_Msk) | u32Stride;
}

/**
 * @brief     Set Planar Frame Output Pixel Stride Width.
 *
 * @param[in] u32Stride : set PNSTRIDE register, It should be 0x0 ~ 0x3FFF
 *
 * @return    None
 *
 * @details  Set Planar Frame Output Pixel Stride Width
 */
void CAP_SetPlanarStride(uint32_t u32Stride )
{
    CAP->STRIDE = (CAP->STRIDE & ~CAP_STRIDE_PNSTRIDE_Msk) | u32Stride<<CAP_STRIDE_PNSTRIDE_Pos;
}


/**
 * @brief     Enable Motion Detection Function
 *
 * @param[in] u32Freq: Motion Detection Detect Frequency. It should be 0x0 ~ 0x3.
 *
 * @param[in] u32BlockSize: Motion Detection Block Size
 *                        FALSE : 16x16
 *                        TRUE  : 8x8
 *
 * @param[in] u32Format: Motion Detection Save Mode
 *                        FALSE : 1 bit DIFF + 7 Y Differential
 *                        TRUE :  1 bit DIFF only
 *
 * @param[in] u32Threshold: Motion Detection Detect Threshold. It should be 0x0 ~ 0x1F.
 *
 * @param[in] u32YDetAddr : Motion Detection Detect Temp Y Output Address
 *
 * @param[in] u32DetAddr: Motion Detection Detect Address
 *
 * @return    None
 *
 * @details  Set Planar Frame Output Pixel Stride Width
 */
void CAP_EnableMotionDet(uint32_t u32Freq, uint32_t u32BlockSize, uint32_t u32Format, uint32_t u32Threshold,  uint32_t u32YDetAddr, uint32_t u32DetAddr)
{
    CAP->MD = (CAP->MD & ~(CAP_MD_MDSM_Msk | CAP_MD_MDBS_Msk | CAP_MD_MDEN_Msk)) |
              ((CAP_MD_MDEN_Msk | (u32BlockSize?CAP_MD_MDBS_Msk:0)) |
               (u32Format?CAP_MD_MDSM_Msk:0));

    CAP->MD = (CAP->MD & ~CAP_MD_MDDF_Msk) | (u32Freq<<CAP_MD_MDDF_Pos);
    CAP->MD = (CAP->MD & ~CAP_MD_MDTHR_Msk) | (u32Threshold<<CAP_MD_MDTHR_Pos);

    CAP->MDYADDR = u32YDetAddr;
    CAP->MDADDR = u32DetAddr;
}

/**
 * @brief     Enable Motion Detection Function
 *
 * @return    None
 *
 * @details  Set Planar Frame Output Pixel Stride Width
 */
void CAP_DisableMotionDet(void)
{
    CAP->MD &= ~CAP_MD_MDEN_Msk;
}

/*@}*/ /* end of group NUC400_CAP_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_CAP_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
