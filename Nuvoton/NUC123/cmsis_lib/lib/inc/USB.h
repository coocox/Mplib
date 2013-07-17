/**************************************************************************//**
 * @file     USB.h
 * @version  V1.0
 * $Revision  1 $
 * $Date:    12/09/11 1:45p $
 * @brief    USB Header File for Nuc123 Series
 *
 * @note
 * Copyright (C) 2012 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef _USB_H
#define _USB_H

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup USB_MACRO USB Macro
  * @{
  */
/** @addtogroup USB_MACRO_CONTANT USB Macro Contant
  * @{
  */  

#ifdef __cplusplus
extern "C"
{
#endif

#define USB_SRAM	(USBD_BASE + 0x100)

/*---------------------------------------------------------------------------------------------------------*/
/* Macro, type and constant definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define EP(n)                   (n)                                 /*!< Endpoint n */
#define EP0                     EP(0)                               /*!< Endpoint 0 */
#define EP1                     EP(1)                               /*!< Endpoint 0 */
#define EP2                     EP(2)                               /*!< Endpoint 0 */
#define EP3                     EP(3)                               /*!< Endpoint 0 */
#define EP4                     EP(4)                               /*!< Endpoint 0 */
#define EP5                     EP(5)                               /*!< Endpoint 0 */
#if USBD_EP_NUM > 6
#define EP6                     EP(6)                               /*!< Endpoint 0 */
#define EP7                     EP(7)                               /*!< Endpoint 0 */
#endif

#define USBD_INT_INNAK          USBD_INTEN_INNAK_EN_Msk             /*!< Active NAK Function and its Status in IN Token */
#define USBD_INT_WAKEUP         USBD_INTEN_WAKEUP_IE_Msk            /*!< USB Wake-up Interrupt Enable */
#define USBD_INT_FLDET          USBD_INTEN_FLDET_IE_Msk             /*!< Floating Detected Interrupt Enable */
#define USBD_INT_USB            USBD_INTEN_USB_IE_Msk               /*!< USB Event Interrupt Enable */
#define USBD_INT_BUS            USBD_INTEN_BUS_IE_Msk               /*!< Bus Event Interrupt Enable */

#define USBD_INTF_SETUP         USBD_INTSTS_SETUP_Msk               /*!< Setup Event Status */
#if USBD_EP_NUM > 6
#define USBD_INTF_EP7           (1ul << (USBD_INTSTS_EPEVT_Pos+7))	/*!< Endpoint 7's USB Event Status */
#define USBD_INTF_EP6           (1ul << (USBD_INTSTS_EPEVT_Pos+6))	/*!< Endpoint 6's USB Event Status */
#endif
#define USBD_INTF_EP5           (1ul << (USBD_INTSTS_EPEVT_Pos+5))	/*!< Endpoint 5's USB Event Status */
#define USBD_INTF_EP4           (1ul << (USBD_INTSTS_EPEVT_Pos+4))	/*!< Endpoint 4's USB Event Status */
#define USBD_INTF_EP3           (1ul << (USBD_INTSTS_EPEVT_Pos+3))	/*!< Endpoint 3's USB Event Status */
#define USBD_INTF_EP2           (1ul << (USBD_INTSTS_EPEVT_Pos+2))	/*!< Endpoint 2's USB Event Status */
#define USBD_INTF_EP1           (1ul << (USBD_INTSTS_EPEVT_Pos+1))	/*!< Endpoint 1's USB Event Status */
#define USBD_INTF_EP0           (1ul << (USBD_INTSTS_EPEVT_Pos+0))	/*!< Endpoint 0's USB Event Status */
#define USBD_INTF_EP(n)         (1ul << (USBD_INTSTS_EPEVT_Pos+(n)))/*!< Endpoint n's USB Event Status */
#define USBD_INTF_WAKEUP        USBD_INTSTS_WAKEUP_STS_Msk          /*!< Wake-up Interrupt Status */
#define USBD_INTF_FLDET         USBD_INTSTS_FLDET_STS_Msk           /*!< Floating Detected Interrupt Status */
#define USBD_INTF_USB           USBD_INTSTS_USB_STS_Msk             /*!< USB event Interrupt Status */
#define USBD_INTF_BUS           USBD_INTSTS_BUS_STS_Msk             /*!< BUS Interrupt Status */

#define USBD_EPSTAT_INACK       0                                   /*!< In ACK */
#define USBD_EPSTAT_INNAK       1                                   /*!< In NAK */
#define USBD_EPSTAT_OUTDATA0ACK 2                                   /*!< Out Packet Data0 ACK */
#define USBD_EPSTAT_OUTDATA1ACK 6                                   /*!< Out Packet Data1 ACK */
#define USBD_EPSTAT_SETUPACK    3                                   /*!< Setup ACK */
#define USBD_EPSTAT_ISO         7                                   /*!< Isochronous transfer end */
#define USBD_EPSTAT_MASK		7                                   /*!< EPSTAT is 3 bits */
												  
#define USBD_ATTR_BYTEMODE      USBD_ATTR_BYTEM_Msk                 /*!< CPU access USB SRAM In Byte Mode */
#define USBD_ATTR_POWERON       USBD_ATTR_PWRDN_Msk                 /*!< Power-on PHY Transceiver */
#define USBD_ATTR_PULLUP        USBD_ATTR_DPPU_EN_Msk               /*!< Pull-up resistor on USB_DP enable */
#define USBD_ATTR_ENABLE        USBD_ATTR_USB_EN_Msk                /*!< USB Controller Enable */
#define USBD_ATTR_REMOTEWAKEUP  USBD_ATTR_RWAKEUP_Msk               /*!< Remote Wake-up */
#define USBD_ATTR_ENABLEPHY     USBD_ATTR_PHY_EN_Msk                /*!< PHY Transceiver Function Enable */

#define USBD_ATTR_USB_EN        (USBD_ATTR_BYTEMODE|USBD_ATTR_POWERON|USBD_ATTR_PULLUP|USBD_ATTR_ENABLE|USBD_ATTR_ENABLEPHY)

#define USBD_STATE_TIMEOUT      USBD_ATTR_TIMEOUT_Msk               /*!< Time Out Status */
#define USBD_STATE_RESUME       USBD_ATTR_RESUME_Msk                /*!< Resume Status */
#define USBD_STATE_SUSPEND      USBD_ATTR_SUSPEND_Msk               /*!< Suspend Status */
#define USBD_STATE_USBRST       USBD_ATTR_USBRST_Msk                /*!< USB Reset Status */

#define USBD_EPCFG_CLEARSTALL   USBD_CFG_CSTALL_Msk                 /*!< Clear STALL Response */
#define USBD_EPCFG_DATA1        USBD_CFG_DSQ_SYNC_Msk               /*!< Data1 Sequence Synchronization */
#define USBD_EPCFG_DATA0        0                                   /*!< Data0 Sequence Synchronization */
#define USBD_EPCFG_TYPE_MASK    (USBD_CFG_STATE_Msk|USBD_CFG_ISOCH_Msk)/*!< Endpoint Type Mask */
#define USBD_EPCFG_TYPE_DISABLE	(0x0ul << USBD_CFG_STATE_Pos)       /*!< Endpoint Disabled */
#define USBD_EPCFG_TYPE_OUT     (0x1ul << USBD_CFG_STATE_Pos)       /*!< Out endpoint */
#define USBD_EPCFG_TYPE_IN      (0x2ul << USBD_CFG_STATE_Pos)       /*!< In endpoint */
#define USBD_EPCFG_TYPE_ISO     (0x1ul << USBD_CFG_ISOCH_Pos)       /*!< Isochronous endpoint */

/*@}*/ /* end of group USB_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup USB_MACRO_FUNC USB Macro Func
  @{
*/

/**
 * @brief       Enable interrupt 
 *
 * @param[in]   Interrupt  Interrupt mask , should be ored by:
 *                          -  USBD_INT_INNAK
 *                          -  USBD_INT_WAKEUP
 *                          -  USBD_INT_FLDET
 *                          -  USBD_INT_USB
 *                          -  USBD_INT_BUS
 * @return      None
 *
 * @details     Enable the USB interrupt according to mask.
 */
static __INLINE void UBSD_ENABLE_INT(uint32_t intr)
{
    USBD->INTEN |= (intr);
}

/**
 * @brief       Disable interrupt 
 *
 * @param[in]   Interrupt  Interrupt mask , should be ored by:
 *                          -  USBD_INT_INNAK
 *                          -  USBD_INT_WAKEUP
 *                          -  USBD_INT_FLDET
 *                          -  USBD_INT_USB
 *                          -  USBD_INT_BUS
 * @return      None
 *
 * @details     Disable the USB interrupt according to mask.
 */
static __INLINE void USBD_DISABLE_INT(uint32_t intr)
{
    USBD->INTEN &= ~(intr);
}

/**
 * @brief       Enable wakeup function 
 *
 * @param[in]   None
 * @return      None
 *
 * @details     Enable the USB wakeup function.
 */
static __INLINE void USBD_ENABLE_WAKEUP(void)
{
    USBD->INTEN |= USBD_INTEN_WAKEUP_EN_Msk;
}

/**
 * @brief       Disable wakeup function 
 *
 * @param[in]   None
 * @return      None
 *
 * @details     Disable the USB wakeup function.
 */
static __INLINE void USBD_DISABLE_WAKEUP(void)
{
    USBD->INTEN &= ~USBD_INTEN_WAKEUP_EN_Msk;
}

/**
 * @brief       Set USB address 
 *
 * @param[in]   Address    USB Address , should be:
 *                          -  0 -- 127
 * @return      None
 *
 * @details     Set USB address.
 */
static __INLINE void USBD_SET_ADDR(uint8_t addr)
{
    USBD->FADDR = (addr);
}

/**
 * @brief       Get USB address 
 *
 * @param[in]   None
 * @return      Address    USB Address , should be:
 *                          -  0 -- 127
 *
 * @details     Get USB address.
 */
static __INLINE uint8_t USBD_GET_ADDR(void)
{
    return USBD->FADDR;
}

/**
 * @brief       Get interrupt flag 
 *
 * @param[in]   None
 * @return      Flag       Interrupt flag mask , ored by:
 *                          -  USBD_INTF_SETUP
 *                          -  USBD_INTF_EP7
 *                          -  USBD_INTF_EP6
 *                          -  USBD_INTF_EP5
 *                          -  USBD_INTF_EP4
 *                          -  USBD_INTF_EP3
 *                          -  USBD_INTF_EP2
 *                          -  USBD_INTF_EP1
 *                          -  USBD_INTF_EP0
 *                          -  USBD_INTF_WAKEUP
 *                          -  USBD_INTF_FLDET
 *                          -  USBD_INTF_USB
 *                          -  USBD_INTF_BUS
 *
 * @details     Get the USB interrupt flag.
 */
static __INLINE uint32_t USBD_GET_INTF(void)
{
    return USBD->INTSTS;
}

/**
 * @brief       Clear interrupt flag 
 *
 * @param[in]   Flag       Interrupt flag to be cleared, should be ored by:
 *                          -  USBD_INTF_SETUP
 *                          -  USBD_INTF_EP7
 *                          -  USBD_INTF_EP6
 *                          -  USBD_INTF_EP5
 *                          -  USBD_INTF_EP4
 *                          -  USBD_INTF_EP3
 *                          -  USBD_INTF_EP2
 *                          -  USBD_INTF_EP1
 *                          -  USBD_INTF_EP0
 *                          -  USBD_INTF_WAKEUP
 *                          -  USBD_INTF_FLDET
 *                          -  USBD_INTF_USB
 *                          -  USBD_INTF_BUS
 * @return      None
 *
 * @details     Clear the USB interrupt flag.
 */
static __INLINE void USBD_CLR_INTF(uint32_t flag)
{
    USBD->INTSTS = flag;
}

/**
 * @brief       Assign USB attribute
 *
 * @param[in]   Attribute  USB Attribute, should be ored by:
 *                          -  USBD_ATTR_BYTEMODE
 *                          -  USBD_ATTR_POWERON
 *                          -  USBD_ATTR_PULLUP
 *                          -  USBD_ATTR_ENABLE
 *                          -  USBD_ATTR_REMOTEWAKEUP
 *                          -  USBD_ATTR_ENABLEPHY
 * @return      None
 *
 * @details     Assign USB attribute, other attribute will be lost.
 */
static __INLINE void USBD_ASSIGN_ATTR(uint32_t attr)
{
    USBD->ATTR = (attr);
}

/**
 * @brief       Set USB attribute
 *
 * @param[in]   Attribute  USB Attribute, should be ored by:
 *                          -  USBD_ATTR_BYTEMODE
 *                          -  USBD_ATTR_POWERON
 *                          -  USBD_ATTR_PULLUP
 *                          -  USBD_ATTR_ENABLE
 *                          -  USBD_ATTR_REMOTEWAKEUP
 *                          -  USBD_ATTR_ENABLEPHY
 * @return      None
 *
 * @details     Set USB attribute, other attribute will not be lost.
 */
static __INLINE void USBD_SET_ATTR(uint32_t attr)
{
    USBD->ATTR |= (attr);
}

/**
 * @brief       Clear USB attribute
 *
 * @param[in]   Attribute  USB Attribute, should be ored by:
 *                          -  USBD_ATTR_BYTEMODE
 *                          -  USBD_ATTR_POWERON
 *                          -  USBD_ATTR_PULLUP
 *                          -  USBD_ATTR_ENABLE
 *                          -  USBD_ATTR_REMOTEWAKEUP
 *                          -  USBD_ATTR_ENABLEPHY
 * @return      None
 *
 * @details     Clear USB attribute, other attribute will not be lost.
 */
static __INLINE void USBD_CLR_ATTR(uint32_t attr)
{
    USBD->ATTR &= ~(attr);
}

/**
 * @brief       Get state
 *
 * @param[in]   None
 * @return      State      USB state, should be ored by:
 *                          -  USBD_STATE_TIMEOUT
 *                          -  USBD_STATE_RESUME
 *                          -  USBD_STATE_SUSPEND
 *                          -  USBD_STATE_USBRST
 *
 * @details     Get USB state.
 */
static __INLINE uint32_t USBD_GET_STATE(void)
{
    return USBD->ATTR;
}

/**
 * @brief       Check USB connection
 *
 * @param[in]   None
 * @retval      0: USB device is not connected to host.
 * @retval      non-0: USB device is connected to host.
 *
 * @details     Check whether USB device is connected to host.
 */
static __INLINE uint32_t USBD_IS_CONNECTED(void)
{
    return (USBD->FLDET & USBD_FLDET_FLDET_Msk);
}

/**
 * @brief       Check USB overrun state
 *
 * @param[in]   None
 * @retval      0: USB device is not overrun.
 * @retval      non-0: USB device is overrun.
 *
 * @details     Check whether USB device is overrun.
 */
static __INLINE uint32_t USBD_IS_OVERRUN(void)
{
    return (USBD->EPSTS & USBD_EPSTS_OVERRUN_Msk);
}

/**
 * @brief       Set buffer for SETUP package
 *
 * @param[in]   Offset     Byte offset for the buffer in USB SRAM, should be:
 *                          - 0 -- sizeof(USB_SRAM) - 1
 * @return      None
 *
 * @details     Set buffer for SETUP package.
 */
static __INLINE void USBD_SET_SETUPBUF(uint32_t offset)
{
    USBD->STBUFSEG = (offset);
}

/**
 * @brief       Get buffer for SETUP package
 *
 * @param[in]   None
 * @return      Offset     Byte offset for the buffer in USB SRAM, should be:
 *                          - 0 -- sizeof(USB_SRAM) - 1
 *
 * @details     Get buffer for SETUP package.
 */
static __INLINE uint32_t USBD_GET_SETUPBUF(void)
{
    return USBD->STBUFSEG;
}

/**
 * @brief       Set SE0 state
 *
 * @param[in]   None
 * @return      None
 *
 * @details     Set SE0 state to force a USB reset.
 */
static __INLINE void USBD_SET_SE0(void)
{
    USBD->DRVSE0 = USBD_DRVSE0_DRVSE0_Msk;
}

/**
 * @brief       Clear SE0 state
 *
 * @param[in]   None
 * @return      None
 *
 * @details     Clear SE0 state to exit USB reset.
 */
static __INLINE void USBD_CLR_SE0(void)
{
    USBD->DRVSE0 = 0;
}

/**
 * @brief       Set buffer for USB endpoint
 *
 * @param[in]   ep         USB endpoint
 *              Offset     Byte offset for the buffer in USB SRAM, should be:
 *                          - 0 -- sizeof(USB_SRAM) - 1
 * @return      None
 *
 * @details     Set buffer for USB endpoint.
 */
static __INLINE void USBD_EP_SET_BUF(uint8_t ep, uint32_t offset)
{
    if(ep <= EP5)
        USBD->EP[(ep)].BUFSEG = (offset);
    else
        USBD->EP_NEW[(ep)].BUFSEG = (offset);
}

/**
 * @brief       Get buffer for USB endpoint
 *
 * @param[in]   ep         USB endpoint
 * @return      Offset     Byte offset for the buffer in USB SRAM, should be:
 *                          - 0 -- sizeof(USB_SRAM) - 1
 *
 * @details     Get buffer for USB endpoint.
 */
static __INLINE uint32_t USBD_EP_GET_BUF(uint8_t ep)
{
    if(ep <= EP5)
        return USBD->EP[(ep)].BUFSEG;
    else
        return USBD->EP_NEW[(ep)].BUFSEG;
}

/**
 * @brief       Get memory buffer for USB endpoint
 *
 * @param[in]   ep         USB endpoint
 * @return      Address    Address of buffer in USB SRAM, should be:
 *                          - 0 -- sizeof(USB_SRAM) - 1
 *
 * @details     Get memory buffer for USB endpoint.
 */
static __INLINE uint32_t USBD_EP_GET_MEMBUF(uint8_t ep)
{
    return (USB_SRAM + USBD_EP_GET_BUF(ep));
}

/**
 * @brief       Set USB payload size
 *
 * @param[in]   ep         USB endpoint
 *              Size       Byte size for USB payload, should be:
 *                          - 0 -- 64 for USB 2.0 FS
 * @return      None
 *
 * @details     Set USB payload size.
 */
static __INLINE void USBD_EP_SET_PAYLOAD_LEN(uint8_t ep, uint32_t size)
{
    if(ep <= EP5)
        USBD->EP[(ep)].MXPLD = (size);
    else
        USBD->EP_NEW[(ep)].MXPLD = (size);
}

/**
 * @brief       Get USB payload size
 *
 * @param[in]   ep         USB endpoint
 *              Size       Byte size for USB payload, should be:
 *                          - 0 -- 64 for USB 2.0 FS
 * @return      None
 *
 * @details     Get USB payload size.
 */
static __INLINE uint32_t USBD_EP_GET_PAYLOAD_LEN(uint8_t ep)
{
    if(ep <= EP5)
        return USBD->EP[(ep)].MXPLD;
    else
        return USBD->EP_NEW[(ep)].MXPLD;
}

/**
 * @brief       Get USB endpoint states
 *
 * @param       None
 * @return      All USB endpoint states
 *
 * @details     Get all USB endpoint states
 */
static __INLINE uint32_t USBD_EP_GET_STAT_ALL(void)
{
    return (USBD->EPSTS>>8);
}

/**
 * @brief       Get USB endpoint state
 *
 * @param[in]   sts        All USB endpoint status, which were gotten through call USBD_EP_GET_STAT_ALL macro
 * @param[in]   ep         USB endpoint
 * @return      None
 *
 * @details     Get specified USB endpoint state.
 */
static __INLINE uint32_t USBD_EP_GET_STAT_FROM(uint32_t sts, uint8_t ep)
{
    return (((sts)>>((ep)*3))&USBD_EPSTAT_MASK);
}

/**
 * @brief       Assign USB endpoint configuration
 *
 * @param[in]   ep         USB endpoint
 *              Config     USB configuration mask, should be ored by:
 *                          - USBD_EPCFG_CLEARSTALL
 *                          - USBD_EPCFG_DATA0 / USBD_EPCFG_DATA1
 *                          - USBD_EPCFG_TYPE_DISABLE / USBD_EPCFG_TYPE_OUT / USBD_EPCFG_TYPE_IN
 *                          - USBD_EPCFG_TYPE_ISO
 * @return      None
 *
 * @details     Assign USB endpoint configuration.
 */
static __INLINE void USBD_EP_ASSIGN_CFG(uint8_t ep, uint32_t config)
{
    if(ep <= EP5)
        USBD->EP[(ep)].CFG = (config);
    else
        USBD->EP_NEW[(ep)].CFG = (config);
}

/**
 * @brief       Set USB endpoint type
 *
 * @param[in]   ep         USB endpoint
 *              Type       USB endpoint type, should be ored by:
 *                          - USBD_EPCFG_TYPE_DISABLE / USBD_EPCFG_TYPE_OUT / USBD_EPCFG_TYPE_IN
 *                          - USBD_EPCFG_TYPE_ISO
 * @return      None
 *
 * @details     Set USB endpoint type.
 */
static __INLINE void USBD_EP_SET_TYPE(uint8_t ep, uint32_t type)
{
    if(ep <= EP5)
        USBD->EP[(ep)].CFG = (USBD->EP[(ep)].CFG&~USBD_EPCFG_TYPE_MASK)|(type);
    else
        USBD->EP_NEW[(ep)].CFG = (USBD->EP_NEW[(ep)].CFG&~USBD_EPCFG_TYPE_MASK)|(type);
}

/**
 * @brief       Set USB endpoint number
 *
 * @param[in]   ep         USB endpoint
 *              Number     USB endpoint number, should be:
 *                          - 0 -- 15
 * @return      None
 *
 * @details     Set USB endpoint number.
 */
static __INLINE void USBD_EP_SET_NUM(uint8_t ep, uint8_t ep_num)
{
    if(ep <= EP5)
        USBD->EP[(ep)].CFG = (USBD->EP[(ep)].CFG&~USBD_CFG_EP_NUM_Msk)|(ep_num);
    else
        USBD->EP_NEW[(ep)].CFG = (USBD->EP_NEW[(ep)].CFG&~USBD_CFG_EP_NUM_Msk)|(ep_num);
}

/**
 * @brief       Set USB data token
 *
 * @param[in]   ep         USB endpoint
 *              Token      USB endpoint Data Token, should be:
 *                          - USBD_EPCFG_DATA0
 *                          - USBD_EPCFG_DATA1
 * @return      None
 *
 * @details     Set USB data token, to be DATA0 or DATA1.
 */
static __INLINE void USBD_EP_SET_DATATOG(uint8_t ep, uint32_t toggle)
{
    if(ep <= EP5)
        USBD->EP[(ep)].CFG = (USBD->EP[(ep)].CFG&~USBD_CFG_DSQ_SYNC_Msk)|(toggle);
    else
        USBD->EP_NEW[(ep)].CFG = (USBD->EP_NEW[(ep)].CFG&~USBD_CFG_DSQ_SYNC_Msk)|(toggle);
}

/**
 * @brief       Toggle USB data token
 *
 * @param[in]   ep         USB endpoint
 * @return      None
 *
 * @details     Toggle USB data token, change between DATA0 and DATA1.
 */
static __INLINE void USBD_EP_TOG_DATATOG(uint8_t ep)
{
    if(ep <= EP5)
        USBD_EP_SET_DATATOG((ep),(USBD->EP[(ep)].CFG&USBD_CFG_DSQ_SYNC_Msk)?USBD_EPCFG_DATA0:USBD_EPCFG_DATA1);
    else
        USBD_EP_SET_DATATOG((ep),(USBD->EP_NEW[(ep)].CFG&USBD_CFG_DSQ_SYNC_Msk)?USBD_EPCFG_DATA0:USBD_EPCFG_DATA1);
}

/**
 * @brief       Get USB endpoint data token
 *
 * @param[in]   ep         USB endpoint
 * @return      Token      USB endpoint Data Token, should be:
 *                          - USBD_EPCFG_DATA0
 *                          - USBD_EPCFG_DATA1
 *
 * @details     Get USB endpoint data token.
 */
static __INLINE uint32_t USBD_EP_GET_DATATOG(uint8_t ep)
{
    if(ep <= EP5)
        return (USBD->EP[(ep)].CFG & USBD_CFG_DSQ_SYNC_Msk);
    else
        return (USBD->EP_NEW[(ep)].CFG & USBD_CFG_DSQ_SYNC_Msk);
}

/**
 * @brief       Set USB endpoint stall state
 *
 * @param[in]   ep         USB endpoint
 * @return      None
 *
 * @details     Set USB endpoint stall state, endpoint will return STALL token.
 */
static __INLINE void USBD_EP_SET_STALL(uint8_t ep)
{
    if(ep <= EP5)
        USBD->EP[(ep)].CFGP |= USBD_CFGP_SSTALL_Msk | USBD_CFGP_CLRRDY_Msk;
    else
        USBD->EP_NEW[(ep)].CFGP |= USBD_CFGP_SSTALL_Msk | USBD_CFGP_CLRRDY_Msk;
}

/**
 * @brief       Clear USB endpoint stall state
 *
 * @param[in]   ep         USB endpoint
 * @return      None
 *
 * @details     Clear USB endpoint stall state, endpoint will return ACK/NAK token.
 */
static __INLINE void USBD_EP_CLR_STALL(uint8_t ep)
{
    if(ep <= EP5)
        USBD->EP[(ep)].CFGP &= ~USBD_CFGP_SSTALL_Msk;
    else
        USBD->EP_NEW[(ep)].CFGP &= ~USBD_CFGP_SSTALL_Msk;
}

/**
 * @brief       Get USB endpoint stall state
 *
 * @param[in]   ep         USB endpoint
 * @retval      0: USB endpoint is not stalled.
 * @retval      non-0: USB endpoint is stalled.
 *
 * @details     Get USB endpoint stall state.
 */
static __INLINE uint32_t USBD_EP_GET_STALL(uint8_t ep)
{
    if(ep <= EP5)
        return (USBD->EP[(ep)].CFGP & USBD_CFGP_SSTALL_Msk);
    else
        return (USBD->EP_NEW[(ep)].CFGP & USBD_CFGP_SSTALL_Msk);
}

/**
 * @brief       Stop USB endpoint transaction
 *
 * @param[in]   ep         USB endpoint
 * @return      None
 *
 * @details     Stop USB endpoint transaction.
 */
static __INLINE void USBD_EP_STOP_TRANSACT(uint8_t ep)
{
    if(ep <= EP5)
        USBD->EP[(ep)].CFGP |= USBD_CFGP_CLRRDY_Msk;
    else
        USBD->EP_NEW[(ep)].CFGP |= USBD_CFGP_CLRRDY_Msk;
}

/*---------------------------------------------------------------------------------------------------------*/
/* USB Request                                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
/* Request Type */
#define REQ_MASK            0x60
#define REQ_STANDARD        0x00
#define REQ_CLASS           0x20
#define REQ_VENDOR          0x40

/* Request */
#define GET_STATUS          0x00
#define CLEAR_FEATURE       0x01
#define SET_FEATURE         0x03
#define SET_ADDRESS         0x05
#define GET_DESCRIPTOR      0x06
#define SET_DESCRIPTOR      0x07
#define GET_CONFIGURATION   0x08
#define SET_CONFIGURATION   0x09
#define GET_INTERFACE       0x0A
#define SET_INTERFACE       0x0B
#define SYNC_FRAME          0x0C


/*---------------------------------------------------------------------------------------------------------*/
/* USB Descriptor Type                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
#define DESC_DEVICE         0x01
#define DESC_CONFIG         0x02
#define DESC_STRING         0x03
#define DESC_INTERFACE      0x04
#define DESC_ENDPOINT       0x05
#define DESC_QUALIFIER      0x06
#define DESC_OTHERSPEED     0x07
#define DESC_IAD            0x0B
/* For HID */
#define DESC_HID            0x21
#define DESC_HID_RPT        0x22

/*---------------------------------------------------------------------------------------------------------*/
/* USB Descriptor Length                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define LEN_DEVICE          18
#define LEN_CONFIG          9
#define LEN_INTERFACE       9
#define LEN_ENDPOINT        7
#define LEN_IAD             8
/* For HID */
#define LEN_HID             0x09

/* USB Endpoint Type */
#define EP_ISO              0x01
#define EP_BULK             0x02
#define EP_INT              0x03

/*---------------------------------------------------------------------------------------------------------*/
/* USB Feature Selector                                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define FEATURE_DEVICE_REMOTE_WAKEUP    0x01
#define FEATURE_ENDPOINT_HALT           0x00

#define EP_INPUT                        0x80
#define EP_OUTPUT                       0x00

/* FLAG */
#define FLAG_OUT_ACK        0x01
#define FLAG_SET_ADDRESS    0x02
#define FLAG_SET_CONFIG     0x04
#define FLAG_SET_INTERFACE  0x08
#define	FLAG_EP0_DATA_OUT   0x10
#define	FLAG_EP0_DATA_IN    0x20
#define	FLAG_EP0_OUT_END    0x40
    
#ifdef __cplusplus
}
#endif

/*@}*/ /* end of group USB_MACRO_FUNC */
/*@}*/ /* end of group USB_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

#endif 
