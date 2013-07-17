/******************************************************************************
 * @file     PWM.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/14 15:12p $
 * @brief    NUC123 Series PWM Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef  __PWM_H
#define  __PWM_H

#include  "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup PWM_MACRO PWM Macro
  * @{
  */

/** @addtogroup PWM_MACRO_CONTANT PWM Macro Contant
  * @{
  */

////PWMA->CSR ///////////////////////////////////////////////////////////////////////////
#define  PWM_CSR_1                 4ul
#define  PWM_CSR_2                 0
#define  PWM_CSR_4                 1ul
#define  PWM_CSR_8                 2ul
#define  PWM_CSR_16                3ul

////PWMA->PCR ///////////////////////////////////////////////////////////////////////////
#define  PWM_CH23_CENTER_ALIGN     (1ul << PWM_PCR_PWM23TYPE_Pos)
#define  PWM_CH01_CENTER_ALIGN     (1ul << PWM_PCR_PWM01TYPE_Pos)  
#define  PWM_CH3_PERIODIC          (1ul << PWM_PCR_CH3MOD_Pos)   
#define  PWM_CH3_INV               (1ul << PWM_PCR_CH3INV_Pos)  
#define  PWM_CH3_PINV              (1ul << PWM_PCR_CH3PINV_Pos)    
#define  PWM_CH3_EN                (1ul << PWM_PCR_CH3EN_Pos)  
#define  PWM_CH2_PERIODIC          (1ul << PWM_PCR_CH2MOD_Pos)   
#define  PWM_CH2_INV               (1ul << PWM_PCR_CH2INV_Pos)  
#define  PWM_CH2_PINV              (1ul << PWM_PCR_CH2PINV_Pos)    
#define  PWM_CH2_EN                (1ul << PWM_PCR_CH2EN_Pos)  
#define  PWM_CH1_PERIODIC          (1ul << PWM_PCR_CH1MOD_Pos)   
#define  PWM_CH1_INV               (1ul << PWM_PCR_CH1INV_Pos)  
#define  PWM_CH1_PINV              (1ul << PWM_PCR_CH1PINV_Pos)    
#define  PWM_CH1_EN                (1ul << PWM_PCR_CH1EN_Pos)  
#define  PWM_DZ23_EN               (1ul << PWM_PCR_DZEN23_Pos)  
#define  PWM_DZ01_EN               (1ul << PWM_PCR_DZEN01_Pos)  
#define  PWM_CH0_PERIODIC          (1ul << PWM_PCR_CH0MOD_Pos)   
#define  PWM_CH0_INV               (1ul << PWM_PCR_CH0INV_Pos)  
#define  PWM_CH0_PINV              (1ul << PWM_PCR_CH0PINV_Pos)    
#define  PWM_CH0_EN                (1ul << PWM_PCR_CH0EN_Pos)  

////PWMA->PIER //////////////////////////////////////////////////////////////////////////
#define  PWM_INT_TYPE23_UP         (1ul << PWM_PIER_INT23TYPE_Pos)
#define  PWM_INT_TYPE23_DOWN       (0ul << PWM_PIER_INT23TYPE_Pos)
#define  PWM_INT_TYPE01_UP         (1ul << PWM_PIER_INT01TYPE_Pos)
#define  PWM_INT_TYPE01_DOWN       (0ul << PWM_PIER_INT01TYPE_Pos)
#define  PWM_DIE3_EN               (1ul << PWM_PIER_PWMDIE3_Pos) 
#define  PWM_DIE2_EN               (1ul << PWM_PIER_PWMDIE2_Pos) 
#define  PWM_DIE1_EN               (1ul << PWM_PIER_PWMDIE1_Pos) 
#define  PWM_DIE0_EN               (1ul << PWM_PIER_PWMDIE0_Pos) 
#define  PWM_IE3_EN                (1ul << PWM_PIER_PWMIE3_Pos) 
#define  PWM_IE2_EN                (1ul << PWM_PIER_PWMIE2_Pos) 
#define  PWM_IE1_EN                (1ul << PWM_PIER_PWMIE1_Pos) 
#define  PWM_IE0_EN                (1ul << PWM_PIER_PWMIE0_Pos) 

////PWMA->PIIR //////////////////////////////////////////////////////////////////////////
#define  PWM_DIF3                  (1ul << PWM_PIIR_PWMDIF3_Pos) 
#define  PWM_DIF2                  (1ul << PWM_PIIR_PWMDIF2_Pos) 
#define  PWM_DIF1                  (1ul << PWM_PIIR_PWMDIF1_Pos) 
#define  PWM_DIF0                  (1ul << PWM_PIIR_PWMDIF0_Pos) 
#define  PWM_IF3                   (1ul << PWM_PIIR_PWMIF3_Pos) 
#define  PWM_IF2                   (1ul << PWM_PIIR_PWMIF2_Pos) 
#define  PWM_IF1                   (1ul << PWM_PIIR_PWMIF1_Pos) 
#define  PWM_IF0                   (1ul << PWM_PIIR_PWMIF0_Pos) 

////PWMA->CCR0 //////////////////////////////////////////////////////////////////////////
#define  PWM1_CAP_FALL_FLAG        (1ul << PWM_CCR0_CFLRI1_Pos) 
#define  PWM1_CAP_RISE_FLAG        (1ul << PWM_CCR0_CRLRI1_Pos) 
#define  PWM1_CAP_IF               (1ul << PWM_CCR0_CAPIF1_Pos) 
#define  PWM1_CAP_EN               (1ul << PWM_CCR0_CAPCH1EN_Pos)  
#define  PWM1_CAP_FALL_IE          (1ul << PWM_CCR0_CFL_IE1_Pos)  
#define  PWM1_CAP_RISE_IE          (1ul << PWM_CCR0_CRL_IE1_Pos) 
#define  PWM1_CAP_IN_INV           (1ul << PWM_CCR0_INV1_Pos) 
    
#define  PWM0_CAP_FALL_FLAG        (1ul << PWM_CCR0_CFLRI0_Pos) 
#define  PWM0_CAP_RISE_FLAG        (1ul << PWM_CCR0_CRLRI0_Pos) 
#define  PWM0_CAP_IF               (1ul << PWM_CCR0_CAPIF0_Pos) 
#define  PWM0_CAP_EN               (1ul << PWM_CCR0_CAPCH0EN_Pos)  
#define  PWM0_CAP_FALL_IE          (1ul << PWM_CCR0_CFL_IE0_Pos)  
#define  PWM0_CAP_RISE_IE          (1ul << PWM_CCR0_CRL_IE0_Pos) 
#define  PWM0_CAP_IN_INV           (1ul << PWM_CCR0_INV0_Pos)     

////PWMA->CCR2 //////////////////////////////////////////////////////////////////////////
#define  PWM3_CAP_FALL_FLAG        (1ul << PWM_CCR2_CFLRI3_Pos) 
#define  PWM3_CAP_RISE_FLAG        (1ul << PWM_CCR2_CRLRI3_Pos) 
#define  PWM3_CAP_IF               (1ul << PWM_CCR2_CAPIF3_Pos) 
#define  PWM3_CAP_EN               (1ul << PWM_CCR2_CAPCH3EN_Pos) 
#define  PWM3_CAP_FALL_IE          (1ul << PWM_CCR2_CFL_IE3_Pos)  
#define  PWM3_CAP_RISE_IE          (1ul << PWM_CCR2_CRL_IE3_Pos) 
#define  PWM3_CAP_IN_INV           (1ul << PWM_CCR2_INV3_Pos) 
    
#define  PWM2_CAP_FALL_FLAG        (1ul << PWM_CCR2_CFLRI2_Pos) 
#define  PWM2_CAP_RISE_FLAG        (1ul << PWM_CCR2_CRLRI2_Pos) 
#define  PWM2_CAP_IF               (1ul << PWM_CCR2_CAPIF2_Pos) 
#define  PWM2_CAP_EN               (1ul << PWM_CCR2_CAPCH2EN_Pos)  
#define  PWM2_CAP_FALL_IE          (1ul << PWM_CCR2_CFL_IE2_Pos)  
#define  PWM2_CAP_RISE_IE          (1ul << PWM_CCR2_CRL_IE2_Pos) 
#define  PWM2_CAP_IN_INV           (1ul << PWM_CCR2_INV2_Pos)     

