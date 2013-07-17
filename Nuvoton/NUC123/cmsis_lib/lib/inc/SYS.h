/**************************************************************************//**
 * @file     SYS.h
 * @version  V1.0
 * $Revision  1 $
 * $Date:    12/08/20 1:45p $
 * @brief    IP SYS Header File for Nuc123 Series
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef  __SYS_H
#define  __SYS_H

#include  "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup SYS_MACRO System Macro
  * @{
  */
/** @addtogroup SYS_MACRO_CONTANT System Macro Contant
  * @{
  */

////SYS->RSTSRC /////////////////////////////////////////////////////////////////////////
#define  SYS_RST_SRC_CPU           (1<<SYS_RSTSRC_RSTS_CPU_Pos)      //writing bit SYS_CPU_RST in IPRSTC1 cause reset.
#define  SYS_RST_SRC_SYSTEM        (1<<SYS_RSTSRC_RSTS_SYS_Pos)      //Writing bit SYSRESETREQ in AIRCR cause reset. 
#define  SYS_RST_SRC_BOD           (1<<SYS_RSTSRC_RSTS_BOD_Pos)      //It cause reset that VCC is lower than BOD voltage.
#define  SYS_RST_SRC_LVR           (1<<SYS_RSTSRC_RSTS_LVR_Pos)      //It cause reset that VCC is lower than LVRvoltage. 
#define  SYS_RST_SRC_WDT           (1<<SYS_RSTSRC_RSTS_WDT_Pos)      //WDT cuase reset.
#define  SYS_RST_SRC_RST           (1<<SYS_RSTSRC_RSTS_RESET_Pos)    //Pulling down #Rst pin cause reset.
#define  SYS_RST_SRC_POR           (1<<SYS_RSTSRC_RSTS_POR_Pos)      //Power on cause reset.

////SYS->IPRSTC1 ////////////////////////////////////////////////////////////////////////
#define  SYS_RST_PDMA              (1<<SYS_IPRSTC1_PDMA_RST_Pos)     //Reset PDMA.
#define  SYS_RST_CPU               (1<<SYS_IPRSTC1_CPU_RST_Pos)      //Reset CPU excluding IP.
#define  SYS_RST_CHIP              (1<<SYS_IPRSTC1_CHIP_RST_Pos)     //Reset chip like pulling down #Rst pin.

////SYS->IPRSTC2 ////////////////////////////////////////////////////////////////////////
#define  SYS_RST_I2S               (1<<SYS_IPRSTC2_I2S_RST_Pos)      //Reset I2S.
#define  SYS_RST_ADC               (1<<SYS_IPRSTC2_ADC_RST_Pos)      //Reset ADC.
#define  SYS_RST_USBD              (1<<SYS_IPRSTC2_USBD_RST_Pos)     //Reset USBD.
#define  SYS_RST_PS2               (1<<SYS_IPRSTC2_PS2_RST_Pos)      //Reset PS2.
#define  SYS_RST_PWM0123           (1<<SYS_IPRSTC2_PWM03_RST_Pos)    //Reset PWM0123.
#define  SYS_RST_UART1             (1<<SYS_IPRSTC2_UART1_RST_Pos)    //Reset UART1.
#define  SYS_RST_UART0             (1<<SYS_IPRSTC2_UART0_RST_Pos)    //Reset UART0.
#define  SYS_RST_SPI2              (1<<SYS_IPRSTC2_SPI2_RST_Pos)     //Reset SPI2.
#define  SYS_RST_SPI1              (1<<SYS_IPRSTC2_SPI1_RST_Pos)     //Reset SPI1.
#define  SYS_RST_SPI0              (1<<SYS_IPRSTC2_SPI0_RST_Pos)     //Reset SPI0.
#define  SYS_RST_I2C1              (1<<SYS_IPRSTC2_I2C1_RST_Pos)     //Reset I2C1.
#define  SYS_RST_I2C0              (1<<SYS_IPRSTC2_I2C0_RST_Pos)     //Reset I2C0.
#define  SYS_RST_TMR3              (1<<SYS_IPRSTC2_TMR3_RST_Pos)     //Reset Timer3.
#define  SYS_RST_TMR2              (1<<SYS_IPRSTC2_TMR2_RST_Pos)     //Reset Timer2.
#define  SYS_RST_TMR1              (1<<SYS_IPRSTC2_TMR1_RST_Pos)     //Reset Timer1.
#define  SYS_RST_TMR0              (1<<SYS_IPRSTC2_TMR0_RST_Pos)     //Reset Timer0.
#define  SYS_RST_GPIO              (1<<SYS_IPRSTC2_GPIO_RST_Pos)     //Reset GPIO.

////SYS->BODCR //////////////////////////////////////////////////////////////////////////
#define  SYS_LVR_EN                (1<<SYS_BODCR_LVR_EN_Pos)         //Enable LVR function.
#define  SYS_BOD_OUT               (1<<SYS_BODCR_BOD_OUT_Pos)        //Output of BOD IP.
#define  SYS_BOD_LOW_POWER_MODE    (1<<SYS_BODCR_BOD_LPM_Pos)        //BOD work in low power mode.
#define  SYS_BOD_INT_FLAG          (1<<SYS_BODCR_BOD_INTF_Pos)       //BOD cuased a interrupt.
#define  SYS_BOD_RST_ENABLE        (1<<SYS_BODCR_BOD_RSTEN_Pos)      //Enable reset function of BOD.
#define  SYS_BOD_22V               (0<<SYS_BODCR_BOD_OUT_Pos)        //Threshlod voltage of BOD is selected 2.2V
#define  SYS_BOD_27V               (1<<SYS_BODCR_BOD_OUT_Pos)        //Threshlod voltage of BOD is selected 2.7V
#define  SYS_BOD_38V               (2<<SYS_BODCR_BOD_OUT_Pos)        //Threshlod voltage of BOD is selected 3.82V
#define  SYS_BOD_45V               (3<<SYS_BODCR_BOD_OUT_Pos)        //Threshlod voltage of BOD is selected 4.5V
#define  SYS_BOD_ENABLE            (1<<SYS_BODCR_BOD_EN_Pos)         //Enable BOD IP

