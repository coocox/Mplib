/**************************************************************************//**
 * @file     SYS.h
 * @version  V1.0
 * $Revision  1 $
 * $Date: 13/11/10 9:44a $
 * @brief    NUC400 Series SYS Header File
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_SYS_Driver SYS Driver
  @{
*/

/** @addtogroup NUC400_SYS_EXPORTED_CONSTANTS SYS Exported Constants
  @{
*/

//SYS->RSTSRC
#define  SYS_RSTSRC_CPUINST       (0x1UL<<SYS_RSTSRC_CPUINST_Pos)      /*!<CPU Instant  Priority. */
#define  SYS_RSTSRC_CPU           (0x1UL<<SYS_RSTSRC_RSTS_CPU_Pos)      /*!<writing bit SYS_CPU_RST in IPRSTC1 cause reset. */
#define  SYS_RSTSRC_SYSTEM        (0x1UL<<SYS_RSTSRC_RSTS_SYS_Pos)      /*!<Writing bit SYSRESETREQ in AIRCR cause reset. */
#define  SYS_RSTSRC_BOD           (0x1UL<<SYS_RSTSRC_RSTS_BOD_Pos)      /*!<It cause reset that VCC is lower than BOD voltage. */
#define  SYS_RSTSRC_LVR           (0x1UL<<SYS_RSTSRC_RSTS_LVR_Pos)      /*!<It cause reset that VCC is lower than LVRvoltage.  */
#define  SYS_RSTSRC_WDT           (0x1UL<<SYS_RSTSRC_RSTS_WDT_Pos)      /*!<WDT cause reset. */
#define  SYS_RSTSRC_RST           (0x1UL<<SYS_RSTSRC_RSTS_RESET_Pos)    /*!<Pulling down Reset pin cause reset.  */
#define  SYS_RSTSRC_POR           (0x1UL<<SYS_RSTSRC_RSTS_POR_Pos)      /*!<Power on cause reset. */

/*---------------------------------------------------------------------------------------------------------*/
/*  Module Reset Control Resister constant definitions.                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define CHIP_RST  ((0x0<<24)|SYS_IPRSTC1_CHIP_RST_Pos)    /*!<Reset CHIP */
#define CPU_RST   ((0x0<<24)|SYS_IPRSTC1_CPU_RST_Pos)     /*!<Reset CPU */
#define PDMA_RST  ((0x0<<24)|SYS_IPRSTC1_PDMA_RST_Pos)    /*!<Reset PDMA */
#define EBI_RST   ((0x0<<24)|SYS_IPRSTC1_EBI_RST_Pos)     /*!<Reset EBI */
#define UHC_RST   ((0x0<<24)|SYS_IPRSTC1_UHC_RST_Pos)     /*!<Reset UHC */
#define EMAC_RST  ((0x0<<24)|SYS_IPRSTC1_EMAC_RST_Pos)    /*!<Reset EMAC */
#define SDIO_RST  ((0x0<<24)|SYS_IPRSTC1_SD_RST_Pos)      /*!<Reset SDIO */
#define CRC_RST   ((0x0<<24)|SYS_IPRSTC1_CRC_RST_Pos)     /*!<Reset CRC */
#define CAP_RST   ((0x0<<24)|SYS_IPRSTC1_CAP_RST_Pos)     /*!<Reset CAP */
#define SPACC_RST ((0x0<<24)|SYS_IPRSTC1_SPACC_RST_Pos)   /*!<Reset SPACC */
#define GPIO_RST  ((0x4<<24)|SYS_IPRSTC2_GPIO_RST_Pos)    /*!<Reset GPIO */
#define TMR0_RST  ((0x4<<24)|SYS_IPRSTC2_TMR0_RST_Pos)    /*!<Reset TMR0 */
#define TMR1_RST  ((0x4<<24)|SYS_IPRSTC2_TMR1_RST_Pos)    /*!<Reset TMR1 */
#define TMR2_RST  ((0x4<<24)|SYS_IPRSTC2_TMR2_RST_Pos)    /*!<Reset TMR2 */
#define TMR3_RST  ((0x4<<24)|SYS_IPRSTC2_TMR3_RST_Pos)    /*!<Reset TMR3 */
#define ACMP_RST  ((0x4<<24)|SYS_IPRSTC2_ACMP_RST_Pos)    /*!<Reset ACMP */
#define I2C0_RST  ((0x4<<24)|SYS_IPRSTC2_I2C0_RST_Pos)    /*!<Reset I2C0 */
#define I2C1_RST  ((0x4<<24)|SYS_IPRSTC2_I2C1_RST_Pos)    /*!<Reset I2C1 */
#define I2C2_RST  ((0x4<<24)|SYS_IPRSTC2_I2C2_RST_Pos)    /*!<Reset I2C2 */
#define I2C3_RST  ((0x4<<24)|SYS_IPRSTC2_I2C3_RST_Pos)    /*!<Reset I2C3 */
#define SPI0_RST  ((0x4<<24)|SYS_IPRSTC2_SPI0_RST_Pos)    /*!<Reset SPI0 */
#define SPI1_RST  ((0x4<<24)|SYS_IPRSTC2_SPI1_RST_Pos)    /*!<Reset SPI1 */
#define SPI2_RST  ((0x4<<24)|SYS_IPRSTC2_SPI2_RST_Pos)    /*!<Reset SPI2 */
#define SPI3_RST  ((0x4<<24)|SYS_IPRSTC2_SPI3_RST_Pos)    /*!<Reset SPI3 */
#define UART0_RST ((0x4<<24)|SYS_IPRSTC2_UART0_RST_Pos)   /*!<Reset UART0 */
#define UART1_RST ((0x4<<24)|SYS_IPRSTC2_UART1_RST_Pos)   /*!<Reset UART1 */
#define UART2_RST ((0x4<<24)|SYS_IPRSTC2_UART2_RST_Pos)   /*!<Reset UART2 */
#define UART3_RST ((0x4<<24)|SYS_IPRSTC2_UART3_RST_Pos)   /*!<Reset UART3 */
#define UART4_RST ((0x4<<24)|SYS_IPRSTC2_UART4_RST_Pos)   /*!<Reset UART4 */
#define UART5_RST ((0x4<<24)|SYS_IPRSTC2_UART5_RST_Pos)   /*!<Reset UART5 */
#define CAN0_RST  ((0x4<<24)|SYS_IPRSTC2_CAN0_RST_Pos)    /*!<Reset CAN0 */
#define CAN1_RST  ((0x4<<24)|SYS_IPRSTC2_CAN1_RST_Pos)    /*!<Reset CAN1 */
#define OTG_RST   ((0x4<<24)|SYS_IPRSTC2_OTG_RST_Pos)     /*!<Reset OTG */
#define USBD_RST  ((0x4<<24)|SYS_IPRSTC2_USBD_RST_Pos)    /*!<Reset USBD */
#define ADC_RST   ((0x4<<24)|SYS_IPRSTC2_ADC_RST_Pos)     /*!<Reset ADC */
#define I2S_RST   ((0x4<<24)|SYS_IPRSTC2_I2S_RST_Pos)     /*!<Reset I2S */
#define I2S1_RST  ((0x4<<24)|SYS_IPRSTC2_I2S1_RST_Pos)    /*!<Reset I2S1 */
#define PS2_RST   ((0x4<<24)|SYS_IPRSTC2_PS2_RST_Pos)     /*!<Reset PS2 */
#define SC0_RST  ((0x8<<24)|SYS_IPRSTC3_SC0_RST_Pos)      /*!<Reset SC0 */
#define SC1_RST  ((0x8<<24)|SYS_IPRSTC3_SC1_RST_Pos)      /*!<Reset SC1 */
#define SC2_RST  ((0x8<<24)|SYS_IPRSTC3_SC2_RST_Pos)      /*!<Reset SC2 */
#define SC3_RST  ((0x8<<24)|SYS_IPRSTC3_SC3_RST_Pos)      /*!<Reset SC3 */
#define SC4_RST  ((0x8<<24)|SYS_IPRSTC3_SC4_RST_Pos)      /*!<Reset SC4 */
#define SC5_RST  ((0x8<<24)|SYS_IPRSTC3_SC5_RST_Pos)      /*!<Reset SC5 */
#define I2C4_RST ((0x8<<24)|SYS_IPRSTC3_I2C4_RST_Pos)     /*!<Reset I2C4 */
#define PWM0_RST ((0x8<<24)|SYS_IPRSTC3_PWM0_RST_Pos)     /*!<Reset PWM0 */
#define PWM1_RST ((0x8<<24)|SYS_IPRSTC3_PWM1_RST_Pos)     /*!<Reset PWM1 */
#define QEI0_RST ((0x8<<24)|SYS_IPRSTC3_QEI0_RST_Pos)     /*!<Reset QEI0 */
#define QEI1_RST ((0x8<<24)|SYS_IPRSTC3_QEI1_RST_Pos)     /*!<Reset QEI1 */

/*---------------------------------------------------------------------------------------------------------*/
/*  BODCR constant definitions.                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define  SYS_BODCR_EN                 (0x1UL<<SYS_BODCR_BOD_EN_Pos)        /*!Enable BOD IP */
#define  SYS_BODCR_BOD_VL_2_2V        (0x0UL<<SYS_BODCR_BOD_VL_Pos)        /*!Threshold voltage of BOD is selected 2.2V */
#define  SYS_BODCR_BOD_VL_2_7V        (0x1UL<<SYS_BODCR_BOD_VL_Pos)        /*!Threshold voltage of BOD is selected 2.7V */
#define  SYS_BODCR_BOD_VL_3_8V        (0x2UL<<SYS_BODCR_BOD_VL_Pos)        /*!Threshold voltage of BOD is selected 3.82V */
#define  SYS_BODCR_BOD_VL_4_5V        (0x3UL<<SYS_BODCR_BOD_VL_Pos)        /*!Threshold voltage of BOD is selected 4.5V */
#define  SYS_BODCR_BOD_RSTEN          (0x1UL<<SYS_BODCR_BOD_RSTEN_Pos)     /*!Enable reset function of BOD. */
#define  SYS_BODCR_BOD_INTEN          (0x0UL<<SYS_BODCR_BOD_RSTEN_Pos)     /*!Enable interrupt function of BOD. */
#define  SYS_BODCR_BOD_INTF           (0x1UL<<SYS_BODCR_BOD_INTF_Pos)      /*!BOD caused a interrupt. */
#define  SYS_BODCR_BOD_LPM            (0x1UL<<SYS_BODCR_BOD_LPM_Pos)       /*!BOD work in low power mode. */
#define  SYS_BODCR_BOD_OUT            (0x1UL<<SYS_BODCR_BOD_OUT_Pos)       /*!Output of BOD IP. */
#define  SYS_BODCR_LVR_EN             (0x1UL<<SYS_BODCR_LVR_EN_Pos)        /*!Enable LVR function. */

/*---------------------------------------------------------------------------------------------------------*/
/*  TEMPCR constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define SYS_TEMPCR_VTEMP_EN (0x1UL<<SYS_TEMPCR_VTEMP_EN_Pos)     /*!Temperature sensor function Enabled */

/*---------------------------------------------------------------------------------------------------------*/
/*  VREFCR constant definitions. (Write-Protection Register)                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define SYS_VREFCR_VREF_ENG (0x1UL<<SYS_VREFCR_VREF_ENG_Pos)  /*!VREF current band-gap  Enabled */
#define SYS_VREFCR_VREF_ENREG (0x1UL<<SYS_VREFCR_VREF_ENREG_Pos)  /*!  VREF regulator  out Enabled  */
#define SYS_VREFCR_VREF_2_56V (0x0UL<<SYS_VREFCR_VREF_SEL_Pos)  /*!  VOUT= 2.56V  */
#define SYS_VREFCR_VREF_2_048V (0x1UL<<SYS_VREFCR_VREF_SEL_Pos)  /*! VOUT= 2.048V  */
#define SYS_VREFCR_VREF_3_072V (0x2UL<<SYS_VREFCR_VREF_SEL_Pos)  /*! VOUT= 3.072V  */
#define SYS_VREFCR_VREF_4_096V (0x3UL<<SYS_VREFCR_VREF_SEL_Pos)  /*! VOUT= 4.096V  */
#define SYS_VREFCR_ADC_VREFSEL (0x1UL<<SYS_VREFCR_ADC_VREFSEL_Pos)  /*!AVDD connected  */
#define SYS_VREFCR_ADC_SEL (0x1UL<<SYS_VREFCR_ADC_SEL_Pos)      /*!FA8249 ADC mode  */
#define SYS_VREFCR_PWM_MODE (0x1UL<<SYS_VREFCR_PWM_MODE_Pos)      /*!PWM SYNC MODE ENABLED, PWM engine clock is same as HCLK  */

/*---------------------------------------------------------------------------------------------------------*/
/*  OTSYS constant definitions. (Write-Protection Register)                                                */
/*---------------------------------------------------------------------------------------------------------*/
#define SYS_OTSYS_OTG_V33_EN (0x1UL<<SYS_OTSYS_OTG_V33_EN_Pos) /*!   USB LDO33 Enabled  */
#define SYS_OTSYS_STD_USBD (0x0UL<<SYS_OTSYS_OTG_ROLE_Pos) /*!    Standard USB device  */
#define SYS_OTSYS_STD_USBH (0x1UL<<SYS_OTSYS_OTG_ROLE_Pos) /*!   Standard USB host  */
#define SYS_OTSYS_ID_DEPH (0x2UL<<SYS_OTSYS_OTG_ROLE_Pos)  /*!   ID dependent device  */
#define SYS_OTSYS_ON_THE_GO (0x3UL<<SYS_OTSYS_OTG_ROLE_Pos) /*!   On-The-Go device  */



/*---------------------------------------------------------------------------------------------------------*/
/*  Multi-Function constant definitions.                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
/* How to use below #define?
Example 1: If user want to set PA.0 as SC0_CD in initial function,
           user can issue following command to achieve it.

           SYS->GPA_MFPL  = (SYS->GPA_MFPL & (~SYS_GPA_MFPL_PA0_MFP_Msk) ) | SYS_GPA_MFPL_PA0_MFP_SC0_CD  ;

*/
//GPA_MFPL_PA0_MFP
#define SYS_GPA_MFPL_PA0_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA0_MFP_Pos)           /*!< GPA_MFPL PA0 setting for GPIO   */
#define SYS_GPA_MFPL_PA0_MFP_TAMPER0     (0x1UL<<SYS_GPA_MFPL_PA0_MFP_Pos)           /*!< GPA_MFPL PA0 setting for TAMPER0    */
#define SYS_GPA_MFPL_PA0_MFP_SC0_CD      (0x2UL<<SYS_GPA_MFPL_PA0_MFP_Pos)           /*!< GPA_MFPL PA0 setting for SC0_CD   */
#define SYS_GPA_MFPL_PA0_MFP_CAN1_RXD    (0x3UL<<SYS_GPA_MFPL_PA0_MFP_Pos)           /*!< GPA_MFPL PA0 setting for CAN1_RXD  */
#define SYS_GPA_MFPL_PA0_MFP_INT0        (0x8UL<<SYS_GPA_MFPL_PA0_MFP_Pos)           /*!< GPA_MFPL PA0 setting for INT0  */

//GPA_MFPL_PA1_MFP
#define SYS_GPA_MFPL_PA1_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA1_MFP_Pos)            /*!< GPA_MFPL PA1 setting for GPIO    */
#define SYS_GPA_MFPL_PA1_MFP_TAMPER0     (0x1UL<<SYS_GPA_MFPL_PA0_MFP_Pos)            /*!< GPA_MFPL PA1 setting for TAMPER1   */
#define SYS_GPA_MFPL_PA1_MFP_SC5_CD      (0x2UL<<SYS_GPA_MFPL_PA1_MFP_Pos)            /*!< GPA_MFPL PA1 setting for SC5_CD  */
#define SYS_GPA_MFPL_PA1_MFP_CAN1_TXD    (0x3UL<<SYS_GPA_MFPL_PA1_MFP_Pos)            /*!< GPA_MFPL PA1 setting for CAN1_TXD  */
#define SYS_GPA_MFPL_PA1_MFP_EBI_A22     (0x7UL<<SYS_GPA_MFPL_PA1_MFP_Pos)            /*!< GPA_MFPL PA1 setting for EBI_A22 */

//GPA_MFPL_PA2_MFP
#define SYS_GPA_MFPL_PA2_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA2_MFP_Pos)           /*!< GPA_MFPL PA2 setting for GPIO     */
#define SYS_GPA_MFPL_PA2_MFP_SC2_DAT     (0x1UL<<SYS_GPA_MFPL_PA2_MFP_Pos)           /*!< GPA_MFPL PA2 setting for SC2_DAT    */
#define SYS_GPA_MFPL_PA2_MFP_SPI3_MISO0      (0x2UL<<SYS_GPA_MFPL_PA2_MFP_Pos)           /*!< GPA_MFPL PA2 setting for SPI3_MISO0     */
#define SYS_GPA_MFPL_PA2_MFP_I2S0_MCLK       (0x3UL<<SYS_GPA_MFPL_PA2_MFP_Pos)           /*!< GPA_MFPL PA2 setting for I2S0_MCLK    */
#define SYS_GPA_MFPL_PA2_MFP_BRAKE11       (0x4UL<<SYS_GPA_MFPL_PA2_MFP_Pos)           /*!< GPA_MFPL PA2 setting for BRAKE11    */
#define SYS_GPA_MFPL_PA2_MFP_CAP_SFIELD     (0x5UL<<SYS_GPA_MFPL_PA2_MFP_Pos)           /*!< GPA_MFPL PA2 setting for CAP_SFIELD    */
#define SYS_GPA_MFPL_PA2_MFP_EBI_A12       (0x7UL<<SYS_GPA_MFPL_PA2_MFP_Pos)           /*!< GPA_MFPL PA2 setting for EBI_A12    */

//GPA_MFPL_PA3_MFP
#define SYS_GPA_MFPL_PA3_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA3_MFP_Pos)           /*!< GPA_MFPL PA3 setting for GPIO     */
#define SYS_GPA_MFPL_PA3_MFP_SC2_CLK       (0x1UL<<SYS_GPA_MFPL_PA3_MFP_Pos)           /*!< GPA_MFPL PA3 setting for SC2_CLK      */
#define SYS_GPA_MFPL_PA3_MFP_SP3_MOSI0       (0x2UL<<SYS_GPA_MFPL_PA3_MFP_Pos)           /*!< GPA_MFPL PA3 setting for SP3_MOSI0      */
#define SYS_GPA_MFPL_PA3_MFP_I2S0_D0      (0x3UL<<SYS_GPA_MFPL_PA3_MFP_Pos)           /*!< GPA_MFPL PA3 setting for I2S0_D0     */
#define SYS_GPA_MFPL_PA3_MFP_BRAKE10       (0x4UL<<SYS_GPA_MFPL_PA3_MFP_Pos)           /*!< GPA_MFPL PA3 setting for BRAKE10    */
#define SYS_GPA_MFPL_PA3_MFP_EBI_A13       (0x7UL<<SYS_GPA_MFPL_PA3_MFP_Pos)           /*!< GPA_MFPL PA3 setting for EBI_A13    */