////PWMA->CAPENR ////////////////////////////////////////////////////////////////////////
#define  PWMA_CAP0_PA12_EN         (1ul << PWM_CAPENR_CINEN0_Pos)
#define  PWMA_CAP1_PA13_EN         (1ul << PWM_CAPENR_CINEN1_Pos)
#define  PWMA_CAP2_PA14_EN         (1ul << PWM_CAPENR_CINEN2_Pos)
#define  PWMA_CAP3_PA15_EN         (1ul << PWM_CAPENR_CINEN3_Pos)

////PWMA->POE //////////////////////////////////////////////////////////////////////////
#define  PWM_POE3                  (1ul << PWM_POE_POE3_Pos) 
#define  PWM_POE2                  (1ul << PWM_POE_POE2_Pos) 
#define  PWM_POE1                  (1ul << PWM_POE_POE1_Pos) 
#define  PWM_POE0                  (1ul << PWM_POE_POE0_Pos) 

////PWMA->CAPPDMACTL ////////////////////////////////////////////////////////////////////
#define  PWM3CAP_DMA_FALL_FIRST    (0ul << PWM_CAPPDMACTL_CAP3RFORDER_Pos)
#define  PWM3CAP_DMA_RISE_FIRST    (1ul << PWM_CAPPDMACTL_CAP3RFORDER_Pos)

#define  PWM3CAP_DMA_RISE          (1ul << PWM_CAPPDMACTL_CAP3PDMAMOD_Pos)
#define  PWM3CAP_DMA_FALL          (2ul << PWM_CAPPDMACTL_CAP3PDMAMOD_Pos)
#define  PWM3CAP_DMA_RISE_FALL     (3ul << PWM_CAPPDMACTL_CAP3PDMAMOD_Pos)

#define  PWM3CAP_DMA_EN            (1ul << PWM_CAPPDMACTL_CAP3PDMAEN_Pos)

#define  PWM2CAP_DMA_FALL_FIRST    (0ul << PWM_CAPPDMACTL_CAP2RFORDER_Pos)
#define  PWM2CAP_DMA_RISE_FIRST    (1ul << PWM_CAPPDMACTL_CAP2RFORDER_Pos)
#define  PWM2CAP_DMA_RISE          (1ul << PWM_CAPPDMACTL_CAP2PDMAMOD_Pos)
#define  PWM2CAP_DMA_FALL          (2ul << PWM_CAPPDMACTL_CAP2PDMAMOD_Pos)
#define  PWM2CAP_DMA_RISE_FALL     (3ul << PWM_CAPPDMACTL_CAP2PDMAMOD_Pos)
#define  PWM2CAP_DMA_EN            (1ul << PWM_CAPPDMACTL_CAP2PDMAEN_Pos)

#define  PWM1CAP_DMA_FALL_FIRST    (0ul << PWM_CAPPDMACTL_CAP1RFORDER_Pos)
#define  PWM1CAP_DMA_RISE_FIRST    (1ul << PWM_CAPPDMACTL_CAP1RFORDER_Pos)
#define  PWM1CAP_DMA_RISE          (1ul << PWM_CAPPDMACTL_CAP1PDMAMOD_Pos)
#define  PWM1CAP_DMA_FALL          (2ul << PWM_CAPPDMACTL_CAP1PDMAMOD_Pos)
#define  PWM1CAP_DMA_RISE_FALL     (3ul << PWM_CAPPDMACTL_CAP1PDMAMOD_Pos)
#define  PWM1CAP_DMA_EN            (1ul << PWM_CAPPDMACTL_CAP1PDMAEN_Pos)

#define  PWM0CAP_DMA_FALL_FIRST    (0ul << PWM_CAPPDMACTL_CAP0RFORDER_Pos)
#define  PWM0CAP_DMA_RISE_FIRST    (1ul << PWM_CAPPDMACTL_CAP0RFORDER_Pos)
#define  PWM0CAP_DMA_RISE          (1ul << PWM_CAPPDMACTL_CAP0PDMAMOD_Pos)
#define  PWM0CAP_DMA_FALL          (2ul << PWM_CAPPDMACTL_CAP0PDMAMOD_Pos)
#define  PWM0CAP_DMA_RISE_FALL     (3ul << PWM_CAPPDMACTL_CAP0PDMAMOD_Pos)
#define  PWM0CAP_DMA_EN            (1ul << PWM_CAPPDMACTL_CAP0PDMAEN_Pos)

////////////////////////////////////////////////////////////////////////////////////////
#define  PWM_CHMOD_ONE_SHOT        0
#define  PWM_CHMOD_AUTO_RELOAD     1
#define  PWM_NO_INVERT             0
#define  PWM_INVERT                1
#define  PWM_CAP_RISING            2ul
#define  PWM_CAP_FALLING           4ul

/** Structure used to configure PWM output waveform */
typedef struct
{
	uint16_t  u16Cn;	 ///< CN (0~0xFFFF) or (0~0xFFFFFFFF) in cascade capture mode. 0 will stop PWM counter
	uint16_t  u16Cm;	 ///< CM (0~0xFFFF)
	uint8_t	  u8PreScale;	 ///< Valid range is between 1~0xFF
	uint8_t   u8Div;	 ///< PWM_CSR_1, PWM_CSR_2, PWM_CSR_4, PWM_CSR_8, or PWM_CSR_16
	uint8_t	  u8Mode;	 ///< 0: PWM_CHMOD_ONE_SHOT. 1: PWM_CHMOD_AUTO_RELOAD 
 	uint8_t	  u8Inv;	 ///< 0: output waveform not inversed, Other: output inversed waveform
}S_DRVPWM_TIME_DATA_T;

/*@}*/ /* end of group PWM_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup PWM_MACRO_FUNC PWM Macro Func
  @{
*/

/**
 * @brief      Set PWMA01 dead-zone time
 *
 * @param[in]   x      dead-zone time range from 0 to 255 :          
 *  
 * @return      None
 *
 * @details     Write x into field DZ01 of PWMA->PPR. 
 *              Example of function call:  
 *              PWMA_SET_DZ01(100) ;
 */
static __INLINE void  PWMA_SET_DZ01(uint8_t x) 
{
   (PWMA->PPR = (((PWMA->PPR)&(~PWM_PPR_DZI01_Msk))|((x)<<PWM_PPR_DZI01_Pos))) ;
}

/**
 * @brief      Get PWMA01 dead-zone time
 *
 * @param[in]          
 *  
 * @return      Value of field DZ01 in register PWMA->PPR.
 *
 * @details     Read DZ01 from TCSR. 
 *              Example of function call:  
 *              PWMA_DZ01_GET() ;
 */
static __INLINE uint8_t PWMA_GET_DZ01(void) 
{
   return (((PWMA->PPR) & PWM_PPR_DZI01_Msk)>>PWM_PPR_DZI01_Pos) ;
}

/**
 * @brief      Set PWMA23 dead-zone time
 *
 * @param[in]   x      dead-zone time range from 0 to 255 :          
 *  
 * @return      None
 *
 * @details     Write x into field DZ23 of PWMA->PPR. 
 *              Example of function call:  
 *              PWMA_SET_DZ23(100) ;
 */
static __INLINE void PWMA_SET_DZ23(uint8_t x) 
{
   (PWMA->PPR = (((PWMA->PPR)&(~PWM_PPR_DZI23_Msk))|((x)<<PWM_PPR_DZI23_Pos)));
}

/**
 * @brief      Get PWMA23 dead-zone time
 *
 * @param[in]          
 *  
 * @return      Value of field DZ23 in register PWMA->PPR.
 *
 * @details     Read DZ23 from TCSR. 
 *              Example of function call:  
 *              PWMA_GET_DZ23() ;
 */
static __INLINE uint8_t PWMA_GET_DZ23(void)    
{
  return (((PWMA->PPR) & PWM_PPR_DZI23_Msk)>> PWM_PPR_DZI23_Pos) ;
}

/**
 * @brief      Set PWMA01 clock pre-scaler
 *
 * @param[in]   x      clock pre-scaler range from 0 to 255 :          
 *  
 * @return      None
 *
 * @details     Write x into field CP01 of PWMA->PPR. 
 *              Example of function call:  
 *             PWMA_SET_PRESCALER01(100) ;
 */
static __INLINE void PWMA_SET_PRESCALER01(uint8_t x)  
{
   (PWMA->PPR = (((PWMA->PPR)&(~PWM_PPR_CP01_Msk))|(x)));
}

/**
 * @brief      Get PWMA01 clock pre-scaler
 *
 * @param[in]   None       
 *  
 * @return      Value of field CP01 in register PWMA->PPR.
 *
 * @details     Read CP01 from PWMA->PPR. 
 *              Example of function call:  
 *              PWMA_GET_PRESCALER01() ;
 */
