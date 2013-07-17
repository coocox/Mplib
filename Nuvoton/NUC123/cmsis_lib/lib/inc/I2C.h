/**************************************************************************//**
 * @file     I2C.h   
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/24 1:45p $
 * @brief    NUC123 Series I2C Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __I2C_H__
#define __I2C_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup I2C_MACRO I2C Macro
  * @{
  */

/** @addtogroup I2C_MACRO_CONTANT I2C Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/*  I2CON constant definitions.                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define I2C_CON_EI          (1ul << I2C_I2CON_EI_Pos)	   /*!< Enable Interrupt */
#define I2C_CON_ENSI        (1ul << I2C_I2CON_ENS1_Pos)  /*!< I2C Controller Enable Bit  */
#define I2C_CON_STA         (1ul << I2C_I2CON_STA_Pos)   /*!< I2C START Control Bit */
#define I2C_CON_STO         (1ul << I2C_I2CON_STO_Pos)   /*!< I2C STOP Control Bit  */
#define I2C_CON_SI          (1ul << I2C_I2CON_SI_Pos)	   /*!< I2C Interrupt Flag */
#define I2C_CON_AA          (1ul << I2C_I2CON_AA_Pos)	   /*!< Assert Acknowledge Control Bit  */

#define I2C_CON_STA_STO_SI        0x38UL /*!< I2CON setting for I2C control bits. It would set STA, STO and SI bits     */
#define I2C_CON_STA_STO_SI_AA     0x3CUL /*!< I2CON setting for I2C control bits. It would set STA, STO, SI and AA bits */
#define I2C_CON_STA_SI            0x28UL /*!< I2CON setting for I2C control bits. It would set STA and SI bits          */
#define I2C_CON_STA_SI_AA         0x2CUL /*!< I2CON setting for I2C control bits. It would set STA, SI and AA bits      */
#define I2C_CON_STO_SI            0x18UL /*!< I2CON setting for I2C control bits. It would set STO and SI bits          */
#define I2C_CON_STO_SI_AA         0x1CUL /*!< I2CON setting for I2C control bits. It would set STO, SI and AA bits      */
//#define I2C_I2CON_SI                0x08UL /*!< I2CON setting for I2C control bits. It would set SI bit                   */
#define I2C_CON_SI_AA             0x0CUL /*!< I2CON setting for I2C control bits. It would set SI and AA bits           */
//#define I2C_I2CON_STA               0x20UL /*!< I2CON setting for I2C control bits. It would set STA bit                  */
//#define I2C_I2CON_AA                0x04UL /*!< I2CON setting for I2C control bits. It would set AA bit                   */


/*---------------------------------------------------------------------------------------------------------*/
/*  I2CTOC constant definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define I2C_TOC_ENTI          (1ul << I2C_I2CTOC_ENTI_Pos)   /*!< Time-out Counter Enable/Disable */
#define I2C_TOC_DIV4          (1ul << I2C_I2CTOC_DIV4_Pos)   /*!< Time-out Counter Input Clock Divided by 4*/
#define I2C_TOC_TIF           (1ul << I2C_I2CTOC_TIF_Pos)    /*!< Time-Out Flag */
/*---------------------------------------------------------------------------------------------------------*/
/*  I2CADDR0 constant definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define I2C_ADDR_GC			 (1ul << 0)					   /*!< General Call Function */

/*---------------------------------------------------------------------------------------------------------*/
/*  I2CWKUPCON constant definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define I2C_I2CWKUPCON_WKUPEN          (1ul << I2C_I2CWKUPCON_WKUPEN_Pos)	  /*!< I2C Wake-up Function Enable */

/*---------------------------------------------------------------------------------------------------------*/
/*  I2CWKUPSTS constant definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define I2C_I2CWKUPCON_WKUPIF          (1ul << I2C_I2CWKUPSTS_WKUPIF_Pos)	 /*!< Wake-up Interrupt Flag */

/*@}*/ /* end of group I2C_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup I2C_MACRO_FUNC I2C Macro Func
  @{
*/

/**
 * @brief      Generate START signal to I2C bus
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    This macro is used to generate START signal to specified I2C port 
 *			   Example: I2C_START(I2C0)
 */
static __INLINE void I2C_START(I2C_T *port)
{ 
    ((port)->I2CON = ((port)->I2CON&(~I2C_CON_STO)) | I2C_CON_STA_SI);
}

/**
 * @brief      Generate STOP signal to I2C bus
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    This macro is used to generate STOP signal to specified I2C port  
 *             Example: I2C_STOP(I2C0)
 */
static __INLINE void I2C_STOP(I2C_T *port)
{
    ((port)->I2CON = (port)->I2CON | I2C_CON_STO_SI);
}