//GPA_MFPL_PA4_MFP
#define SYS_GPA_MFPL_PA4_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA4_MFP_Pos)           /*!< GPA_MFPL PA4 setting for GPIO     */
#define SYS_GPA_MFPL_PA4_MFP_SC2_PWR       (0x1UL<<SYS_GPA_MFPL_PA4_MFP_Pos)            /*!< GPA_MFPL PA4 setting for SC2_PWR     */
#define SYS_GPA_MFPL_PA4_MFP_SPI3_CLK      (0x2UL<<SYS_GPA_MFPL_PA4_MFP_Pos)            /*!< GPA_MFPL PA4 setting for SPI3_CLK    */
#define SYS_GPA_MFPL_PA4_MFP_I2S0_DI       (0x3UL<<SYS_GPA_MFPL_PA4_MFP_Pos)            /*!< GPA_MFPL PA4 setting for I2S0_DI     */
#define SYS_GPA_MFPL_PA4_MFP_QEI1_Z        (0x5UL<<SYS_GPA_MFPL_PA4_MFP_Pos)            /*!< GPA_MFPL PA4 setting for QEI1_Z      */
#define SYS_GPA_MFPL_PA4_MFP_EBI_A14       (0x7UL<<SYS_GPA_MFPL_PA4_MFP_Pos)            /*!< GPA_MFPL PA4 setting for EBI_A14     */
#define SYS_GPA_MFPL_PA4_MFP_ECAP1_IC2      (0x8UL<<SYS_GPA_MFPL_PA4_MFP_Pos)             /*!< GPA_MFPL PA4 setting for ECAP1_IC2   */

//GPA_MFPL_PA5_MFP
#define SYS_GPA_MFPL_PA5_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA5_MFP_Pos)           /*!< GPA_MFPL PA5 setting for GPIO     */
#define SYS_GPA_MFPL_PA5_MFP_SC2_RST       (0x1UL<<SYS_GPA_MFPL_PA5_MFP_Pos)            /*!< GPA_MFPL PA5 setting for SC2_RST     */
#define SYS_GPA_MFPL_PA5_MFP_SPI3_SS0      (0x2UL<<SYS_GPA_MFPL_PA5_MFP_Pos)            /*!< GPA_MFPL PA5 setting for SPI3_SS0    */
#define SYS_GPA_MFPL_PA5_MFP_I2S0_BCLK    (0x3UL<<SYS_GPA_MFPL_PA5_MFP_Pos)          /*!< GPA_MFPL PA5 setting for I2S0_BCLK    */
#define SYS_GPA_MFPL_PA5_MFP_PWM0_CH0       (0x4UL<<SYS_GPA_MFPL_PA5_MFP_Pos)            /*!< GPA_MFPL PA5 setting for PWM0 CH0     */
#define SYS_GPA_MFPL_PA5_MFP_QEI1_B      (0x5UL<<SYS_GPA_MFPL_PA5_MFP_Pos)            /*!< GPA_MFPL PA5 setting for QEI1_B    */
#define SYS_GPA_MFPL_PA5_MFP_EBIA15      (0x7UL<<SYS_GPA_MFPL_PA5_MFP_Pos)            /*!< GPA_MFPL PA5 setting for EBIA15    */
#define SYS_GPA_MFPL_PA5_MFP_ECAP1_IC1      (0x8UL<<SYS_GPA_MFPL_PA5_MFP_Pos)            /*!< GPA_MFPL PA5 setting for ECAP1_IC1    */

//GPA_MFPL_PA6_MFP
#define SYS_GPA_MFPL_PA6_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for GPIO     */
#define SYS_GPA_MFPL_PA6_MFP_SC2_CD      (0x1UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for SC2_CD     */
#define SYS_GPA_MFPL_PA6_MFP_I2S0_LRCK       (0x3UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for I2S0_LRCK    */
#define SYS_GPA_MFPL_PA6_MFP_PWM0_CH1       (0x4UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for PWM1 CH1    */
#define SYS_GPA_MFPL_PA6_MFP_QEI1_A      (0x5UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for QEI1_A     */
#define SYS_GPA_MFPL_PA6_MFP_CAN1_TXD     (0x6UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for CAN1_TXD    */
#define SYS_GPA_MFPL_PA6_MFP_EBI_A16     (0x7UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for EBI_A16    */
#define SYS_GPA_MFPL_PA6_MFP_ECAP1_IC0       (0x8UL<<SYS_GPA_MFPL_PA6_MFP_Pos)           /*!< GPA_MFPL PA6 setting for ECAP1_IC0    */

//GPA_MFPL_PA7_MFP
#define SYS_GPA_MFPL_PA7_MFP_GPIO      (0x0UL<<SYS_GPA_MFPL_PA7_MFP_Pos)           /*!< GPA_MFPL PA7 setting for GPIO     */
#define SYS_GPA_MFPL_PA7_MFP_SC0_CLK       (0x2UL<<SYS_GPA_MFPL_PA7_MFP_Pos)           /*!< GPA_MFPL PA7 setting for SC0_CLK    */
#define SYS_GPA_MFPL_PA7_MFP_SPI3_SS0      (0x3UL<<SYS_GPA_MFPL_PA7_MFP_Pos)           /*!< GPA_MFPL PA7 setting for SPI3_SS0     */
#define SYS_GPA_MFPL_PA7_MFP_PWM1_CH3       (0x4UL<<SYS_GPA_MFPL_PA7_MFP_Pos)          /*!< GPA_MFPL PA7 setting for PWM1 CH3     */
#define SYS_GPA_MFPL_PA7_MFP_EPWM0_CH5      (0x5UL<<SYS_GPA_MFPL_PA7_MFP_Pos)           /*!< GPA_MFPL PA7 setting for EPWM0 CH5     */
#define SYS_GPA_MFPL_PA7_MFP_EBI_A17      (0x7UL<<SYS_GPA_MFPL_PA7_MFP_Pos)           /*!< GPA_MFPL PA7 setting for EBI_A17     */

//GPA_MFPL_PA8_MFP
#define SYS_GPA_MFPH_PA8_MFP_GPIO      (0x0UL<<SYS_GPA_MFPH_PA8_MFP_Pos)           /*!< GPA_MFPH PA8 setting for GPIO     */
#define SYS_GPA_MFPH_PA8_MFP_SC0_RST       (0x2UL<<SYS_GPA_MFPH_PA8_MFP_Pos)           /*!< GPA_MFPH PA8 setting for SC0_RST    */
#define SYS_GPA_MFPH_PA8_MFP_SPI3_CLK      (0x3UL<<SYS_GPA_MFPH_PA8_MFP_Pos)           /*!< GPA_MFPH PA8 setting for SPI3_CLK     */
#define SYS_GPA_MFPH_PA8_MFP_PWM1_CH2       (0x4UL<<SYS_GPA_MFPH_PA8_MFP_Pos)           /*!< GPA_MFPH PA8 setting for PWM1 CH2    */
#define SYS_GPA_MFPH_PA8_MFP_EPWM0_CH4      (0x5UL<<SYS_GPA_MFPH_PA8_MFP_Pos)           /*!< GPA_MFPH PA8 setting for EPWM0_CH4     */
#define SYS_GPA_MFPH_PA8_MFP_EBI_A18       (0x7UL<<SYS_GPA_MFPH_PA8_MFP_Pos)           /*!< GPA_MFPH PA8 setting for EBI_A18    */

//GPA_MFPH_PA9_MFP
#define SYS_GPA_MFPH_PA9_MFP_GPIO      (0x0UL<<SYS_GPA_MFPH_PA9_MFP_Pos)           /*!< GPA_MFPH PA9 setting for GPIO     */
#define SYS_GPA_MFPH_PA9_MFP_SC0_PWR       (0x2UL<<SYS_GPA_MFPH_PA9_MFP_Pos)           /*!< GPA_MFPH PA9 setting for SC0_PWR    */
#define SYS_GPA_MFPH_PA9_MFP_SPI3_MISO0      (0x3UL<<SYS_GPA_MFPH_PA9_MFP_Pos)           /*!< GPA_MFPH PA9 setting for SPI3_MISO0     */
#define SYS_GPA_MFPH_PA9_MFP_PWM1_CH1       (0x4UL<<SYS_GPA_MFPH_PA9_MFP_Pos)           /*!< GPA_MFPH PA9 setting for PWM1 CH1    */
#define SYS_GPA_MFPH_PA9_MFP_EPWM0_CH3      (0x5UL<<SYS_GPA_MFPH_PA9_MFP_Pos)           /*!< GPA_MFPH PA9 setting for EPWM0 CH3     */
#define SYS_GPA_MFPH_PA9_MFP_EBI_A19       (0x7UL<<SYS_GPA_MFPH_PA9_MFP_Pos)           /*!< GPA_MFPH PA9 setting for EBI_A19    */

//GPA_MFPH_PA10_MFP
#define SYS_GPA_MFPH_PA10_MFP_GPIO       (0x0UL<<SYS_GPA_MFPH_PA10_MFP_Pos)           /*!< GPA_MFPH PA10 setting for GPIO   */
#define SYS_GPA_MFPH_PA10_MFP_SC0_DAT        (0x2UL<<SYS_GPA_MFPH_PA10_MFP_Pos)           /*!< GPA_MFPH PA10 setting for SC0_DAT  */
#define SYS_GPA_MFPH_PA10_MFP_SPI3_MOSI0       (0x3UL<<SYS_GPA_MFPH_PA10_MFP_Pos)           /*!< GPA_MFPH PA10 setting for SPI3_MOSI0   */
#define SYS_GPA_MFPH_PA10_MFP_PWM1_CH0        (0x4UL<<SYS_GPA_MFPH_PA10_MFP_Pos)           /*!< GPA_MFPH PA10 setting for PWM1_CH0  */
#define SYS_GPA_MFPH_PA10_MFP_EPWM0_CH2       (0x5UL<<SYS_GPA_MFPH_PA10_MFP_Pos)           /*!< GPA_MFPH PA10 setting for EPWM0_CH2   */
#define SYS_GPA_MFPH_PA10_MFP_EBI_A20        (0x7UL<<SYS_GPA_MFPH_PA10_MFP_Pos)           /*!< GPA_MFPH PA10 setting for EBI_A20  */

//GPA_MFPH_PA11_MFP
#define SYS_GPA_MFPH_PA11_MFP_GPIO       (0x0UL<<SYS_GPA_MFPH_PA11_MFP_Pos)           /*!< GPA_MFPH PA11 setting for GPIO   */
#define SYS_GPA_MFPH_PA11_MFP_UART0_RTS       (0x1UL<<SYS_GPA_MFPH_PA11_MFP_Pos)           /*!< GPA_MFPH PA11 setting for UART0_RTS   */
#define SYS_GPA_MFPH_PA11_MFP_SPI3_MISO1       (0x3UL<<SYS_GPA_MFPH_PA11_MFP_Pos)           /*!< GPA_MFPH PA11 setting for SPI3_MISO1   */
#define SYS_GPA_MFPH_PA11_MFP_PWM0_CH5       (0x4UL<<SYS_GPA_MFPH_PA11_MFP_Pos)           /*!< GPA_MFPH PA11 setting for PWM0_CH5   */
#define SYS_GPA_MFPH_PA11_MFP_EPWM0_CH1       (0x5UL<<SYS_GPA_MFPH_PA11_MFP_Pos)           /*!< GPA_MFPH PA11 setting for EPWM0_CH1   */
#define SYS_GPA_MFPH_PA11_MFP_EBI_AD0       (0x7UL<<SYS_GPA_MFPH_PA11_MFP_Pos)           /*!< GPA_MFPH PA11 setting for EBI_AD0   */

//GPA_MFPH_PA12_MFP
#define SYS_GPA_MFPH_PA12_MFP_GPIO       (0x0UL<<SYS_GPA_MFPH_PA12_MFP_Pos)           /*!< GPA_MFPH PA12 setting for GPIO   */
#define SYS_GPA_MFPH_PA12_MFP_UART0_CTS       (0x1UL<<SYS_GPA_MFPH_PA12_MFP_Pos)           /*!< GPA_MFPH PA12 setting for UART0_CTS   */
#define SYS_GPA_MFPH_PA12_MFP_SPI3_MOSI1       (0x3UL<<SYS_GPA_MFPH_PA12_MFP_Pos)           /*!< GPA_MFPH PA12 setting for SPI3_MOSI1   */
#define SYS_GPA_MFPH_PA12_MFP_PWM0_CH4       (0x4UL<<SYS_GPA_MFPH_PA12_MFP_Pos)           /*!< GPA_MFPH PA12 setting for PWM0_CH4   */
#define SYS_GPA_MFPH_PA12_MFP_EPWM0_CH0       (0x5UL<<SYS_GPA_MFPH_PA12_MFP_Pos)           /*!< GPA_MFPH PA12 setting for EPWM0_CH0   */
#define SYS_GPA_MFPH_PA12_MFP_EBI_AD1       (0x7UL<<SYS_GPA_MFPH_PA12_MFP_Pos)           /*!< GPA_MFPH PA12 setting for EBI_AD1   */

//GPA_MFPH_PA13_MFP
#define SYS_GPA_MFPH_PA13_MFP_GPIO       (0x0UL<<SYS_GPA_MFPH_PA13_MFP_Pos)           /*!< GPA_MFPH PA13 setting for GPIO   */
#define SYS_GPA_MFPH_PA13_MFP_UART0_RXD       (0x1UL<<SYS_GPA_MFPH_PA13_MFP_Pos)           /*!< GPA_MFPH PA13 setting for UART0_RXD   */
#define SYS_GPA_MFPH_PA13_MFP_SC3_DAT       (0x3UL<<SYS_GPA_MFPH_PA13_MFP_Pos)           /*!< GPA_MFPH PA13 setting for SC3_DAT   */
#define SYS_GPA_MFPH_PA13_MFP_PWM1_CH4       (0x4UL<<SYS_GPA_MFPH_PA13_MFP_Pos)           /*!< GPA_MFPH PA13 setting for PWM1_CH4   */
#define SYS_GPA_MFPH_PA13_MFP_EBI_AD2       (0x7UL<<SYS_GPA_MFPH_PA13_MFP_Pos)           /*!< GPA_MFPH PA13 setting for EBI_AD2   */

//GPA_MFPH_PA14_MFP
#define SYS_GPA_MFPH_PA14_MFP_GPIO       (0x0UL<<SYS_GPA_MFPH_PA14_MFP_Pos)           /*!< GPA_MFPH PA14 setting for GPIO   */
#define SYS_GPA_MFPH_PA14_MFP_UART0_TXD       (0x1UL<<SYS_GPA_MFPH_PA14_MFP_Pos)           /*!< GPA_MFPH PA14 setting for UART0_TXD   */
#define SYS_GPA_MFPH_PA14_MFP_SC3_CLK       (0x3UL<<SYS_GPA_MFPH_PA14_MFP_Pos)           /*!< GPA_MFPH PA14 setting for SC3_CLK   */
#define SYS_GPA_MFPH_PA14_MFP_PWM1_CH5       (0x4UL<<SYS_GPA_MFPH_PA14_MFP_Pos)           /*!< GPA_MFPH PA14 setting for PWM1_CH5   */
#define SYS_GPA_MFPH_PA14_MFP_EBI_AD3       (0x7UL<<SYS_GPA_MFPH_PA14_MFP_Pos)           /*!< GPA_MFPH PA14 setting for EBI_AD3   */
//GPA_MFPH_PA15_MFP
#define SYS_GPA_MFPH_PA15_MFP_GPIO       (0x0UL<<SYS_GPA_MFPH_PA15_MFP_Pos)           /*!< GPA_MFPH PA15 setting for GPIO   */
#define SYS_GPA_MFPH_PA15_MFP_SC3_PWR       (0x1UL<<SYS_GPA_MFPH_PA15_MFP_Pos)           /*!< GPA_MFPH PA15 setting for SC3_PWR   */
#define SYS_GPA_MFPH_PA15_MFP_UART2_RTS       (0x2UL<<SYS_GPA_MFPH_PA15_MFP_Pos)           /*!< GPA_MFPH PA15 setting for UART2_RTS   */
#define SYS_GPA_MFPH_PA15_MFP_I2C0_SCL       (0x4UL<<SYS_GPA_MFPH_PA15_MFP_Pos)           /*!< GPA_MFPH PA15 setting for I2C0_SCL   */
#define SYS_GPA_MFPH_PA15_MFP_EBI_A21       (0x7UL<<SYS_GPA_MFPH_PA15_MFP_Pos)           /*!< GPA_MFPH PA15 setting for EBI_A21   */


//GPB_MFPL_PB0_MFP
#define SYS_GPB_MFPL_PB0_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB0_MFP_Pos)           /*!< GPB_MFPL PB0 setting for GPIO     */
#define SYS_GPB_MFPL_PB0_MFP_USB0_OTG5V_ST       (0x1UL<<SYS_GPB_MFPL_PB0_MFP_Pos)           /*!< GPB_MFPL PB0 setting for USB0_OTG5V_ST    */
#define SYS_GPB_MFPL_PB0_MFP_I2C4_SCL      (0x2UL<<SYS_GPB_MFPL_PB0_MFP_Pos)           /*!< GPB_MFPL PB0 setting for I2C4_SCL     */
#define SYS_GPB_MFPL_PB0_MFP_INT11       (0x8UL<<SYS_GPB_MFPL_PB0_MFP_Pos)           /*!< GPB_MFPL PB0 setting for INT11    */

//GPB_MFPL_PB1_MFP
#define SYS_GPB_MFPL_PB1_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB1_MFP_Pos)           /*!< GPB_MFPL PB1 setting for GPIO     */
#define SYS_GPB_MFPL_PB1_MFP_USB0_OTG5V_EN       (0x1UL<<SYS_GPB_MFPL_PB1_MFP_Pos)           /*!< GPB_MFPL PB1 setting for USB0_OTG5V_EN    */
#define SYS_GPB_MFPL_PB1_MFP_I2C4_SDA      (0x2UL<<SYS_GPB_MFPL_PB1_MFP_Pos)           /*!< GPB_MFPL PB1 setting for I2C4_SDA     */
#define SYS_GPB_MFPL_PB1_MFP_TM1_CNT_OUT       (0x3UL<<SYS_GPB_MFPL_PB1_MFP_Pos)           /*!< GPB_MFPL PB1 setting for TM1_CNT_OUT    */

//GPB_MFPL_PB2_MFP
#define SYS_GPB_MFPL_PB2_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB2_MFP_Pos)           /*!< GPB_MFPL PB2 setting for GPIO     */
#define SYS_GPB_MFPL_PB2_MFP_UART1_RXD       (0x1UL<<SYS_GPB_MFPL_PB2_MFP_Pos)           /*!< GPB_MFPL PB2 setting for UART1_RXD    */
#define SYS_GPB_MFPL_PB2_MFP_SPI2_SS0      (0x2UL<<SYS_GPB_MFPL_PB2_MFP_Pos)           /*!< GPB_MFPL PB2 setting for SPI2_SS0     */
#define SYS_GPB_MFPL_PB2_MFP_USB1_D_N      (0x3UL<<SYS_GPB_MFPL_PB2_MFP_Pos)           /*!< GPB_MFPL PB2 setting for USB1_D_N     */
#define SYS_GPB_MFPL_PB2_MFP_EBI_AD4       (0x7UL<<SYS_GPB_MFPL_PB2_MFP_Pos)           /*!< GPB_MFPL PB2 setting for EBI_AD4    */

//GPB_MFPL_PB3_MFP
#define SYS_GPB_MFPL_PB3_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB3_MFP_Pos)           /*!< GPB_MFPL PB3 setting for GPIO     */
#define SYS_GPB_MFPL_PB3_MFP_UART1_TXD       (0x1UL<<SYS_GPB_MFPL_PB3_MFP_Pos)           /*!< GPB_MFPL PB3 setting for UART1_TXD    */
#define SYS_GPB_MFPL_PB3_MFP_SPI2_CLK      (0x2UL<<SYS_GPB_MFPL_PB3_MFP_Pos)           /*!< GPB_MFPL PB3 setting for SPI2_CLK     */
#define SYS_GPB_MFPL_PB3_MFP_USB1_D_P      (0x3UL<<SYS_GPB_MFPL_PB3_MFP_Pos)           /*!< GPB_MFPL PB3 setting for USB1_D_P     */
#define SYS_GPB_MFPL_PB3_MFP_EBI_AD5       (0x7UL<<SYS_GPB_MFPL_PB3_MFP_Pos)           /*!< GPB_MFPL PB3 setting for EBI_AD5    */