static __INLINE uint8_t PWMA_GET_PRESCALER01(void)
{
  return  ((PWMA->PPR) & PWM_PPR_CP01_Msk) ;
}

/**
 * @brief      Set PWMA01 clock pre-scaler
 *
 * @param[in]   x      clock pre-scaler range from 0 to 255 :          
 *  
 * @return      None
 *
 * @details     Write x into field CP23 of PWMA->PPR. 
 *              Example of function call:  
 *             PWMA_SET_PRESCALER23(100) ;
 */
static __INLINE void PWMA_SET_PRESCALER23(uint8_t x)
{
   (PWMA->PPR = (((PWMA->PPR)&(~PWM_PPR_CP23_Msk))|(((x)&0xFF)<<PWM_PPR_CP23_Pos)));
}

/**
 * @brief      Get PWMA01 clock pre-scaler
 *
 * @param[in]   None       
 *  
 * @return      Value of field CP23 in register PWMA->PPR.
 *
 * @details     Read CP23 from PWMA->PPR. 
 *              Example of function call:  
 *              PWMA_GET_PRESCALER23() ;
 */
static __INLINE uint8_t PWMA_GET_PRESCALER23(void) 
{
  return  (((PWMA->PPR) & PWM_PPR_CP23_Msk)>>PWM_PPR_CP23_Pos) ;
}

/**
 * @brief      Set PWMA01 CSR
 *
 * @param[in]   PWMA_CSR   It must be following value              
 *                           PWM_CSR_1    
 *                           PWM_CSR_2  
 *                           PWM_CSR_4   
 *                           PWM_CSR_8  
 *                           PWM_CSR_16  
 *  
 * @return      None
 *
 * @details     Write PWMA_CSR into field CSR0 of PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_SET_CSR0(PWM_CSR_1) ;
 */
static __INLINE void PWMA_SET_CSR0(uint8_t PWMA_CSR) 
{
    (PWMA->CSR = (((PWMA->CSR)&(~PWM_CSR_CSR0_Msk))|(PWMA_CSR)));
}

/**
 * @brief      Get PWMA0 CSR
 *
 * @param[in]          
 *  
 * @return      Value of field CSR0 in register PWMA->CSR.
 *
 * @details     Read CSR0 from PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_GET_CSR0() ;
 */
static __INLINE uint8_t PWMA_GET_CSR0() 
{
  return  ((PWMA->CSR) & PWM_CSR_CSR0_Msk);
}

/**
 * @brief      Set PWMA01 CSR
 *
 * @param[in]   PWMA_CSR   It must be following value              
 *                           PWM_CSR_1    
 *                           PWM_CSR_2  
 *                           PWM_CSR_4   
 *                           PWM_CSR_8  
 *                           PWM_CSR_16  
 *  
 * @return      None
 *
 * @details     Write PWMA_CSR into field CSR1 of PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_SET_CSR1(PWM_CSR_1) ;
 */
static __INLINE void PWMA_SET_CSR1(uint8_t PWMA_CSR) 
{
    (PWMA->CSR = (((PWMA->CSR)&(~PWM_CSR_CSR1_Msk))|((PWMA_CSR)<<PWM_CSR_CSR1_Pos)))  ;
}

/**
 * @brief      Get PWMA0 CSR
 *
 * @param[in]          
 *  
 * @return      Value of field CSR1 in register PWMA->CSR.
 *
 * @details     Read CSR1 from PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_GET_CSR1() ;
 */
static __INLINE uint8_t PWMA_GET_CSR1(void)
{
   return (((PWMA->CSR) & PWM_CSR_CSR1_Msk)>>PWM_CSR_CSR1_Pos)  ;
}

/**
 * @brief      Set PWMA01 CSR
 *
 * @param[in]   PWMA_CSR   It must be following value              
 *                           PWM_CSR_1    
 *                           PWM_CSR_2  
 *                           PWM_CSR_4   
 *                           PWM_CSR_8  
 *                           PWM_CSR_16  
 *  
 * @return      None
 *
 * @details     Write PWMA_CSR into field CSR2 of PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_SET_CSR2(PWM_CSR_1) ;
 */
static __INLINE void PWMA_SET_CSR2(uint8_t PWMA_CSR)
{
  (PWMA->CSR = (((PWMA->CSR)&(~PWM_CSR_CSR2_Msk))|((PWMA_CSR)<<PWM_CSR_CSR2_Pos))) ;
}

/**
 * @brief      Get PWMA0 CSR
 *
 * @param[in]          
 *  
 * @return      Value of field CSR2 in register PWMA->CSR.
 *
 * @details     Read CSR2 from PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_GET_CSR2() ;
 */
static __INLINE uint8_t PWMA_GET_CSR2(void)  
{
  return (((PWMA->CSR) & PWM_CSR_CSR2_Msk)>>PWM_CSR_CSR2_Pos) ;
}

/**
 * @brief      Set PWMA01 CSR
 *
 * @param[in]   PWMA_CSR   It must be following value              
 *                           PWM_CSR_1    
 *                           PWM_CSR_2  
 *                           PWM_CSR_4   
 *                           PWM_CSR_8  
 *                           PWM_CSR_16  
 *  
 * @return      None
 *
 * @details     Write PWMA_CSR into field CSR3 of PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_SET_CSR3(PWM_CSR_1) ;
 */
static __INLINE void PWMA_SET_CSR3(uint8_t PWMA_CSR)
{
  (PWMA->CSR = (((PWMA->CSR)&(~PWM_CSR_CSR3_Msk))|((PWMA_CSR)<<PWM_CSR_CSR3_Pos))) ;
}

/**
 * @brief      Get PWMA0 CSR
 *
 * @param[in]          
 *  
 * @return      Value of field CSR3 in register PWMA->CSR.
 *
 * @details     Read CSR3 from PWMA->CSR. 
 *              Example of function call:  
 *              PWMA_GET_CSR3() ;
 */
static __INLINE uint8_t PWMA_GET_CSR3(void)
{
  return (((PWMA->CSR) & PWM_CSR_CSR3_Msk)>>PWM_CSR_CSR3_Pos) ;
}

/**
 * @brief      Configue PWMA CH23 work in center aligned mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into bit PWMTYPE23 of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH23_CENTER_ALIGN() ;
 */
static __INLINE void PWMA_CH23_CENTER_ALIGN(void)
{
  (PWMA->PCR |= PWM_CH23_CENTER_ALIGN) ;
}

/**
 * @brief      Configue PWMA CH23 work in edge aligned mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into bit PWMTYPE23 of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH23_EDGE_ALIGN() ;
 */
static __INLINE void PWMA_CH23_EDGE_ALIGN(void) 
{
  (PWMA->PCR &= ~PWM_CH23_CENTER_ALIGN) ;
}

/**
 * @brief      Configue PWMA CH01 work in center aligned mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into bit PWMTYPE01 of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH01_CENTER_ALIGN() ;
 */
static __INLINE void PWMA_CH01_CENTER_ALIGN(void) 
{
  (PWMA->PCR |= PWM_CH01_CENTER_ALIGN) ;
}

/**
 * @brief      Configue PWMA CH01 work in edge aligned mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into bit PWMTYPE01 of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH01_EDGE_ALIGN() ;
 */
static __INLINE void PWMA_CH01_EDGE_ALIGN(void)
{
  (PWMA->PCR &= ~PWM_CH01_CENTER_ALIGN) ;
}

/**
 * @brief      Configue PWMA CH3 periodic mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH3MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3_PERIODIC_MODE() ;
 */
static __INLINE void PWMA_CH3_PERIODIC_MODE(void)
{
  (PWMA->PCR |= PWM_CH3_PERIODIC) ;
}

/**
 * @brief      Configue PWMA CH3 once mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH3MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3_ONCE_MODE() ;
 */
static __INLINE void PWMA_CH3_ONCE_MODE(void)
{
  (PWMA->PCR &= ~PWM_CH3_PERIODIC) ;
}

/**
 * @brief      Configue PWMA CH2 periodic mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH2MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2_PERIODIC_MODE() ;
 */
static __INLINE void PWMA_CH2_PERIODIC_MODE(void)
{
  (PWMA->PCR |= PWM_CH2_PERIODIC) ;
}

/**
 * @brief      Configue PWMA CH2 once mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH2MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2_ONCE_MODE() ;
 */
