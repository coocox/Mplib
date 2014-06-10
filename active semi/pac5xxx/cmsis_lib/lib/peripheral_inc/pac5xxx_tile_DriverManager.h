
/**************************************************************************//**
 * @file     act_tile_DriverManager.h
 * @brief    CMSIS Header File for the PAC5XXX System Manager Tile
 * @version  V0.1
 * @date     21 Sep 2011
 *
 * @note
 * Copyright (C) 2011 Active Semiconductor. All rights reserved.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/
 

/** @addtogroup PAC5XXX_Tile_DriverManager PAC5XXX Driver Manager Tile
  @{
*/

/*!< Driver Manager Register Addresses */

typedef enum {
	ADDR_CFGDRV0 = 0x60,					/*!< Driver Manager Configuration 0 Register					*/
	ADDR_CFGDRV1 = 0x61,					/*!< Driver Manager Configuration 1 Register					*/
	ADDR_CFGDRQ6 = 0x62,					/*!< DRQ6 Configuration											*/
	ADDR_CFGDRQ7 = 0x63,					/*!< DRQ7 Configuration											*/
	ADDR_DOUTDRV = 0x64,					/*!< Driver Manager Data output									*/
	ADDR_DINDRV = 0x65,						/*!< Driver Manager Data input									*/
	ADDR_ENDRV = 0x66,						/*!< Enable Driver Manager Tile									*/
	ADDR_ENBBM = 0x67						/*!< Enable BBM (break before make) function					*/
} Driver_Manager_Reg_Addr;

//
// Type Enumerations
//

/** PAC5XXX Propogation Delay Type Enumeration */
typedef enum 
{
	PAC5XXX_PROP_DEL_0ns = 0,					/*!< Propagation Delay: 0ns										*/
	PAC5XXX_PROP_DEL_50ns = 1,					/*!< Propagation Delay: 50ns									*/
	PAC5XXX_PROP_DEL_100ns = 2,					/*!< Propagation Delay: 100ns									*/
	PAC5XXX_PROP_DEL_200ns = 3					/*!< Propagation Delay: 200ns									*/
} PAC5XXX_PropDelay_Type;

/** PAC5XXX Driver Option Setting Type Enumeration */
typedef enum 
{
	PAC5XXX_DRVOPT_IN = 0,						/*!< Driver Option: Input										*/
	PAC5XXX_DRVOPT_ODSTRONG = 1,				/*!< Driver Option: Open-Drain Strong Driver					*/
	PAC5XXX_DRVOPT_OD = 2						/*!< Driver Option: Open-Drain Output							*/
} PAC5XXX_DriverOption_Type;

/** PAC5XXX Driver Polarity Setting Type Enumeration */
typedef enum
{
	PAC5XXX_POLARITY_PAC5XXXHIGH = 0,				/*!< Driver Polarity Setting: active high						*/
	PAC5XXX_POLARITY_PAC5XXXLOW = 1					/*!< Driver Polarity Setting: active low						*/
} PAC5XXX_DriverPolarity_Type;

/** PAC5XXX Driver MUX Setting Type Enumeration */
typedef enum
{
	PAC5XXX_DRVMUX_DRQnIN = 0,					/*!< Driver MUX Setting: DRQ<n>IN								*/
	PAC5XXX_DRVMUX_DB1 = 1,						/*!< Driver MUX Setting: DB[1]									*/
	PAC5XXX_DRVMUX_DB2 = 2,						/*!< Driver MUX Setting: DB[2]									*/
	PAC5XXX_DRVMUX_DB3 = 3,						/*!< Driver MUX Setting: DB[3]									*/
	PAC5XXX_DRVMUX_DB4 = 4,						/*!< Driver MUX Setting: DB[4]									*/
	PAC5XXX_DRVMUX_DB5 = 5,						/*!< Driver MUX Setting: DB[5]									*/
	PAC5XXX_DRVMUX_DB6 = 6,						/*!< Driver MUX Setting: DB[6]									*/
	PAC5XXX_DRVMUX_DB7 = 7						/*!< Driver MUX Setting: DB[7]									*/
} PAC5XXX_DriverMux_Type;
	

//
// Bit Definitions
//

/*!< Driver Manager Tile Registers */