////SYS->GPA_MFP ///////////////////////////////////////////////////////////////////
#define  SYS_MFPA15_GPIO_CLKO      0
#define  SYS_MFPA15_PWM3_I2SMCLK   0x8000ul

#define  SYS_MFPA14_GPIO           0
#define  SYS_MFPA14_PWM2           0x4000ul

#define  SYS_MFPA13_GPIO           0
#define  SYS_MFPA13_PWM1           0x2000ul

#define  SYS_MFPA12_GPIO           0
#define  SYS_MFPA12_PWM0           0x1000ul

#define  SYS_MFPA11_GPIO_SPICLK1   0
#define  SYS_MFPA11_I2C1CLK_MOSI20 0x0800ul

#define  SYS_MFPA10_GPIO_MISO10    0
#define  SYS_MFPA10_I2C1SDA_MISO20 0x0400ul

////SYS->GPB_MFP ///////////////////////////////////////////////////////////////////
#define  SYS_MFPB15_GPIO           0
#define  SYS_MFPB15_INT1_T0EX      0x8000ul

#define  SYS_MFPB14_GPIO           0
#define  SYS_MFPB14_INT0           0x4000ul

#define  SYS_MFPB13_GPIO           0

#define  SYS_MFPB12_GPIO           0
#define  SYS_MFPB12_SPISS10_CLKO   0x1000ul

#define  SYS_MFPB10_GPIO           0
#define  SYS_MFPB10_TM2_SPISS01    0x0400ul

#define  SYS_MFPB9_GPIO            0
#define  SYS_MFPB9_TM1_SPISS11     0x0200ul

#define  SYS_MFPB8_GPIO            0
#define  SYS_MFPB8_TM0             0x0100ul

#define  SYS_MFPB7_GPIO            0
#define  SYS_MFPB7_CTS1_MISO20     0x0080ul

#define  SYS_MFPB6_GPIO            0
#define  SYS_MFPB6_RTS1_MOSI20     0x0040ul

#define  SYS_MFPB5_GPIO            0
#define  SYS_MFPB5_TX1_SPICLK2     0x0020ul

#define  SYS_MFPB4_GPIO_SPISS20    0
#define  SYS_MFPB4_RX1_SPISS11     0x0010ul

#define  SYS_MFPB3_GPIO            0
#define  SYS_MFPB3_CTS0_T3EX       0x0008ul

#define  SYS_MFPB2_GPIO            0
#define  SYS_MFPB2_RTS0_T2EX       0x0004ul

#define  SYS_MFPB1_GPIO            0
#define  SYS_MFPB1_TX0             0x0002ul

#define  SYS_MFPB0_GPIO            0
#define  SYS_MFPB0_RX0             0x0001ul

////SYS->GPC_MFP ///////////////////////////////////////////////////////////////////
#define  SYS_MFPC13_GPIO_CLKO      0
#define  SYS_MFPC13_MOSI11_PWM3    0x2000ul

#define  SYS_MFPC12_GPIO_I2SMCLK   0
#define  SYS_MFPC12_MISO11_PWM2    0x1000ul

#define  SYS_MFPC11_GPIO           0
#define  SYS_MFPC11_MOSI10         0x0800ul

#define  SYS_MFPC10_GPIO           0
#define  SYS_MFPC10_MISO10         0x0400ul

#define  SYS_MFPC9_GPIO            0
#define  SYS_MFPC9_SPICLK1         0x0200ul

#define  SYS_MFPC8_GPIO            0
#define  SYS_MFPC8_SPISS10         0x0100ul

#define  SYS_MFPC5_GPIO            0
#define  SYS_MFPC5_MOSI01_TX0      0x0020ul

#define  SYS_MFPC4_GPIO            0
#define  SYS_MFPC4_MISO01_RX0      0x0010ul

#define  SYS_MFPC3_GPIO            0
#define  SYS_MFPC3_MOSI00_I2SDO    0x0008ul

#define  SYS_MFPC2_GPIO            0
#define  SYS_MFPC2_MISO00_I2SDI    0x0004ul

#define  SYS_MFPC1_GPIO            0
#define  SYS_MFPC1_SPICLK0_I2SBCLK 0x0002ul

#define  SYS_MFPC0_GPIO              0
#define  SYS_MFPC0_SPISS00_I2SLRCLK  0x0001ul

////SYS->GPD_MFP ///////////////////////////////////////////////////////////////////
#define  SYS_MFPD11_GPIO           0
#define  SYS_MFPD11_INT1           0x0800ul

#define  SYS_MFPD10_GPIO           0
#define  SYS_MFPD10_CLKO           0x0400ul

#define  SYS_MFPD9_GPIO            0

#define  SYS_MFPD8_GPIO            0
#define  SYS_MFPD8_MOSI10          0x0100ul

#define  SYS_MFPD5_GPIO_MOSI21     0
#define  SYS_MFPD5_ADC5            0x0020ul

#define  SYS_MFPD4_GPIO_MISO21     0
#define  SYS_MFPD4_ADC4            0x0010ul

#define  SYS_MFPD3_GPIO_MOSI20     0
#define  SYS_MFPD3_MISO01_ADC3     0x0008ul

#define  SYS_MFPD2_GPIO_MISO20     0
#define  SYS_MFPD2_MISO01_ADC2     0x0004ul

#define  SYS_MFPD1_GPIO_SPICLK2    0
#define  SYS_MFPD1_SPISS01_ADC1    0x0002ul