static __INLINE void PWMA_CH2_ONCE_MODE(void)
{
  (PWMA->PCR &= ~PWM_CH2_PERIODIC) ;
}

/**
 * @brief      Configue PWMA CH1 periodic mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH1MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1_PERIODIC_MODE() ;
 */
static __INLINE void PWMA_CH1_PERIODIC_MODE(void)
{
  (PWMA->PCR |= PWM_CH1_PERIODIC) ;
}

/**
 * @brief      Configue PWMA CH1 once mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH1MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1_ONCE_MODE() ;
 */
static __INLINE void PWMA_CH1_ONCE_MODE(void)
{
  (PWMA->PCR &= ~PWM_CH1_PERIODIC) ;
}

/**
 * @brief      Configue PWMA CH0 periodic mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH0MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0_PERIODIC_MODE() ;
 */
static __INLINE void PWMA_CH0_PERIODIC_MODE(void)
{
  (PWMA->PCR |= PWM_CH0_PERIODIC) ;
}

/**
 * @brief      Configue PWMA CH0 once mode
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH0MOD of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0_ONCE_MODE() ;
 */
static __INLINE void PWMA_CH0_ONCE_MODE(void)
{
  (PWMA->PCR &= ~PWM_CH0_PERIODIC) ;
}

/**
 * @brief       Enable PWMA CH3INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH3INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3INV_ENABLE() ;
 */
static __INLINE void PWMA_CH3INV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH3_INV) ;
}

/**
 * @brief       Disable PWMA CH3INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH3INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3INV_DISABLE() ;
 */
static __INLINE void PWMA_CH3INV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH3_INV) ;
}
 
/**
 * @brief       Enable PWMA CH2INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH2INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2INV_ENABLE() ;
 */
static __INLINE void PWMA_CH2INV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH2_INV) ;
}

/**
 * @brief       Disable PWMA CH2INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH2INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2INV_DISABLE() ;
 */
static __INLINE void PWMA_CH2INV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH2_INV) ;
}

/**
 * @brief       Enable PWMA CH1INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH1INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1INV_ENABLE() ;
 */
static __INLINE void PWMA_CH1INV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH1_INV) ;
}

/**
 * @brief       Disable PWMA CH1INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH1INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1INV_DISABLE() ;
 */
static __INLINE void PWMA_CH1INV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH1_INV) ;
}

/**
 * @brief       Enable PWMA CH0INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH0INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0INV_ENABLE() ;
 */
static __INLINE void PWMA_CH0INV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH0_INV) ;
}

/**
 * @brief       Disable PWMA CH0INV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH0INV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0INV_DISABLE() ;
 */
static __INLINE void PWMA_CH0INV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH0_INV) ;
}

/**
 * @brief       Enable PWMA CH3PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH3PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3PINV_ENABLE() ;
 */
static __INLINE void PWMA_CH3PINV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH3_PINV) ;
}

/**
 * @brief       Disable PWMA CH3PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH3PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3PINV_DISABLE() ;
 */
static __INLINE void PWMA_CH3PINV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH3_PINV) ;
}

/**
 * @brief       Enable PWMA CH2PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH2PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2PINV_ENABLE() ;
 */
static __INLINE void PWMA_CH2PINV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH2_PINV) ;
}

/**
 * @brief       Disable PWMA CH2PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH2PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2PINV_DISABLE() ;
 */
static __INLINE void PWMA_CH2PINV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH2_PINV) ;
}

/**
 * @brief       Enable PWMA CH1PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH1PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1PINV_ENABLE() ;
 */
static __INLINE void PWMA_CH1PINV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH1_PINV) ;
}

/**
 * @brief       Disable PWMA CH1PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH1PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1PINV_DISABLE() ;
 */
static __INLINE void PWMA_CH1PINV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH1_PINV) ;
}

/**
 * @brief       Enable PWMA CH0PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH0PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0PINV_ENABLE() ;
 */
static __INLINE void PWMA_CH0PINV_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH0_PINV) ;
}

/**
 * @brief       Disable PWMA CH0PINV
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH0PINV of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0PINV_DISABLE() ;
 */
static __INLINE void PWMA_CH0PINV_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH0_PINV) ;
}

/**
 * @brief       Enable PWMA CH3
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH3EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3_ENABLE() ;
 */
static __INLINE void PWMA_CH3_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH3_EN) ;
}

/**
 * @brief       Disable PWMA CH3
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH3EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH3_DISABLE() ;
 */
static __INLINE void PWMA_CH3_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH3_EN) ;
}

/**
 * @brief       Enable PWMA CH2EN
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH2EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2_ENABLE() ;
 */
static __INLINE void PWMA_CH2_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH2_EN) ;
}
 
/**
 * @brief       Disable PWMA CH2EN
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH2EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH2_DISABLE() ;
 */
static __INLINE void PWMA_CH2_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH2_EN) ;
}

/**
 * @brief       Enable PWMA CH1EN
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH1EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1_ENABLE() ;
 */
static __INLINE void PWMA_CH1_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH1_EN) ;
}
 
/**
 * @brief       Disable PWMA CH1EN
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH1EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH1_DISABLE() ;
 */
static __INLINE void PWMA_CH1_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH1_EN) ;
}

/**
 * @brief       Enable PWMA CH0EN
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 1 into field CH0EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0_ENABLE() ;
 */
static __INLINE void PWMA_CH0_ENABLE(void)
{
  (PWMA->PCR |= PWM_CH0_EN) ;
}
 
/**
 * @brief       Disable PWMA CH0EN
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details     Write 0 into field CH0EN of PWMA->PCR. 
 *              Example of function call:  
 *              PWMA_CH0_DISABLE() ;
 */
static __INLINE void PWMA_CH0_DISABLE(void)
{
  (PWMA->PCR &= ~PWM_CH0_EN) ;
}

/**
 * @brief       Write PWM0 frequency register CNR0
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CNR0. 
 *              Example of function call:  
 *              PWMA_SET_CNR0(1000) ;
 */
static __INLINE void PWMA_SET_CNR0(uint16_t x)
{
  (PWMA->CNR0 = (x))  ;
}

/**
 * @brief       Read CNR0 of PWM0
 *
 * @param[in]         
 *  
 * @return      PWMA->CNR0
 *
 * @details     Read register CNR0 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CNR0() ;
 */
static __INLINE uint16_t PWMA_GET_CNR0(void)
{
 return (PWMA->CNR0)  ;
}
/**
 * @brief       Write PWM0 frequency register CMR0
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CMR0. 
 *              Example of function call:  
 *              PWMA_SET_CMR0(1000) ;
 */
static __INLINE void PWMA_SET_CMR0(uint16_t x)
{
  (PWMA->CMR0 = (x))  ;
}

/**
 * @brief       Read CMR0 of PWM0
 *
 * @param[in]         
 *  
 * @return      PWMA->CMR0
 *
 * @details     Read register CMR0 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CMR0() ;
 */
static __INLINE uint16_t PWMA_GET_CMR0(void)
{
  return  (PWMA->CMR0) ; 
}

/**
 * @brief       Write PWM1 frequency register CNR1
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CNR1. 
 *              Example of function call:  
 *              PWMA_SET_CNR1(1000) ;
 */
static __INLINE void PWMA_SET_CNR1(uint16_t x)
{
  (PWMA->CNR1 = (x)) ;
}

/**
 * @brief       Read CNR1 of PWM1
 *
 * @param[in]         
 *  
 * @return      PWMA->CNR1
 *
 * @details     Read register CNR1 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CNR1() ;
 */
static __INLINE uint16_t PWMA_GET_CNR1(void)
{
  return (PWMA->CNR1) ;
}

/**
 * @brief       Write PWM1 frequency register CMR1
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CMR1. 
 *              Example of function call:  
 *              PWMA_SET_CMR1(1000) ;
 */
static __INLINE void PWMA_SET_CMR1(uint16_t x)
{
  (PWMA->CMR1 = (x)) ;
}

/**
 * @brief       Read CMR1 of PWM1
 *
 * @param[in]         
 *  
 * @return      PWMA->CMR1
 *
 * @details     Read register CMR1 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CMR1() ;
 */
static __INLINE uint16_t PWMA_GET_CMR1(void)
{
  return (PWMA->CMR1) ;
}

/**
 * @brief       Write PWM2 frequency register CNR2
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CNR2. 
 *              Example of function call:  
 *              PWMA_SET_CNR2(1000) ;
 */
static __INLINE void PWMA_SET_CNR2(uint16_t x)
{
  (PWMA->CNR2 = (x))  ;
}