/**
 * @brief      Enable I2C interrupt
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Enable I2C interrupt. 
 *             Example: I2C_ENABLE_I2C_INT(I2C0)
 */
static __INLINE void I2C_ENABLE_I2C_INT(I2C_T *port)
{
    ((port)->I2CON |= I2C_CON_EI);
}
/**
 * @brief      Disable I2C interrupt
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Disable I2C interrupt. 
 *             Example: I2C_DISABLE_I2C_INT(I2C0)
 */
static __INLINE void I2C_DISABLE_I2C_INT(I2C_T *port)
{
    ((port)->I2CON &= ~I2C_CON_EI);
}
/**
 * @brief      Enable I2C
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Enable I2C. 
 *             Example: I2C_ENABLE_I2C(I2C0)
 */
static __INLINE void I2C_ENABLE_I2C(I2C_T *port)
{
    ((port)->I2CON |= I2C_CON_ENSI);
}
/**
 * @brief      Disable I2C
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Disable I2C. 
 *             Example: I2C_DISABLE_I2C(I2C0)
 */
static __INLINE void I2C_DISABLE_I2C(I2C_T *port)
{
    ((port)->I2CON &= ~I2C_CON_ENSI);
}

/**
 * @brief      Waiting for I2C action done
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    This function is used to wait I2C action done by polling SI bit of I2CON. 
 *             Example: I2C_WAIT_READY(I2C0)
 */
static __INLINE void I2C_WAIT_READY(I2C_T *port)
{
    while(((port)->I2CON & I2C_CON_SI) == 0);
}
/**
 * @brief      Clear SI
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Clear SI to start action. 
 *             Example: I2C_CLEAR_SI(I2C0)
 */
static __INLINE void I2C_CLEAR_SI(I2C_T *port)
{
    ((port)->I2CON = ((port)->I2CON& ~(I2C_CON_STA|I2C_CON_STO)) | I2C_CON_SI);
}
/**
 * @brief      Set AA
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    An acknowledged (low level to SDA) will be returned during the acknowledge clock pulse on the SCL line when 1 
 *             Example: I2C_SET_AA(I2C0)
 */
static __INLINE void I2C_SET_AA(I2C_T *port)
{
    ((port)->I2CON |= I2C_CON_AA);
}
/**
 * @brief      Clear AA
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    No acknowledged (low level to SDA) will be returned
 *             Example: I2C_CLEAR_AA(I2C0)
 */
static __INLINE void I2C_CLEAR_AA(I2C_T *port)
{
    ((port)->I2CON &= ~I2C_CON_AA);
}
/**
 * @brief      Set I2C data
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Set I2C data
 *             Example: I2C_SET_DATA(I2C0,0x55)
 */
static __INLINE void I2C_SET_DATA(I2C_T *port,uint32_t u8data)
{
    ((port)->I2CDAT = u8data);
}
/**
 * @brief      Get I2C data
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     I2C data
 *
 * @details    Get I2C data
 *             Example: I2C_GET_DATA(I2C0)
 */
static __INLINE uint32_t I2C_GET_DATA(I2C_T *port)
{
    return ((port)->I2CDAT); 
}
/**
 * @brief      Get I2C data	status
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return      I2C status
 *
 * @details    Get I2C data	status
 *             Example: I2C_GET_I2CSTATUS(I2C0)
 */
static __INLINE uint32_t I2C_GET_I2CSTATUS(I2C_T *port)
{
    return ((port)->I2CSTATUS);
}
/**
 * @brief      Set I2C divider
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Set I2C divider
 *             Example: I2C_SET_DIVIDER(I2C0,0x05)
 */
static __INLINE void I2C_SET_DIVIDER(I2C_T *port,uint32_t u8div)
{
    ((port)->I2CLK |= u8div);
}
/**
 * @brief      Enable I2C time out counter
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Enable I2C time out counter 
 *             Example: I2C_ENABLE_TOC(I2C0)
 */
static __INLINE void I2C_ENABLE_TOC(I2C_T *port)
{
    ((port)->I2CTOC |= I2C_TOC_ENTI);
}
/**
 * @brief      Disable I2C time out counter
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Disable I2C time out counter 
 *             Example: I2C_DISABLE_TOC(I2C0)
 */
static __INLINE void I2C_DISABLE_TOC(I2C_T *port)
{
    ((port)->I2CTOC &= ~I2C_TOC_ENTI);
}
/**
 * @brief      Enable I2C time out counter clock Divided by 4
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    When Enabled, the time-out period is extend 4 times.
 *             Example: I2C_ENABLE_TOC_DIV4(I2C0)
 */