#define  SYS_MFPD0_GPIO_SPISS20    0
#define  SYS_MFPD0_ADC0            0x0001ul

////SYS->GPF_MFP ///////////////////////////////////////////////////////////////////
#define  SYS_MFPF3_GPIO                 0
#define  SYS_MFPF3_PS2CLK_I2C0CLK_ADC7  0x0008ul

#define  SYS_MFPF2_GPIO                 0
#define  SYS_MFPF2_PS2SDA_I2C0SDA_ADC6  0x0004ul

#define  SYS_MFPF1_GPIO            0
#define  SYS_MFPF1_XI              0x0002ul

#define  SYS_MFPF0_GPIO            0
#define  SYS_MFPF0_XO              0x0001ul

////SYS->ALT_MFP ///////////////////////////////////////////////////////////////////
#define  SYS_ALT_PC5_GPIO_MOSI01   (0   << SYS_ALT_MFP_PC5_MFP1_Pos)
#define  SYS_ALT_PC5_TX0           (1ul << SYS_ALT_MFP_PC5_MFP1_Pos)

#define  SYS_ALT_PC4_GPIO_MISO01   (0ul << SYS_ALT_MFP_PC4_MFP1_Pos)
#define  SYS_ALT_PC4_RX0           (1ul << SYS_ALT_MFP_PC4_MFP1_Pos)

#define  SYS_ALT_PB3_GPIO_CTS0     (0ul << SYS_ALT_MFP_PB3_MFP1_Pos) 
#define  SYS_ALT_PB3_T3EX          (1ul << SYS_ALT_MFP_PB3_MFP1_Pos) 

#define  SYS_ALT_PB2_GPIO_RTS0     (0ul << SYS_ALT_MFP_PB2_MFP1_Pos)
#define  SYS_ALT_PB2_T2EX          (1ul << SYS_ALT_MFP_PB2_MFP1_Pos)

#define  SYS_ALT_PB15_GPIO_INT1    (0ul << SYS_ALT_MFP_PB15_MFP1_Pos)  
#define  SYS_ALT_PB15_T0EX         (1ul << SYS_ALT_MFP_PB15_MFP1_Pos)  

#define  SYS_ALT_PC13_GPIO_MOSI11  (0ul << SYS_ALT_MFP_PC13_MFP1_Pos)
#define  SYS_ALT_PC13_CLKO_PWM3    (1ul << SYS_ALT_MFP_PC13_MFP1_Pos)

#define  SYS_ALT_PC12_GPIO_MISO11  (0ul << SYS_ALT_MFP_PC12_MFP1_Pos)  
#define  SYS_ALT_PC12_I2SMCLK_PWM2 (1ul << SYS_ALT_MFP_PC12_MFP1_Pos)  

#define  SYS_ALT_PB5_GPIO_TX1      (0ul << SYS_ALT_MFP_PB5_MFP1_Pos)   
#define  SYS_ALT_PB5_SPICLK2       (1ul << SYS_ALT_MFP_PB5_MFP1_Pos)   

#define  SYS_ALT_PB6_GPIO_RTS1     (0ul << SYS_ALT_MFP_PB6_MFP1_Pos)   
#define  SYS_ALT_PB6_MOSI20        (1ul << SYS_ALT_MFP_PB6_MFP1_Pos)   

#define  SYS_ALT_PB7_GPIO_CTS1     (0ul << SYS_ALT_MFP_PB7_MFP1_Pos)   
#define  SYS_ALT_PB7_MISO20        (1ul << SYS_ALT_MFP_PB7_MFP1_Pos)   

#define  SYS_ALT_PB4_GPIO_RX1      (0ul << SYS_ALT_MFP_PB4_MFP1_Pos)   
#define  SYS_ALT_PB4_SPISS20_11    (1ul << SYS_ALT_MFP_PB4_MFP1_Pos)   

#define  SYS_ALT_PA10_GPIO_I2C1SDA (0ul << SYS_ALT_MFP_PA10_MFP1_Pos) 
#define  SYS_ALT_PA10_MISO10_20    (0ul << SYS_ALT_MFP_PA10_MFP1_Pos) 

#define  SYS_ALT_PA11_GPIO_I2C1SCL (0ul << SYS_ALT_MFP_PA11_MFP1_Pos) 
#define  SYS_ALT_PA11_SPICLK1_MOSI20 (1ul << SYS_ALT_MFP_PA11_MFP1_Pos) 

#define  SYS_ALT_PB12_GPIO_SPISS10 (0ul << SYS_ALT_MFP_PB12_MFP1_Pos)  
#define  SYS_ALT_PB12_CLKO         (1ul << SYS_ALT_MFP_PB12_MFP1_Pos)  

#define  SYS_ALT_PA15_GPIO_PWM3    (0ul << SYS_ALT_MFP_PA15_MFP1_Pos)     
#define  SYS_ALT_PA15_CLKO_I2SMCLK (1ul << SYS_ALT_MFP_PA15_MFP1_Pos)     

#define  SYS_ALT_PC3_GPIO_MOSI00   (0ul << SYS_ALT_MFP_PC3_MFP1_Pos)   
#define  SYS_ALT_PC3_I2SDO         (1ul << SYS_ALT_MFP_PC3_MFP1_Pos)   

#define  SYS_ALT_PC2_GPIO_MISO00   (0ul << SYS_ALT_MFP_PC2_MFP1_Pos)   
#define  SYS_ALT_PC2_I2SDI         (1ul << SYS_ALT_MFP_PC2_MFP1_Pos)   

#define  SYS_ALT_PC1_GPIO_SPICLK0  (0ul << SYS_ALT_MFP_PC1_MFP1_Pos)   
#define  SYS_ALT_PC1_I2SBCLK       (1ul << SYS_ALT_MFP_PC1_MFP1_Pos)   