/**
 * @brief       Read CNR2 of PWM2
 *
 * @param[in]         
 *  
 * @return      PWMA->CNR2
 *
 * @details     Read register CNR2 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CNR2() ;
 */
static __INLINE uint16_t PWMA_GET_CNR2(void)
{
 return (PWMA->CNR2) ;
}

/**
 * @brief       Write PWM2 frequency register CMR2
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CMR2. 
 *              Example of function call:  
 *              PWMA_SET_CMR2(1000) ;
 */
static __INLINE void PWMA_SET_CMR2(uint16_t x) 
{
  (PWMA->CMR2 = (x)) ;
}

/**
 * @brief       Read CMR2 of PWM2
 *
 * @param[in]         
 *  
 * @return      PWMA->CMR2
 *
 * @details     Read register CMR2 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CMR2() ;
 */
static __INLINE uint16_t PWMA_GET_CMR2(void)
{
  return (PWMA->CMR2) ;
}

/**
 * @brief       Write PWM3 frequency register CNR3
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CNR3. 
 *              Example of function call:  
 *              PWMA_SET_CNR3(1000) ;
 */
static __INLINE void PWMA_SET_CNR3(uint16_t x)
{
  (PWMA->CNR3 = (x)) ;
}

/**
 * @brief       Read CNR3 of PWM3
 *
 * @param[in]         
 *  
 * @return      PWMA->CNR0
 *
 * @details     Read register CNR3 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CNR3() ;
 */
static __INLINE uint16_t PWMA_GET_CNR3(void)
{
  return (PWMA->CNR3) ;
}

/**
 * @brief       Write PWM3 frequency register CMR3
 *
 * @param[in]   x    a value of uint16_t type.       
 *  
 * @return      None
 *
 * @details     Write x into register PWMA->CMR3. 
 *              Example of function call:  
 *              PWMA_SET_CMR3(1000) ;
 */
static __INLINE void PWMA_SET_CMR3(uint16_t x)
{
  (PWMA->CMR3 = (x)) ;
}

/**
 * @brief       Read CMR3 of PWM3
 *
 * @param[in]         
 *  
 * @return      PWMA->CMR3
 *
 * @details     Read register CMR3 of PWMA. 
 *              Example of function call:  
 *              Period  = PWMA_GET_CMR3() ;
 */
static __INLINE uint16_t PWMA_GET_CMR3(void)
{
  return (PWMA->CMR3) ;
}

/**
 * @brief       Enable PWMA DIE
 *
 * @param[in]   DIE    It must be the following constance or addition of some them.       
 *                    PWM_DIE3_EN              
 *                    PWM_DIE2_EN           
 *                    PWM_DIE1_EN   
 *                    PWM_DIE0_EN  
 *  
 * @return      None
 *
 * @details     Write 1 into field PWMDIEx of PWMA->PIER. 
 *              Example of function call:  
 *              PWMA_DIE_ENABLE(PWM_DIE0_EN) ;
 */
static __INLINE void  PWMA_DIE_ENABLE(uint32_t DIE)
{
  (PWMA->PIER |= (DIE)) ;
}

/**
 * @brief       Disable PWMA DIE
 *
 * @param[in]   DIE   It must be the following constance or addition of some them.                
 *                    PWM_DIE3_EN              
 *                    PWM_DIE2_EN           
 *                    PWM_DIE1_EN   
 *                    PWM_DIE0_EN  
 *  
 * @return      None
 *
 * @details     Write 0 into field PWMDIEx of PWMA->PIER. 
 *              Example of function call:  
 *              PWMA_DIE_DISABLE(PWM_DIE0_EN) ;
 */
static __INLINE void PWMA_DIE_DISABLE(uint32_t DIE) 
{
  (PWMA->PIER &= ~(DIE)) ;
}

/**
 * @brief       Enable PWMA interrupt
 *
 * @param[in]   DIE    It must be the following constance or addition of some them.       
 *                    PWM_IE3_EN              
 *                    PWM_IE2_EN           
 *                    PWM_IE1_EN   
 *                    PWM_IE0_EN  
 *  
 * @return      None
 *
 * @details     Write 1 into field PWMIEx of PWMA->PIER. 
 *              Example of function call:  
 *              PWMA_INT_ENABLE(PWM_IE0_EN) ;
 */
static __INLINE void PWMA_INT_ENABLE(uint32_t IE)
{
  (PWMA->PIER |= (IE)) ;
}

/**
 * @brief       Disable PWMA interrupt
 *
 * @param[in]   DIE   It must be the following constance or addition of some them.                
 *                    PWM_IE3_EN              
 *                    PWM_IE2_EN           
 *                    PWM_IE1_EN   
 *                    PWM_IE0_EN  
 *  
 * @return      None
 *
 * @details     Write 0 into field PWMIEx of PWMA->PIER. 
 *              Example of function call:  
 *              PWMA_INT_DISABLE(PWM_IE0_EN) ;
 */
static __INLINE void PWMA_INT_DISABLE(uint32_t IE)
{
  (PWMA->PIER &= ~(IE)) ;
}
/**
 * @brief       Get PWMA interrupt flag
 *
 * @param[in]   DIE   It must be the following constance or addition of some them.                
 *                    PWM_DIF3             
 *                    PWM_DIF2           
 *                    PWM_DIF1  
 *                    PWM_DIF0 
 *                    PWM_IF3             
 *                    PWM_IF2           
 *                    PWM_IF1  
 *                    PWM_IF0 
 *  
 * @return      The value of IF which is selected. 
 *
 * @details    
 *              Example of function call:  
 *              PWMA_GET_IF( PWM_IF3 | PWM_IF2) ;
 */
static __INLINE uint32_t PWMA_GET_IF(uint32_t IF)
{
  return (PWMA->PIIR & (IF)) ;
}

/**
 * @brief       Clear PWMA interrupt flag
 *
 * @param[in]   DIE   It must be the following constance or addition of some them.                
 *                    PWM_DIF3             
 *                    PWM_DIF2           
 *                    PWM_DIF1  
 *                    PWM_DIF0 
 *                    PWM_IF3             
 *                    PWM_IF2           
 *                    PWM_IF1  
 *                    PWM_IF0 
 *  
 * @return      None. 
 *
 * @details     Clear interrupt flag.
 *              Example of function call:  
 *              PWMA_CLEAR_IF( PWM_IF3 | PWM_IF2) ;
 */
static __INLINE void PWMA_CLEAR_IF(uint32_t IF)
{
  (PWMA->PIIR |= (IF)) ;
}
/**
 * @brief       Enable PWMA output
 *
 * @param[in]   POE_    It must be the following constance or addition of some them.       
 *                    PWM_POE3             
 *                    PWM_POE2           
 *                    PWM_POE1   
 *                    PWM_POE0  
 *  
 * @return      None
 *
 * @details     Write 1 into field PWMPOEx of PWMA->POE. 
 *              Example of function call:  
 *              PWMA_POE_ENABLE(PWM_POE0 | PWM_POE0) ;
 */
static __INLINE void PWMA_POE_ENABLE(uint32_t POE_)
{
  (PWMA->POE |= (POE_)) ;
}

/**
 * @brief       Disable PWMA output
 *
 * @param[in]   POE_   It must be the following constance or addition of some them.                
 *                    PWM_POE3             
 *                    PWM_POE2           
 *                    PWM_POE1   
 *                    PWM_POE0  
 *  
 * @return      None
 *
 * @details     Write 0 into field PWMPOEx of PWMA->POE. 
 *              Example of function call:  
 *              PWMA_POE_DISABLE(PWM_POE0 | PWM_POE0) ;
 */
static __INLINE void PWMA_POE_DISABLE(uint32_t POE_)
{
  (PWMA->POE &= ~(POE_)) ;
}

/**
 * @brief       Enable PWM3 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 1 into field CAPCH3EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM3_CAPTURE_ENABLE() ;
 */
static __INLINE void PWM3_CAPTURE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM3_CAP_EN) ;
}

/**
 * @brief       Disable PWM3 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 0 into field CAPCH3EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM3_CAPTURE_DISABLE() ;
 */
static __INLINE void PWM3_CAPTURE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM3_CAP_EN) ;
}

/**
 * @brief       Enable PWM2 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 1 into field CAPCH3EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM2_CAPTURE_ENABLE() ;
 */
static __INLINE void PWM2_CAPTURE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM2_CAP_EN) ;
}

/**
 * @brief       Disable PWM2 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 0 into field CAPCH3EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM2_CAPTURE_DISABLE() ;
 */
