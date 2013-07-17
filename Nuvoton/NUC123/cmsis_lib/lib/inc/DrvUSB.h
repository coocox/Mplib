/******************************************************************************
 * @file     DrvUSB.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/09/11 14:35p $
 * @brief    NUC123 Series DrvUSB Header File
 *
 * @note
 * Copyright (C) 2012 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef _DRVUSB_H
#define _DRVUSB_H

#include "USB.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup NUC123_FUNC NUC123 FUNC Interface
  * @{
  */

/** @addtogroup DrvUSB_FUNC DrvUSB Function Interface
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro, type and constant definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
typedef struct
{
	uint8_t *buffer;
	uint32_t size;
	uint32_t cur_pos;
	uint16_t ep_size;
	enum
	{
		DATA_IN,
		DATA_OUT
	} direction;
	void *param;
	void (*callback)(void *param);
} USB_EP_T;

typedef struct
{
	enum
	{
		USB_STATE_DETACHED		= 0x00,
		USB_STATE_ATTACHED		= 0x01,
		USB_STATE_CONFIGURED	= 0x11,
		USB_STATE_SUSPENDED		= 0x31,
	} State;
	uint8_t Address;
	uint8_t Config;
	uint32_t Flag;
	USB_EP_T* ep[USBD_EP_NUM];
	 struct
	{
		uint8_t bmRequestType;
		uint8_t bRequest;
		uint16_t wValue;
		uint16_t wIndex;
		uint16_t wLength;
	} __attribute__((packed)) Setup;
} USBDEV_T;
extern USBDEV_T UsbDev;

/** @addtogroup USB_FEATURE USB FEATURE
  * @{
  */
/*---------------------------------------------------------------------------------------------------------*/
/* USB Feature Selector                                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define FEATURE_DEVICE_REMOTE_WAKEUP    0x01
#define FEATURE_ENDPOINT_HALT           0x00

#define EP_INPUT                        0x80
#define EP_OUTPUT                       0x00
/*@}*/ /* end of group USB_FEATURE */

/** @addtogroup USB_STATE USB STATE
  * @{
  */
/* USB STATE */
#define USB_STATE_ADDRESS               0x31

#define USB_STATE_FLAG_DEFAULT          0x10
#define USB_STATE_FLAG_ADDRESS          0x20
#define USB_STATE_FLAG_CONFIGURED       0x40
#define USB_STATE_FLAG_SUSPENDED        0x80
/*@}*/ /* end of group USB_STATE */

/** @addtogroup USB_FLAG USB FLAG
  * @{
  */
/* FLAG */
#define FLAG_OUT_ACK			0x01
#define FLAG_SET_ADDRESS		0x02
#define FLAG_SET_CONFIG			0x04
#define FLAG_SET_INTERFACE		0x08
/*@}*/ /* end of group USB_FLAG */

/*@}*/ /* end of group DrvUSB_FUNC */
/*@}*/ /* end of group NUC123_FUNC */


/**************************************************/

void DrvUSB_Init(void);
void DrvUSB_UsbBus(uint32_t u32State);
void DrvUSB_UsbInAck(void);
int32_t DrvUSB_UsbSetup(void);
void DrvUSB_UsbFdt(void);
void DrvUSB_Transact(uint8_t ep, USB_EP_T *t);
void DrvUSB_UsbTransact(uint32_t* u32IntFlag);
void DrvUSB_WordsCpy(uint8_t *dest, uint8_t *src, int32_t size);

extern void UsbCfg(void);
extern int32_t UsbStdReq(void);
extern int32_t UsbClassReq(void);
    
#ifdef __cplusplus
}
#endif

#endif 