#define  SYS_ALT_PC0_GPIO_SPISS0   (0ul << SYS_ALT_MFP_PC0_MFP1_Pos)   
#define  SYS_ALT_PC0_I2SLRCLK      (1ul << SYS_ALT_MFP_PC0_MFP1_Pos)   

#define  SYS_ALT_PB9_GPIO_TM1      (0ul << SYS_ALT_MFP_PB9_MFP1_Pos)       
#define  SYS_ALT_PB9_SPISS11       (1ul << SYS_ALT_MFP_PB9_MFP1_Pos)       

#define  SYS_ALT_PB10_GPIO_TM2     (0ul << SYS_ALT_MFP_PB10_MFP1_Pos) 
#define  SYS_ALT_PB10_SPISS01      (1ul << SYS_ALT_MFP_PB10_MFP1_Pos) 

////SYS->ALT_MFP1 ///////////////////////////////////////////////////////////////////
#define  SYS_ALT1_PF3_GPIO_PS2CLK  (0ul << SYS_ALT_MFP1_PF3_MFP1_Pos) 
#define  SYS_ALT1_PF3_I2C0SCL      (2ul << SYS_ALT_MFP1_PF3_MFP1_Pos) 
#define  SYS_ALT1_PF3_ADC7         (3ul << SYS_ALT_MFP1_PF3_MFP1_Pos) 

#define  SYS_ALT1_PF2_GPIO_PS2DA   (0ul << SYS_ALT_MFP1_PF2_MFP1_Pos)  
#define  SYS_ALT1_PF2_I2C0SDA      (2ul << SYS_ALT_MFP1_PF2_MFP1_Pos)  
#define  SYS_ALT1_PF2_ADC6         (3ul << SYS_ALT_MFP1_PF2_MFP1_Pos)  

#define  SYS_ALT1_PD5_GPIO         (0ul << SYS_ALT_MFP1_PD5_MFP1_Pos) 
#define  SYS_ALT1_PD5_MOSI21_ADC5  (1ul << SYS_ALT_MFP1_PD5_MFP1_Pos) 

#define  SYS_ALT1_PD4_GPIO         (0ul << SYS_ALT_MFP1_PD4_MFP1_Pos)
#define  SYS_ALT1_PD4_MISO21_ADC4  (1ul << SYS_ALT_MFP1_PD4_MFP1_Pos)  

#define  SYS_ALT1_PD3_GPIO_MOSI01  (0ul << SYS_ALT_MFP1_PD3_MFP1_Pos)   
#define  SYS_ALT1_PD3_MOSI20_ADC3  (1ul << SYS_ALT_MFP1_PD3_MFP1_Pos)     

#define  SYS_ALT1_PD2_GPIO_MISO01  (0ul << SYS_ALT_MFP1_PD2_MFP1_Pos)   
#define  SYS_ALT1_PD2_MISO20_ADC2  (1ul << SYS_ALT_MFP1_PD2_MFP1_Pos)     

#define  SYS_ALT1_PD1_GPIO_SPISS01 (0ul << SYS_ALT_MFP1_PD1_MFP1_Pos)   
#define  SYS_ALT1_PD1_SPICLK2_ADC1 (1ul << SYS_ALT_MFP1_PD1_MFP1_Pos)     

#define  SYS_ALT1_PD0_GPIO         (0ul << SYS_ALT_MFP1_PD0_MFP1_Pos)   
#define  SYS_ALT1_PD0_SPISS20_ADC0 (1ul << SYS_ALT_MFP1_PD0_MFP1_Pos)     

////SYS->DFP ///////////////////////////////////////////////////////////////////////
#define  SYS_PB7_CONFLICT          (1<<SYS_DFP_CSR_DFP6_CST_Pos )    //Function of GPIOB7 is conflicted.
#define  SYS_PB6_CONFLICT          (1<<SYS_DFP_CSR_DFP5_CST_Pos )    //Function of GPIOB6 is conflicted.
#define  SYS_PB5_CONFLICT          (1<<SYS_DFP_CSR_DFP4_CST_Pos )    //Function of GPIOB5 is conflicted.
#define  SYS_PB4_CONFLICT          (1<<SYS_DFP_CSR_DFP3_CST_Pos )    //Function of GPIOB4 is conflicted.
#define  SYS_PD11_CONFLICT         (1<<SYS_DFP_CSR_DFP2_CST_Pos )    //Function of GPIOD11 is conflicted.
#define  SYS_PD10_CONFLICT         (1<<SYS_DFP_CSR_DFP1_CST_Pos )    //Function of GPIOD10 is conflicted.
#define  SYS_PD9_CONFLICT          (1<<SYS_DFP_CSR_DFP0_CST_Pos )    //Function of GPIOD9 is conflicted.

////SYS->GPA_IOCR ///////////////////////////////////////////////////////////////////////
#define  SYS_PA11_STRONG_DRV_EN    (1<<SYS_GPA_IOCR_GPA11_DS_Pos)    //PA.11 strong driving strength mode Enabled.
#define  SYS_PA10_STRONG_DRV_EN    (1<<SYS_GPA_IOCR_GPA10_DS_Pos)    //PA.10 strong driving strength mode Enabled.