//GPB_MFPL_PB4_MFP
#define SYS_GPB_MFPL_PB4_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB4_MFP_Pos)           /*!< GPB_MFPL PB4 setting for GPIO     */
#define SYS_GPB_MFPL_PB4_MFP_UART1_RTS       (0x1UL<<SYS_GPB_MFPL_PB4_MFP_Pos)           /*!< GPB_MFPL PB4 setting for UART1_RTS    */
#define SYS_GPB_MFPL_PB4_MFP_SPI2_MISO0      (0x2UL<<SYS_GPB_MFPL_PB4_MFP_Pos)           /*!< GPB_MFPL PB4 setting for SPI2_MISO0     */
#define SYS_GPB_MFPL_PB4_MFP_UART4_RXD       (0x3UL<<SYS_GPB_MFPL_PB4_MFP_Pos)           /*!< GPB_MFPL PB4 setting for UART4_RXD    */
#define SYS_GPB_MFPL_PB4_MFP_TM0_CNT_OUT       (0x4UL<<SYS_GPB_MFPL_PB4_MFP_Pos)           /*!< GPB_MFPL PB4 setting for TM0_CNT_OUT      */
#define SYS_GPB_MFPL_PB4_MFP_EBI_AD6       (0x7UL<<SYS_GPB_MFPL_PB4_MFP_Pos)           /*!< GPB_MFPL PB4 setting for EBI_AD6    */

//GPB_MFPL_PB5_MFP
#define SYS_GPB_MFPL_PB5_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB5_MFP_Pos)           /*!< GPB_MFPL PB5 setting for GPIO     */
#define SYS_GPB_MFPL_PB5_MFP_UART1_CTS       (0x1UL<<SYS_GPB_MFPL_PB5_MFP_Pos)           /*!< GPB_MFPL PB5 setting for UART1_CTS    */
#define SYS_GPB_MFPL_PB5_MFP_SPI2_MOSI0      (0x2UL<<SYS_GPB_MFPL_PB5_MFP_Pos)           /*!< GPB_MFPL PB5 setting for SPI2_MOSI0     */
#define SYS_GPB_MFPL_PB5_MFP_UART4_TXD       (0x3UL<<SYS_GPB_MFPL_PB5_MFP_Pos)           /*!< GPB_MFPL PB5 setting for UART4_TXD    */
#define SYS_GPB_MFPL_PB5_MFP_EBI_AD7       (0x7UL<<SYS_GPB_MFPL_PB5_MFP_Pos)           /*!< GPB_MFPL PB5 setting for EBI_AD7    */

//GPB_MFPL_PB6_MFP
#define SYS_GPB_MFPL_PB6_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB6_MFP_Pos)           /*!< GPB_MFPL PB6 setting for GPIO     */
#define SYS_GPB_MFPL_PB6_MFP_I2C2_SCL      (0x1UL<<SYS_GPB_MFPL_PB6_MFP_Pos)           /*!< GPB_MFPL PB6 setting for I2C2_SCL     */
#define SYS_GPB_MFPL_PB6_MFP_BRAKE01       (0x2UL<<SYS_GPB_MFPL_PB6_MFP_Pos)           /*!< GPB_MFPL PB6 setting for BRAKE01      */
#define SYS_GPB_MFPL_PB6_MFP_UART4_RTS       (0x3UL<<SYS_GPB_MFPL_PB6_MFP_Pos)           /*!< GPB_MFPL PB6 setting for UART4_RTS    */
#define SYS_GPB_MFPL_PB6_MFP_PWM1_CH4       (0x4UL<<SYS_GPB_MFPL_PB6_MFP_Pos)          /*!< GPB_MFPL PB6 setting for PWM1_CH4     */
#define SYS_GPB_MFPL_PB6_MFP_EPWM1_CH0      (0x5UL<<SYS_GPB_MFPL_PB6_MFP_Pos)           /*!< GPB_MFPL PB6 setting for EPWM1_CH0     */
#define SYS_GPB_MFPL_PB6_MFP_EBI_AD8       (0x7UL<<SYS_GPB_MFPL_PB6_MFP_Pos)           /*!< GPB_MFPL PB6 setting for EBI_AD8    */

//GPB_MFPL_PB7_MFP
#define SYS_GPB_MFPL_PB7_MFP_GPIO      (0x0UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for GPIO     */
#define SYS_GPB_MFPL_PB7_MFP_I2C2_SDA      (0x1UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for I2C2_SDA     */
#define SYS_GPB_MFPL_PB7_MFP_BRAKE00       (0x2UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for BRAKE00    */
#define SYS_GPB_MFPL_PB7_MFP_UART4_CTS       (0x3UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for UART4_CTS    */
#define SYS_GPB_MFPL_PB7_MFP_PWM1_CH5       (0x4UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for PWM1_CH5    */
#define SYS_GPB_MFPL_PB7_MFP_EPWM1_CH1      (0x5UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for EPWM1_CH1     */
#define SYS_GPB_MFPL_PB7_MFP_ETM_TRACE_DATA3       (0x6UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for ETM_TRACE_DATA3    */
#define SYS_GPB_MFPL_PB7_MFP_EBI_AD9       (0x7UL<<SYS_GPB_MFPL_PB7_MFP_Pos)           /*!< GPB_MFPL PB7 setting for EBI_AD9    */

//GPB_MFPL_PB8_MFP
#define SYS_GPB_MFPH_PB8_MFP_GPIO      (0x0UL<<SYS_GPB_MFPH_PB8_MFP_Pos)           /*!< GPB_MFPH PB8 setting for GPIO     */
#define SYS_GPB_MFPH_PB8_MFP_UART5_CTS       (0x1UL<<SYS_GPB_MFPH_PB8_MFP_Pos)            /*!< GPB_MFPH PB8 setting for UART5_CTS     */
#define SYS_GPB_MFPH_PB8_MFP_EPWM1_CH2      (0x5UL<<SYS_GPB_MFPH_PB8_MFP_Pos)            /*!< GPB_MFPH PB8 setting for EPWM1_CH2    */
#define SYS_GPB_MFPH_PB8_MFP_ETM_TRACE_DATA2       (0x6UL<<SYS_GPB_MFPH_PB8_MFP_Pos)            /*!< GPB_MFPH PB8 setting for ETM_TRACE_DATA2     */
#define SYS_GPB_MFPH_PB8_MFP_EBI_AD10      (0x7UL<<SYS_GPB_MFPH_PB8_MFP_Pos)            /*!< GPB_MFPH PB8 setting for EBI_AD10    */

//GPB_MFPH_PB9_MFP
#define SYS_GPB_MFPH_PB9_MFP_GPIO      (0x0UL<<SYS_GPB_MFPH_PB9_MFP_Pos)            /*!< GPB_MFPH PB9 setting for GPIO    */
#define SYS_GPB_MFPH_PB9_MFP_UART5_RTS       (0x1UL<<SYS_GPB_MFPH_PB9_MFP_Pos)           /*!< GPB_MFPH PB9 setting for UART5_RTS    */
#define SYS_GPB_MFPH_PB9_MFP_EPWM1_CH3      (0x5UL<<SYS_GPB_MFPH_PB9_MFP_Pos)           /*!< GPB_MFPH PB9 setting for EPWM1_CH3     */
#define SYS_GPB_MFPH_PB9_MFP_ETM_TRACE_DATA1       (0x6UL<<SYS_GPB_MFPH_PB9_MFP_Pos)           /*!< GPB_MFPH PB9 setting for ETM_TRACE_DATA1      */
#define SYS_GPB_MFPH_PB9_MFP_EBI_AD11      (0x7UL<<SYS_GPB_MFPH_PB9_MFP_Pos)           /*!< GPB_MFPH PB9 setting for EBI_AD11     */

//GPB_MFPH_PB10_MFP
#define SYS_GPB_MFPH_PB10_MFP_GPIO       (0x0UL<<SYS_GPB_MFPH_PB10_MFP_Pos)           /*!< GPB_MFPH PB10 setting for GPIO   */
#define SYS_GPB_MFPH_PB10_MFP_UART5_TXD        (0x1UL<<SYS_GPB_MFPH_PB10_MFP_Pos)           /*!< GPB_MFPH PB10 setting for UART5_TXD  */
#define SYS_GPB_MFPH_PB10_MFP_EPWM1_CH4       (0x5UL<<SYS_GPB_MFPH_PB10_MFP_Pos)           /*!< GPB_MFPH PB10 setting for EPWM1_CH4   */
#define SYS_GPB_MFPH_PB10_MFP_ETM_TRACE_DATA0        (0x6UL<<SYS_GPB_MFPH_PB10_MFP_Pos)           /*!< GPB_MFPH PB10 setting for ETM_TRACE_DATA0  */
#define SYS_GPB_MFPH_PB10_MFP_EBI_AD12       (0x7UL<<SYS_GPB_MFPH_PB10_MFP_Pos)           /*!< GPB_MFPH PB10 setting for EBI_AD12   */

//GPB_MFPH_PB11_MFP
#define SYS_GPB_MFPH_PB11_MFP_GPIO       (0x0UL<<SYS_GPB_MFPH_PB11_MFP_Pos)           /*!< GPB_MFPH PB11 setting for GPIO   */
#define SYS_GPB_MFPH_PB11_MFP_UART5_RXD       (0x1UL<<SYS_GPB_MFPH_PB11_MFP_Pos)           /*!< GPB_MFPH PB11 setting for UART5_RXD   */
#define SYS_GPB_MFPH_PB11_MFP_EPWM1_CH5       (0x5UL<<SYS_GPB_MFPH_PB11_MFP_Pos)           /*!< GPB_MFPH PB11 setting for EPWM1_CH5   */
#define SYS_GPB_MFPH_PB11_MFP_ETM_TRACE_CLK       (0x6UL<<SYS_GPB_MFPH_PB11_MFP_Pos)           /*!< GPB_MFPH PB11 setting for ETM_TRACE_CLK   */
#define SYS_GPB_MFPH_PB11_MFP_EBI_AD13       (0x7UL<<SYS_GPB_MFPH_PB11_MFP_Pos)           /*!< GPB_MFPH PB11 setting for EBI_AD13   */

//GPB_MFPH_PB12_MFP
#define SYS_GPB_MFPH_PB12_MFP_GPIO       (0x0UL<<SYS_GPB_MFPH_PB12_MFP_Pos)           /*!< GPB_MFPH PB12 setting for GPIO   */
#define SYS_GPB_MFPH_PB12_MFP_UART4_RTS       (0x1UL<<SYS_GPB_MFPH_PB12_MFP_Pos)           /*!< GPB_MFPH PB12 setting for UART4_RTS   */
#define SYS_GPB_MFPH_PB12_MFP_SPI2_MISO1       (0x2UL<<SYS_GPB_MFPH_PB12_MFP_Pos)           /*!< GPB_MFPH PB12 setting for _SPI2_MISO1  */
#define SYS_GPB_MFPH_PB12_MFP_CAN0_RXD       (0x3UL<<SYS_GPB_MFPH_PB12_MFP_Pos)           /*!< GPB_MFPH PB12 setting for CAN0_RXD   */
#define SYS_GPB_MFPH_PB12_MFP_EMAC_MII_MDC       (0x6UL<<SYS_GPB_MFPH_PB12_MFP_Pos)           /*!< GPB_MFPH PB12 setting for EMAC_MII_MDC   */
#define SYS_GPB_MFPH_PB12_MFP_EBI_AD14       (0x7UL<<SYS_GPB_MFPH_PB12_MFP_Pos)           /*!< GPB_MFPH PB12 setting for EBI_AD4  */

//GPB_MFPH_PB13_MFP
#define SYS_GPB_MFPH_PB13_MFP_GPIO       (0x0UL<<SYS_GPB_MFPH_PB13_MFP_Pos)           /*!< GPB_MFPH PB13 setting for GPIO   */
#define SYS_GPB_MFPH_PB13_MFP_UART4_CTS       (0x1UL<<SYS_GPB_MFPH_PB13_MFP_Pos)           /*!< GPB_MFPH PB13 setting for UART4_CTS   */
#define SYS_GPB_MFPH_PB13_MFP_SPI2_MOSI1       (0x2UL<<SYS_GPB_MFPH_PB13_MFP_Pos)           /*!< GPB_MFPH PB13 setting for SPI2_MOSI1   */
#define SYS_GPB_MFPH_PB13_MFP_CAN0_TXD       (0x3UL<<SYS_GPB_MFPH_PB13_MFP_Pos)           /*!< GPB_MFPH PB13 setting for CAN0_TXD   */
#define SYS_GPB_MFPH_PB13_MFP_EMAC_MII_MDIO       (0x6UL<<SYS_GPB_MFPH_PB13_MFP_Pos)           /*!< GPB_MFPH PB13 setting for EMAC_MII_MDIO   */
#define SYS_GPB_MFPH_PB13_MFP_EBI_AD15       (0x7UL<<SYS_GPB_MFPH_PB13_MFP_Pos)           /*!< GPB_MFPH PB13 setting for EBI_AD15   */

//GPB_MFPH_PB14_MFP
#define SYS_GPB_MFPH_PB14_MFP_GPIO       (0x0UL<<SYS_GPB_MFPH_PB14_MFP_Pos)           /*!< GPB_MFPH PB14 setting for GPIO   */
#define SYS_GPB_MFPH_PB14_MFP_I2S1_MCLK       (0x1UL<<SYS_GPB_MFPH_PB14_MFP_Pos)           /*!< GPB_MFPH PB14 setting for I2S1_MCLK   */
#define SYS_GPB_MFPH_PB14_MFP_SC1_RST       (0x2UL<<SYS_GPB_MFPH_PB14_MFP_Pos)           /*!< GPB_MFPH PB14 setting for SC1_RST   */
#define SYS_GPB_MFPH_PB14_MFP_BRAKE01       (0x4UL<<SYS_GPB_MFPH_PB14_MFP_Pos)           /*!< GPB_MFPH PB14 setting for BRAKE01   */
#define SYS_GPB_MFPH_PB14_MFP_EMAC_MII_MDC       (0x6UL<<SYS_GPB_MFPH_PB14_MFP_Pos)           /*!< GPB_MFPH PB14 setting for EMAC_MII_MDC   */

//GPB_MFPH_PB15_MFP
#define SYS_GPB_MFPH_PB15_MFP_GPIO       (0x0UL<<SYS_GPB_MFPH_PB15_MFP_Pos)           /*!< GPA_MFPH PB15 setting for GPIO   */
#define SYS_GPB_MFPH_PB15_MFP_I2S1_DO       (0x1UL<<SYS_GPB_MFPH_PB15_MFP_Pos)            /*!< GPA_MFPH PB15 setting for I2S1_DO  */
#define SYS_GPB_MFPH_PB15_MFP_SC1_DAT       (0x2UL<<SYS_GPB_MFPH_PB15_MFP_Pos)            /*!< GPA_MFPH PB15 setting for SC1_DAT  */
#define SYS_GPB_MFPH_PB15_MFP_BRAKE00      (0x4UL<<SYS_GPB_MFPH_PB15_MFP_Pos)            /*!< GPA_MFPH PB15 setting for BRAKE00   */
#define SYS_GPB_MFPH_PB15_MFP_EMAC_MII_MDIO       (0x6UL<<SYS_GPB_MFPH_PB15_MFP_Pos)            /*!< GPA_MFPH PB15 setting for EMAC_MII_MDIO  */


//GPC_MFPL_PC0_MFP
#define SYS_GPC_MFPL_PC0_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC0_MFP_Pos)           /*!< GPC_MFPL PC0 setting for GPIO     */
#define SYS_GPC_MFPL_PC0_MFP_I2S1_DI     (0x1UL<<SYS_GPC_MFPL_PC0_MFP_Pos)           /*!< GPC_MFPL PC0 setting for I2S1_D1    */
#define SYS_GPC_MFPL_PC0_MFP_SC1_DAT       (0x2UL<<SYS_GPC_MFPL_PC0_MFP_Pos)           /*!< GPC_MFPL PC0 setting for SC1_DAT    */
#define SYS_GPC_MFPL_PC0_MFP_UART4_RXD       (0x3UL<<SYS_GPC_MFPL_PC0_MFP_Pos)           /*!< GPC_MFPL PC0 setting for UART4_RXD    */
#define SYS_GPC_MFPL_PC0_MFP_EMAC_REFCLK       (0x6UL<<SYS_GPC_MFPL_PC0_MFP_Pos)           /*!< GPC_MFPL PC0 setting for EMAC_REFCLK    */
#define SYS_GPC_MFPL_PC0_MFP_EBI_MCLK      (0x7UL<<SYS_GPC_MFPL_PC0_MFP_Pos)           /*!< GPC_MFPL PC0 setting for EBI_MCLK     */
#define SYS_GPC_MFPL_PC0_MFP_INT2      (0x8UL<<SYS_GPC_MFPL_PC0_MFP_Pos)           /*!< GPC_MFPL PC0 setting for INT2     */


//GPC_MFPL_PC1_MFP
#define SYS_GPC_MFPL_PC1_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC1_MFP_Pos)           /*!< GPC_MFPL PC1 setting for GPIO     */
#define SYS_GPC_MFPL_PC1_MFP_I2S1_BCLK       (0x1UL<<SYS_GPC_MFPL_PC1_MFP_Pos)           /*!< GPC_MFPL PC1 setting for I2S1_BCLK    */
#define SYS_GPC_MFPL_PC1_MFP_SC1_CLK       (0x2UL<<SYS_GPC_MFPL_PC1_MFP_Pos)           /*!< GPC_MFPL PC1 setting for SC1_CLK    */
#define SYS_GPC_MFPL_PC1_MFP_UART4_TXD       (0x3UL<<SYS_GPC_MFPL_PC1_MFP_Pos)           /*!< GPC_MFPL PC1 setting for UART4_TXD      */
#define SYS_GPC_MFPL_PC1_MFP_TM3_CNT_OUT       (0x5UL<<SYS_GPC_MFPL_PC1_MFP_Pos)           /*!< GPC_MFPL PC1 setting for TM3_CNT_OUT    */
#define SYS_GPC_MFPL_PC1_MFP_EMAC_MII_RXERR      (0x6UL<<SYS_GPC_MFPL_PC1_MFP_Pos)           /*!< GPC_MFPL PC1 setting for EMAC_MII_RXERR     */
#define SYS_GPC_MFPL_PC1_MFP_EBI_AD13      (0x7UL<<SYS_GPC_MFPL_PC1_MFP_Pos)           /*!< GPC_MFPL PC1 setting for EBI_AD13     */

