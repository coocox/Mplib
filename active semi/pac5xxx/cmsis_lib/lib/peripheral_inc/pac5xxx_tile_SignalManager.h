
/**************************************************************************//**
* @file     act_tile_SignalManager.h
* @brief    CMSIS Header File for the PAC5XXX Signal Manager Tile
* @version  V0.2
* @date     17 May 2012
*
* @note
* Copyright (C) 2012 Active Semiconductor. All rights reserved.
*
* @par
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
* CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
******************************************************************************/


/** @addtogroup PAC5XXX_Tile_SignalManager PAC5XXX Signal Manager Tile
@{
*/

/*!< Signal Manager EMUX/Mini-SPI data definitions */

typedef enum {
	SIGMGR_AIO10 = 0,				/*!< Differential Analog AIO01 									*/
	SIGMGR_AIO32 = 1,				/*!< Differential Analog AIO32 									*/
	SIGMGR_AIO54 = 2,				/*!< Differential Analog AIO54 									*/
	SIGMGR_AB1 = 3,					/*!< Analog Bus Input 1 (AB1)									*/
	SIGMGR_AB2 = 4,					/*!< Analog Bus Input 2 (AB2)									*/
	SIGMGR_AB3 = 5,					/*!< Analog Bus Input 3 (AB3)									*/
	SIGMGR_AB4 = 6,					/*!< Analog Bus Input 4 (AB4)									*/
	SIGMGR_AB5 = 7,					/*!< Analog Bus Input 5 (AB5)									*/
	SIGMGR_AB6 = 8,					/*!< Analog Bus Input 6 (AB6)									*/
	SIGMGR_AB7 = 9,					/*!< Analog Bus Input 7 (AB7)									*/
	SIGMGR_AB8 = 10,				/*!< Analog Bus Input 8 (AB8)									*/
	SIGMGR_AB9 = 11,				/*!< Analog Bus Input 9 (AB9)									*/
	SIGMGR_AB10 = 12,				/*!< Analog Bus Input 10 (AB10)									*/
	SIGMGR_AB11 = 13,				/*!< Analog Bus Input 11 (AB11)									*/
	SIGMGR_AB12 = 14,				/*!< Analog Bus Input 12 (AB12)									*/
	SIGMGR_VREFDIV2 = 15			/*!< VREF/2														*/
} Signal_Manager_MUX_Select;

/**
 *  Mini-SPI bit definitions
 *
 *  MUXCLK   0   1   2   3   4   5   6   7
 *  MUXDAT  C1  C0 SH1 SH0  A3  A2  A1  A0
 *
 *  A[3:0]:	Analog IO value from \a Signal_Manager_MUX_Select enumeration
 *  SH0:	Enable sample and hold for AIO10, AIO32 or AIO54
 *  SH1:	Enable sample and hold for 3-phase comparators
 *  C[1:0]	Set to 01b to activate mini-SPI
 */

#define SIGMGR_EN_MSPI					0x40															/*!< C[1:0] to activate mini-SPI			*/
#define SIGMGR_EN_SH_DIFFAMP 			0x20															/*!< SH0 to activate S&H for DiffAmp 		*/
#define SIGMGR_EN_SH_COMP 				0x10															/*!< SH1 to activate S&H for Comparators	*/

#define SIGMGR_MSPI(channel)			((channel) | SIGMGR_EN_MSPI)									/*!< MSPI data for given channel 					*/
#define SIGMGR_MSPI_SH_DIFFAMP			(SIGMGR_EN_MSPI | SIGMGR_EN_SH_DIFFAMP)							/*!< MSPI data for S&H start on DiffAmp channels 	*/
#define SIGMGR_MSPI_SH_COMP				(SIGMGR_EN_MSPI | SIGMGR_EN_SH_COMP)							/*!< MSPI data for comparator 						*/

/*!< Signal Manager Tile Register Addresses */