////SYS->GPB_IOCR ///////////////////////////////////////////////////////////////////////
#define  SYS_PB14_STRONG_DRV_EN    (1<<SYS_GPB_IOCR_GPB14_DS_Pos)    //PB.14 strong driving strength mode Enabled.
#define  SYS_PB13_STRONG_DRV_EN    (1<<SYS_GPB_IOCR_GPB13_DS_Pos)    //PB.13 strong driving strength mode Enabled.
#define  SYS_PB12_STRONG_DRV_EN    (1<<SYS_GPB_IOCR_GPB12_DS_Pos)    //PB.12 strong driving strength mode Enabled.
#define  SYS_PB8_STRONG_DRV_EN     (1<<SYS_GPB_IOCR_GPB8_DS_Pos)     //PB.8 strong driving strength mode Enabled.
#define  SYS_PB7_STRONG_DRV_EN     (1<<SYS_GPB_IOCR_GPB7_DS_Pos)     //PB.7 strong driving strength mode Enabled.
#define  SYS_PB6_STRONG_DRV_EN     (1<<SYS_GPB_IOCR_GPB6_DS_Pos)     //PB.6 strong driving strength mode Enabled.
#define  SYS_PB5_STRONG_DRV_EN     (1<<SYS_GPB_IOCR_GPB5_DS_Pos)     //PB.5 strong driving strength mode Enabled.
#define  SYS_PB4_STRONG_DRV_EN     (1<<SYS_GPB_IOCR_GPB4_DS_Pos)     //PB.4 strong driving strength mode Enabled. 

////SYS->GPD_IOCR ///////////////////////////////////////////////////////////////////////
#define  SYS_PD11_STRONG_DRV_EN    (1<<SYS_GPB_IOCR_GPD11_DS_Pos)    //PD.11 strong driving strength mode Enabled.
#define  SYS_PD10_STRONG_DRV_EN    (1<<SYS_GPB_IOCR_GPD10_DS_Pos)    //PD.10 strong driving strength mode Enabled.
#define  SYS_PD9_STRONG_DRV_EN     (1<<SYS_GPB_IOCR_GPD9_DS_Pos)     //PD.9 strong driving strength mode Enabled.
#define  SYS_PD8_STRONG_DRV_EN     (1<<SYS_GPB_IOCR_GPD8_DS_Pos)     //PD.8 strong driving strength mode Enabled.

/*@}*/ /* end of group SYS_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup SYS_MACRO_FUNC System Macro Func
  @{
*/

/**
 * @brief       Read register RSTSRC
 *
 * @param[in]   None
 *
 * @return      The value of register RSTSRC.
 *          
 * @details     To obtain reset source by Reading register RSTSRC.
 *              Example of function call: 
 *              RstSrc = SYS_READ_RST_SOURCE() ; 
 */
static __INLINE uint32_t SYS_READ_RST_SOURCE(void)
{
  return (SYS->RSTSRC)  ;
}

/**
 * @brief       To test whether is CPU reset.
 *
 * @param[in]   None
 *
 * @return      SYS_RST_SRC_CPU,  If it is CPU reset.
 *              0              ,  If it is not CPU reset.
 *          
 * @details     To read the value of bit SYS_RST_SRC_CPU in register RSTSRC.
 *              Example of function call: 
 *                IS_CPU_RST() ; 
 */
static __INLINE uint32_t IS_CPU_RST(void) 
{
  return (SYS->RSTSRC & SYS_RST_SRC_CPU)  ;
}

/**
 * @brief       To test whether is system reset.
 *
 * @param[in]   None
 *
 * @return      SYS_RST_SRC_SYSTEM ,  If it is system reset.
 *              0                  ,  If it is not system reset.
 *          
 * @details     To read the value of bit SYS_RST_SRC_SYSTEM in register RSTSRC.
 *              Example of function call: 
 *                IS_SYSTEM_RST() ; 
 */
static __INLINE uint32_t IS_SYSTEM_RST(void)
{
  return (SYS->RSTSRC & SYS_RST_SRC_SYSTEM) ;
}

/**
 * @brief       To test whether is BOD causing reset.
 *
 * @param[in]   None
 *
 * @return      SYS_RST_SRC_BOD ,  If it is BOD causing reset.
 *              0               ,  If it is not BOD causing reset.
 *          
 * @details     To read the value of bit SYS_RST_SRC_BOD in register RSTSRC.
 *              Example of function call: 
 *               IS_BOD_CAUSE_RST() ; 
 */
static __INLINE uint32_t IS_BOD_CAUSE_RST(void)
{
  return (SYS->RSTSRC & SYS_RST_SRC_BOD) ;
}

/**
 * @brief       To test whether is LVR causing reset.
 *
 * @param[in]   None
 *
 * @return      SYS_RST_SRC_LVR ,  If it is LVR causing reset.
 *              0               ,  If it is not LVR causing reset.
 *          
 * @details     To read the value of bit SYS_RST_SRC_LVR in register RSTSRC.
 *              Example of function call: 
 *                IS_LVR_CAUSE_RST()  ; 
 */
static __INLINE uint32_t IS_LVR_CAUSE_RST(void)
{
  return (SYS->RSTSRC & SYS_RST_SRC_LVR) ;
}

/**
 * @brief       To test whether is WDT causing reset.
 *
 * @param[in]   None
 *
 * @return      SYS_RST_SRC_WDT ,  If it is WDT causing reset.
 *              0               ,  If it is not WDT causing reset.
 *          
 * @details     To read the value of bit SYS_RST_SRC_WDT in register RSTSRC.
 *              Example of function call: 
 *                IS_WDT_CAUSE_RST()    ; 
 */
static __INLINE uint32_t IS_WDT_CAUSE_RST(void)
{
  return (SYS->RSTSRC & SYS_RST_SRC_WDT) ;
}

/**
 * @brief       To test whether is #RST pin causing reset.
 *
 * @param[in]   None
 *
 * @return      SYS_RST_SRC_RST ,  If it is #RST pin causing reset.
 *              0               ,  If it is not #RST pin causing reset.
 *          
 * @details     To read the value of bit SYS_RST_SRC_RST in register RSTSRC.
 *              Example of function call: 
 *                IS_RSTPIN_CAUSR_RST()  ; 
 */
static __INLINE uint32_t IS_RSTPIN_CAUSR_RST(void)
{
  return (SYS->RSTSRC & SYS_RST_SRC_RST) ;
}