//GPC_MFPL_PC2_MFP
#define SYS_GPC_MFPL_PC2_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC2_MFP_Pos)           /*!< GPC_MFPL PC2 setting for GPIO     */
#define SYS_GPC_MFPL_PC2_MFP_I2S1_LRCK       (0x1UL<<SYS_GPC_MFPL_PC2_MFP_Pos)           /*!< GPC_MFPL PC2 setting for I2S1_LRCK    */
#define SYS_GPC_MFPL_PC2_MFP_SC1_PWR       (0x2UL<<SYS_GPC_MFPL_PC2_MFP_Pos)           /*!< GPC_MFPL PC2 setting for SC1_PWR    */
#define SYS_GPC_MFPL_PC2_MFP_UART4_RTS       (0x3UL<<SYS_GPC_MFPL_PC2_MFP_Pos)           /*!< GPC_MFPL PC2 setting for UART4_RTS    */
#define SYS_GPC_MFPL_PC2_MFP_SPI0_SS0      (0x4UL<<SYS_GPC_MFPL_PC2_MFP_Pos)           /*!< GPC_MFPL PC2 setting for SPI0_SS0     */
#define SYS_GPC_MFPL_PC2_MFP_EMAC_MII_RXDV       (0x6UL<<SYS_GPC_MFPL_PC2_MFP_Pos)           /*!< GPC_MFPL PC2 setting for EMAC_MII_RXDV    */
#define SYS_GPC_MFPL_PC2_MFP_EBI_AD12      (0x7UL<<SYS_GPC_MFPL_PC2_MFP_Pos)           /*!< GPC_MFPL PC2 setting for EBI_AD12     */

//GPC_MFPL_PC3_MFP
#define SYS_GPC_MFPL_PC3_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for GPIO     */
#define SYS_GPC_MFPL_PC3_MFP_I2S1_MCLK       (0x1UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for I2S1_MCLK    */
#define SYS_GPC_MFPL_PC3_MFP_SC1_CD      (0x2UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for SC1_CD     */
#define SYS_GPC_MFPL_PC3_MFP_UART4_CTS       (0x3UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for UART4_CTS    */
#define SYS_GPC_MFPL_PC3_MFP_SPI0_MISO1      (0x4UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for SPI0_MISO1     */
#define SYS_GPC_MFPL_PC3_MFP_QEI0_Z      (0x5UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for QEI0_Z     */
#define SYS_GPC_MFPL_PC3_MFP_EMAC_MII_RXD1       (0x6UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for EMAC_MII_RXD1    */
#define SYS_GPC_MFPL_PC3_MFP_EBI_AD11      (0x7UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for EBI_AD11     */
#define SYS_GPC_MFPL_PC3_MFP_ECAP0_IC2       (0x8UL<<SYS_GPC_MFPL_PC3_MFP_Pos)           /*!< GPC_MFPL PC3 setting for ECAP0_IC2    */

//GPC_MFPL_PC4_MFP
#define SYS_GPC_MFPL_PC4_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for GPIO     */
#define SYS_GPC_MFPL_PC4_MFP_I2S1_DO       (0x1UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for I2S1_DO    */
#define SYS_GPC_MFPL_PC4_MFP_SC1_RST       (0x2UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for SC1_RST    */
#define SYS_GPC_MFPL_PC4_MFP_SPI0_MOSI0      (0x4UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for SPI0_MOSI0     */
#define SYS_GPC_MFPL_PC4_MFP_QEI0_B      (0x5UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for QEI0_B     */
#define SYS_GPC_MFPL_PC4_MFP_EMAC_MII_RXD0       (0x6UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for EMAC_MII_RXD0    */
#define SYS_GPC_MFPL_PC4_MFP_EBI_AD10      (0x7UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for EBI_AD10     */
#define SYS_GPC_MFPL_PC4_MFP_ECAP0_IC1       (0x8UL<<SYS_GPC_MFPL_PC4_MFP_Pos)           /*!< GPC_MFPL PC4 setting for ECAP0_IC1    */

//GPC_MFPL_PC5_MFP
#define SYS_GPC_MFPL_PC5_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC5_MFP_Pos)           /*!< GPC_MFPL PC5 setting for GPIO     */
#define SYS_GPC_MFPL_PC5_MFP_CLK_O       (0x1UL<<SYS_GPC_MFPL_PC5_MFP_Pos)           /*!< GPC_MFPL PC5 setting for CLK_O    */
#define SYS_GPC_MFPL_PC5_MFP_QEI0_A      (0x5UL<<SYS_GPC_MFPL_PC5_MFP_Pos)           /*!< GPC_MFPL PC5 setting for QEI0_A     */
#define SYS_GPC_MFPL_PC5_MFP_EMAC_MII_RXCLK      (0x6UL<<SYS_GPC_MFPL_PC5_MFP_Pos)           /*!< GPC_MFPL PC5 setting for EMAC_MII_RXCLK     */
#define SYS_GPC_MFPL_PC5_MFP_EBI_MCLK      (0x7UL<<SYS_GPC_MFPL_PC5_MFP_Pos)           /*!< GPC_MFPL PC5 setting for EBI_MCLK     */
#define SYS_GPC_MFPL_PC5_MFP_ECAP0_IC0       (0x8UL<<SYS_GPC_MFPL_PC5_MFP_Pos)           /*!< GPC_MFPL PC5 setting for ECAP0_IC0    */

//GPC_MFPL_PC6_MFP
#define SYS_GPC_MFPL_PC6_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC6_MFP_Pos)           /*!< GPC_MFPL PC6 setting for GPIO     */
#define SYS_GPC_MFPL_PC6_MFP_TM2_EXT       (0x1UL<<SYS_GPC_MFPL_PC6_MFP_Pos)           /*!< GPC_MFPL PC6 setting for TM2_EXT    */
#define SYS_GPC_MFPL_PC6_MFP_SPI0_MISO0      (0x4UL<<SYS_GPC_MFPL_PC6_MFP_Pos)           /*!< GPC_MFPL PC6 setting for SPI0_MISO0     */
#define SYS_GPC_MFPL_PC6_MFP_TM2_CNT_OUT       (0x5UL<<SYS_GPC_MFPL_PC6_MFP_Pos)           /*!< GPC_MFPL PC6 setting for TM2_CNT_OUT    */
#define SYS_GPC_MFPL_PC6_MFP_EMAC_MII_TXD0       (0x6UL<<SYS_GPC_MFPL_PC6_MFP_Pos)           /*!< GPC_MFPL PC6 setting for EMAC_MII_TXD0    */
#define SYS_GPC_MFPL_PC6_MFP_EBI_AD9       (0x7UL<<SYS_GPC_MFPL_PC6_MFP_Pos)           /*!< GPC_MFPL PC6 setting for EBI_AD9    */

//GPC_MFPL_PC7_MFP
#define SYS_GPC_MFPL_PC7_MFP_GPIO      (0x0UL<<SYS_GPC_MFPL_PC7_MFP_Pos)           /*!< GPC_MFPL PC7 setting for GPIO     */
#define SYS_GPC_MFPL_PC7_MFP_TM1_EXT       (0x1UL<<SYS_GPC_MFPL_PC7_MFP_Pos)           /*!< GPC_MFPL PC7 setting for TM1_EXT    */
#define SYS_GPC_MFPL_PC7_MFP_SPI0_MOSI0      (0x4UL<<SYS_GPC_MFPL_PC7_MFP_Pos)           /*!< GPC_MFPL PC7 setting for SPI0_MOSI0     */
#define SYS_GPC_MFPL_PC7_MFP_EMAC_MII_TXD1       (0x6UL<<SYS_GPC_MFPL_PC7_MFP_Pos)           /*!< GPC_MFPL PC7 setting for EMAC_MII_TXD1    */
#define SYS_GPC_MFPL_PC7_MFP_EBI_AD8       (0x7UL<<SYS_GPC_MFPL_PC7_MFP_Pos)           /*!< GPC_MFPL PC7 setting for EBI_AD8    */

//GPC_MFPL_PC8_MFP
#define SYS_GPC_MFPH_PC8_MFP_GPIO      (0x0UL<<SYS_GPC_MFPH_PC8_MFP_Pos)           /*!< GPC_MFPH PC8 setting for GPIO     */
#define SYS_GPC_MFPH_PC8_MFP_TM0_EXT       (0x1UL<<SYS_GPC_MFPH_PC8_MFP_Pos)           /*!< GPC_MFPH PC8 setting for TM0_EXT    */
#define SYS_GPC_MFPH_PC8_MFP_SPI0_CLK      (0x4UL<<SYS_GPC_MFPH_PC8_MFP_Pos)           /*!< GPC_MFPH PC8 setting for SPI0_CLK     */
#define SYS_GPC_MFPH_PC8_MFP_EMAC_MII_TXEN       (0x6UL<<SYS_GPC_MFPH_PC8_MFP_Pos)           /*!< GPC_MFPH PC8 setting for EMAC_MII_TXEN    */

//GPC_MFPH_PC9_MFP
#define SYS_GPC_MFPH_PC9_MFP_GPIO      (0x0UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for GPIO     */
#define SYS_GPC_MFPH_PC9_MFP_STADC       (0x1UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for STADC    */
#define SYS_GPC_MFPH_PC9_MFP_UART2_CTS       (0x2UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for UART2_CTS    */
#define SYS_GPC_MFPH_PC9_MFP_SC3_RST       (0x3UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for SC3_RST    */
#define SYS_GPC_MFPH_PC9_MFP_SPI0_SDA      (0x4UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for SPI0_SDA     */
#define SYS_GPC_MFPH_PC9_MFP_CAP_DATA1       (0x5UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for CAP_DATA1    */
#define SYS_GPC_MFPH_PC9_MFP_I2C3_SCL      (0x6UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for I2C3_SCL     */
#define SYS_GPC_MFPH_PC9_MFP_EBI_A22       (0x7UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for EBI_A22    */
#define SYS_GPC_MFPH_PC9_MFP_SD1_DAT0      (0x8UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for SD1_DAT0     */
#define SYS_GPC_MFPH_PC9_MFP_EBI_A6      (0x9UL<<SYS_GPC_MFPH_PC9_MFP_Pos)           /*!< GPC_MFPH PC9 setting for EBI_A6     */
//GPC_MFPH_PC10_MFP
#define SYS_GPC_MFPH_PC10_MFP_GPIO       (0x0UL<<SYS_GPC_MFPH_PC10_MFP_Pos)           /*!< GPC_MFPH PC10 setting for GPIO   */
#define SYS_GPC_MFPH_PC10_MFP_SC3_CD       (0x1UL<<SYS_GPC_MFPH_PC10_MFP_Pos)           /*!< GPC_MFPH PC10 setting for SC3_CD   */
#define SYS_GPC_MFPH_PC10_MFP_UART2_RXD        (0x2UL<<SYS_GPC_MFPH_PC10_MFP_Pos)           /*!< GPC_MFPH PC10 setting for UART2_RXD  */
#define SYS_GPC_MFPH_PC10_MFP_PWM0_CH2        (0x4UL<<SYS_GPC_MFPH_PC10_MFP_Pos)           /*!< GPC_MFPH PC10 setting for PWM0_CH2  */
#define SYS_GPC_MFPH_PC10_MFP_EBI_A23        (0x6UL<<SYS_GPC_MFPH_PC10_MFP_Pos)           /*!< GPC_MFPH PC10 setting for EBI_A23  */
#define SYS_GPC_MFPH_PC10_MFP_EBI_AD2        (0x7UL<<SYS_GPC_MFPH_PC10_MFP_Pos)           /*!< GPC_MFPH PC10 setting for EBI_AD2  */

//GPC_MFPH_PC11_MFP
#define SYS_GPC_MFPH_PC11_MFP_GPIO       (0x0UL<<SYS_GPC_MFPH_PC11_MFP_Pos)           /*!< GPC_MFPH PC11 setting for GPIO   */
#define SYS_GPC_MFPH_PC11_MFP_UART2_TXD       (0x2UL<<SYS_GPC_MFPH_PC11_MFP_Pos)           /*!< GPC_MFPH PC11 setting for UART2_TXD   */
#define SYS_GPC_MFPH_PC11_MFP_PWM0_CH3       (0x4UL<<SYS_GPC_MFPH_PC11_MFP_Pos)           /*!< GPC_MFPH PC11 setting for PWM0_CH3   */
#define SYS_GPC_MFPH_PC11_MFP_EBI_A24       (0x6UL<<SYS_GPC_MFPH_PC11_MFP_Pos)           /*!< GPC_MFPH PC11 setting for EBI_A24   */
#define SYS_GPC_MFPH_PC11_MFP_EBI_AD3       (0x7UL<<SYS_GPC_MFPH_PC11_MFP_Pos)           /*!< GPC_MFPH PC11 setting for EBI_AD3   */

//GPC_MFPH_PC12_MFP
#define SYS_GPC_MFPH_PC12_MFP_GPIO       (0x0UL<<SYS_GPC_MFPH_PC12_MFP_Pos)           /*!< GPC_MFPH PC12 setting for GPIO   */
#define SYS_GPC_MFPH_PC12_MFP_SPI1_SS0       (0x1UL<<SYS_GPC_MFPH_PC12_MFP_Pos)           /*!< GPC_MFPH PC12 setting for SPI1_SS0   */
#define SYS_GPC_MFPH_PC12_MFP_SC4_CD       (0x2UL<<SYS_GPC_MFPH_PC12_MFP_Pos)           /*!< GPC_MFPH PC12 setting for SC4_CD   */
#define SYS_GPC_MFPH_PC12_MFP_SD1_CDn       (0x4UL<<SYS_GPC_MFPH_PC12_MFP_Pos)          /*!< GPC_MFPH PC12 setting for SD1_CDn  */
#define SYS_GPC_MFPH_PC12_MFP_CAP_DATA7       (0x5UL<<SYS_GPC_MFPH_PC12_MFP_Pos)           /*!< GPC_MFPH PC12 setting for CAP_DATA7   */
#define SYS_GPC_MFPH_PC12_MFP_ETM_TRACE_DATA3       (0x6UL<<SYS_GPC_MFPH_PC12_MFP_Pos)           /*!< GPC_MFPH PC12 setting for ETM_TRACE_DATA3   */
#define SYS_GPC_MFPH_PC12_MFP_EBI_A0       (0x7UL<<SYS_GPC_MFPH_PC12_MFP_Pos)           /*!< GPC_MFPH PC12 setting for MFP_EBI_A0   */

//GPC_MFPH_PC13_MFP
#define SYS_GPC_MFPH_PC13_MFP_GPIO       (0x0UL<<SYS_GPC_MFPH_PC13_MFP_Pos)           /*!< GPC_MFPH PC13 setting for GPIO   */
#define SYS_GPC_MFPH_PC13_MFP_SPI1_MOSI1       (0x1UL<<SYS_GPC_MFPH_PC13_MFP_Pos)           /*!< GPC_MFPH PC13 setting for SPI1_MOSI1   */
#define SYS_GPC_MFPH_PC13_MFP_SC4_RST       (0x2UL<<SYS_GPC_MFPH_PC13_MFP_Pos)           /*!< GPC_MFPH PC13 setting for SC4_RST   */
#define SYS_GPC_MFPH_PC13_MFP_SD1_CMD       (0x4UL<<SYS_GPC_MFPH_PC13_MFP_Pos)           /*!< GPC_MFPH PC13 setting for SD1_CMD   */
#define SYS_GPC_MFPH_PC13_MFP_CAP_DATA6       (0x5UL<<SYS_GPC_MFPH_PC13_MFP_Pos)           /*!< GPC_MFPH PC13 setting for CAP_DATA6   */
#define SYS_GPC_MFPH_PC13_MFP_ETM_TRACE_DATA2       (0x6UL<<SYS_GPC_MFPH_PC13_MFP_Pos)           /*!< GPC_MFPH PC13 setting for ETM_TRACE_DATA2   */
#define SYS_GPC_MFPH_PC13_MFP_EBI_A1       (0x7UL<<SYS_GPC_MFPH_PC13_MFP_Pos)           /*!< GPC_MFPH PC13 setting for EBI_A1   */

//GPC_MFPH_PC14_MFP
#define SYS_GPC_MFPH_PC14_MFP_GPIO       (0x0UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for GPIO   */
#define SYS_GPC_MFPH_PC14_MFP_SPI1_MISO1       (0x1UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for SPI1_MISO1   */
#define SYS_GPC_MFPH_PC14_MFP_SC4_PWR       (0x2UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for SC4_PWR   */
#define SYS_GPC_MFPH_PC14_MFP_TM3_EXT       (0x3UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for TM3_EXT   */
#define SYS_GPC_MFPH_PC14_MFP_SD1_CLK       (0x4UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for SD1_CLK   */
#define SYS_GPC_MFPH_PC14_MFP_CAP_DATA5       (0x5UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for CAP_DATA5   */
#define SYS_GPC_MFPH_PC14_MFP_ETM_TRACE_DATA1       (0x6UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for ETM_TRACE_DATA1   */
#define SYS_GPC_MFPH_PC14_MFP_EBI_A2       (0x7UL<<SYS_GPC_MFPH_PC14_MFP_Pos)           /*!< GPC_MFPH PC14 setting for EBI_A2   */

//GPC_MFPH_PC15_MFP
#define SYS_GPC_MFPH_PC15_MFP_GPIO       (0x0UL<<SYS_GPC_MFPH_PC15_MFP_Pos)           /*!< GPC_MFPH PC15 setting for GPIO   */
#define SYS_GPC_MFPH_PC15_MFP_SPI1_MOSI0       (0x1UL<<SYS_GPC_MFPH_PC15_MFP_Pos)           /*!< GPC_MFPH PC15 setting for SPI1_MOSI0   */
#define SYS_GPC_MFPH_PC15_MFP_SC4_DAT       (0x2UL<<SYS_GPC_MFPH_PC15_MFP_Pos)           /*!< GPC_MFPH PC15 setting for SC4_DAT   */
#define SYS_GPC_MFPH_PC15_MFP_SD1_DAT3       (0x4UL<<SYS_GPC_MFPH_PC15_MFP_Pos)           /*!< GPC_MFPH PC15 setting for SD1_DAT3   */
#define SYS_GPC_MFPH_PC15_MFP_CAP_DATA4       (0x5UL<<SYS_GPC_MFPH_PC15_MFP_Pos)           /*!< GPC_MFPH PC15 setting for CAP_DATA4   */
#define SYS_GPC_MFPH_PC15_MFP_ETM_TRACE_DATA0       (0x6UL<<SYS_GPC_MFPH_PC15_MFP_Pos)           /*!< GPC_MFPH PC15 setting for ETM_TRACE_DATA0   */
#define SYS_GPC_MFPH_PC15_MFP_EBI_A3       (0x7UL<<SYS_GPC_MFPH_PC15_MFP_Pos)           /*!< GPC_MFPH PC15 setting for EBI_A3   */

//GPD_MFPL_PD0_MFP
#define SYS_GPD_MFPL_PD0_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for GPIO     */
#define SYS_GPD_MFPL_PD0_MFP_SPI1_MISO0      (0x1UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for SPI1_MISO0     */
#define SYS_GPD_MFPL_PD0_MFP_SC4_CLK       (0x2UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for SC4_CLK    */
#define SYS_GPD_MFPL_PD0_MFP_SD1_DAT2      (0x4UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for SD1_DAT2     */
#define SYS_GPD_MFPL_PD0_MFP_CAP_DATA3       (0x5UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for CAP_DATA3    */
#define SYS_GPD_MFPL_PD0_MFP_ETM_TRACE_CLK       (0x6UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for ETM_TRACE_CLK    */
#define SYS_GPD_MFPL_PD0_MFP_EBI_A4      (0x7UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for EBI_A4     */
#define SYS_GPD_MFPL_PD0_MFP_INT3      (0x8UL<<SYS_GPD_MFPL_PD0_MFP_Pos)           /*!< GPD_MFPL PD0 setting for INT3     */

