/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2009 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#ifndef __VCOMSYS_H__
#define __VCOMSYS_H__


#ifdef  __cplusplus
extern "C"
{
#endif


/* Define the endpoint number for relative endpoints. */
#define CTRL_EP_NUM         0
#define BULK_IN_EP_NUM      1
#define BULK_OUT_EP_NUM     2
#define INT_IN_EP_NUM       3

/* Max Packet Size */
#define MAX_PACKET_SIZE0	    8
#define MAX_PACKET_SIZE_BULK	64	/* Maximum packet size of BULK endpoint */
#define MAX_PACKET_SIZE_INT		8	/* Maximum packet size of INT endpoint  */

/* SRAM */
#define BUF_SETUP	    0xF8
#define BUF_CTRL	    0x00
#define BUF_BULK_IN		(MAX_PACKET_SIZE0)
#define BUF_BULK_OUT	(BUF_BULK_IN+MAX_PACKET_SIZE_BULK)
#define BUF_INT_IN		(BUF_BULK_OUT+MAX_PACKET_SIZE_BULK)

/* CFG */
#define CFG0_SETTING	(USBD_EPCFG_CLEARSTALL | USBD_EPCFG_TYPE_IN  | CTRL_EP_NUM)	/* EP address 0, control IN  */
#define CFG1_SETTING	(USBD_EPCFG_CLEARSTALL | USBD_EPCFG_TYPE_OUT | CTRL_EP_NUM)	/* EP address 0, control OUT */
#define CFG2_SETTING	(USBD_EPCFG_TYPE_IN  | BULK_IN_EP_NUM)				/* EP address 1 */
#define CFG3_SETTING	(USBD_EPCFG_TYPE_OUT | BULK_OUT_EP_NUM)				/* EP address 2 */
#define CFG4_SETTING	(USBD_EPCFG_TYPE_IN  | INT_IN_EP_NUM)				/* EP address 3 */

#define g_au8UsbSetup	((uint8_t *)(USBD_BASE+0x100+BUF_SETUP))
#define g_au8UsbCtrl	((uint8_t *)(USBD_BASE+0x100+BUF_CTRL))
#define g_au8UsbBulkIn	((uint8_t *)(USBD_BASE+0x100+BUF_BULK_IN))
#define g_au8UsbBulkOut	((uint8_t *)(USBD_BASE+0x100+BUF_BULK_OUT))
#define g_au8UsbIntIn	((uint8_t *)(USBD_BASE+0x100+BUF_INT_IN))

/********************************************/

#define SEND_ENCAPSULATED_COMMAND   0x00
#define GET_ENCAPSULATED_RESPONSE   0x01
#define SET_COMM_FEATURE            0x02
#define GET_COMM_FEATURE            0x03
#define CLEAR_COMM_FEATURE          0x04
#define SET_LINE_CODE               0x20
#define GET_LINE_CODE               0x21
#define SET_CONTROL_LINE_STATE      0x22
#define SEND_BREAK                  0x23

/********************************************/
#define	FLAG_SET_LINE_CODE		0x100

void VCOM_MainProcess(void);
void UsbUsb(uint32_t u32IntFlag, uint32_t u32EPSTS);

#ifdef  __cplusplus
}
#endif

#endif // __VCOMSYS_H__