/**
 * @brief       To test whether is POR causing reset.
 *
 * @param[in]   None
 *
 * @return      SYS_RST_SRC_POR ,  If it is POR causing reset.
 *              0               ,  If it is not POR causing reset.
 *          
 * @details     To read the value of bit SYS_RST_SRC_POR in register RSTSRC.
 *              Example of function call: 
 *                IS_POR_CAUSR_RST()  ; 
 */
static __INLINE uint32_t IS_POR_CAUSR_RST(void)
{
   return (SYS->RSTSRC & SYS_RST_SRC_POR) ;
}
  
/**
 * @brief       Clear reset source from register RSTSRC
 *
 * @param[in]   RST_SOURCE   The reset-source which will be cleared. It should be 
 *              following constance or addition of some:         
 *                    SYS_RST_SRC_CPU          
 *                    SYS_RST_SRC_SYSTEM          
 *                    SYS_RST_SRC_BOD            
 *                    SYS_RST_SRC_LVR            
 *                    SYS_RST_SRC_WDT              
 *                    SYS_RST_SRC_RST             
 *                    SYS_RST_SRC_POR  
 *          
 * @return      None
 *
 * @details     Clear reset source from register RSTSRC.
 *              Example of function call:  
 *              SYS_CLEAR_RST_SOURCE(SYS_RST_SRC_RST | SYS_RST_SRC_POR ) ; 
 */
static __INLINE void SYS_CLEAR_RST_SOURCE(uint32_t RST_SOURCE)
{
  (SYS->RSTSRC |= (RST_SOURCE)) ;
}

/**
 * @brief       Reset IP in IPRSTC1 
 *
 * @param[in]   SYS_RST_IP   The bit corresponding IP in IPRSTC1, It should be following 
 *                           constance or  addition of some:         
 *                                 SYS_RST_PDMA      
 *                                 SYS_RST_CPU         
 *                                 SYS_RST_CHIP  
 *    
 * @return      None
 *
 * @details     Reset IP in IPRSTC1 . 
 *              Example of function call:  
 *              SYS_RESET_IP1(SYS_RST_PDMA) ;
 */
static __INLINE void SYS_RESET_IP1(uint32_t SYS_RST_IP)
{
    SYS->IPRSTC1 |= (SYS_RST_IP) ; 
    SYS->IPRSTC1 &= ~(SYS_RST_IP) ; 
}

/**
 * @brief       Reset IP in IPRSTC2 
 *
 * @param[in]   SYS_RST_IP   The bit corresponding IP inIPRSTC2, It should be following 
 *                    constance or addition of some  :         
 *                      SYS_RST_I2S       
 *                      SYS_RST_ADC                
 *                      SYS_RST_USBD                
 *                      SYS_RST_PS2                 
 *                      SYS_RST_PWM0123             
 *                      SYS_RST_UART1               
 *                      SYS_RST_UART0              
 *                      SYS_RST_SPI2               
 *                      SYS_RST_SPI1               
 *                      SYS_RST_SPI0               
 *                      SYS_RST_I2C1             
 *                      SYS_RST_I2C0             
 *                      SYS_RST_TMR3          
 *                      SYS_RST_TMR2            
 *                      SYS_RST_TMR1          
 *                      SYS_RST_TMR0          
 *                      SYS_RST_GPIO       
 *
 * @return      None
 *
 * @details     Reset IP in IPRSTC2 .
 *              Example of function call:  
 *              SYS_RESET_IP2(SYS_RST_TMR1 | SYS_RST_TMR0) ;
 */
static __INLINE void SYS_RESET_IP2(uint32_t SYS_RST_IP)
{
   SYS->IPRSTC2 |= (SYS_RST_IP) ; 
   SYS->IPRSTC2 &= ~(SYS_RST_IP) ; 
}

/**
 * @brief       Enable LVR function
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Enable LVR function.
 *              Example of function call: 
 *              LVR_ENABLE() ; 
 */
static __INLINE void LVR_ENABLE(void)
{
     (SYS->BODCR |=  SYS_LVR_EN) ;
}

/**
 * @brief       Disable LVR function
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Disable LVR function.
 *              Example of function call: 
 *              LVR_DISABLE() ; 
 */
static __INLINE void LVR_DISABLE(void)
{
  (SYS->BODCR &= ~SYS_LVR_EN) ;
}

/**
 * @brief       Get BOD output.
 *
 * @param[in]   None
 *
 * @return      The value of bit SYS_BOD_OUT in register BODCR.
 *          
 * @details     Read value of bit SYS_BOD_OUT in register BODCR.
 *              Example of function call: 
 *              BodValue = BOD_OUTPUT() ; 
 */
static __INLINE uint32_t BOD_OUTPUT(void)
{
  return   (SYS->BODCR & SYS_BOD_OUT) ;
}

/**
 * @brief       Enable Low power mode of BOD
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Set bit SYS_BOD_LOW_POWER_MODE in register BODCR.
 *              Example of function call: 
 *              BOD_SET_LPM() ; 
 */
static __INLINE void BOD_SET_LPM(void)
{
  (SYS->BODCR |=  SYS_BOD_LOW_POWER_MODE) ;
}

/**
 * @brief       Disable Low power mode of BOD
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Clear bit SYS_BOD_LOW_POWER_MODE in register BODCR.
 *              Example of function call: 
 *              BOD_CLEAR_LPM() ; 
 */
static __INLINE void BOD_CLEAR_LPM(void)
{
   (SYS->BODCR &= ~SYS_BOD_LOW_POWER_MODE) ;
}

/**
 * @brief       Get Interrupt flag of BOD.
 *
 * @param[in]   None
 *
 * @return      The value of bit SYS_BOD_INT_FLAG in register BODCR.
 *          
 * @details     Read value of bit SYS_BOD_INT_FLAG in register BODCR.
 *              Example of function call: 
 *              BodValue = BOD_GET_INT_FLAG() ; 
 */