//GPD_MFPL_PD1_MFP
#define SYS_GPD_MFPL_PD1_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD1_MFP_Pos)           /*!< GPD_MFPL PD1 setting for GPIO     */
#define SYS_GPD_MFPL_PD1_MFP_SPI1_CLK      (0x1UL<<SYS_GPD_MFPL_PD1_MFP_Pos)           /*!< GPD_MFPL PD1 setting for SPI1_CLK     */
#define SYS_GPD_MFPL_PD1_MFP_TM0_CNT_OUT       (0x3UL<<SYS_GPD_MFPL_PD1_MFP_Pos)           /*!< GPD_MFPL PD1 setting for TM0_CNT_OUT      */
#define SYS_GPD_MFPL_PD1_MFP_SD1_DAT1      (0x4UL<<SYS_GPD_MFPL_PD1_MFP_Pos)           /*!< GPD_MFPL PD1 setting for SD1_DAT1     */
#define SYS_GPD_MFPL_PD1_MFP_CAP_DATA2       (0x5UL<<SYS_GPD_MFPL_PD1_MFP_Pos)           /*!< GPD_MFPL PD1 setting for CAP_DATA2    */
#define SYS_GPD_MFPL_PD1_MFP_EBI_A5      (0x7UL<<SYS_GPD_MFPL_PD1_MFP_Pos)           /*!< GPD_MFPL PD1 setting for EBI_A5     */

//GPD_MFPL_PD2_MFP
#define SYS_GPD_MFPL_PD2_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD2_MFP_Pos)           /*!< GPD_MFPL PD2 setting for GPIO     */
#define SYS_GPD_MFPL_PD2_MFP_STADC       (0x1UL<<SYS_GPD_MFPL_PD2_MFP_Pos)           /*!< GPD_MFPL PD2 setting for STADC    */
#define SYS_GPD_MFPL_PD2_MFP_I2C3_SCL      (0x2UL<<SYS_GPD_MFPL_PD2_MFP_Pos)           /*!< GPD_MFPL PD2 setting for I2C3_SCL     */
#define SYS_GPD_MFPL_PD2_MFP_SD1_DAT0      (0x4UL<<SYS_GPD_MFPL_PD2_MFP_Pos)           /*!< GPD_MFPL PD2 setting for SD1_DAT0     */
#define SYS_GPD_MFPL_PD2_MFP_CAP_DATA1       (0x5UL<<SYS_GPD_MFPL_PD2_MFP_Pos)           /*!< GPD_MFPL PD2 setting for CAP_DATA1    */
#define SYS_GPD_MFPL_PD2_MFP_EBI_A6      (0x7UL<<SYS_GPD_MFPL_PD2_MFP_Pos)           /*!< GPD_MFPL PD2 setting for EBI_A6     */

//GPD_MFPL_PD3_MFP
#define SYS_GPD_MFPL_PD3_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for GPIO     */
#define SYS_GPD_MFPL_PD3_MFP_SC5_CLK       (0x1UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for SC5_CLK    */
#define SYS_GPD_MFPL_PD3_MFP_I2C3_SDA      (0x2UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for I2C3_SDA     */
#define SYS_GPD_MFPL_PD3_MFP_ACMP2_O       (0x3UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for ACMP2_O    */
#define SYS_GPD_MFPL_PD3_MFP_SD1_CDn       (0x4UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for SD1_CDn    */
#define SYS_GPD_MFPL_PD3_MFP_CAP_DATA0       (0x5UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for CAP_DATA0    */
#define SYS_GPD_MFPL_PD3_MFP_JTAG_TDO      (0x6UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for JTAG_TDO     */
#define SYS_GPD_MFPL_PD3_MFP_EBI_A7      (0x7UL<<SYS_GPD_MFPL_PD3_MFP_Pos)           /*!< GPD_MFPL PD3 setting for EBI_A7     */

//GPD_MFPL_PD4_MFP
#define SYS_GPD_MFPL_PD4_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD4_MFP_Pos)           /*!< GPD_MFPL PD4 setting for GPIO     */
#define SYS_GPD_MFPL_PD4_MFP_SC5_CD      (0x1UL<<SYS_GPD_MFPL_PD4_MFP_Pos)           /*!< GPD_MFPL PD4 setting for SC5_CD     */
#define SYS_GPD_MFPL_PD4_MFP_UART3_RXD       (0x2UL<<SYS_GPD_MFPL_PD4_MFP_Pos)           /*!< GPD_MFPL PD4 setting for UART3_RXD    */
#define SYS_GPD_MFPL_PD4_MFP_ACMP1_O       (0x3UL<<SYS_GPD_MFPL_PD4_MFP_Pos)           /*!< GPD_MFPL PD4 setting for ACMP1_O    */
#define SYS_GPD_MFPL_PD4_MFP_CAP_SCLK      (0x5UL<<SYS_GPD_MFPL_PD4_MFP_Pos)           /*!< GPD_MFPL PD4 setting for CAP_SCLK     */
#define SYS_GPD_MFPL_PD4_MFP_JTAG_TDI      (0x6UL<<SYS_GPD_MFPL_PD4_MFP_Pos)           /*!< GPD_MFPL PD4 setting for JTAG_TDI     */
#define SYS_GPD_MFPL_PD4_MFP_EBI_A8      (0x7UL<<SYS_GPD_MFPL_PD4_MFP_Pos)           /*!< GPD_MFPL PD4 setting for EBI_A8     */

//GPD_MFPL_PD5_MFP
#define SYS_GPD_MFPL_PD5_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD5_MFP_Pos)           /*!< GPD_MFPL PD5 setting for GPIO     */
#define SYS_GPD_MFPL_PD5_MFP_SC5_RST       (0x1UL<<SYS_GPD_MFPL_PD5_MFP_Pos)           /*!< GPD_MFPL PD5 setting for SC5_RST      */
#define SYS_GPD_MFPL_PD5_MFP_UART3_TXD       (0x2UL<<SYS_GPD_MFPL_PD5_MFP_Pos)           /*!< GPD_MFPL PD5 setting for UART3_TXD    */
#define SYS_GPD_MFPL_PD5_MFP_CAP_VSYNC       (0x5UL<<SYS_GPD_MFPL_PD5_MFP_Pos)           /*!< GPD_MFPL PD5 setting for CAP_VSYNC    */
#define SYS_GPD_MFPL_PD5_MFP_JTAG_nTRST      (0x6UL<<SYS_GPD_MFPL_PD5_MFP_Pos)           /*!< GPD_MFPL PD5 setting for JTAG_nTRST     */
#define SYS_GPD_MFPL_PD5_MFP_EBI_A9      (0x7UL<<SYS_GPD_MFPL_PD5_MFP_Pos)           /*!< GPD_MFPL PD5 setting for EBI_A9     */

//GPD_MFPL_PD6_MFP
#define SYS_GPD_MFPL_PD6_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD6_MFP_Pos)           /*!< GPD_MFPL PD6 setting for GPIO     */
#define SYS_GPD_MFPL_PD6_MFP_SC5_PWR       (0x1UL<<SYS_GPD_MFPL_PD6_MFP_Pos)           /*!< GPD_MFPL PD6 setting for SC5_PWR    */
#define SYS_GPD_MFPL_PD6_MFP_UART3_RTS       (0x2UL<<SYS_GPD_MFPL_PD6_MFP_Pos)           /*!< GPD_MFPL PD6 setting for UART3_RTS    */
#define SYS_GPD_MFPL_PD6_MFP_SD0_CMD       (0x4UL<<SYS_GPD_MFPL_PD6_MFP_Pos)           /*!< GPD_MFPL PD6 setting for SD0_CMD      */
#define SYS_GPD_MFPL_PD6_MFP_CAP_HSYNC       (0x5UL<<SYS_GPD_MFPL_PD6_MFP_Pos)           /*!< GPD_MFPL PD6 setting for CAP_HSYNC      */
#define SYS_GPD_MFPL_PD6_MFP_EBI_A10       (0x7UL<<SYS_GPD_MFPL_PD6_MFP_Pos)           /*!< GPD_MFPL PD6 setting for EBI_A10    */

//GPD_MFPL_PD7_MFP
#define SYS_GPD_MFPL_PD7_MFP_GPIO      (0x0UL<<SYS_GPD_MFPL_PD7_MFP_Pos)           /*!< GPD_MFPL PD7 setting for GPIO     */
#define SYS_GPD_MFPL_PD7_MFP_SC5_DAT       (0x1UL<<SYS_GPD_MFPL_PD7_MFP_Pos)           /*!< GPD_MFPL PD7 setting for SC5_DAT    */
#define SYS_GPD_MFPL_PD7_MFP_UART3_CTS       (0x2UL<<SYS_GPD_MFPL_PD7_MFP_Pos)           /*!< GPD_MFPL PD7 setting for UART3_CTS      */
#define SYS_GPD_MFPL_PD7_MFP_SD0_CLK       (0x4UL<<SYS_GPD_MFPL_PD7_MFP_Pos)           /*!< GPD_MFPL PD7 setting for SD0_CLK    */
#define SYS_GPD_MFPL_PD7_MFP_CAP_PIXCLK      (0x5UL<<SYS_GPD_MFPL_PD7_MFP_Pos)           /*!< GPD_MFPL PD7 setting for CAP_PIXCLK     */
#define SYS_GPD_MFPL_PD7_MFP_EBI_A11       (0x7UL<<SYS_GPD_MFPL_PD7_MFP_Pos)           /*!< GPD_MFPL PD7 setting for EBI_A11    */

//GPD_MFPL_PD8_MFP
#define SYS_GPD_MFPH_PD8_MFP_GPIO      (0x0UL<<SYS_GPD_MFPH_PD8_MFP_Pos)           /*!< GPD_MFPH PD8 setting for GPIO     */
#define SYS_GPD_MFPH_PD8_MFP_SPI3_MISO1      (0x1UL<<SYS_GPD_MFPH_PD8_MFP_Pos)           /*!< GPD_MFPH PD8 setting for SPI3_MISO1     */
#define SYS_GPD_MFPH_PD8_MFP_I2C0_SCL      (0x2UL<<SYS_GPD_MFPH_PD8_MFP_Pos)           /*!< GPD_MFPH PD8 setting for I2C0_SCL     */

//GPD_MFPH_PD9_MFP
#define SYS_GPD_MFPH_PD9_MFP_GPIO      (0x0UL<<SYS_GPD_MFPH_PD9_MFP_Pos)           /*!< GPD_MFPH PD9 setting for GPIO     */
#define SYS_GPD_MFPH_PD9_MFP_SPI3_MOSI1      (0x1UL<<SYS_GPD_MFPH_PD9_MFP_Pos)           /*!< GPD_MFPH PD9 setting for SPI3_MOSI1     */
#define SYS_GPD_MFPH_PD9_MFP_I2C0_SDA      (0x2UL<<SYS_GPD_MFPH_PD9_MFP_Pos)           /*!< GPD_MFPH PD9 setting for I2C0_SDA     */

//GPD_MFPH_PD10_MFP
#define SYS_GPD_MFPH_PD10_MFP_GPIO       (0x0UL<<SYS_GPD_MFPH_PD10_MFP_Pos)           /*!< GPD_MFPH PD10 setting for GPIO   */
#define SYS_GPD_MFPH_PD10_MFP_SC3_DAT        (0x1UL<<SYS_GPD_MFPH_PD10_MFP_Pos)           /*!< GPD_MFPH PD10 setting for SC3_DAT    */
#define SYS_GPD_MFPH_PD10_MFP_I2C4_SCL       (0x2UL<<SYS_GPD_MFPH_PD10_MFP_Pos)           /*!< GPD_MFPH PD10 setting for I2C4_SCL     */

//GPD_MFPH_PD11_MFP
#define SYS_GPD_MFPH_PD11_MFP_GPIO       (0x0UL<<SYS_GPD_MFPH_PD11_MFP_Pos)           /*!< GPD_MFPH PD11 setting for GPIO   */
#define SYS_GPD_MFPH_PD11_MFP_SC3_RST       (0x1UL<<SYS_GPD_MFPH_PD11_MFP_Pos)           /*!< GPD_MFPH PD11 setting for SC3_RST   */
#define SYS_GPD_MFPH_PD11_MFP_TM3_CNT_OUT       (0x3UL<<SYS_GPD_MFPH_PD11_MFP_Pos)           /*!< GPD_MFPH PD11 setting for TM3_CNT_OUT   */

//GPD_MFPH_PD12_MFP
#define SYS_GPD_MFPH_PD12_MFP_GPIO       (0x0UL<<SYS_GPD_MFPH_PD12_MFP_Pos)           /*!< GPD_MFPH PD12 setting for GPIO   */
#define SYS_GPD_MFPH_PD12_MFP_SC3_CLK       (0x1UL<<SYS_GPD_MFPH_PD12_MFP_Pos)           /*!< GPD_MFPH PD12 setting for SC3_CLK   */
#define SYS_GPD_MFPH_PD12_MFP_I2C4_SDA       (0x2UL<<SYS_GPD_MFPH_PD12_MFP_Pos)           /*!< GPD_MFPH PD12 setting for I2C4_SDA   */

//GPD_MFPH_PD13_MFP
#define SYS_GPD_MFPH_PD13_MFP_GPIO       (0x0UL<<SYS_GPD_MFPH_PD13_MFP_Pos)           /*!< GPD_MFPH PD13 setting for GPIO   */
#define SYS_GPD_MFPH_PD13_MFP_SC3_SS0       (0x1UL<<SYS_GPD_MFPH_PD13_MFP_Pos)           /*!< GPD_MFPH PD13 setting for SC3_SS0   */
#define SYS_GPD_MFPH_PD13_MFP_UART5_CTS       (0x2UL<<SYS_GPD_MFPH_PD13_MFP_Pos)           /*!< GPD_MFPH PD13 setting for UART5_CTS   */
#define SYS_GPD_MFPH_PD13_MFP_ECAP0_IC2       (0x3UL<<SYS_GPD_MFPH_PD13_MFP_Pos)           /*!< GPD_MFPH PD13 setting for ECAP0_IC2   */

//GPD_MFPH_PD14_MFP
#define SYS_GPD_MFPH_PD14_MFP_GPIO       (0x0UL<<SYS_GPD_MFPH_PD14_MFP_Pos)           /*!< GPD_MFPH PD14 setting for GPIO   */
#define SYS_GPD_MFPH_PD14_MFP_SPI1_CLK       (0x1UL<<SYS_GPD_MFPH_PD14_MFP_Pos)           /*!< GPD_MFPH PD14 setting for SPI1_CLK   */
#define SYS_GPD_MFPH_PD14_MFP_UART5_RTS       (0x2UL<<SYS_GPD_MFPH_PD14_MFP_Pos)           /*!< GPD_MFPH PD14 setting for UART5_RTS   */
#define SYS_GPD_MFPH_PD14_MFP_ECAP0_IC1       (0x3UL<<SYS_GPD_MFPH_PD14_MFP_Pos)           /*!< GPD_MFPH PD14 setting for ECAP0_IC1   */

//GPD_MFPH_PD15_MFP
#define SYS_GPD_MFPH_PD15_MFP_GPIO       (0x0UL<<SYS_GPD_MFPH_PD15_MFP_Pos)           /*!< GPD_MFPH PD15 setting for GPIO  */
#define SYS_GPD_MFPH_PD15_MFP_SPI1_MISO0       (0x1UL<<SYS_GPD_MFPH_PD15_MFP_Pos)           /*!< GPD_MFPH PD15 setting for SPI1_MISO0    */
#define SYS_GPD_MFPH_PD15_MFP_UART5_TXD       (0x2UL<<SYS_GPD_MFPH_PD15_MFP_Pos)           /*!< GPD_MFPH PD15 setting for UART5_TXD  */
#define SYS_GPD_MFPH_PD15_MFP_ECAP0_IC0       (0x3UL<<SYS_GPD_MFPH_PD15_MFP_Pos)           /*!< GPD_MFPH PD15 setting for ECAP0_IC0  */

//GPE_MFPL_PE0_MFP
#define SYS_GPE_MFPL_PE0_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE0_MFP_Pos)           /*!< GPE_MFPL PE0 setting for GPIO     */
#define SYS_GPE_MFPL_PE0_MFP_ADC0_0      (0x1UL<<SYS_GPE_MFPL_PE0_MFP_Pos)           /*!< GPE_MFPL PE0 setting for ADC0_0     */
#define SYS_GPE_MFPL_PE0_MFP_INT4      (0x8UL<<SYS_GPE_MFPL_PE0_MFP_Pos)           /*!< GPE_MFPL PE0 setting for INT4     */

//GPE_MFPL_PE1_MFP
#define SYS_GPE_MFPL_PE1_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE1_MFP_Pos)           /*!< GPE_MFPL PE1 setting for GPIO     */
#define SYS_GPE_MFPL_PE1_MFP_ADC0_1      (0x1UL<<SYS_GPE_MFPL_PE1_MFP_Pos)           /*!< GPE_MFPL PE1 setting for ADC0_1     */
#define SYS_GPE_MFPL_PE1_MFP_TM2_CNT_OUT       (0x3UL<<SYS_GPE_MFPL_PE1_MFP_Pos)           /*!< GPE_MFPL PE1 setting for TM2_CNT_OUT      */

//GPE_MFPL_PE2_MFP
#define SYS_GPE_MFPL_PE2_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE2_MFP_Pos)           /*!< GPE_MFPL PE2 setting for GPIO     */
#define SYS_GPE_MFPL_PE2_MFP_ADC0_2      (0x1UL<<SYS_GPE_MFPL_PE2_MFP_Pos)           /*!< GPE_MFPL PE2 setting for ADC0_2     */
#define SYS_GPE_MFPL_PE2_MFP_ACMP0_O       (0x2UL<<SYS_GPE_MFPL_PE2_MFP_Pos)           /*!< GPE_MFPL PE2 setting for ACMP0_O      */
#define SYS_GPE_MFPL_PE2_MFP_SPI0_MISO0      (0x3UL<<SYS_GPE_MFPL_PE2_MFP_Pos)           /*!< GPE_MFPL PE2 setting for SPI0_MISO0     */

//GPE_MFPL_PE3_MFP
#define SYS_GPE_MFPL_PE3_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE3_MFP_Pos)           /*!< GPE_MFPL PE3 setting for GPIO     */
#define SYS_GPE_MFPL_PE3_MFP_ADC0_3      (0x1UL<<SYS_GPE_MFPL_PE3_MFP_Pos)           /*!< GPE_MFPL PE3 setting for ADC0_3     */
#define SYS_GPE_MFPL_PE3_MFP_ACMP0_P3      (0x2UL<<SYS_GPE_MFPL_PE3_MFP_Pos)           /*!< GPE_MFPL PE3 setting for ACMP0_P3     */
#define SYS_GPE_MFPL_PE3_MFP_SPI0_MOSI0      (0x3UL<<SYS_GPE_MFPL_PE3_MFP_Pos)           /*!< GPE_MFPL PE3 setting for SPI0_MOSI0     */

//GPE_MFPL_PE4_MFP
#define SYS_GPE_MFPL_PE4_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE4_MFP_Pos)           /*!< GPE_MFPL PE4 setting for GPIO     */
#define SYS_GPE_MFPL_PE4_MFP_ADC0_4      (0x1UL<<SYS_GPE_MFPL_PE4_MFP_Pos)           /*!< GPE_MFPL PE4 setting for ADC0_4     */
#define SYS_GPE_MFPL_PE4_MFP_ACMP0_P2      (0x2UL<<SYS_GPE_MFPL_PE4_MFP_Pos)           /*!< GPE_MFPL PE4 setting for ACMP0_P2     */
#define SYS_GPE_MFPL_PE4_MFP_SPI0_SS0      (0x3UL<<SYS_GPE_MFPL_PE4_MFP_Pos)           /*!< GPE_MFPL PE4 setting for SPI0_SS0     */