/*!< CFGDRV0: Address: 0x60		Driver Manager Configuration 0 Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t PROP0  				: 2;		/*!< Prop Delay 0 (\a PAC5XXX_PropDelay_Type)		*/
		__IO uint8_t PROP1					: 2;		/*!< Prop Delay 1 (\a PAC5XXX_PropDelay_Type)		*/
		__IO uint8_t PROP2					: 2;		/*!< Prop Delay 2 (\a PAC5XXX_PropDelay_Type)		*/
		__IO uint8_t PROP3					: 2;		/*!< Prop Delay 3 (\a PAC5XXX_PropDelay_Type)		*/
	};
} CFGDRV0;

/*!< CFGDRV1: Address: 0x61		Driver Manager Configuration 1 Register */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t PROP4					: 2;		/*!< Prop Delay 4 (\a PAC5XXX_PropDelay_Type)		*/
		__IO uint8_t PROP5					: 2;		/*!< Prop Delay 5 (\a PAC5XXX_PropDelay_Type)		*/
		__IO uint8_t nLSPR2M				: 1;		/*!< Low-Side PR2 Protection Mask (act low)     */
		__IO uint8_t nLSPR1M				: 1;		/*!< Low-Side PR1 Protection Mask (act low)     */
		__IO uint8_t nHSPR2M				: 1;		/*!< High-Side PR2 Protection Mask (act low) 	*/
		__IO uint8_t nHSPR1M				: 1;		/*!< High-Side PR1 Protection Mask (act low)	*/
	};
} CFGDRV1;

/*!< CFGDRQ6: Address: 0x62		DRQ6 Configuration */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX6					: 3;		/*!< DRQ6 MUX (\a PAC5XXX_DriverMux_Type)			*/
		__IO uint8_t POL6					: 1;		/*!< DRQ6 Polarity (\a PAC5XXX_DriverPolarity_Type)	*/
		__IO uint8_t OPT6					: 2;		/*!< DRQ6 Option (\a PAC5XXX_DriverOption_Type)		*/
             uint8_t                        : 2;
	};
} CFGDRQ6;

/*!< CFGDRQ7: Address: 0x63		DRQ7 Configuration */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t MUX7					: 3;		/*!< DRQ7 MUX (\a PAC5XXX_DriverMux_Type)			*/
		__IO uint8_t POL7					: 1;		/*!< DRQ7 Polarity (\a PAC5XXX_DriverPolarity_Type)	*/
		__IO uint8_t OPT7					: 2;		/*!< DRQ7 Option (\a PAC5XXX_DriverOption_Type)		*/
             uint8_t                        : 2;
	};
} CFGDRQ7;

/*!< DOUTDRV: Address: 0x64		Driver Manager Output Data */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t DOUTS3					: 1;		/*!< Output data for DRS3 open-drain driver		*/
		__IO uint8_t DOUTB3					: 1;		/*!< Output data for DRB3 open-drain driver		*/
		__IO uint8_t DOUTS4					: 1;		/*!< Output data for DRS4 open-drain driver		*/
		__IO uint8_t DOUTB4					: 1;		/*!< Output data for DRB4 open-drain driver		*/
		__IO uint8_t DOUTS5					: 1;		/*!< Output data for DRS5 open-drain driver		*/
		__IO uint8_t DOUTB5					: 1;		/*!< Output data for DRB5 open-drain driver		*/
		__IO uint8_t DOUTQ6					: 1;		/*!< Output data for DRQ6 in open-drain mode    */
		__IO uint8_t DOUTQ7					: 1;		/*!< Output data for DRQ7 in open-drain mode	*/
	};
} CFGDOUTDRV;

/*!< DINDRV: Address: 0x65		Driver Manager Input Data */
union
{
	__IO uint8_t b;
	struct {
		     uint8_t                        : 6;
        __IO uint8_t DINQ6					: 1;		/*!< Input data from DRQ7 in input mode			*/
        __IO uint8_t DINQ7					: 1;		/*!< Input data from DRQ6 in input mode			*/
	};
} DINDRV;

/*!< ENDRV: Address: 0x6A		Driver Manager Tile Enable */
union
{
	__IO uint8_t b;
	struct {
		__IO uint8_t EN						: 1;		/*!< 0: Disable; 1: Enable						*/
			 uint8_t 						: 7;
	};
} ENDRV;

	
/*@}*/ /* end of group PAC5XXX_Tile_DriverManager */