static __INLINE uint32_t BOD_GET_INT_FLAG(void)
{
   return (SYS->BODCR & SYS_BOD_INT_FLAG) ;
}
/**
 * @brief       Clear Interrupt flag of BOD.
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Clear value of bit SYS_BOD_INT_FLAG in register BODCR.
 *              Example of function call: 
 *              BOD_CLEAR_INT_FLAG() ; 
 */
static __INLINE void BOD_CLEAR_INT_FLAG(void)
{
  (SYS->BODCR &= ~SYS_BOD_INT_FLAG) ;
}
/**
 * @brief       Enable reset function of BOD
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Set bit SYS_BOD_RST_ENABLE in register BODCR.
 *              Example of function call: 
 *              BOD_RST_ENABLE() ; 
 */
static __INLINE void BOD_RST_ENABLE(void)
{
     (SYS->BODCR |= SYS_BOD_RST_ENABLE)  ;
}
/**
 * @brief       Disable reset function of BOD
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Clear bit SYS_BOD_RST_ENABLE in register BODCR.
 *              Example of function call: 
 *              BOD_RST_DISABLE() ; 
 */
static __INLINE void BOD_RST_DISABLE(void)
{
    (SYS->BODCR &= ~SYS_BOD_RST_ENABLE) ;
}

/**
 * @brief       Set BOD Voltage
 *
 * @param[in]   SYS_BOD_VOLTAGE   BOD Voltage, It should be following constance:          
 *                      SYS_BOD_22V           
 *                      SYS_BOD_27V                 
 *                      SYS_BOD_38V                 
 *                      SYS_BOD_45V                 
 *    
 * @return      None
 *
 * @details     Reset IP in IPRSTC2 .
 *              Example of function call:  
 *              SYS_RESET_IP2(SYS_RST_TMR1 | SYS_RST_TMR0) ;
 */
static __INLINE void BOD_SET_VOLTAGE(uint32_t SYS_BOD_VOLTAGE)
{
   (SYS->BODCR = (SYS->BODCR & SYS_BODCR_BOD_VL_Msk) | (SYS_BOD_VOLTAGE)) ;
}

/**
 * @brief       Enable BOD
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Set bit SYS_BOD_ENABLE in register BODCR.
 *              Example of function call: 
 *              BOD_ENABLE()  ; 
 */
static __INLINE void BOD_ENABLE(void)
{
    (SYS->BODCR |= SYS_BOD_ENABLE) ;
}
/**
 * @brief       Disable BOD
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Clear bit SYS_BOD_ENABLE in register BODCR.
 *              Example of function call: 
 *              BOD_DISABLE()  ; 
 */
static __INLINE void BOD_DISABLE(void)
{
  (SYS->BODCR &= ~SYS_BOD_ENABLE) ;
}
/**
 * @brief       Disable POR
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     To write 0x5AA5 into register PORCR.
 *              Example of function call: 
 *              POR_DISABLE() ; 
 */
static __INLINE void POR_DISABLE(void)
{
   (SYS->PORCR = 0x5AA5) ;
}
/**
 * @brief       Enable POR
 *
 * @param[in]   None
 *
 * @return      None.
 *          
 * @details     Clear register BODCR.
 *              Example of function call: 
 *              POR_ENABLE() ; 
 */
static __INLINE void POR_ENABLE(void)
{
   (SYS->PORCR = 0) ;
}

/**
 * @brief       Make GPIOA driving strength  
 *
 * @param[in]   x     Bit constance corresponding PIN of GPIOA, It should be following
 *                    constance or their addition :          
 *                        SYS_PA11_STRONG_DRV_EN   
 *                        SYS_PA10_STRONG_DRV_EN      
 *    
 * @return      None
 *
 * @details     Set corresponding bit in GPIOA_IOCR.
 *              Example of function call:  
 *              SYS_GPIOA_STRONG_SET(SYS_PA11_STRONG_DRV_EN | SYS_PA10_STRONG_DRV_EN) ;
 */
static __INLINE void SYS_GPIOA_STRONG_ENABLE(uint32_t x)
{
   (SYS->GPA_IOCR |= (x)) ;
}

/**
 * @brief       Disable GPIOA driving strength  
 *
 * @param[in]   x     Bit constance corresponding PIN of GPIOA, It should be following
 *                    constance or their addition :          
 *                        SYS_PA11_STRONG_DRV_EN   
 *                        SYS_PA10_STRONG_DRV_EN      
 *    
 * @return      None
 *
 * @details     Clear corresponding bit in GPIOA_IOCR.
 *              Example of function call:  
 *              SYS_GPIOA_STRONG_RST(SYS_PA11_STRONG_DRV_EN | SYS_PA10_STRONG_DRV_EN) ;
 */
static __INLINE void SYS_GPIOA_STRONG_DISABLE(uint32_t x)
{
  ((SYS->GPA_IOCR &= ~(x))) ;
}
/**
 * @brief       Make GPIOB driving strength  
 *
 * @param[in]   x     Bit constance corresponding PIN of GPIOB, It should be following
 *                    constance or addition of some them:  
 *                       SYS_PB14_STRONG_DRV_EN      
 *                       SYS_PB13_STRONG_DRV_EN    
 *                       SYS_PB12_STRONG_DRV_EN    
 *                       SYS_PB8_STRONG_DRV_EN      
 *                       SYS_PB7_STRONG_DRV_EN      
 *                       SYS_PB6_STRONG_DRV_EN   
 *                       SYS_PB5_STRONG_DRV_EN    
 *                       SYS_PB4_STRONG_DRV_EN     
 *    
 * @return      None
 *
 * @details     Set corresponding bit in GPIOB_IOCR.
 *              Example of function call:  
 *              SYS_GPIOB_STRONG_SET(SYS_PB14_STRONG_DRV_EN | SYS_PB12_STRONG_DRV_EN) ;
 */