typedef enum {
	ADDR_CFGAIO0 = 0x20,			/*!< Signal Manager AIO0 Configuration Register					*/
	ADDR_CFGAIO1 = 0x21,			/*!< Signal Manager AIO1 Configuration Register					*/
	ADDR_CFGAIO2 = 0x22,			/*!< Signal Manager AIO2 Configuration Register					*/
	ADDR_CFGAIO3 = 0x23,			/*!< Signal Manager AIO3 Configuration Register					*/
	ADDR_CFGAIO4 = 0x24,			/*!< Signal Manager AIO4 Configuration Register					*/
	ADDR_CFGAIO5 = 0x25,			/*!< Signal Manager AIO5 Configuration Register					*/
	ADDR_CFGAIO6 = 0x26,			/*!< Signal Manager AIO6 Configuration Register					*/
	ADDR_CFGAIO7 = 0x27,			/*!< Signal Manager AIO7 Configuration Register					*/
	ADDR_CFGAIO8 = 0x28,			/*!< Signal Manager AIO8 Configuration Register					*/
	ADDR_CFGAIO9 = 0x29,			/*!< Signal Manager AIO9 Configuration Register					*/
	ADDR_SIGSET = 0x2A,			    /*!< Signal Manager Setting Register							*/
	ADDR_HPDAC = 0x2B,				/*!< High Protection Threshold DAC Control 0 Register			*/
	ADDR_LPDAC0 = 0x2C,				/*!< Low Protection Threshold DAC Control 0 Register			*/
	ADDR_LPDAC1 = 0x2D,				/*!< Low Protection Threshold DAC Control 1 Register			*/
	ADDR_ADCSCAN = 0x2E,			/*!< ADC Scan Control											*/
	ADDR_ADCIN1 = 0x2F,				/*!< ADC Input Select 1											*/
	ADDR_PROTINTM = 0x30,			/*!< Protection Interrupt Mask									*/
	ADDR_PROTSTAT = 0x31,			/*!< Protection Status											*/
	ADDR_DOUTSIG0 = 0x32,			/*!< Signal Manager Data Output 0								*/
	ADDR_DOUTSIG1 = 0x33,			/*!< Signal Manager Data Output 1								*/
	ADDR_DINSIG0 = 0x34,			/*!< Signal Manager Data Input 0								*/
	ADDR_DINSIG1 = 0x35,			/*!< Signal Manager Data Input 1								*/
	ADDR_SIGINTM = 0x36,			/*!< AIO Interrupt Mask											*/
	ADDR_SIGINTF = 0x37,			/*!< AIO Interrupt Flag											*/
	ADDR_ENSIG = 0x38				/*!< Signal Manager Enable										*/
} Signal_Manager_Reg_Addr;

/*!< Signal Manager Tile Register Definitions */

/*!< CFGAIO0: Address: 0x20		AIO0 Configuration Register */
union {
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX0     				: 3;		/*!< MUX setting for AIO0 						*/
		__IO uint8_t POL0					: 1;		/*!< Polarity setting for AIO0					*/
		__IO uint8_t OPT0					: 2;		/*!< Option setting for AIO0					*/
		__IO uint8_t MODE0					: 2;		/*!< Mode setting for AIO0						*/
	};
} CFGAIO0;

/*!< CFGAIO1: Address: 0x21		AIO1 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX1					: 3;		/*!< MUX setting for AIO1						*/
		__IO uint8_t POL1					: 1;		/*!< Polarity setting for AIO1					*/
		__IO uint8_t OPT1					: 2;		/*!< Option setting for AIO1					*/
			 uint8_t						: 2;
	};
} CFGAIO1;

/*!< CFGAIO2: Address: 0x22		AIO2 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX2					: 3;		/*!< MUX setting for AIO2						*/
		__IO uint8_t POL2					: 1;		/*!< Polarity setting for AIO2					*/
		__IO uint8_t OPT2					: 2;		/*!< Option setting for AIO2					*/
		__IO uint8_t MODE2					: 2;		/*!< Mode setting for AIO2						*/
	};
} CFGAIO2;

/*!< CFGAIO3: Address: 0x23		AIO3 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX3					: 3;		/*!< MUX setting for AIO3						*/
		__IO uint8_t POL3					: 1;		/*!< Polarity setting for AIO3					*/
		__IO uint8_t OPT3					: 2;		/*!< Option setting for AIO3					*/
			 uint8_t    					: 2;
	};
} CFGAIO3;

/*!< CFGAIO4: Address: 0x24		AIO4 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX4					: 3;		/*!< MUX setting for AIO4						*/
		__IO uint8_t POL4					: 1;		/*!< Polarity setting for AIO4					*/
		__IO uint8_t OPT4					: 2;		/*!< Option setting for AIO4					*/
		__IO uint8_t MODE4					: 2;		/*!< Mode setting for AIO4						*/
	};
} CFGAIO4;

/*!< CFGAIO5: Address: 0x25		AIO5 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX5					: 3;		/*!< MUX setting for AIO5						*/
		__IO uint8_t POL5					: 1;		/*!< Polarity setting for AIO5					*/
		__IO uint8_t OPT5					: 2;		/*!< Option setting for AIO5					*/
			 uint8_t    					: 2;
	};
} CFGAIO5;

/*!< CFGAIO6: Address: 0x26		AIO6 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX6					: 3;		/*!< MUX setting for AIO6						*/
		__IO uint8_t POL6					: 1;		/*!< Polarity setting for AIO6					*/
		__IO uint8_t OPT6					: 2;		/*!< Option setting for AIO6					*/
		__IO uint8_t MODE6					: 2;		/*!< Mode setting for AIO6						*/
	};
} CFGAIO6;