//GPE_MFPL_PE5_MFP
#define SYS_GPE_MFPL_PE5_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE5_MFP_Pos)           /*!< GPE_MFPL PE5 setting for GPIO     */
#define SYS_GPE_MFPL_PE5_MFP_ADC0_5      (0x1UL<<SYS_GPE_MFPL_PE5_MFP_Pos)           /*!< GPE_MFPL PE5 setting for ADC0_5     */
#define SYS_GPE_MFPL_PE5_MFP_ACMP0_P1      (0x2UL<<SYS_GPE_MFPL_PE5_MFP_Pos)           /*!< GPE_MFPL PE5 setting for ACMP0_P1     */
#define SYS_GPE_MFPL_PE5_MFP_SPI0_CLK      (0x3UL<<SYS_GPE_MFPL_PE5_MFP_Pos)           /*!< GPE_MFPL PE5 setting for SPI0_CLK     */
#define SYS_GPE_MFPL_PE5_MFP_SC0_CDn       (0x4UL<<SYS_GPE_MFPL_PE5_MFP_Pos)           /*!< GPE_MFPL PE5 setting for SC0_CDn      */

//GPE_MFPL_PE6_MFP
#define SYS_GPE_MFPL_PE6_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE6_MFP_Pos)           /*!< GPE_MFPL PE6 setting for GPIO     */
#define SYS_GPE_MFPL_PE6_MFP_ADC0_6      (0x1UL<<SYS_GPE_MFPL_PE6_MFP_Pos)            /*!< GPE_MFPL PE6 setting for ADC0_6    */
#define SYS_GPE_MFPL_PE6_MFP_ACMP0_P0      (0x2UL<<SYS_GPE_MFPL_PE6_MFP_Pos)            /*!< GPE_MFPL PE6 setting for ACMP0_P0    */
#define SYS_GPE_MFPL_PE6_MFP_SPI0_MISO0      (0x3UL<<SYS_GPE_MFPL_PE6_MFP_Pos)            /*!< GPE_MFPL PE6 setting for SPI0_MISO0    */
#define SYS_GPE_MFPL_PE6_MFP_SC0_CMD       (0x4UL<<SYS_GPE_MFPL_PE6_MFP_Pos)            /*!< GPE_MFPL PE6 setting for SC0_CMD     */
#define SYS_GPE_MFPL_PE6_MFP_EBI_nWR       (0x7UL<<SYS_GPE_MFPL_PE6_MFP_Pos)            /*!< GPE_MFPL PE6 setting for EBI_nWR     */

//GPE_MFPL_PE7_MFP
#define SYS_GPE_MFPL_PE7_MFP_GPIO      (0x0UL<<SYS_GPE_MFPL_PE7_MFP_Pos)            /*!< GPE_MFPL PE7 setting for GPIO    */
#define SYS_GPE_MFPL_PE7_MFP_ADC0_7      (0x1UL<<SYS_GPE_MFPL_PE7_MFP_Pos)           /*!< GPE_MFPL PE7 setting for ADC0_7     */
#define SYS_GPE_MFPL_PE7_MFP_ACMP0_N       (0x2UL<<SYS_GPE_MFPL_PE7_MFP_Pos)           /*!< GPE_MFPL PE7 setting for ACMP0_N      */
#define SYS_GPE_MFPL_PE7_MFP_SPI0_MOSI0      (0x3UL<<SYS_GPE_MFPL_PE7_MFP_Pos)           /*!< GPE_MFPL PE7 setting for SPI0_MOSI0     */
#define SYS_GPE_MFPL_PE7_MFP_SC0_CLK       (0x4UL<<SYS_GPE_MFPL_PE7_MFP_Pos)           /*!< GPE_MFPL PE7 setting for SC0_CLK      */
#define SYS_GPE_MFPL_PE7_MFP_EBI_nRD       (0x7UL<<SYS_GPE_MFPL_PE7_MFP_Pos)           /*!< GPE_MFPL PE7 setting for _EBI_nRD     */

//GPE_MFPL_PE8_MFP
#define SYS_GPE_MFPH_PE8_MFP_GPIO      (0x0UL<<SYS_GPE_MFPH_PE8_MFP_Pos)           /*!< GPE_MFPH PE8 setting for GPIO     */
#define SYS_GPE_MFPH_PE8_MFP_ADC1_0      (0x1UL<<SYS_GPE_MFPH_PE8_MFP_Pos)           /*!< GPE_MFPH PE8 setting for ADC1_0     */
#define SYS_GPE_MFPH_PE8_MFP_ACMP1_N     (0x2UL<<SYS_GPE_MFPH_PE8_MFP_Pos)           /*!< GPE_MFPH PE8 setting for ACMP1_N    */
#define SYS_GPE_MFPH_PE8_MFP_TM1_CNT_OUT       (0x3UL<<SYS_GPE_MFPH_PE8_MFP_Pos)           /*!< GPE_MFPH PE8 setting for TM1_CNT_OUT    */
#define SYS_GPE_MFPH_PE8_MFP_SC0_DAT3      (0x4UL<<SYS_GPE_MFPH_PE8_MFP_Pos)           /*!< GPE_MFPH PE8 setting for SC0_DAT3     */
#define SYS_GPE_MFPH_PE8_MFP_EBI_ALE       (0x7UL<<SYS_GPE_MFPH_PE8_MFP_Pos)           /*!< GPE_MFPH PE8 setting for EBI_ALE    */

//GPE_MFPH_PE9_MFP
#define SYS_GPE_MFPH_PE9_MFP_GPIO      (0x0UL<<SYS_GPE_MFPH_PE9_MFP_Pos)           /*!< GPE_MFPH PE9 setting for GPIO     */
#define SYS_GPE_MFPH_PE9_MFP_ADC1_1      (0x1UL<<SYS_GPE_MFPH_PE9_MFP_Pos)           /*!< GPE_MFPH PE9 setting for ADC1_1     */
#define SYS_GPE_MFPH_PE9_MFP_ACMP1_P0      (0x2UL<<SYS_GPE_MFPH_PE9_MFP_Pos)           /*!< GPE_MFPH PE9 setting for ACMP1_P0     */
#define SYS_GPE_MFPH_PE9_MFP_SC0_DAT2      (0x4UL<<SYS_GPE_MFPH_PE9_MFP_Pos)           /*!< GPE_MFPH PE9 setting for SC0_DAT2     */
#define SYS_GPE_MFPH_PE9_MFP_EBI_nWRH      (0x7UL<<SYS_GPE_MFPH_PE9_MFP_Pos)           /*!< GPE_MFPH PE9 setting for EBI_nWRH     */

//GPE_MFPH_PE10_MFP
#define SYS_GPE_MFPH_PE10_MFP_GPIO       (0x0UL<<SYS_GPE_MFPH_PE10_MFP_Pos)           /*!< GPE_MFPH PE10 setting for GPIO   */
#define SYS_GPE_MFPH_PE10_MFP_ADC1_2       (0x1UL<<SYS_GPE_MFPH_PE10_MFP_Pos)           /*!< GPE_MFPH PE10 setting for ADC1_2   */
#define SYS_GPE_MFPH_PE10_MFP_ACMP1_P1       (0x2UL<<SYS_GPE_MFPH_PE10_MFP_Pos)           /*!< GPE_MFPH PE10 setting for ACMP1_P1   */
#define SYS_GPE_MFPH_PE10_MFP_SPI0_MISO1       (0x3UL<<SYS_GPE_MFPH_PE10_MFP_Pos)           /*!< GPE_MFPH PE10 setting for SPI0_MISO1   */
#define SYS_GPE_MFPH_PE10_MFP_EBI_nWRL       (0x7UL<<SYS_GPE_MFPH_PE10_MFP_Pos)           /*!< GPE_MFPH PE10 setting for EBI_nWRL   */

//GPE_MFPH_PE11_MFP
#define SYS_GPE_MFPH_PE11_MFP_GPIO       (0x0UL<<SYS_GPE_MFPH_PE11_MFP_Pos)           /*!< GPE_MFPH PE11 setting for GPIO   */
#define SYS_GPE_MFPH_PE11_MFP_ADC1_3       (0x1UL<<SYS_GPE_MFPH_PE11_MFP_Pos)           /*!< GPE_MFPH PE11 setting for ADC1_3   */
#define SYS_GPE_MFPH_PE11_MFP_ACMP1_P2       (0x2UL<<SYS_GPE_MFPH_PE11_MFP_Pos)           /*!< GPE_MFPH PE11 setting for ACMP1_P2   */
#define SYS_GPE_MFPH_PE11_MFP_SPI0_MOSI1       (0x3UL<<SYS_GPE_MFPH_PE11_MFP_Pos)           /*!< GPE_MFPH PE11 setting for SPI0_MOSI1   */
#define SYS_GPE_MFPH_PE11_MFP_SC0_DAT0       (0x4UL<<SYS_GPE_MFPH_PE11_MFP_Pos)           /*!< GPE_MFPH PE11 setting for SC0_DAT0   */
#define SYS_GPE_MFPH_PE11_MFP_CMP2_P3       (0x5UL<<SYS_GPE_MFPH_PE11_MFP_Pos)           /*!< GPE_MFPH PE11 setting for CMP2_P3   */
#define SYS_GPE_MFPH_PE11_MFP_EBI_nCS0       (0x7UL<<SYS_GPE_MFPH_PE11_MFP_Pos)           /*!< GPE_MFPH PE11 setting for EBI_nCS0   */

//GPE_MFPH_PE12_MFP
#define SYS_GPE_MFPH_PE12_MFP_GPIO       (0x0UL<<SYS_GPE_MFPH_PE12_MFP_Pos)           /*!< GPE_MFPH PE12 setting for GPIO   */
#define SYS_GPE_MFPH_PE12_MFP_ADC1_4       (0x1UL<<SYS_GPE_MFPH_PE12_MFP_Pos)           /*!< GPE_MFPH PE12 setting for ADC1_4   */
#define SYS_GPE_MFPH_PE12_MFP_ACMP1_P3       (0x2UL<<SYS_GPE_MFPH_PE12_MFP_Pos)           /*!< GPE_MFPH PE12 setting for ACMP1_P3   */
#define SYS_GPE_MFPH_PE12_MFP_ACMP2_P2       (0x3UL<<SYS_GPE_MFPH_PE12_MFP_Pos)           /*!< GPE_MFPH PE12 setting for ACMP2_P2   */
#define SYS_GPE_MFPH_PE12_MFP_EBI_nCS1       (0x7UL<<SYS_GPE_MFPH_PE12_MFP_Pos)           /*!< GPE_MFPH PE12 setting for EBI_nCS1   */
//GPE_MFPH_PE13_MFP
#define SYS_GPE_MFPH_PE13_MFP_GPIO       (0x0UL<<SYS_GPE_MFPH_PE13_MFP_Pos)           /*!< GPE_MFPH PE13 setting for GPIO   */
#define SYS_GPE_MFPH_PE13_MFP_ADC1_5       (0x1UL<<SYS_GPE_MFPH_PE13_MFP_Pos)           /*!< GPE_MFPH PE13 setting for ADC1_5   */
#define SYS_GPE_MFPH_PE13_MFP_ACMP2_P1       (0x3UL<<SYS_GPE_MFPH_PE13_MFP_Pos)           /*!< GPE_MFPH PE13 setting for ACMP2_P1   */
#define SYS_GPE_MFPH_PE13_MFP_EBI_nCS2       (0x7UL<<SYS_GPE_MFPH_PE13_MFP_Pos)           /*!< GPE_MFPH PE13 setting for EBI_nCS2   */

//GPE_MFPH_PE14_MFP
#define SYS_GPE_MFPH_PE14_MFP_GPIO       (0x0UL<<SYS_GPE_MFPH_PE14_MFP_Pos)           /*!< GPE_MFPH PE14 setting for GPIO   */
#define SYS_GPE_MFPH_PE14_MFP_ADC1_6       (0x1UL<<SYS_GPE_MFPH_PE14_MFP_Pos)           /*!< GPE_MFPH PE14 setting for ADC1_6   */
#define SYS_GPE_MFPH_PE14_MFP_ACMP2_P0       (0x3UL<<SYS_GPE_MFPH_PE14_MFP_Pos)           /*!< GPE_MFPH PE14 setting for ACMP2_P0   */
#define SYS_GPE_MFPH_PE14_MFP_EBI_nCS3       (0x7UL<<SYS_GPE_MFPH_PE14_MFP_Pos)           /*!< GPE_MFPH PE14 setting for EBI_nCS3   */

//GPE_MFPH_PE15_MFP
#define SYS_GPE_MFPH_PE15_MFP_GPIO       (0x0UL<<SYS_GPE_MFPH_PE15_MFP_Pos)           /*!< GPE_MFPH PE15 setting for GPIO   */
#define SYS_GPE_MFPH_PE15_MFP_ADC1_7       (0x1UL<<SYS_GPE_MFPH_PE15_MFP_Pos)            /*!< GPE_MFPH PE15 setting for ADC1_7    */
#define SYS_GPE_MFPH_PE15_MFP_ACMP2_N       (0x3UL<<SYS_GPE_MFPH_PE15_MFP_Pos)            /*!< GPE_MFPH PE15 setting for ACMP2_N  */

//GPF_MFPL_PF0_MFP
#define SYS_GPF_MFPL_PF0_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF0_MFP_Pos)            /*!< GPF_MFPL PF0 setting for GPIO    */
#define SYS_GPF_MFPL_PF0_MFP_SPI1_MOSI0      (0x1UL<<SYS_GPF_MFPL_PF0_MFP_Pos)           /*!< GPF_MFPL PF0 setting for SPI1_MOSI0     */
#define SYS_GPF_MFPL_PF0_MFP_UART5_RXD       (0x2UL<<SYS_GPF_MFPL_PF0_MFP_Pos)           /*!< GPF_MFPL PF0 setting for UART5_RXD      */
#define SYS_GPF_MFPL_PF0_MFP_INT5      (0x8UL<<SYS_GPF_MFPL_PF0_MFP_Pos)           /*!< GPF_MFPL PF0 setting for INT5     */

//GPF_MFPL_PF1_MFP
#define SYS_GPF_MFPL_PF1_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF1_MFP_Pos)           /*!< GPF_MFPL PF1 setting for GPIO     */
#define SYS_GPF_MFPL_PF1_MFP_SPI2_MOSI0      (0x1UL<<SYS_GPF_MFPL_PF1_MFP_Pos)           /*!< GPF_MFPL PF1 setting for SPI2_MOSI0     */

//GPF_MFPL_PF2_MFP
#define SYS_GPF_MFPL_PF2_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF2_MFP_Pos)           /*!< GPF_MFPL PF2 setting for GPIO     */
#define SYS_GPF_MFPL_PF2_MFP_SPI3_SS0      (0x1UL<<SYS_GPF_MFPL_PF2_MFP_Pos)           /*!< GPF_MFPL PF2 setting for SPI3_SS0     */
#define SYS_GPF_MFPL_PF2_MFP_SD0_DAT3      (0x4UL<<SYS_GPF_MFPL_PF2_MFP_Pos)           /*!< GPF_MFPL PF2 setting for SD0_DAT3     */
#define SYS_GPF_MFPL_PF2_MFP_EMAC_MII_RXD3       (0x6UL<<SYS_GPF_MFPL_PF2_MFP_Pos)           /*!< GPF_MFPL PF2 setting for EMAC_MII_RXD3    */

//GPF_MFPL_PF3_MFP
#define SYS_GPF_MFPL_PF3_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF3_MFP_Pos)           /*!< GPF_MFPL PF3 setting for GPIO     */
#define SYS_GPF_MFPL_PF3_MFP_SPI3_CLK      (0x1UL<<SYS_GPF_MFPL_PF3_MFP_Pos)           /*!< GPF_MFPL PF3 setting for SPI3_CLK     */
#define SYS_GPF_MFPL_PF3_MFP_SD0_DAT2      (0x4UL<<SYS_GPF_MFPL_PF3_MFP_Pos)           /*!< GPF_MFPL PF3 setting for SD0_DAT2     */
#define SYS_GPF_MFPL_PF3_MFP_EMAC_MII_RXD2       (0x6UL<<SYS_GPF_MFPL_PF3_MFP_Pos)          /*!< GPF_MFPL PF3 setting for EMAC_MII_RXD2     */

//GPF_MFPL_PF4_MFP
#define SYS_GPF_MFPL_PF4_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF4_MFP_Pos)           /*!< GPF_MFPL PF4 setting for GPIO     */
#define SYS_GPF_MFPL_PF4_MFP_SPI3_MISO0      (0x1UL<<SYS_GPF_MFPL_PF4_MFP_Pos)           /*!< GPF_MFPL PF4 setting for SPI3_MISO0     */
#define SYS_GPF_MFPL_PF4_MFP_SD0_DAT1      (0x4UL<<SYS_GPF_MFPL_PF4_MFP_Pos)           /*!< GPF_MFPL PF4 setting for SD0_DAT1     */
#define SYS_GPF_MFPL_PF4_MFP_EMAC_MII_COL0       (0x6UL<<SYS_GPF_MFPL_PF4_MFP_Pos)           /*!< GPF_MFPL PF4 setting for EMAC_MII_COL0    */

//GPF_MFPL_PF5_MFP
#define SYS_GPF_MFPL_PF5_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF5_MFP_Pos)           /*!< GPF_MFPL PF5 setting for GPIO     */
#define SYS_GPF_MFPL_PF5_MFP_SPI3_MOSI0      (0x1UL<<SYS_GPF_MFPL_PF5_MFP_Pos)           /*!< GPF_MFPL PF5 setting for SPI3_MOSI0     */
#define SYS_GPF_MFPL_PF5_MFP_SD0_DAT0      (0x4UL<<SYS_GPF_MFPL_PF5_MFP_Pos)           /*!< GPF_MFPL PF5 setting for SD0_DAT0     */
#define SYS_GPF_MFPL_PF5_MFP_EMAC_MII_CRS      (0x6UL<<SYS_GPF_MFPL_PF5_MFP_Pos)           /*!< GPF_MFPL PF5 setting for EMAC_MII_CRS     */

//GPF_MFPL_PF6_MFP
#define SYS_GPF_MFPL_PF6_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF6_MFP_Pos)           /*!< GPF_MFPL PF6 setting for GPIO     */
#define SYS_GPF_MFPL_PF6_MFP_UART2_RXD       (0x1UL<<SYS_GPF_MFPL_PF6_MFP_Pos)           /*!< GPF_MFPL PF6 setting for UART2_RXD    */
#define SYS_GPF_MFPL_PF6_MFP_SD0_CDn       (0x4UL<<SYS_GPF_MFPL_PF6_MFP_Pos)           /*!< GPF_MFPL PF6 setting for SD0_CDn    */
#define SYS_GPF_MFPL_PF6_MFP_EMAC_MII_TXCLK      (0x6UL<<SYS_GPF_MFPL_PF6_MFP_Pos)           /*!< GPF_MFPL PF6 setting for EMAC_MII_TXCLK     */

//GPF_MFPL_PF7_MFP
#define SYS_GPF_MFPL_PF7_MFP_GPIO      (0x0UL<<SYS_GPF_MFPL_PF7_MFP_Pos)           /*!< GPF_MFPL PF7 setting for GPIO     */
#define SYS_GPF_MFPL_PF7_MFP_UART2_TXD       (0x1UL<<SYS_GPF_MFPL_PF7_MFP_Pos)           /*!< GPF_MFPL PF7 setting for UART2_TXD    */
#define SYS_GPF_MFPL_PF7_MFP_SD0_CMD       (0x4UL<<SYS_GPF_MFPL_PF7_MFP_Pos)           /*!< GPF_MFPL PF7 setting for SD0_CMD    */
#define SYS_GPF_MFPL_PF7_MFP_EMAC_MII_TXD3       (0x6UL<<SYS_GPF_MFPL_PF7_MFP_Pos)           /*!< GPF_MFPL PF7 setting for EMAC_MII_TXD3    */