static __INLINE void SYS_GPIOB_STRONG_ENABLE(uint32_t x)
{
  (SYS->GPB_IOCR |= (x))  ;
}

/**
 * @brief       Disable GPIOB driving strength  
 *
 * @param[in]   x     Bit constance corresponding PIN of GPIOB, It should be following
 *                     constance or some of addition :  
 *                    SYS_PB14_STRONG_DRV_EN      
 *                    SYS_PB13_STRONG_DRV_EN    
 *                    SYS_PB12_STRONG_DRV_EN    
 *                    SYS_PB8_STRONG_DRV_EN      
 *                    SYS_PB7_STRONG_DRV_EN      
 *                    SYS_PB6_STRONG_DRV_EN   
 *                    SYS_PB5_STRONG_DRV_EN    
 *                    SYS_PB4_STRONG_DRV_EN     
 *    
 * @return      None
 *
 * @details     Clear corresponding bit in GPIOB_IOCR.
 *              Example of function call:  
 *              SYS_GPIOB_STRONG_RST(SYS_PB14_STRONG_DRV_EN | SYS_PB12_STRONG_DRV_EN) ;
 */
static __INLINE void SYS_GPIOB_STRONG_RST(uint32_t x)
{
  ((SYS->GPB_IOCR &= ~(x))) ;
}

/**
 * @brief       Make GPIOD driving strength  
 *
 * @param[in]   x     Bit constance corresponding PIN of GPIOD, It should be following
 *                     constance or some of addition :  
 *                    SYS_PD11_STRONG_DRV_EN     
 *                    SYS_PD10_STRONG_DRV_EN 
 *                    SYS_PD9_STRONG_DRV_EN   
 *                    SYS_PD8_STRONG_DRV_EN     
 *    
 * @return      None
 *
 * @details     Set corresponding bit in GPIOD_IOCR.
 *              Example of function call:  
 *              SYS_GPIOD_STRONG_SET(SYS_PD11_STRONG_DRV_EN | SYS_PD10_STRONG_DRV_EN) ;
 */
static __INLINE void SYS_GPIOD_STRONG_ENABLE(uint32_t x) 
{
   ((SYS->GPD_IOCR |= (x)))   ;
}

/**
 * @brief       Disable GPIOD driving strength  
 *
 * @param[in]   x     Bit constance corresponding PIN of GPIOD, It should be following
 *                     constance or addition of some:  
 *                    SYS_PD11_STRONG_DRV_EN     
 *                    SYS_PD10_STRONG_DRV_EN 
 *                    SYS_PD9_STRONG_DRV_EN   
 *                    SYS_PD8_STRONG_DRV_EN     
 *    
 * @return      None
 *
 * @details     Clear corresponding bit in GPIOD_IOCR.
 *              Example of function call:  
 *              SYS_GPIOD_STRONG_SET(SYS_PD11_STRONG_DRV_EN | SYS_PD10_STRONG_DRV_EN) ;
 */
static __INLINE void SYS_GPIOD_STRONG_DISABLE(uint32_t x)
{
  ((SYS->GPD_IOCR &= ~(x))) ;
}
/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/

/**
 * @brief      Unlock the protected registers
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Clear corresponding bit in GPIOD_IOCR.
 *             Example of function call:  
 *             SYS_GPIOD_STRONG_SET(SYS_PD11_STRONG_DRV_EN | SYS_PD10_STRONG_DRV_EN);
 */
static __INLINE void SYS_UnlockReg(void)
{   
    SYS->REGWRPROT = 0x59;
    SYS->REGWRPROT = 0x16;
    SYS->REGWRPROT = 0x88;
}

/**
 * @brief      Lock the protected registers
 *
 * @param      None
 *
 * @return     None
 *
 * @details    To lock the protected register to forbid write access
 */
static __INLINE void SYS_LockReg(void)
{   
    SYS->REGWRPROT = 0;
}
/**
 * @brief      Generate the Delay Time by Systick
 *
 * @param[in]  us  Delay time. The Max value is 2^24 / CPU Clock(MHz). Ex:
 *                             50MHz => 335544us, 48MHz => 349525us, 28MHz => 699050us ...
 *
 * @return     None
 *
 * @details    Use the SysTick to generate the delay time and the UNIT is in us. 
 *             The SysTick clock source is from HCLK, i.e the same as system core clock.
 */

static __INLINE void SYS_SysTickDelay(uint32_t us)
{
    SysTick->LOAD = us * CyclesPerUs;
    SysTick->VAL  =  (0x00);
    SysTick->CTRL = SysTick->CTRL | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    // Waiting for down-count to zero 
    while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
}

/**
 * @brief      System enter power down mode
 *
 * @param[in]  u32WaitCpu  indicate when entering power down mode, to wait for wfi instruction or not. 
 *                         It could be: CLK_PWRCON_PD_WAIT_CPU, CLK_PWRCON_PD_NWAIT_CPU
 *
 * @return     None
 *
 * @details    Force system to enter power down(deep sleep) mode 
 *
 * @note   
 *             User must call SYS_UnlockReg() to unlock protected registers before calling this function
 */

static __INLINE void SYS_EnterPowerDown(uint32_t u32WaitCpu)
{   
    SCB->SCR = SCB_SCR_SLEEPDEEP_Msk;
    CLK->PWRCON  = (CLK->PWRCON & (~CLK_PWRCON_PD_WAIT_CPU_Msk)) | u32WaitCpu | CLK_PWRCON_PD_EN;
}

/*@}*/ /* end of group SYS_MACRO_FUNC */
/*@}*/ /* end of group SYS_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */


#endif   //__SYS_H