static __INLINE void PWM2_CAPTURE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM2_CAP_EN) ;
}

/**
 * @brief       Enable PWM1 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 1 into field CAPCH1EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM1_CAPTURE_ENABLE() ;
 */
static __INLINE void PWM1_CAPTURE_ENABLE(void) 
{
  (PWMA->CCR0 |= PWM1_CAP_EN) ;
}

/**
 * @brief       Disable PWM1 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 0 into field CAPCH1EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM1_CAPTURE_DISABLE() ;
 */
static __INLINE void PWM1_CAPTURE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM1_CAP_EN) ;
}

/**
 * @brief       Enable PWM0 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 1 into field CAPCH0EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM0_CAPTURE_ENABLE() ;
 */
static __INLINE void PWM0_CAPTURE_ENABLE(void)
{
  (PWMA->CCR0 |= PWM0_CAP_EN) ;
}
/**
 * @brief       Disable PWM0 capture function
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details     Write 0 into field CAPCH0EN of PWMA->CCR2. 
 *              Example of function call:  
 *              PWM0_CAPTURE_DISABLE() ;
 */
static __INLINE void  PWM0_CAPTURE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM0_CAP_EN) ;
}
/**
 * @brief       Read CCR0 get whether PWM1 captured a fall edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM1_CAP_GET_FALL of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_GET_FALL() ;
 */
static __INLINE uint16_t PWM1_CAP_GET_FALL(void)
{
 return (PWMA->CCR0 & PWM1_CAP_FALL_FLAG) ;
}


/**
 * @brief       Read CCR0 get whether PWM1 captured a rise edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM1_CAP_GET_FALL of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_GET_RISE() ;
 */
static __INLINE uint32_t  PWM1_CAP_GET_RISE(void)
{
  return (PWMA->CCR0 & PWM1_CAP_RISE_FLAG) ;
}
/**
 * @brief       Read CCR0 get whether PWM0 captured a fall edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM0_CAP_GET_FALL of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_GET_FALL() ;
 */
static __INLINE uint32_t  PWM0_CAP_GET_FALL(void)
{
  return  (PWMA->CCR0 & PWM0_CAP_FALL_FLAG) ;
}

/**
 * @brief       Read CCR0 get whether PWM0 captured a rise edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM0_CAP_GET_FALL of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_GET_RISE() ;
 */
static __INLINE uint32_t  PWM0_CAP_GET_RISE(void)
{
 return  (PWMA->CCR0 & PWM0_CAP_RISE_FLAG) ;
}

/**
 * @brief       Read CCR2 get whether PWM3 captured a fall edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM3_CAP_GET_FALL of register CCR2
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_GET_FALL() ;
 */
static __INLINE uint32_t  PWM3_CAP_GET_FALL(void)
{
  return  (PWMA->CCR2 & PWM3_CAP_FALL_FLAG) ;
}
/**
 * @brief       Read CCR2 get whether PWM3 captured a rise edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM3_CAP_GET_FALL of register CCR2
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_GET_RISE() ;
 */
static __INLINE uint32_t  PWM3_CAP_GET_RISE(void)
{
  return (PWMA->CCR2 & PWM3_CAP_RISE_FLAG) ;
}

/**
 * @brief       Read CCR2 get whether PWM2 captured a fall edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM2_CAP_GET_FALL of register CCR2
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_GET_FALL() ;
 */
static __INLINE uint32_t  PWM2_CAP_GET_FALL(void)
{
 return   (PWMA->CCR2 & PWM2_CAP_FALL_FLAG) ;
}

/**
 * @brief       Read CCR2 get whether PWM2 captured a rise edge.
 *
 * @param[in]   None       
 *  
 * @return      PWM2_CAP_GET_FALL of register CCR2
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_GET_RISE() ;
 */
static __INLINE uint32_t  PWM2_CAP_GET_RISE(void)
{
  return (PWMA->CCR2 & PWM2_CAP_RISE_FLAG) ;
}

/**
 * @brief       Read CCR0 get whether PWM1 capture interrupt occured.
 *
 * @param[in]   None       
 *  
 * @return      PWM1_CAP_IF of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_GET_IF() ;
 */
static __INLINE uint32_t  PWM1_CAP_GET_IF(void)
{
  return (PWMA->CCR0 & PWM1_CAP_IF) ;
}

/**
 * @brief       Clear PWM1 capture interrupt flag.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_CLEAR_IF() ;
 */
static __INLINE void PWM1_CAP_CLEAR_IF(void)
{
  (PWMA->CCR0 |= PWM1_CAP_IF)  ;
}

/**
 * @brief       Read CCR0 get whether PWM0 capture interrupt occured.
 *
 * @param[in]   None       
 *  
 * @return      PWM0_CAP_IF of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_GET_IF() ;
 */
static __INLINE uint32_t  PWM0_CAP_GET_IF(void)
{
  return  (PWMA->CCR0 & PWM0_CAP_IF) ;
}

/**
 * @brief       Clear PWM0 capture interrupt flag.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_CLEAR_IF() ;
 */
static __INLINE void PWM0_CAP_CLEAR_IF(void)
{
  (PWMA->CCR0 |= PWM0_CAP_IF) ;
}

/**
 * @brief       Read CCR0 get whether PWM3 capture interrupt occured.
 *
 * @param[in]   None       
 *  
 * @return      PWM3_CAP_IF of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_GET_IF() ;
 */
static __INLINE uint32_t  PWM3_CAP_GET_IF(void)
{
  return  (PWMA->CCR2 & PWM3_CAP_IF) ;
}

/**
 * @brief       Clear PWM3 capture interrupt flag.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_CLEAR_IF() ;
 */
static __INLINE void PWM3_CAP_CLEAR_IF(void)
{
  (PWMA->CCR2 |= PWM3_CAP_IF) ;
}

/**
 * @brief       Read CCR0 get whether PWM2 capture interrupt occured.
 *
 * @param[in]   None       
 *  
 * @return      PWM2_CAP_IF of register CCR0
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_GET_IF() ;
 */
static __INLINE uint32_t  PWM2_CAP_GET_IF(void)
{
  return (PWMA->CCR2 & PWM2_CAP_IF) ;
}

/**
 * @brief        Clear PWM2 capture interrupt flag.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_CLEAR_IF() ;
 */
static __INLINE void PWM2_CAP_CLEAR_IF(void)
{
  (PWMA->CCR2 |= PWM2_CAP_IF) ;
}

/**
 * @brief       Enable PWM1 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_FALL_IE_ENABLE() ;
 */
static __INLINE void PWM1_CAP_FALL_IE_ENABLE(void)
{
  (PWMA->CCR0 |= PWM1_CAP_FALL_IE) ;
}

/**
 * @brief       Disable PWM1 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_FALL_IE_DISABLE() ;
 */
static __INLINE void PWM1_CAP_FALL_IE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM1_CAP_FALL_IE) ;
}

/**
 * @brief       Enable PWM0 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_FALL_IE_ENABLE() ;
 */
static __INLINE void PWM0_CAP_FALL_IE_ENABLE(void)
{
  (PWMA->CCR0 |= PWM0_CAP_FALL_IE) ;
}

/**
 * @brief       Disable PWM0 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_FALL_IE_DISABLE() ;
 */
static __INLINE void PWM0_CAP_FALL_IE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM0_CAP_FALL_IE) ;
}

/**
 * @brief       Enable PWM3 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_FALL_IE_ENABLE() ;
 */
static __INLINE void PWM3_CAP_FALL_IE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM3_CAP_FALL_IE) ;
}

/**
 * @brief       Disable PWM3 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_FALL_IE_DISABLE() ;
 */
static __INLINE void  PWM3_CAP_FALL_IE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM3_CAP_FALL_IE) ;
}

/**
 * @brief       Enable PWM2 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_FALL_IE_ENABLE() ;
 */
static __INLINE void PWM2_CAP_FALL_IE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM2_CAP_FALL_IE) ;
}

/**
 * @brief       Disable PWM2 capture fall interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_FALL_IE_DISABLE() ;
 */
static __INLINE void PWM2_CAP_FALL_IE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM2_CAP_FALL_IE) ;
}

/**
 * @brief       Enable PWM1 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_RISE_IE_ENABLE() ;
 */
static __INLINE void PWM1_CAP_RISE_IE_ENABLE(void)
{
  (PWMA->CCR0 |= PWM1_CAP_RISE_IE) ;
}