/*!< CFGAIO7: Address: 0x27		AIO7 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX7					: 3;		/*!< MUX setting for AIO7						*/
		__IO uint8_t POL7					: 1;		/*!< Polarity setting for AIO7					*/
		__IO uint8_t OPT7					: 2;		/*!< Option setting for AIO7					*/
		__IO uint8_t MODE7					: 2;		/*!< Mode setting for AIO7						*/
	};
} CFGAIO7;

/*!< CFGAIO8: Address: 0x28		AIO8 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX8					: 3;		/*!< MUX setting for AIO8						*/
		__IO uint8_t POL8					: 1;		/*!< Polarity setting for AIO8					*/
		__IO uint8_t OPT8					: 2;		/*!< Option setting for AIO8					*/
		__IO uint8_t MODE8					: 2;		/*!< Mode setting for AIO8						*/
	};
} CFGAIO8;

/*!< CFGAIO9: Address: 0x29		AIO9 Configuration Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX9					: 3;		/*!< MUX setting for AIO9						*/
		__IO uint8_t POL9					: 1;		/*!< Polarity setting for AIO9					*/
		__IO uint8_t OPT9					: 2;		/*!< Option setting for AIO9					*/
		__IO uint8_t MODE9					: 2;		/*!< Mode setting for AIO9						*/
	};
} CFGAIO9;

/*!< SIGSET: Address: 0x2A		Signal Manager Setting */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t HPDACAB2				: 1;		/*!< Connect HPDAC output to AB2				*/
		__IO uint8_t LPDACAB3				: 1;		/*!< Connect LPDAC output to AB3				*/
		__IO uint8_t LPROTHYS				: 1;		/*!< Low Protection Comparator Hysteresis enbl  */
		__IO uint8_t HPROTHYS				: 1; 		/*!< High Protection Comparator Hys Enbl		*/
		__IO uint8_t AIO6HYS				: 1;		/*!< AIO6 Comparator Hys Enable					*/
		__IO uint8_t AIO7HYS				: 1;		/*!< AIO7 Comparator Hys Enable					*/
		__IO uint8_t AIO8HYS				: 1;		/*!< AIO8 Comparator Hys Enable					*/
		__IO uint8_t AIO9HYS				: 1;		/*!< AIO9 Comparator Hys Enable					*/
	};
} SIGSTAT;

/*!< LPDAC1: Address: 0x2D		Low Protection Threshold DAC Control 1 */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t VAL					: 2;		/*!< DAC register lower two bits				*/
			 uint8_t                        : 6;
	};
} LPDAC1;

/*!< ADCSCAN: Address: 0x2E		ADC Scan Control */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t DAO54SH					: 1;		/*!< Enable S&H circuit to sync DiffAmp 54		*/
		__IO uint8_t DAO32SH					: 1;		/*!< Enable S&H circuit to sync DiffAmp 32		*/
		__IO uint8_t DAO10SH					: 1;		/*!< Enable S&H circuit to sync DiffAmp 10		*/
		__IO uint8_t ENADCBUF					: 1; 		/*!< ADC buffer circuit enable					*/
		__IO uint8_t ENSCAN						: 1;		/*!< ADC scan control circuit enable			*/
			 uint8_t 							: 3;
	};
} ADCSCAN;

/*!< ADCIN1: Address: 0x2E		ADC Input Select 1 */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t VAL					: 4;		/*!< Signal select for ADCIN when ENMUXCH = 0	*/
			 uint8_t                        : 4;
	};
} ADCIN1;

/*!< PROTINTM: Address: 0x30	Protection Interrupt Mask */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t nLP10INTM				: 1;		/*!< LPROT10 Interrupt Mask (active low)		*/
		__IO uint8_t nLP32INTM				: 1;		/*!< LPROT32 Interrupt Mask (active low)		*/
		__IO uint8_t nLP54INTM				: 1;		/*!< LPROT54 Interrupt Mask (active low)		*/
		     uint8_t						: 1;
		__IO uint8_t nHP10INTM				: 1;		/*!< HPROT10 Interrupt Mask (active low)		*/
		__IO uint8_t nHP32INTM				: 1;		/*!< HPROT32 Interrupt Mask (active low)		*/
		__IO uint8_t nHP54INTM				: 1;		/*!< HPROT54 Interrupt Mask (active low)		*/
		     uint8_t                        : 1;
	};
} PROTINTM;

/*!< PROTSTAT: Address: 0x31	Protection Status */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t LPROT10				: 1;		/*!< LPROT10 Status (write 1 to clear)			*/
		__IO uint8_t LPROT32				: 1;		/*!< LPROT32 Status (write 1 to clear)			*/
		__IO uint8_t LPROT54				: 1;		/*!< LPROT54 Status (write 1 to clear) 			*/
		     uint8_t						: 1;
		__IO uint8_t HPROT10				: 1;		/*!< HPROT10 Status (write 1 to clear)			*/
		__IO uint8_t HPROT32				: 1;		/*!< HPROT32 Status (write 1 to clear)			*/
		__IO uint8_t HPROT54				: 1;		/*!< HPROT54 Status (write 1 to clear)			*/
		     uint8_t						: 1;
	};
} PROTSTAT;

