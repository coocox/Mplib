
/**************************************************************************//**
 * @file     pac5xxx_tile_PowerManager.h
 * @brief    CMSIS Header File for the PAC5XXX Power Manager Tile
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
 

/** @addtogroup PAC5XXX_Tile_PowerManager PAC5XXX Power Manager Tile
  @{
*/

/*!< Power Manager Register Addresses */

typedef enum {
	ADDR_PWRCTL = 0x10,						/*!< Power Manager Control Register								*/
	ADDR_PWRSTAT = 0x11,					/*!< Power Manager Status Register   							*/
	ADDR_PSTATSET = 0x12,					/*!< Power Manager Status Settings								*/
	ADDR_IMOD = 0x13,						/*!< Current Modulation Register      							*/
	ADDR_SCFG = 0x14						/*!< Power Manager Monitor 1 Register  							*/
} Power_Manager_Reg_Addr;

//
// Type Enumerations
//

/** PAC5XXX WUTIMER Enumeration Type */
typedef enum {
	WUTIMER_INFINITE = 0,					/*!< Wake up timer: infinite									*/
	WUTIMER_125ms = 1,						/*!< Wake up timer: 125 ms										*/
	WUTIMER_250ms = 2,						/*!< Wake up timer: 250 ms										*/
	WUTIMER_500ms = 3,						/*!< Wake up timer: 500 ms										*/
	WUTIMER_1s = 4,							/*!< Wake up timer: 1 s	  										*/
	WUTIMER_2s = 5,							/*!< Wake up timer: 2 s											*/
	WUTIMER_4s = 6,							/*!< Wake up timer: 4 s											*/
	WUTIMER_8s = 7							/*!< Wake up timer: 8 s											*/
} PAC5XXX_WUTIMER_Type;

/** PAC5XXX PWMMON Enumeration Type */
typedef enum {
	PWRMON_VCORE = 0,						/*!< Select signal for AB11 ADC Monitoring: VCORE				*/
	PWRMON_VDDAx4div10 = 1,					/*!< Select signal for AB11 ADC Monitoring: VDDA * 4 / 10 		*/
	PWRMON_VDDIOx4div10 = 2,				/*!< Select signal for AB11 ADC Monitoring: VDDIO * 4 / 10		*/
	PWRMON_VSYSx4div10 = 3,					/*!< Select signal for AB11 ADC Monitoring: VSYS * 4 / 10		*/
	PWRMON_REGIx1div10 = 4,					/*!< Select signal for AB11 ADC Monitoring: REGI * 1 / 10		*/
	PWRMON_VPx1div10 = 5,					/*!< Select signal for AB11 ADC Monitoring: VP * 1 / 10  		*/
	PWRMON_VHMx1div30 = 6,					/*!< Select signal for AB11 ADC Monitoring: VHM * 1 / 30		*/
	PWRMON_VCOMP = 7						/*!< Select signal for AB11 ADC Monitoring: VCOMP				*/
} PAC5XXX_PWRMON_Type;

/** PAC5XXX Watchdog Timer (TWD) Time Enumeration Type */
typedef enum {
	TWD_4s = 0,								/*!< Watchdog time: 4s											*/
	TWD_8s = 1								/*!< Watchdog time: 8s											*/
} PAC5XXX_TWD_Type;

/** PAC5XXX DMAX Setting Enumeration Type */
typedef enum {
	DMAX_500ns_min_off = 0,					/*!< 500ns minimum off time										*/
	DMAX_75pct = 1							/*!< 75% maximum duty											*/
} PAC5XXX_DMAX_Type;

/** PAC5XXX Switching Frequency Setting (FSWM) Enumeration Type */
typedef enum {
	FREQ_500_kHZ = 0,						/*!< Switching Frequency Setting: 500kHz (FMODE = 0)			*/
	FREQ_400_kHZ = 1,						/*!< Switching Frequency Setting: 400kHz (FMODE = 0)			*/
	FREQ_330_kHZ = 2,						/*!< Switching Frequency Setting: 330kHz (FMODE = 0)			*/
	FREQ_289_kHZ = 3,						/*!< Switching Frequency Setting: 289kHz (FMODE = 0)			*/
	FREQ_250_kHZ = 4,						/*!< Switching Frequency Setting: 250kHz (FMODE = 0)			*/
	FREQ_220_kHZ = 5,						/*!< Switching Frequency Setting: 220kHz (FMODE = 0)			*/
	FREQ_200_kHZ = 6,						/*!< Switching Frequency Setting: 200kHz (FMODE = 0)			*/
	FREQ_181_kHZ = 7,						/*!< Switching Frequency Setting: 181kHz (FMODE = 0)			*/
	FREQ_125_kHZ = 0,						/*!< Switching Frequency Setting: 125kHz (FMODE = 1)			*/
	FREQ_100_kHZ = 1,						/*!< Switching Frequency Setting: 100kHz (FMODE = 1)			*/
	FREQ_83_kHZ = 2,						/*!< Switching Frequency Setting: 83kHz (FMODE = 1)				*/
	FREQ_72_kHZ = 3,						/*!< Switching Frequency Setting: 72kHz (FMODE = 1)				*/
	FREQ_63_kHZ = 4,						/*!< Switching Frequency Setting: 63kHz (FMODE = 1)				*/
	FREQ_55_kHZ = 5,						/*!< Switching Frequency Setting: 55kHz (FMODE = 1)				*/
	FREQ_50_kHZ = 6,						/*!< Switching Frequency Setting: 50kHz (FMODE = 1)				*/
	FREQ_45_kHZ = 7							/*!< Switching Frequency Setting: 45kHz (FMODE = 1)				*/
} PAC5XXX_FSWM_Type;