static __INLINE void I2C_ENABLE_TOC_DIV4(I2C_T *port)
{
    ((port)->I2CTOC |= I2C_TOC_DIV4);
}
/**
 * @brief      Disable I2C time out counter clock Divided by 4
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Disable I2C time out counter clock Divided by 4
 *             Example: I2C_DISABLE_TOC_DIV4(I2C0)
 */
static __INLINE void I2C_DISABLE_TOC_DIV4(I2C_T *port)
{
    ((port)->I2CTOC &= ~I2C_TOC_DIV4);
}
/**
 * @brief      Read time out flag
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @retval     0 =  No time out happened
 * @retval     !0 =  Time out happened. 
 *
 * @details    Read time out flag. Time-out flag is set by H/W. It can interrupt CPU
 *             Example: I2C_READ_TIMEOUT_FLAG(I2C0)
 */
static __INLINE uint32_t I2C_READ_TIMEOUT_FLAG(I2C_T *port)
{
    return ((port)->I2CTOC &I2C_TOC_TIF);
}
/**
 * @brief      Clear time out flag
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Clear time out flag
 *             Example: I2C_CLEAR_TIMEOUT_FLAG(I2C0)
 */
static __INLINE void I2C_CLEAR_TIMEOUT_FLAG(I2C_T *port)
{
    ((port)->I2CTOC &= ~I2C_TOC_TIF);
}
/**
 * @brief      Enable General Call Mode
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Enable General Call Mode.
 *             Example: I2C_ENABLE_GENERAL_CALL(I2C0)
 */
static __INLINE void I2C_ENABLE_GENERAL_CALL(I2C_T *port)
{
    ((port)->I2CADDR0 |=  I2C_ADDR_GC); /*!< Enable General Call Mode  */
}
/**
 * @brief      Disable General Call Mode
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    Disable General Call Mode.
 *             Example: I2C_DISABLE_GENERAL_CALL(I2C0)
 */
static __INLINE void I2C_DISABLE_GENERAL_CALL(I2C_T *port)
{
   ((port)->I2CADDR0 &= ~I2C_ADDR_GC); /*!< Disable General Call Mode */
}

/**
 * @brief      Set I2C address
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  u8add  7-bit slave address
 *
 * @return     None
 *
 * @details    Set I2C address 0
 *             Example: I2C_SET_ADDRESS0(I2C0,0xA0)
 */
static __INLINE void I2C_SET_ADDRESS0(I2C_T *port,uint32_t u8add)
{
   ((port)->I2CADDR0 = u8add);
}
/**
 * @brief      Set I2C address
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  u8add  7-bit slave address
 * @return     None
 *
 * @details    Set I2C address 1
 *             Example: I2C_SET_ADDRESS1(I2C0,0xB0)
 */
static __INLINE void I2C_SET_ADDRESS1(I2C_T *port,uint32_t u8add)
{
   ((port)->I2CADDR1 = u8add);
}
/**
 * @brief      Set I2C address
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  u8add  7-bit slave address
 *
 * @return     None
 *
 * @details    Set I2C address 2
 *             Example: I2C_SET_ADDRESS2(I2C0,0xC0)
 */
static __INLINE void I2C_SET_ADDRESS2(I2C_T *port,uint32_t u8add)
{
   ((port)->I2CADDR2 = u8add);
}
/**
 * @brief      Set I2C address
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  u8add  7-bit slave address
 *
 * @return     None
 *
 * @details    Set I2C address 3
 *             Example: I2C_SET_ADDRESS3(I2C0,0xD0)
 */
static __INLINE void I2C_SET_ADDRESS3(I2C_T *port,uint32_t u8add)
{
    ((port)->I2CADDR3 = u8add);
}

/**
 * @brief      Set I2C address mask
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 *
 * @param[in]  u8addm  7-bit data to mask the corresponding slave address bit(s) of I2CADDR0
 *
 * @return     None
 *
 * @details    Set I2C address mask0
 *             Example: I2C_SET_ADDRESS_MASK0(I2C0,0x20)
 */
static __INLINE void I2C_SET_ADDRESS_MASK0(I2C_T *port,uint32_t u8addm)
{
    ((port)->I2CADM0 = u8addm);
}
/**
 * @brief      Set I2C address mask
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  u8addm  7-bit data to mask the corresponding slave address bit(s) of I2CADDR1
 *
 * @return     None
 *
 * @details    Set I2C address mask1
 *             Example: I2C_SET_ADDRESS_MASK1(I2C0,0x40)
 */
static __INLINE void I2C_SET_ADDRESS_MASK1(I2C_T *port,uint32_t u8addm)
{
    ((port)->I2CADM1 = u8addm);
}
/**
 * @brief      Set I2C address mask
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  u8addm  7-bit data to mask the corresponding slave address bit(s) of I2CADDR2
 *
 * @return     None
 *
 * @details    Set I2C address mask2
 *             Example: I2C_SET_ADDRESS_MASK2(I2C0,0x80)
 */