//GPF_MFPL_PF8_MFP
#define SYS_GPF_MFPH_PF8_MFP_GPIO      (0x0UL<<SYS_GPF_MFPH_PF8_MFP_Pos)           /*!< GPF_MFPH PF8 setting for GPIO     */
#define SYS_GPF_MFPH_PF8_MFP_UART2_RTS       (0x1UL<<SYS_GPF_MFPH_PF8_MFP_Pos)           /*!< GPF_MFPH PF8 setting for UART2_RTS    */
#define SYS_GPF_MFPH_PF8_MFP_SD0_CLK       (0x4UL<<SYS_GPF_MFPH_PF8_MFP_Pos)           /*!< GPF_MFPH PF8 setting for SD0_CLK    */
#define SYS_GPF_MFPH_PF8_MFP_EMAC_MII_TXD2       (0x6UL<<SYS_GPF_MFPH_PF8_MFP_Pos)           /*!< GPF_MFPH PF8 setting for EMAC_MII_TXD2    */

//GPF_MFPH_PF9_MFP
#define SYS_GPF_MFPH_PF9_MFP_GPIO      (0x0UL<<SYS_GPF_MFPH_PF9_MFP_Pos)           /*!< GPF_MFPH PF9 setting for GPIO     */
#define SYS_GPF_MFPH_PF9_MFP_OPA0_IN_P       (0x1UL<<SYS_GPF_MFPH_PF9_MFP_Pos)           /*!< GPF_MFPH PF9 setting for OPA0_IN_P      */
#define SYS_GPF_MFPH_PF9_MFP_PWM0_CH0       (0x4UL<<SYS_GPF_MFPH_PF9_MFP_Pos)           /*!< GPF_MFPH PF9 setting for PWM0_CH0      */

//GPF_MFPH_PF10_MFP
#define SYS_GPF_MFPH_PF10_MFP_GPIO       (0x0UL<<SYS_GPF_MFPH_PF10_MFP_Pos)           /*!< GPF_MFPH PF10 setting for GPIO   */
#define SYS_GPF_MFPH_PF10_MFP_OPA0_IN_N        (0x1UL<<SYS_GPF_MFPH_PF10_MFP_Pos)           /*!< GPF_MFPH PF10 setting for OPA0_IN_N    */
#define SYS_GPF_MFPH_PF10_MFP_PWM0_CH1        (0x4UL<<SYS_GPF_MFPH_PF10_MFP_Pos)           /*!< GPF_MFPH PF10 setting for PWM0_CH1  */

//GPF_MFPH_PF11_MFP
#define SYS_GPF_MFPH_PF11_MFP_GPIO       (0x0UL<<SYS_GPF_MFPH_PF11_MFP_Pos)           /*!< GPF_MFPH PF11 setting for GPIO   */
#define SYS_GPF_MFPH_PF11_MFP_OPA0_O       (0x1UL<<SYS_GPF_MFPH_PF11_MFP_Pos)           /*!< GPF_MFPH PF11 setting for OPA0_O   */
#define SYS_GPF_MFPH_PF11_MFP_UART1_RTS       (0x2UL<<SYS_GPF_MFPH_PF11_MFP_Pos)           /*!< GPF_MFPH PF11 setting for UART1_RTS   */

//GPF_MFPH_PF12_MFP
#define SYS_GPF_MFPH_PF12_MFP_GPIO       (0x0UL<<SYS_GPF_MFPH_PF12_MFP_Pos)           /*!< GPF_MFPH PF12 setting for GPIO   */
#define SYS_GPF_MFPH_PF12_MFP_OPA1_IN_P       (0x1UL<<SYS_GPF_MFPH_PF12_MFP_Pos)           /*!< GPF_MFPH PF12 setting for OPA1_IN_P   */
#define SYS_GPF_MFPH_PF12_MFP_UART1_CTS       (0x4UL<<SYS_GPF_MFPH_PF12_MFP_Pos)           /*!< GPF_MFPH PF12 setting for UART1_CTS   */
//GPF_MFPH_PF13_MFP
#define SYS_GPF_MFPH_PF13_MFP_GPIO       (0x0UL<<SYS_GPF_MFPH_PF13_MFP_Pos)           /*!< GPF_MFPH PF13 setting for GPIO   */
#define SYS_GPF_MFPH_PF13_MFP_OPA1_IN_N       (0x1UL<<SYS_GPF_MFPH_PF13_MFP_Pos)            /*!< GPF_MFPH PF13 setting for OPA1_IN_N  */
#define SYS_GPF_MFPH_PF13_MFP_UART1_TXD       (0x2UL<<SYS_GPF_MFPH_PF13_MFP_Pos)            /*!< GPF_MFPH PF13 setting for UART1_TXD    */

//GPF_MFPH_PF14_MFP
#define SYS_GPF_MFPH_PF14_MFP_GPIO       (0x0UL<<SYS_GPF_MFPH_PF14_MFP_Pos)            /*!< GPF_MFPH PF14 setting for GPIO  */
#define SYS_GPF_MFPH_PF14_MFP_OPA1_O       (0x1UL<<SYS_GPF_MFPH_PF14_MFP_Pos)           /*!< GPF_MFPH PF14 setting for OPA1_O   */
#define SYS_GPF_MFPH_PF14_MFP_UART1_RXD       (0x2UL<<SYS_GPF_MFPH_PF14_MFP_Pos)           /*!< GPF_MFPH PF14 setting for UART1_RXD   */

//GPF_MFPH_PF15_MFP
#define SYS_GPF_MFPH_PF15_MFP_GPIO       (0x0UL<<SYS_GPF_MFPH_PF15_MFP_Pos)          /*!< GPF_MFPH PF15 setting for GPIO  */
#define SYS_GPF_MFPH_PF15_MFP_UART0_RTS       (0x1UL<<SYS_GPF_MFPH_PF15_MFP_Pos)            /*!< GPF_MFPH PF15 setting for UART0_RTS  */


//GPG_MFPL_PG0_MFP
#define SYS_GPG_MFPL_PG0_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG0_MFP_Pos)            /*!< GPG_MFPL PG0 setting for GPIO    */
#define SYS_GPG_MFPL_PG0_MFP_UART0_CTS       (0x1UL<<SYS_GPG_MFPL_PG0_MFP_Pos)           /*!< GPG_MFPL PG0 setting for UART0_CTS    */
#define SYS_GPG_MFPL_PG0_MFP_INT6      (0x8UL<<SYS_GPG_MFPL_PG0_MFP_Pos)           /*!< GPG_MFPL PG0 setting for INT6     */

//GPG_MFPL_PG1_MFP
#define SYS_GPG_MFPL_PG1_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG1_MFP_Pos)           /*!< GPG_MFPL PG1 setting for GPIO     */
#define SYS_GPG_MFPL_PG1_MFP_UART0_RXD       (0x1UL<<SYS_GPG_MFPL_PG1_MFP_Pos)           /*!< GPG_MFPL PG1 setting for UART0_RXD    */

//GPG_MFPL_PG2_MFP
#define SYS_GPG_MFPL_PG2_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG2_MFP_Pos)           /*!< GPG_MFPL PG2 setting for GPIO     */
#define SYS_GPG_MFPL_PG2_MFP_UART0_TXD       (0x1UL<<SYS_GPG_MFPL_PG2_MFP_Pos)           /*!< GPG_MFPL PG2 setting for UART0_TXD      */

//GPG_MFPL_PG3_MFP
#define SYS_GPG_MFPL_PG3_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG3_MFP_Pos)           /*!< GPG_MFPL PG3 setting for GPIO     */
#define SYS_GPG_MFPL_PG3_MFP_PS2_CLK       (0x1UL<<SYS_GPG_MFPL_PG3_MFP_Pos)            /*!< GPG_MFPL PG3 setting for PS2_CLK     */
#define SYS_GPG_MFPL_PG3_MFP_I2S1_DO       (0x2UL<<SYS_GPG_MFPL_PG3_MFP_Pos)            /*!< GPG_MFPL PG3 setting for I2S1_DO     */
#define SYS_GPG_MFPL_PG3_MFP_SC1_RST       (0x3UL<<SYS_GPG_MFPL_PG3_MFP_Pos)            /*!< GPG_MFPL PG3 setting for SC1_RST     */
//GPG_MFPL_PG4_MFP
#define SYS_GPG_MFPL_PG4_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG4_MFP_Pos)            /*!< GPG_MFPL PG4 setting for GPIO    */
#define SYS_GPG_MFPL_PG4_MFP_PS2_DAT     (0x1UL<<SYS_GPG_MFPL_PG4_MFP_Pos)           /*!< GPG_MFPL PG4 setting for PS2_DAT      */
#define SYS_GPG_MFPL_PG4_MFP_I2S1_DI       (0x2UL<<SYS_GPG_MFPL_PG4_MFP_Pos)           /*!< GPG_MFPL PG4 setting for I2S1_DI      */
#define SYS_GPG_MFPL_PG4_MFP_SC1_PWR       (0x3UL<<SYS_GPG_MFPL_PG4_MFP_Pos)           /*!< GPG_MFPL PG4 setting for SC1_PWR      */

//GPG_MFPL_PG5_MFP
#define SYS_GPG_MFPL_PG5_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG5_MFP_Pos)           /*!< GPG_MFPL PG5 setting for GPIO     */
#define SYS_GPG_MFPL_PG5_MFP_I2S1_BCLK       (0x2UL<<SYS_GPG_MFPL_PG5_MFP_Pos)           /*!< GPG_MFPL PG5 setting for I2S1_BCLK      */
#define SYS_GPG_MFPL_PG5_MFP_SC1_DAT       (0x3UL<<SYS_GPG_MFPL_PG5_MFP_Pos)           /*!< GPG_MFPL PG5 setting for SC1_DAT    */
//GPG_MFPL_PG6_MFP
#define SYS_GPG_MFPL_PG6_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG6_MFP_Pos)           /*!< GPG_MFPL PG6 setting for GPIO     */
#define SYS_GPG_MFPL_PG6_MFP_I2S1_LRCK       (0x2UL<<SYS_GPG_MFPL_PG6_MFP_Pos)           /*!< GPG_MFPL PG6 setting for I2S1_LRCK    */
#define SYS_GPG_MFPL_PG6_MFP_SC1_CLK       (0x3UL<<SYS_GPG_MFPL_PG6_MFP_Pos)           /*!< GPG_MFPL PG6 setting for SC1_CLK    */

//GPG_MFPL_PG7_MFP
#define SYS_GPG_MFPL_PG7_MFP_GPIO      (0x0UL<<SYS_GPG_MFPL_PG7_MFP_Pos)           /*!< GPG_MFPL PG7 setting for GPIO     */
#define SYS_GPG_MFPL_PG7_MFP_SPI2_MISO0      (0x1UL<<SYS_GPG_MFPL_PG7_MFP_Pos)           /*!< GPG_MFPL PG7 setting for SPI2_MISO0     */
#define SYS_GPG_MFPL_PG7_MFP_I2S1_MCLK       (0x2UL<<SYS_GPG_MFPL_PG7_MFP_Pos)           /*!< GPG_MFPL PG7 setting for I2S1_MCLK    */
#define SYS_GPG_MFPL_PG7_MFP_SC1_CD      (0x3UL<<SYS_GPG_MFPL_PG7_MFP_Pos)           /*!< GPG_MFPL PG7 setting for SC1_CD     */
#define SYS_GPG_MFPL_PG7_MFP_SC3_RST       (0x4UL<<SYS_GPG_MFPL_PG7_MFP_Pos)           /*!< GPG_MFPL PG7 setting for SC3_RST      */

//GPG_MFPL_PG8_MFP
#define SYS_GPG_MFPH_PG8_MFP_GPIO      (0x0UL<<SYS_GPG_MFPH_PG8_MFP_Pos)           /*!< GPG_MFPH PG8 setting for GPIO     */
#define SYS_GPG_MFPH_PG8_MFP_SPI2_MOSI0      (0x1UL<<SYS_GPG_MFPH_PG8_MFP_Pos)           /*!< GPG_MFPH PG8 setting for SPI2_MOSI0     */
#define SYS_GPG_MFPH_PG8_MFP_I2S1_DO       (0x2UL<<SYS_GPG_MFPH_PG8_MFP_Pos)           /*!< GPG_MFPH PG8 setting for I2S1_DO    */
#define SYS_GPG_MFPH_PG8_MFP_UART4_RTS       (0x3UL<<SYS_GPG_MFPH_PG8_MFP_Pos)           /*!< GPG_MFPH PG8 setting for UART4_RTS    */
#define SYS_GPG_MFPH_PG8_MFP_SC3_DAT       (0x4UL<<SYS_GPG_MFPH_PG8_MFP_Pos)           /*!< GPG_MFPH PG8 setting for SC3_DAT    */

//GPG_MFPH_PG9_MFP
#define SYS_GPG_MFPH_PG9_MFP_GPIO      (0x0UL<<SYS_GPG_MFPH_PG9_MFP_Pos)           /*!< GPG_MFPH PG9 setting for GPIO     */
#define SYS_GPG_MFPH_PG9_MFP_SPI2_CLK      (0x1UL<<SYS_GPG_MFPH_PG9_MFP_Pos)           /*!< GPG_MFPH PG9 setting for SPI2_CLK     */
#define SYS_GPG_MFPH_PG9_MFP_I2S1_DI       (0x2UL<<SYS_GPG_MFPH_PG9_MFP_Pos)           /*!< GPG_MFPH PG9 setting for I2S1_DI    */
#define SYS_GPG_MFPH_PG9_MFP_UART4_CTS       (0x3UL<<SYS_GPG_MFPH_PG9_MFP_Pos)           /*!< GPG_MFPH PG9 setting for UART4_CTS    */
#define SYS_GPG_MFPH_PG9_MFP_SC3_CLK       (0x4UL<<SYS_GPG_MFPH_PG9_MFP_Pos)           /*!< GPG_MFPH PG9 setting for SC3_CLK      */

//GPG_MFPH_PG10_MFP
#define SYS_GPG_MFPH_PG10_MFP_GPIO       (0x0UL<<SYS_GPG_MFPH_PG10_MFP_Pos)           /*!< GPG_MFPH PG10 setting for GPIO   */
#define SYS_GPG_MFPH_PG10_MFP_ICE_CLK        (0x1UL<<SYS_GPG_MFPH_PG10_MFP_Pos)           /*!< GPG_MFPH PG10 setting for ICE_CLK    */
#define SYS_GPG_MFPH_PG10_MFP_JTAG_TCLK        (0x6UL<<SYS_GPG_MFPH_PG10_MFP_Pos)           /*!< GPG_MFPH PG10 setting for JTAG_TCLK  */

//GPG_MFPH_PG11_MFP
#define SYS_GPG_MFPH_PG11_MFP_GPIO       (0x0UL<<SYS_GPG_MFPH_PG11_MFP_Pos)           /*!< GPG_MFPH PG11 setting for GPIO   */
#define SYS_GPG_MFPH_PG11_MFP_ICE_DAT       (0x1UL<<SYS_GPG_MFPH_PG11_MFP_Pos)           /*!< GPG_MFPH PG11 setting for ICE_DAT   */
#define SYS_GPG_MFPH_PG11_MFP_JTAG_TMS       (0x6UL<<SYS_GPG_MFPH_PG11_MFP_Pos)           /*!< GPG_MFPH PG11 setting for JTAG_TMS   */

//GPG_MFPH_PG12_MFP
#define SYS_GPG_MFPH_PG12_MFP_GPIO       (0x0UL<<SYS_GPG_MFPH_PG12_MFP_Pos)           /*!< GPG_MFPH PG12 setting for GPIO   */
#define SYS_GPG_MFPH_PG12_MFP_XT1_OUT       (0x1UL<<SYS_GPG_MFPH_PG12_MFP_Pos)           /*!< GPG_MFPH PG12 setting for XT1_OUT   */

//GPG_MFPH_PG13_MFP
#define SYS_GPG_MFPH_PG13_MFP_GPIO       (0x0UL<<SYS_GPG_MFPH_PG13_MFP_Pos)           /*!< GPG_MFPH PG13 setting for GPIO   */
#define SYS_GPG_MFPH_PG13_MFP_XT1_IN       (0x1UL<<SYS_GPG_MFPH_PG13_MFP_Pos)           /*!< GPG_MFPH PG13 setting for XT1_IN   */

//GPG_MFPH_PG14_MFP
#define SYS_GPG_MFPH_PG14_MFP_GPIO       (0x0UL<<SYS_GPG_MFPH_PG14_MFP_Pos)           /*!< GPG_MFPH PG14 setting for GPIO   */
#define SYS_GPG_MFPH_PG14_MFP_X32K_IN       (0x1UL<<SYS_GPG_MFPH_PG14_MFP_Pos)           /*!< GPG_MFPH PG14 setting for X32K_IN   */
#define SYS_GPG_MFPH_PG14_MFP_I2C1_SCL       (0x3UL<<SYS_GPG_MFPH_PG14_MFP_Pos)           /*!< GPG_MFPH PG14 setting for I2C1_SCL   */

//GPG_MFPH_PG15_MFP
#define SYS_GPG_MFPH_PG15_MFP_GPIO       (0x0UL<<SYS_GPG_MFPH_PG15_MFP_Pos)           /*!< GPG_MFPH PG15 setting for GPIO   */
#define SYS_GPG_MFPH_PG15_MFP_X32K_OUT       (0x1UL<<SYS_GPG_MFPH_PG15_MFP_Pos)           /*!< GPG_MFPH PG15 setting for X32K_OUT   */
#define SYS_GPG_MFPH_PG15_MFP_I2C1_SDA       (0x3UL<<SYS_GPG_MFPH_PG15_MFP_Pos)           /*!< GPG_MFPH PG15 setting for I2C1_SDA   */


//GPH_MFPL_PH0_MFP
#define SYS_GPH_MFPL_PH0_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH0_MFP_Pos)           /*!< GPH_MFPL PH0 setting for GPIO     */
#define SYS_GPH_MFPL_PH0_MFP_I2C1_SCL      (0x1UL<<SYS_GPH_MFPL_PH0_MFP_Pos)           /*!< GPH_MFPL PH0 setting for I2C1_SCL     */
#define SYS_GPH_MFPL_PH0_MFP_UART4_RXD       (0x2UL<<SYS_GPH_MFPL_PH0_MFP_Pos)           /*!< GPH_MFPL PH0 setting for UART4_RXD    */
#define SYS_GPH_MFPL_PH0_MFP_CAN1_RXD      (0x3UL<<SYS_GPH_MFPL_PH0_MFP_Pos)           /*!< GPH_MFPL PH0 setting for CAN1_RXD     */
#define SYS_GPH_MFPL_PH0_MFP_INT7      (0x8UL<<SYS_GPH_MFPL_PH0_MFP_Pos)           /*!< GPH_MFPL PH0 setting for INT7     */