/** PAC5XXX FMODE Buck Frequency Setting Enumeration Type */
typedef enum {
	FMODE_45kHz_125kHz = 0,					/*!< FMODE: startup, ultra high buck [45kHz - 125kHz]			*/
	FMODE_181kHz_500kHz = 1					/*!< FMODE: medium voltage buck [181kHz - 500kHz]				*/
} PAC5XXX_FMODE_Buck_Type;

/** PAC5XXX VHM Clamp Selection Enumeration Type */
typedef enum {
	VCLAMPSEL_20V = 0,						/*!< VHM Clamp Selection: 20V									*/
	VCLAMPSEL_69V = 1						/*!< VHM Clamp Selection: 69V									*/
} PAC5XXX_VCLAMPSEL_Type;

//
// Bit Definitions
//

/*!< Power Manager Tile Registers */

/*!< PWRCTL: Address: 0x10		Power Manager Control Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t WUTIMER				: 3;		/*!< Wake-up timer											*/
		__IO uint8_t PWRMON					: 3;		/*!< Selects signal for ADC Monitoring						*/
		__IO uint8_t MCUALIVE				: 1;		/*!< Indicates MCU alive (release all pull-down Rs)			*/
		__IO uint8_t HIB					: 1;		/*!< Shutdown mode (1)										*/
	};
} PWRCTL;

/*!< PWRSTAT: Address: 0x11		Power Manager Status Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t VCOREFLT				: 1;		/*!< VCORE error status (write 1 to clear)					*/
		__IO uint8_t VDDAFLT				: 1;		/*!< VDDA error status (write 1 to clear)					*/
		__IO uint8_t VDDIOFLT				: 1;		/*!< VDDIO error status (write 1 to clear)					*/
		__IO uint8_t VSYSFLT				: 1;		/*!< VSYS error status (write 1 to clear)					*/
		__IO uint8_t TMPFLT					: 1;		/*!< Temperature error status (write 1 to clear)			*/
		__IO uint8_t DCDCFLT				: 1;		/*!< DCDC error status (write 1 to clear)					*/
		__IO uint8_t WDTRSTAT				: 1;		/*!< Watchdog Timer Reset Status (write 1 to clear)			*/
		__IO uint8_t HWRSTAT				: 1;		/*!< Hardware Reset Status (write 1 to clear)				*/
	};
} PWRSTAT;

/*!< PSTATSET: Address: 0x12	Power Status Setting */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t PBEN					: 1;		/*!< Push Button Enable: 0 = disabled, 1 = enabled			*/
		__IO uint8_t WDTEN					: 1;		/*!< Watchdog Timer Enable: 0 = disabled, 1 = enabled 		*/
		__IO uint8_t TWD					: 1;		/*!< Watchdog Timer (0 = 4s, 1 = 8s)						*/
		__IO uint8_t nVPINTM				: 1;		/*!< VPLOW Interrupt Mask (0: mask, 1: not masked)			*/
		__IO uint8_t nPBINTM				: 1;		/*!< Push-button Interrupt Mask (0: mask, 1: not masked)	*/
		__IO uint8_t VPLOW					: 1;		/*!< VP Low status. Write 1 to clear when not masked. 		*/
		     uint8_t                        : 1;
		__IO uint8_t UNLOCK					: 1;		/*!< Software Unlock. Write 1 to allow MCU to write SCFG.	*/
	};
} PSTATSET;

/*!< SCFG: Address: 0x14		Switcher Configuration (unlocked by UNLOCK) */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t DMAX					: 1;		/*!< Maximum Duty (\a PAC5XXX_DMAX_Type)						*/
		__IO uint8_t FSWM					: 3;		/*!< Switching Frequency Setting (\a PAC5XXX_FSWM_Type)			*/
		__IO uint8_t FMODE					: 1;		/*!< Switching Frequency Mode (\a PAC5XXX_FMODE_Type)			*/
		__IO uint8_t VCLAMPSEL				: 1;		/*!< VHM Clamp Selection (\a PAC5XXX_VCLAMPSEL_Type)			*/
		__IO uint8_t DIGCTL					: 1;		/*!< Digital Control										*/
		__IO uint8_t SRST					: 1;		/*!< Soft Reset: Write 1 to assert nRST						*/
	};
} SCFG;


/*@}*/ /* end of group PAC5XXX_Tile_PowerManager */