/*!< DOUTSIG0: Address: 0x32	Signal Manager Data Output 0 */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t DOUT0					: 1;		/*!< Data output from AIO0						*/
		__IO uint8_t DOUT1					: 1;		/*!< Data output from AIO1						*/
		__IO uint8_t DOUT2					: 1;		/*!< Data output from AIO2						*/
		__IO uint8_t DOUT3					: 1;		/*!< Data output from AIO3						*/
		__IO uint8_t DOUT4					: 1;		/*!< Data output from AIO4						*/
		__IO uint8_t DOUT5					: 1;		/*!< Data output from AIO5						*/
		     uint8_t 						: 2;
	};
} DOUTSIG0;

/*!< DOUTSIG1: Address: 0x33	Signal Manager Data Output 1 */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t DOUT6					: 1;		/*!< Data output from AIO6						*/
		__IO uint8_t DOUT7					: 1;		/*!< Data output from AIO7						*/
		__IO uint8_t DOUT8					: 1;		/*!< Data output from AIO8						*/
		__IO uint8_t DOUT9					: 1;		/*!< Data output from AIO9						*/
		     uint8_t 						: 4;
	};
} DOUTSIG1;

/*!< DINSIG0: Address: 0x34		Signal Manager Data Input 0 */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t DIN0					: 1;		/*!< Data input from AIO0						*/
		__IO uint8_t DIN1					: 1;		/*!< Data input from AIO1						*/
		__IO uint8_t DIN2					: 1;		/*!< Data input from AIO2						*/
		__IO uint8_t DIN3					: 1;		/*!< Data input from AIO3						*/
		__IO uint8_t DIN4					: 1;		/*!< Data input from AIO4						*/
		__IO uint8_t DIN5					: 1;		/*!< Data input from AIO5						*/
		     uint8_t               			: 2;
	};
} DINSIG0;

/*!< DINSIG1: Address: 0x35		Signal Manager Data Input 1 */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t DIN6					: 1;		/*!< Data input from AIO6						*/
		__IO uint8_t DIN7					: 1;		/*!< Data input from AIO7						*/
		__IO uint8_t DIN8					: 1;		/*!< Data input from AIO8						*/
		__IO uint8_t DIN9					: 1;		/*!< Data input from AIO9						*/
		     uint8_t               			: 4;
	};
} DINSIG1;

/*!< SIGINTM: Address: 0x36		AIO Interrupt Mask */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t nAIO6FINTM				: 1;		/*!< AIO6 Falling Edge mask (0: masked)			*/
		__IO uint8_t nAIO7FINTM				: 1;		/*!< AIO7 Falling Edge mask (0: masked)			*/
		__IO uint8_t nAIO8FINTM				: 1;		/*!< AIO8 Falling Edge mask (0: masked)			*/
		__IO uint8_t nAIO9FINTM				: 1;		/*!< AIO9 Falling Edge mask (0: masked)			*/
		__IO uint8_t nAIO6RINTM				: 1;		/*!< AIO6 Rising Edge mask (0: masked)			*/
		__IO uint8_t nAIO7RINTM				: 1;		/*!< AIO7 Rising Edge mask (0: masked)			*/
		__IO uint8_t nAIO8RINTM				: 1;		/*!< AIO8 Rising Edge mask (0: masked)			*/
		__IO uint8_t nAIO9RINTM				: 1;		/*!< AIO9 Rising Edge mask (0: masked)			*/
	};
} SIGINTM;

/*!< SIGINTF: Address: 0x37		AIO Interrupt Flag */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t AIO6INTF				: 1;		/*!< AIO6 Interrupt Flag. Write 1 to clear.		*/
		__IO uint8_t AIO7INTF				: 1;		/*!< AIO7 Interrupt Flag. Write 1 to clear.		*/
		__IO uint8_t AIO8INTF				: 1;		/*!< AIO8 Interrupt Flag. Write 1 to clear.		*/
		__IO uint8_t AIO9INTF				: 1;		/*!< AIO9 Interrupt Flag. Write 1 to clear.		*/
		     uint8_t                        : 4;
	};
} SIGINTF;

/*!< ENSIG: Address: 0x38		Signal Manager Tile Enable */
union
{
	__IO uint8_t b;
	struct
	{
		__IO uint8_t ENSIG					: 1;		/*!< SigMgr tile enable: 1; Disable: 0			*/
			 uint8_t 						: 7;
	};
} ENSIG;


/*@}*/ /* end of group PAC5XXX_Tile_SignalManager */