/**
 * @brief       Disable PWM1 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_RISE_IE_DISABLE() ;
 */
static __INLINE void PWM1_CAP_RISE_IE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM1_CAP_RISE_IE) ;
}

/**
 * @brief       Enable PWM0 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_RISE_IE_ENABLE() ;
 */
static __INLINE void PWM0_CAP_RISE_IE_ENABLE(void)
{
  (PWMA->CCR0 |= PWM0_CAP_RISE_IE) ;
}

/**
 * @brief      Disable PWM0 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_RISE_IE_DISABLE() ;
 */
static __INLINE void PWM0_CAP_RISE_IE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM0_CAP_RISE_IE) ;
}
/**
 * @brief       Enable PWM3 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_RISE_IE_ENABLE() ;
 */
static __INLINE void PWM3_CAP_RISE_IE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM3_CAP_RISE_IE) ;
}

/**
 * @brief       Disable PWM3 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_RISE_IE_DISABLE() ;
 */
static __INLINE void PWM3_CAP_RISE_IE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM3_CAP_RISE_IE) ;
}

/**
 * @brief       Enable PWM2 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_RISE_IE_ENABLE() ;
 */
static __INLINE void PWM2_CAP_RISE_IE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM2_CAP_RISE_IE) ;
}

/**
 * @brief       Disable PWM2 capture rise interrupt.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_RISE_IE_DISABLE() ;
 */
static __INLINE void PWM2_CAP_RISE_IE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM2_CAP_RISE_IE) ;
}

/**
 * @brief       Enable PWM1-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_INPUT_INVERSE_ENABLE() ;
 */
static __INLINE void PWM1_CAP_INPUT_INVERSE_ENABLE(void)
{
  (PWMA->CCR0 |= PWM1_CAP_IN_INV) ;
}

/**
 * @brief       Disable PWM1-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1_CAP_INPUT_INVERSE_DISABLE() ;
 */
static __INLINE void PWM1_CAP_INPUT_INVERSE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM1_CAP_IN_INV ) ;
}

/**
 * @brief       Enable PWM0-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_INPUT_INVERSE_ENABLE() ;
 */
static __INLINE void PWM0_CAP_INPUT_INVERSE_ENABLE(void)
{
  (PWMA->CCR0 |= PWM0_CAP_IN_INV) ;
}

/**
 * @brief       Disable PWM0-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0_CAP_INPUT_INVERSE_DISABLE() ;
 */
static __INLINE void PWM0_CAP_INPUT_INVERSE_DISABLE(void)
{
  (PWMA->CCR0 &= ~PWM0_CAP_IN_INV ) ;
}

/**
 * @brief       Enable PWM3-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_INPUT_INVERSE_ENABLE() ;
 */
static __INLINE void PWM3_CAP_INPUT_INVERSE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM3_CAP_IN_INV) ;
}

/**
 * @brief       Disable PWM3-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3_CAP_INPUT_INVERSE_DISABLE() ;
 */
static __INLINE void PWM3_CAP_INPUT_INVERSE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM3_CAP_IN_INV ) ;
}
/**
 * @brief       Enable PWM2-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_INPUT_INVERSE_ENABLE() ;
 */
static __INLINE void PWM2_CAP_INPUT_INVERSE_ENABLE(void)
{
  (PWMA->CCR2 |= PWM2_CAP_IN_INV) ;
}
 
/**
 * @brief       Disable PWM2-capture input inverse.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2_CAP_INPUT_INVERSE_DISABLE() ;
 */
static __INLINE void PWM2_CAP_INPUT_INVERSE_DISABLE(void)
{
  (PWMA->CCR2 &= ~PWM2_CAP_IN_INV ) ;
}

/**
 * @brief       Get PWM channel 0 capture rise time.
 *
 * @param[in]   None       
 *  
 * @return      CRLR0
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP0_RISE_TIME() ;
 */
static __INLINE uint16_t PWM_CAP0_RISE_TIME(void)
{
  return PWMA->CRLR0 ;
}

/**
 * @brief       Get PWM channel 0 capture fall time.
 *
 * @param[in]   None       
 *  
 * @return      CFLR0
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP0_FALL_TIME() ;
 */
static __INLINE uint16_t PWM_CAP0_FALL_TIME(void)
{
  return PWMA->CFLR0 ;
}

/**
 * @brief       Get PWM channel 1 capture rise time.
 *
 * @param[in]   None       
 *  
 * @return      CRLR1
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP1_RISE_TIME() ;
 */
static __INLINE uint16_t PWM_CAP1_RISE_TIME(void)
{
  return PWMA->CRLR1 ;
}

/**
 * @brief       Get PWM channel 1 capture fall time.
 *
 * @param[in]   None       
 *  
 * @return      CFLR1
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP1_FALL_TIME() ;
 */
static __INLINE uint16_t PWM_CAP1_FALL_TIME(void)
{
  return PWMA->CFLR1 ;
}

/**
 * @brief       Get PWM channel 2 capture rise time.
 *
 * @param[in]   None       
 *  
 * @return      CRLR2
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP2_RISE_TIME() ;
 */
static __INLINE uint16_t PWM_CAP2_RISE_TIME(void)
{
  return PWMA->CRLR2 ;
}

/**
 * @brief       Get PWM channel 2 capture fall time.
 *
 * @param[in]   None       
 *  
 * @return      CFLR2
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP0_FALL_TIME() ;
 */
static __INLINE uint16_t PWM_CAP2_FALL_TIME(void)
{
  return PWMA->CFLR2  ;
}

/**
 * @brief       Get PWM channel 3 capture rise time.
 *
 * @param[in]   None       
 *  
 * @return      CRLR3
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP3_RISE_TIME() ;
 */
static __INLINE uint16_t PWM_CAP3_RISE_TIME(void)
{
  return PWMA->CRLR3 ;
}

/**
 * @brief       Get PWM channel 3 capture fall time.
 *
 * @param[in]   None       
 *  
 * @return      CFLR3
 *
 * @details      
 *              Example of function call:  
 *              PWM_CAP3_FALL_TIME() ;
 */
static __INLINE uint16_t  PWM_CAP3_FALL_TIME(void)
{
 return PWMA->CFLR3 ;
}

/**
 * @brief       Enable PWM channel 0 capture input : PA12.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP0_PA12_ENABLE() ;
 */
static __INLINE void PWMA_CAP0_PA12_ENABLE(void)
{
  (PWMA->CAPENR |= PWMA_CAP0_PA12_EN) ;
}

/**
 * @brief       Disable PWM channel 0 capture input : PA12.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP0_PA12_DISABLE() ;
 */
static __INLINE void PWMA_CAP0_PA12_DISABLE(void)
{
  (PWMA->CAPENR &= ~PWMA_CAP0_PA12_EN) ;
}

/**
 * @brief       Enable PWM channel 1 capture input : PA13.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP1_PA13_ENABLE() ;
 */
static __INLINE void PWMA_CAP1_PA13_ENABLE(void)
{
  (PWMA->CAPENR |= PWMA_CAP1_PA13_EN) ;
}

/**
 * @brief       Disable PWM channel 1 capture input : PA13.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP1_PA13_DISABLE() ;
 */
static __INLINE void PWMA_CAP1_PA13_DISABLE(void)
{
  (PWMA->CAPENR &= ~PWMA_CAP1_PA13_EN) ;
}

/**
 * @brief       Enable PWM channel 2 capture input : PA14.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP2_PA14_ENABLE() ;
 */
static __INLINE void PWMA_CAP2_PA14_ENABLE(void)
{
  (PWMA->CAPENR |= PWMA_CAP2_PA14_EN) ;
}

/**
 * @brief       Disable PWM channel 2 capture input : PA14.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP2_PA14_DISABLE() ;
 */
static __INLINE void PWMA_CAP2_PA14_DISABLE(void)
{
  (PWMA->CAPENR &= ~PWMA_CAP2_PA14_EN) ;
}

/**
 * @brief       Enable PWM channel 3 capture input : PA15.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP3_PA15_ENABLE() ;
 */
static __INLINE void PWMA_CAP3_PA15_ENABLE(void)
{
  (PWMA->CAPENR |= PWMA_CAP3_PA15_EN) ;
}

/**
 * @brief       Disable PWM channel 3 capture input : PA15.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWMA_CAP3_PA15_DISABLE() ;
 */
static __INLINE void PWMA_CAP3_PA15_DISABLE(void)
{
  (PWMA->CAPENR &= ~PWMA_CAP3_PA15_EN) ;
}