//GPH_MFPL_PH1_MFP
#define SYS_GPH_MFPL_PH1_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH1_MFP_Pos)           /*!< GPH_MFPL PH1 setting for GPIO     */
#define SYS_GPH_MFPL_PH1_MFP_UART4_TXD       (0x1UL<<SYS_GPH_MFPL_PH1_MFP_Pos)            /*!< GPH_MFPL PH1 setting for UART4_TXD     */
#define SYS_GPH_MFPL_PH1_MFP_I2C1_SDA      (0x2UL<<SYS_GPH_MFPL_PH1_MFP_Pos)            /*!< GPH_MFPL PH1 setting for I2C1_SDA    */
#define SYS_GPH_MFPL_PH1_MFP_CAN1_TXD      (0x3UL<<SYS_GPH_MFPL_PH1_MFP_Pos)            /*!< GPH_MFPL PH1 setting for CAN1_TXD    */

//GPH_MFPL_PH2_MFP
#define SYS_GPH_MFPL_PH2_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH2_MFP_Pos)            /*!< GPH_MFPL PH2 setting for GPIO    */
#define SYS_GPH_MFPL_PH2_MFP_UART2_CTS       (0x1UL<<SYS_GPH_MFPL_PH2_MFP_Pos)           /*!< GPH_MFPL PH2 setting for UART2_CTS    */

//GPH_MFPL_PH3_MFP
#define SYS_GPH_MFPL_PH3_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH3_MFP_Pos)           /*!< GPH_MFPL PH3 setting for GPIO     */
#define SYS_GPH_MFPL_PH3_MFP_I2C3_SCL      (0x1UL<<SYS_GPH_MFPL_PH3_MFP_Pos)           /*!< GPH_MFPL PH3 setting for I2C3_SCL     */

//GPH_MFPL_PH4_MFP
#define SYS_GPH_MFPL_PH4_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH4_MFP_Pos)           /*!< GPH_MFPL PH4 setting for GPIO     */
#define SYS_GPH_MFPL_PH4_MFP_I2C3_SDA      (0x1UL<<SYS_GPH_MFPL_PH4_MFP_Pos)           /*!< GPH_MFPL PH4 setting for I2C3_SDA     */

//GPH_MFPL_PH5_MFP
#define SYS_GPH_MFPL_PH5_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH5_MFP_Pos)           /*!< GPH_MFPL PH5 setting for GPIO     */
#define SYS_GPH_MFPL_PH5_MFP_SPI2_SS0      (0x1UL<<SYS_GPH_MFPL_PH5_MFP_Pos)           /*!< GPH_MFPL PH5 setting for SPI2_SS0     */

//GPH_MFPL_PH6_MFP
#define SYS_GPH_MFPL_PH6_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH6_MFP_Pos)           /*!< GPH_MFPL PH6 setting for GPIO     */
#define SYS_GPH_MFPL_PH6_MFP_SPI2_CLK      (0x1UL<<SYS_GPH_MFPL_PH6_MFP_Pos)            /*!< GPH_MFPL PH6 setting for SPI2_CLK    */

//GPH_MFPL_PH7_MFP
#define SYS_GPH_MFPL_PH7_MFP_GPIO      (0x0UL<<SYS_GPH_MFPL_PH7_MFP_Pos)            /*!< GPH_MFPL PH7 setting for GPIO    */
#define SYS_GPH_MFPL_PH7_MFP_SPI2_MISO0      (0x1UL<<SYS_GPH_MFPL_PH7_MFP_Pos)            /*!< GPH_MFPL PH7 setting for SPI2_MISO0    */

//GPH_MFPL_PH8_MFP
#define SYS_GPH_MFPH_PH8_MFP_GPIO      (0x0UL<<SYS_GPH_MFPH_PH8_MFP_Pos)            /*!< GPH_MFPH PH8 setting for GPIO    */
#define SYS_GPH_MFPH_PH8_MFP_SPI2_MOSI0      (0x1UL<<SYS_GPH_MFPH_PH8_MFP_Pos)           /*!< GPH_MFPH PH8 setting for SPI2_MOSI0     */

//GPH_MFPH_PH9_MFP
#define SYS_GPH_MFPH_PH9_MFP_GPIO      (0x0UL<<SYS_GPH_MFPH_PH9_MFP_Pos)           /*!< GPH_MFPH PH9 setting for GPIO     */
#define SYS_GPH_MFPH_PH9_MFP_SPI2_MISO1      (0x1UL<<SYS_GPH_MFPH_PH9_MFP_Pos)           /*!< GPH_MFPH PH9 setting for SPI2_MISO1     */

//GPH_MFPH_PH10_MFP
#define SYS_GPH_MFPH_PH10_MFP_GPIO       (0x0UL<<SYS_GPH_MFPH_PH10_MFP_Pos)           /*!< GPH_MFPH PH10 setting for GPIO   */
#define SYS_GPH_MFPH_PH10_MFP_SPI2_MOSI1       (0x1UL<<SYS_GPH_MFPH_PH10_MFP_Pos)           /*!< GPH_MFPH PH10 setting for SPI2_MOSI1   */

//GPH_MFPH_PH11_MFP
#define SYS_GPH_MFPH_PH11_MFP_GPIO       (0x0UL<<SYS_GPH_MFPH_PH11_MFP_Pos)           /*!< GPH_MFPH PH11 setting for GPIO   */
#define SYS_GPH_MFPH_PH11_MFP_UART3_RXD       (0x1UL<<SYS_GPH_MFPH_PH11_MFP_Pos)           /*!< GPH_MFPH PH11 setting for UART3_RXD   */

//GPH_MFPH_PH12_MFP
#define SYS_GPH_MFPH_PH12_MFP_GPIO       (0x0UL<<SYS_GPH_MFPH_PH12_MFP_Pos)           /*!< GPH_MFPH PH12 setting for GPIO   */
#define SYS_GPH_MFPH_PH12_MFP_UART3_TXD       (0x1UL<<SYS_GPH_MFPH_PH12_MFP_Pos)           /*!< GPH_MFPH PH12 setting for UART3_TXD   */

//GPH_MFPH_PH13_MFP
#define SYS_GPH_MFPH_PH13_MFP_GPIO       (0x0UL<<SYS_GPH_MFPH_PH13_MFP_Pos)           /*!< GPH_MFPH PH13 setting for GPIO   */
#define SYS_GPH_MFPH_PH13_MFP_UART3_RTS       (0x1UL<<SYS_GPH_MFPH_PH13_MFP_Pos)           /*!< GPH_MFPH PH13 setting for UART3_RTS   */

//GPH_MFPH_PH14_MFP
#define SYS_GPH_MFPH_PH14_MFP_GPIO       (0x0UL<<SYS_GPH_MFPH_PH14_MFP_Pos)           /*!< GPH_MFPH PH14 setting for GPIO   */
#define SYS_GPH_MFPH_PH14_MFP_UART3_CTS       (0x1UL<<SYS_GPH_MFPH_PH14_MFP_Pos)           /*!< GPH_MFPH PH14 setting for UART3_CTS   */

//GPH_MFPH_PH15_MFP
#define SYS_GPH_MFPH_PH15_MFP_GPIO       (0x0UL<<SYS_GPH_MFPH_PH15_MFP_Pos)           /*!< GPH_MFPH PH15 setting for GPIO   */
#define SYS_GPH_MFPH_PH15_MFP_SC5_CLK       (0x2UL<<SYS_GPH_MFPH_PH15_MFP_Pos)           /*!< GPH_MFPH PH15 setting for SC5_CLK   */

//GPI_MFPL_PI0_MFP
#define SYS_GPI_MFPL_PI0_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI0_MFP_Pos)           /*!< GPI_MFPL PI0 setting for GPIO     */
#define SYS_GPI_MFPL_PI0_MFP_SC5_RST       (0x2UL<<SYS_GPI_MFPL_PI0_MFP_Pos)            /*!< GPI_MFPL PI0 setting for SC5_RST     */

//GPI_MFPL_PI1_MFP
#define SYS_GPI_MFPL_PI1_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI1_MFP_Pos)            /*!< GPI_MFPL PI1 setting for GPIO    */
#define SYS_GPI_MFPL_PI1_MFP_SC5_PWR       (0x2UL<<SYS_GPI_MFPL_PI1_MFP_Pos)            /*!< GPI_MFPL PI1 setting for SC5_PWR     */

//GPI_MFPL_PI2_MFP
#define SYS_GPI_MFPL_PI2_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI2_MFP_Pos)            /*!< GPI_MFPL PI2 setting for GPIO    */
#define SYS_GPI_MFPL_PI2_MFP_SC5_DAT       (0x2UL<<SYS_GPI_MFPL_PI2_MFP_Pos)           /*!< GPI_MFPL PI2 setting for SC5_DAT      */

//GPI_MFPL_PI3_MFP
#define SYS_GPI_MFPL_PI3_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI3_MFP_Pos)           /*!< GPI_MFPL PI3 setting for GPIO     */
#define SYS_GPI_MFPL_PI3_MFP_SPI3_SS0      (0x1UL<<SYS_GPI_MFPL_PI3_MFP_Pos)            /*!< GPI_MFPL PI3 setting for SPI3_SS0      */

//GPI_MFPL_PI4_MFP
#define SYS_GPI_MFPL_PI4_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI4_MFP_Pos)            /*!< GPI_MFPL PI4 setting for GPIO    */
#define SYS_GPI_MFPL_PI4_MFP_SPI3_CLK      (0x1UL<<SYS_GPI_MFPL_PI4_MFP_Pos)           /*!< GPI_MFPL PI4 setting for SPI3_CLK     */

//GPI_MFPL_PI5_MFP
#define SYS_GPI_MFPL_PI5_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI5_MFP_Pos)           /*!< GPI_MFPL PI5 setting for GPIO     */
#define SYS_GPI_MFPL_PI5_MFP_SPI3_MISO0      (0x1UL<<SYS_GPI_MFPL_PI5_MFP_Pos)           /*!< GPI_MFPL PI5 setting for SPI3_MISO0     */

//GPI_MFPL_PI6_MFP
#define SYS_GPI_MFPL_PI6_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI6_MFP_Pos)           /*!< GPI_MFPL PI6 setting for GPIO     */
#define SYS_GPI_MFPL_PI6_MFP_SPI3_MOSI0      (0x1UL<<SYS_GPI_MFPL_PI6_MFP_Pos)           /*!< GPI_MFPL PI6 setting for SPI3_MOSI0     */

//GPI_MFPL_PI7_MFP
#define SYS_GPI_MFPL_PI7_MFP_GPIO      (0x0UL<<SYS_GPI_MFPL_PI7_MFP_Pos)           /*!< GPI_MFPL PI7 setting for GPIO     */
#define SYS_GPI_MFPL_PI7_MFP_I2C2_SCL      (0x1UL<<SYS_GPI_MFPL_PI7_MFP_Pos)           /*!< GPI_MFPL PI7 setting for I2C2_SCL     */
#define SYS_GPI_MFPL_PI7_MFP_SPI3_MISO1      (0x2UL<<SYS_GPI_MFPL_PI7_MFP_Pos)           /*!< GPI_MFPL PI7 setting for SPI3_MISO1     */

//GPI_MFPL_PI8_MFP
#define SYS_GPI_MFPH_PI8_MFP_GPIO      (0x0UL<<SYS_GPI_MFPH_PI8_MFP_Pos)           /*!< GPI_MFPH PI8 setting for GPIO     */
#define SYS_GPI_MFPH_PI8_MFP_I2C2_SDA      (0x1UL<<SYS_GPI_MFPH_PI8_MFP_Pos)           /*!< GPI_MFPH PI8 setting for I2C2_SDA     */
#define SYS_GPI_MFPH_PI8_MFP_SPI3_MOSI1      (0x2UL<<SYS_GPI_MFPH_PI8_MFP_Pos)           /*!< GPI_MFPH PI8 setting for SPI3_MOSI1     */

//GPI_MFPH_PI9_MFP
#define SYS_GPI_MFPH_PI9_MFP_GPIO      (0x0UL<<SYS_GPI_MFPH_PI9_MFP_Pos)           /*!< GPI_MFPH PI9 setting for GPIO     */

//GPI_MFPH_PI10_MFP
#define SYS_GPI_MFPH_PI10_MFP_GPIO       (0x0UL<<SYS_GPI_MFPH_PI10_MFP_Pos)           /*!< GPI_MFPH PI10 setting for GPIO   */

//GPI_MFPH_PI11_MFP
#define SYS_GPI_MFPH_PI11_MFP_GPIO       (0x0UL<<SYS_GPI_MFPH_PI11_MFP_Pos)           /*!< GPI_MFPH PI11 setting for GPIO   */
#define SYS_GPI_MFPH_PI11_MFP_SPI2_SS0       (0x1UL<<SYS_GPI_MFPH_PI11_MFP_Pos)            /*!< GPI_MFPH PI11 setting for SPI2_SS0  */
#define SYS_GPI_MFPH_PI11_MFP_I2S1_BCLK       (0x2UL<<SYS_GPI_MFPH_PI11_MFP_Pos)            /*!< GPI_MFPH PI11 setting for I2S1_BCLK  */
#define SYS_GPI_MFPH_PI11_MFP_I2S4_SCL       (0x3UL<<SYS_GPI_MFPH_PI11_MFP_Pos)            /*!< GPI_MFPH PI11 setting for I2S4_SCL  */
#define SYS_GPI_MFPH_PI11_MFP_SC3_PWR       (0x4UL<<SYS_GPI_MFPH_PI11_MFP_Pos)            /*!< GPI_MFPH PI11 setting for SC3_PWR  */

//GPI_MFPH_PI12_MFP
#define SYS_GPI_MFPH_PI12_MFP_GPIO       (0x0UL<<SYS_GPI_MFPH_PI12_MFP_Pos)            /*!< GPI_MFPH PI12 setting for GPIO  */
#define SYS_GPI_MFPH_PI12_MFP_SPI2_MISO1       (0x1UL<<SYS_GPI_MFPH_PI12_MFP_Pos)            /*!< GPI_MFPH PI12 setting for SPI2_MISO1    */
#define SYS_GPI_MFPH_PI12_MFP_I2S1_LRCK      (0x2UL<<SYS_GPI_MFPH_PI12_MFP_Pos)            /*!< GPI_MFPH PI12 setting for I2S1_LRCK     */
#define SYS_GPI_MFPH_PI12_MFP_I2S4_SDA       (0x3UL<<SYS_GPI_MFPH_PI12_MFP_Pos)            /*!< GPI_MFPH PI12 setting for I2S4_SDA  */
#define SYS_GPI_MFPH_PI12_MFP_SC3_CD       (0x4UL<<SYS_GPI_MFPH_PI12_MFP_Pos)            /*!< GPI_MFPH PI12 setting for SC3_CD    */

//GPI_MFPH_PI13_MFP
#define SYS_GPI_MFPH_PI13_MFP_GPIO       (0x0UL<<SYS_GPI_MFPH_PI13_MFP_Pos)            /*!< GPI_MFPH PI13 setting for GPIO  */

//GPI_MFPH_PI14_MFP
#define SYS_GPI_MFPH_PI14_MFP_GPIO       (0x0UL<<SYS_GPI_MFPH_PI14_MFP_Pos)            /*!< GPI_MFPH PI14 setting for GPIO  */

//GPI_MFPH_PI15_MFP
#define SYS_GPI_MFPH_PI15_MFP_GPIO       (0x0UL<<SYS_GPI_MFPH_PI15_MFP_Pos)            /*!< GPI_MFPH PI15 setting for GPIO  */

/*@}*/ /* end of group NUC400_SYS_EXPORTED_CONSTANTS */

/** @addtogroup NUC400_SYS_EXPORTED_FUNCTIONS SYS Exported Functions
  @{
*/

#define SYS_CLEAR_BOD_INT_FLAG()        (SYS->BODCR &= ~SYS_BODCR_BOD_INTF_Msk)        /*!< This macro clear Brown-out interrupt flag */
#define SYS_CLEAR_BOD_LPM()             (SYS->BODCR &= ~SYS_BODCR_BOD_LPM_Msk)         /*!< This macro set Brown-out detect to normal mode */
#define SYS_DISABLE_BOD()               (SYS->BODCR &= ~SYS_BODCR_BOD_EN_Msk)          /*!< This macro disable Brown-out detect function */
#define SYS_ENABLE_BOD()                (SYS->BODCR |= SYS_BODCR_BOD_EN_Msk)           /*!< This macro enable Brown-out detect function and set BOD_LV=3.7V */
#define SYS_GET_BOD_INT_FLAG()          (SYS->BODCR & SYS_BODCR_BOD_INTF_Msk)          /*!< This macro get Brown-out detect interrupt flag */
#define SYS_GET_BOD_OUTPUT()            (SYS->BODCR & SYS_BODCR_BOD_OUT_Msk)           /*!< This macro get Brown-out detector output status */
#define SYS_DISABLE_BOD_RST()           (SYS->BODCR &= ~SYS_BODCR_BOD_RSTEN_Msk)       /*!< This macro enable Brown-out detect interrupt function */
#define SYS_ENABLE_BOD_RST()            (SYS->BODCR |= SYS_BODCR_BOD_RSTEN_Msk)        /*!< This macro enable Brown-out detect reset function */
#define SYS_SET_BOD_LPM()               (SYS->BODCR |= SYS_BODCR_BOD_LPM_Msk)          /*!< This macro set Brown-out detect to low power mode */
#define SYS_SET_BOD_LEVEL(u32Level)     (SYS->BODCR = (SYS->BODCR & ~SYS_BODCR_BOD_VL_Msk) | u32Level) /*!< This macro set Brown-out detect voltage level.u32Level=0~3 */
#define SYS_IS_BOD_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_BOD_Msk)        /*!< This macro get previous reset source is from Brown-out detect reset */
#define SYS_IS_CPU_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_CPU_Msk)        /*!< This macro get previous reset source is from CPU-Reset */
#define SYS_IS_LVR_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_LVR_Msk)        /*!< This macro get previous reset source is from Low-Voltage-Reset */
#define SYS_IS_POR_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_POR_Msk)        /*!< This macro get previous reset source is from Power-on Reset */
#define SYS_IS_RSTPIN_RST()             (SYS->RSTSRC & SYS_RSTSRC_RSTS_RESET_Msk)      /*!< This macro get previous reset source is from reset pin reset */
#define SYS_IS_SYSTEM_RST()             (SYS->RSTSRC & SYS_RSTSRC_RSTS_MCU_Msk)        /*!< This macro get previous reset source is from system reset */
#define SYS_IS_WDT_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_WDT_Msk)        /*!< This macro get previous reset source is from window watch dog  reset */
#define SYS_DISABLE_LVR()               (SYS->BODCR &= ~SYS_BODCR_LVR_EN_Msk)          /*!< This macro disable Low-Voltage Reset function */
#define SYS_ENABLE_LVR()                (SYS->BODCR |= SYS_BODCR_LVR_EN_Msk)           /*!< This macro enable Low-Voltage Reset function */
#define SYS_DISABLE_POR()               (SYS->PORCR = 0x5AA5)                          /*!< This macro disable Power-on Reset function */
#define SYS_ENABLE_POR()                (SYS->PORCR = 0)                               /*!< This macro enable Power-on Reset function */
#define SYS_CLEAR_RST_SOURCE(u32RstSrc) (SYS->RSTSRC = u32RstSrc )

void SYS_ClearResetSrc(uint32_t u32Src);
uint32_t SYS_GetBODStatus(void);
uint32_t SYS_GetResetSrc(void);
uint32_t SYS_IsRegLocked(void);
void SYS_LockReg(void);
void SYS_UnlockReg(void);
uint32_t  SYS_ReadPDID(void);
void SYS_ResetChip(void);
void SYS_ResetCPU(void);
void SYS_ResetModule(uint32_t u32ModuleIndex);
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel);
void SYS_DisableBOD(void);

/*@}*/ /* end of group NUC400_SYS_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_SYS_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__SYS_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