static __INLINE void I2C_SET_ADDRESS_MASK2(I2C_T *port,uint32_t u8addm) 
{
    ((port)->I2CADM2 = u8addm);
}
/**
 * @brief      Set I2C address mask
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  u8addm  7-bit data to mask the corresponding slave address bit(s) of I2CADDR3
 *
 * @return     None
 *
 * @details    Set I2C address mask3
 *             Example: I2C_SET_ADDRESS_MASK3(I2C0,0x10)
 */
static __INLINE void I2C_SET_ADDRESS_MASK3(I2C_T *port,uint32_t u8addm)
{
    ((port)->I2CADM3 = u8addm);
}
/**
 * @brief      I2C Wake-up Function Enable
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    I2C Wake-up Function Enable.
 *             Example: I2C_ENABLE_WAKEUP(I2C0)
 */
static __INLINE void I2C_ENABLE_WAKEUP(I2C_T *port)
{
    ((port)->I2CWKUPCON |= I2C_I2CWKUPCON_WKUPEN);
}
/**
 * @brief      I2C Wake-up Function Disable
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    I2C Wake-up Function Disable.
 *             Example: I2C_DISABLE_WAKEUP(I2C0)
 */
static __INLINE void I2C_DISABLE_WAKEUP(I2C_T *port)
{
    ((port)->I2CWKUPCON &= ~I2C_I2CWKUPCON_WKUPEN);
}
/**
 * @brief      Read wake up Interrupt flag
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @retval     0 = Wake-up flag inactive. 
 * @retval     1 = Wake-up flag active. 
 *
 * @details    Read wake up Interrupt flag
 *             Example: I2C_READ_WAKEUP_FLAG(I2C0)
 */
static __INLINE uint32_t I2C_READ_WAKEUP_FLAG(I2C_T *port)
{
    return ((port)->I2CWKUPSTS & I2C_I2CWKUPCON_WKUPIF);
}
/**
 * @brief      Clear wake up Interrupt flag
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None 
 *
 * @details    Clear wake up Interrupt flag
 *             Example: I2C_CLEAR_WAKEUP_FLAG(I2C0)
 */
static __INLINE void I2C_CLEAR_WAKEUP_FLAG(I2C_T *port)
{
    ((port)->I2CWKUPSTS &= ~I2C_I2CWKUPCON_WKUPIF);
}

/**
 * @brief      Generate START signal to I2C bus
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @return     None
 *
 * @details    This macro is used to generate START signal to specified I2C port,and wait the action finish 
 *			   Example: I2C_START_WAIT_AND_CLEAR(I2C0)
 */
//#define I2C_START_WAIT_AND_CLEAR(port) do{I2C_START(port);I2C_WAIT_READY(port);I2C_CLEAR_START(port);}while(0)

static __INLINE void I2C_START_WAIT_AND_CLEAR(I2C_T *port)
{
     I2C_START(port);
     I2C_WAIT_READY(port);
}

/**
 * @brief      Sent a data 
 *
 * @param[in]  port    I2C port 
 *                     -I2C0
 *                     -I2C1
 * @param[in]  Data    The data to send
 * @return     None 
 *
 * @details    Sent a data and wait for finishing
 *             Example: I2C_SENT_DATA(I2C0,0x55)
 */
static __INLINE void I2C_SENT_DATA(I2C_T *port,uint32_t Data)
{
     I2C_SET_DATA(port,Data);
     I2C_CLEAR_SI(port); 
     I2C_WAIT_READY(port);
}

/*@}*/ /* end of group I2C_MACRO_FUNC */
/*@}*/ /* end of group I2C_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

/*---------------------------------------------------------------------------------------------------------*/
/*  Function declaration                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void DrvI2C_Ctrl(I2C_T *I2cPort, uint8_t start, uint8_t stop, uint8_t si, uint8_t ack);
void DrvI2C_Init(I2C_T *I2cPort, uint32_t u32BusClock, uint8_t EnableInt);
void DrvI2C_DeInit(I2C_T *I2cPort);
uint32_t DrvI2C_GetClockFreq(I2C_T *I2cPort);
void DrvI2C_EnableInt(I2C_T *I2cPort);
void DrvI2C_DisableInt(I2C_T *I2cPort);
int32_t DrvI2C_SetAddress(I2C_T *I2cPort, uint8_t slaveNo, uint8_t slave_addr, uint8_t GC_Flag);
int32_t DrvI2C_SetAddressMask(I2C_T *I2cPort, uint8_t slaveNo, uint8_t slaveAddrMask);

#endif