/**
 * @brief       Data of fall egde that PWM3 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3CAP_PDMA_FALL_FIRST() ;
 */
static __INLINE void PWM3_CAP_PDMA_FALL_FIRST(void)
{
  (PWMA->CAPPDMACTL &= ~PWM3CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of rise egde that PWM3 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3CAP_PDMA_RISE_FIRST() ;
 */
static __INLINE void PWM3_CAP_PDMA_RISE_FIRST(void)
{
  (PWMA->CAPPDMACTL |= PWM3CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of fall egde that PWM2 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2CAP_PDMA_FALL_FIRST() ;
 */
static __INLINE void PWM2_CAP_PDMA_FALL_FIRST(void)
{
  (PWMA->CAPPDMACTL &= ~PWM2CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of rise egde that PWM2 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2CAP_PDMA_RISE_FIRST() ;
 */
static __INLINE void PWM2_CAP_PDMA_RISE_FIRST(void)
{
  (PWMA->CAPPDMACTL |= PWM2CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of fall egde that PWM1 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1CAP_PDMA_FALL_FIRST() ;
 */
static __INLINE void PWM1_CAP_PDMA_FALL_FIRST(void)
{
  (PWMA->CAPPDMACTL &= ~PWM1CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of rise egde that PWM1 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1CAP_PDMA_RISE_FIRST() ;
 */
static __INLINE void PWM1_CAP_PDMA_RISE_FIRST(void)
{
  (PWMA->CAPPDMACTL |= PWM1CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of fall egde that PWM0 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0CAP_PDMA_FALL_FIRST() ;
 */
static __INLINE void PWM0_CAP_PDMA_FALL_FIRST(void)
{
  (PWMA->CAPPDMACTL &= ~PWM0CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of rise egde that PWM0 captured transfer into memory at first.
 *
 * @param[in]   None       
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0CAP_PDMA_RISE_FIRST() ;
 */
static __INLINE void PWM0CAP_PDMA_RISE_FIRST(void)
{
  (PWMA->CAPPDMACTL |= PWM0CAP_DMA_RISE_FIRST) ;
}

/**
 * @brief       Data of rise egde that PWM3 captured transfer into memory at first.
 *
 * @param[in]   x   Must be the following
 *                   PWM3CAP_DMA_RISE
 *                   PWM3CAP_DMA_FALL 
 *                   PWM3CAP_DMA_RISE_FALL     
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM3CAP_PDMA_DATA(ONLY_RISE) ;
 */
static __INLINE void PWM3_CAP_PDMA_DATA(uint16_t x)
{
  (PWMA->CAPPDMACTL = (PWMA->CAPPDMACTL & (~PWM_CAPPDMACTL_CAP3PDMAMOD_Msk))|(x)) ;
}

/**
 * @brief       Data of rise egde that PWM2 captured transfer into memory at first.
 *
 * @param[in]   x   Must be the following
 *                   PWM2CAP_DMA_RISE
 *                   PWM2CAP_DMA_FALL 
 *                   PWM2CAP_DMA_RISE_FALL     
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM2CAP_PDMA_DATA(ONLY_RISE) ;
 */
static __INLINE void PWM2_CAP_PDMA_DATA(uint32_t x)
{
  (PWMA->CAPPDMACTL = (PWMA->CAPPDMACTL & (~PWM_CAPPDMACTL_CAP2PDMAMOD_Msk))|(x)) ;
}

/**
 * @brief       Data of rise egde that PWM1 captured transfer into memory at first.
 *
 * @param[in]   x   Must be the following
 *                   PWM1CAP_DMA_RISE
 *                   PWM1CAP_DMA_FALL 
 *                   PWM1CAP_DMA_RISE_FALL     
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM1CAP_PDMA_DATA(ONLY_RISE) ;
 */
static __INLINE void PWM1_CAP_PDMA_DATA(uint16_t x)
{
  (PWMA->CAPPDMACTL = (PWMA->CAPPDMACTL & (~PWM_CAPPDMACTL_CAP1PDMAMOD_Msk))|(x)) ;
}

/**
 * @brief       Data of rise egde that PWM0 captured transfer into memory at first.
 *
 * @param[in]   x   Must be the following
 *                   PWM0CAP_DMA_RISE
 *                   PWM0CAP_DMA_FALL 
 *                   PWM0CAP_DMA_RISE_FALL     
 *  
 * @return      None
 *
 * @details      
 *              Example of function call:  
 *              PWM0CAP_PDMA_DATA(ONLY_RISE) ;
 */
static __INLINE void PWM0_CAP_PDMA_DATA(uint16_t x)
{
  (PWMA->CAPPDMACTL = (PWMA->CAPPDMACTL & (~PWM_CAPPDMACTL_CAP0PDMAMOD_Msk))|(x)) ;
}

/**
 * @brief       Enable PWM3 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM3CAP_PDMA_ENABLE() ;
 */
static __INLINE void PWM3_CAP_PDMA_ENABLE(void)
{
  (PWMA->CAPPDMACTL |= PWM3CAP_DMA_EN) ;
}

/**
 * @brief       Disable PWM3 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM3CAP_PDMA_DISABLE() ;
 */
static __INLINE void PWM3_CAP_PDMA_DISABLE(void)
{
  (PWMA->CAPPDMACTL &= ~PWM3CAP_DMA_EN) ;
}

/**
 * @brief       Enable PWM1 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM2CAP_PDMA_ENABLE() ;
 */
static __INLINE void PWM2_CAP_PDMA_ENABLE(void)
{
  (PWMA->CAPPDMACTL |= PWM2CAP_DMA_EN) ;
}

/**
 * @brief       Disable PWM2 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM2CAP_PDMA_DISABLE() ;
 */
static __INLINE void PWM2_CAP_PDMA_DISABLE(void)
{
  (PWMA->CAPPDMACTL &= ~PWM2CAP_DMA_EN) ;
}

/**
 * @brief       Enable PWM1 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM1CAP_PDMA_ENABLE() ;
 */
static __INLINE void PWM1_CAP_PDMA_ENABLE(void)
{
  (PWMA->CAPPDMACTL |= PWM1CAP_DMA_EN) ;
}

/**
 * @brief       Disable PWM1 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM1CAP_PDMA_DISABLE() ;
 */
static __INLINE void PWM1_CAP_PDMA_DISABLE(void)
{
  (PWMA->CAPPDMACTL &= ~PWM1CAP_DMA_EN) ;
}

/**
 * @brief       Enable PWM3 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM3CAP_PDMA_ENABLE() ;
 */
static __INLINE void PWM0_CAP_PDMA_ENABLE(void)
{
  (PWMA->CAPPDMACTL |= PWM3CAP_DMA_EN) ;
}

/**
 * @brief       Disable PWM0 PDMA
 *
 * @param[in]   None           
 *  
 * @return      None
 *
 * @details    
 *              Example of function call:  
 *              PWM0CAP_PDMA_DISABLE() ;
 */
static __INLINE void PWM0_CAP_PDMA_DISABLE(void)
{
  (PWMA->CAPPDMACTL &= ~PWM0CAP_DMA_EN) ;
}

/*@}*/ /* end of group PWM_MACRO_FUNC */
/*@}*/ /* end of group PWM_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

/*---------------------------------------------------------------------------------------------------------*/
/*  Function declaration                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/

void DrvPWM_EnableInt(uint8_t u8Ch) ;
void DrvPWM_DisableInt(uint8_t u8Ch)  ;
void DrvPWM_EnableCaptureInt(uint8_t u8Ch, uint32_t u32Int)  ;
void DrvPWM_DisableCaptureInt(uint8_t u8Ch, uint32_t u32Int) ;
void DrvPWM_Init(uint8_t u8Ch) ;
void DrvPWM_DeInit(uint8_t u8Ch) ;
void DrvPWM_EnableDeadZone(uint8_t u8Ch, uint8_t u8Length) ;
void DrvPWM_DisableDeadZone(uint8_t u8Ch) ;
void DrvPWM_CaptureEnable(uint8_t u8Ch) ;
void DrvPWM_CaptureDisable(uint8_t u8Ch) ;
void DrvPWM_SetClk(uint8_t u8Ch, S_DRVPWM_TIME_DATA_T *cfg) ;
void DrvPWM_ConfigCaptureIntput(uint8_t u8Ch, uint32_t u32Enable) ;
void DrvPWM_EnablePdma(uint8_t u8Ch)  ;
void DrvPWM_DisablePdma(uint8_t u8Ch)  ;

#endif     //  __PWM_H
