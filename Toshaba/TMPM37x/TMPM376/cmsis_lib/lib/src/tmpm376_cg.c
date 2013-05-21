/**
 *******************************************************************************
 * @file    tmpm376_cg.c
 * @brief   This file provides API functions for CG driver 
 * @version V2.0.2.1
 * @date    2012/01/17
 * 
 * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". TOSHIBA
 * CORPORATION MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. TOSHIBA CORPORATION
 * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
 * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
 * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
 * 
 * TOSHIBA CORPORATION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
 * ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
 * PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
 * DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
 * WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm376_cg.h"

#if defined(__TMPM376_CG_H) || defined(__TMPM377_CG_H) 
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup CG
  * @brief CG driver modules
  * @{
  */

/** @defgroup CG_Private_Defines
  * @{
  */

#define FC_GEAR_1_1                 ((uint32_t)0x00000000)
#define FC_GEAR_1_2                 ((uint32_t)0x00000004)
#define FC_GEAR_1_4                 ((uint32_t)0x00000005)
#define FC_GEAR_1_8                 ((uint32_t)0x00000006)
#define FC_GEAR_1_16                ((uint32_t)0x00000007)


typedef union {
    uint32_t byte4;
    uint8_t byte[4];
} CG_Byte4;

static CG_DivideLevel numToDivideLevel_table[CG_DIVIDE_MAX] = {
    CG_DIVIDE_1,
    CG_DIVIDE_2,
    CG_DIVIDE_4,
    CG_DIVIDE_8,
    CG_DIVIDE_16,
    CG_DIVIDE_32,
    CG_DIVIDE_64,
    CG_DIVIDE_128,
    CG_DIVIDE_256,
    CG_DIVIDE_512,
    CG_DIVIDE_UNKNOWN,
};


/** @} */
/* End of group CG_Private_Defines */

/** @defgroup CG_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group CG_Private_FunctionPrototypes */

/** @defgroup CG_Private_Functions
  * @{
  */

/** @} */
/* End of group CG_Private_Functions */

/** @defgroup CG_Exported_Functions
  * @{
  */

/**
  * @brief  Set dividing level between clock fgear and fc.
  * @param  DivideFgearFromFc: Dividing level between fgear and fc.
  *   This parameter can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4, CG_DIVIDE_8, CG_DIVIDE_16
  * @retval None
  */
void CG_SetFgearLevel(CG_DivideLevel DivideFgearFromFc)
{
    uint32_t gear = FC_GEAR_1_1;
    uint32_t regval = TSB_CG->SYSCR;

    /* Check the parameters */
    assert_param(IS_CG_GEAR_DIVIDE_LEVEL(DivideFgearFromFc));

    /* Set the value of fgear */
    switch (DivideFgearFromFc) {
    case CG_DIVIDE_1:
        gear = FC_GEAR_1_1;
        break;
    case CG_DIVIDE_2:
        gear = FC_GEAR_1_2;
        break;
    case CG_DIVIDE_4:
        gear = FC_GEAR_1_4;
        break;
    case CG_DIVIDE_8:
        gear = FC_GEAR_1_8;
        break;
    case CG_DIVIDE_16:
        gear = FC_GEAR_1_16;
        break;
    default:
        /* Do nothing */
        break;
    }
    
    /* CG_SYSCR: only need to keep bit12 and bit10,9,8 , then clear bit 2,1,0 */
    regval &= (uint32_t)((0x01U << 12U) | (0x07U << 8U));
    regval |= gear;
    regval |= (uint32_t)(0x01U << 16U); /* bit17,16 must be wrote '01' */
    TSB_CG->SYSCR = regval;
}

/**
  * @brief  Get dividing level between clock fgear and fc.
  * @param  None
  * @retval The dividing level between clock fgear and fc
  *   The value returned can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4,
  *   CG_DIVIDE_8, CG_DIVIDE_16 or CG_DIVIDE_UNKNOWN
  */
CG_DivideLevel CG_GetFgearLevel(void)
{
    CG_DivideLevel DivideFgearFromFc = CG_DIVIDE_UNKNOWN;
    uint32_t syscr = TSB_CG->SYSCR;
        
    syscr &= (uint32_t)0x07U; /* only keep bit2,1,0 */

    switch (syscr) {
    case FC_GEAR_1_1:
        DivideFgearFromFc = CG_DIVIDE_1;
        break;
    case FC_GEAR_1_2:
        DivideFgearFromFc = CG_DIVIDE_2;
        break;
    case FC_GEAR_1_4:
        DivideFgearFromFc = CG_DIVIDE_4;
        break;
    case FC_GEAR_1_8:
        DivideFgearFromFc = CG_DIVIDE_8;
        break;
    case FC_GEAR_1_16:
        DivideFgearFromFc = CG_DIVIDE_16;
        break;
    default:
        /* Do nothing */
        break;
    }

    return DivideFgearFromFc;
}

/**
  * @brief  Select the PhiT0(¦µT0) source between fgear and fc
  * @param  PhiT0Src: Set PhiT0 Source
  *   This parameter can be one of the following values:
  *   CG_PHIT0_SRC_FGEAR, CG_PHIT0_SRC_FC
  * @retval None
  */
void CG_SetPhiT0Src(CG_PhiT0Src PhiT0Src)
{
    uint32_t regval = 0U;

    /* Check the parameters */
    assert_param(IS_CG_PHIT0_SRC(PhiT0Src));

    regval = TSB_CG->SYSCR;
    
    /* SYSCR: keep bit10,9,8, and 2,1,0, then clear bit 12 */
    regval &= (uint32_t)( (0x07U << 8U) | 0x07U);
    
    /* write PhiToSrc to bit 12 and write '01' to bit17,16 */
    regval |= (uint32_t) PhiT0Src << 12U;
    regval |= (uint32_t)(0x01U << 16U);
    
    TSB_CG->SYSCR = regval;
}

/**
  * @brief  Get PhiT0 Source
  * @param  None
  * @retval The source of PhiT0
  *   The value returned can be one of the following values:
  *   CG_PHIT0_SRC_FGEAR, CG_PHIT0_SRC_FC
  */
CG_PhiT0Src CG_GetPhiT0Src(void)
{
    uint32_t regval = 0U;
    CG_PhiT0Src source = CG_PHIT0_SRC_FGEAR;

    regval = TSB_CG->SYSCR;
    
    /* to judge bit 12 */
    regval &= (uint32_t)(0x01U << 12U);
    if( regval ) {
        source = CG_PHIT0_SRC_FC;
    } else {
        /* Do nothing */
    }

    return source;
}

/**
  * @brief  Set dividing level between PhiT0 and fc.
  * @param  DividePhiT0FromFc: Dividing level between PhiT0 and fc.
  *   This parameter can be one of the following values:
  *   CG_DIVIDE_1,   CG_DIVIDE_2,  CG_DIVIDE_4,  CG_DIVIDE_8,
  *   CG_DIVIDE_16,  CG_DIVIDE_32, CG_DIVIDE_64, CG_DIVIDE_128,
  *   CG_DIVIDE_256, CG_DIVIDE_512
  * @retval  Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CG_SetPhiT0Level(CG_DivideLevel DividePhiT0FromFc)
{
    uint32_t fprclk = 0U;
    CG_DivideLevel fgear = CG_DIVIDE_UNKNOWN;
    CG_PhiT0Src PhiT0_src = CG_PHIT0_SRC_FGEAR;
    Result retval = ERROR;
    
    uint32_t regval = TSB_CG->SYSCR;

    PhiT0_src = CG_GetPhiT0Src();
    if (PhiT0_src == CG_PHIT0_SRC_FC) {
        /* Check the parameters */
        assert_param(IS_CG_DIVIDE_FC_LEVEL(DividePhiT0FromFc));

        /* only keep bit12 and bit2,1,0 */
        regval &= (uint32_t)((0x01U << 12U) | 0x07U);
        
        fprclk = (uint32_t) DividePhiT0FromFc << 8U;
                
        regval |= fprclk;
        regval |= (uint32_t)(0x01U << 16U); /* bit17,16 must be wrote '01' */
        TSB_CG->SYSCR = regval;
        retval = SUCCESS;
    } else {
        /* Check the parameters */
        assert_param(IS_CG_DIVIDE_FGEAR_LEVEL(DividePhiT0FromFc));

        fgear = CG_GetFgearLevel();
        if (fgear != CG_DIVIDE_UNKNOWN) {
            if ((DividePhiT0FromFc > fgear) || (DividePhiT0FromFc == fgear)) {
                fprclk = (uint32_t) DividePhiT0FromFc - (uint32_t) fgear;
                if (fprclk <= CG_DIVIDE_32) {
                    /* only keep bit12 and bit2,1,0 */
                    regval &= (uint32_t)((0x01U << 12U) | 0x07U);
                    fprclk <<= 8U;
                    regval |= fprclk;
                    regval |= (uint32_t)(0x01U << 16U); /* bit17,16 must be wrote '01' */
                    TSB_CG->SYSCR = regval;
                    retval = SUCCESS;
                } else {
                    /* Do nothing */
                }
            } else {
                /* Do nothing */
            }
        } else {
            /* Do nothing */
        }
    }

    return retval;
}

/**
  * @brief  Get dividing level between clock phiT0 and fc.
  * @param  None
  * @retval The divide level between clock phiT0 and fc
  *   The value returned can be one of the following values:
  *   CG_DIVIDE_1,   CG_DIVIDE_2,  CG_DIVIDE_4,  CG_DIVIDE_8,
  *   CG_DIVIDE_16,  CG_DIVIDE_32, CG_DIVIDE_64, CG_DIVIDE_128,
  *   CG_DIVIDE_256, CG_DIVIDE_512, CG_DIVIDE_UNKNOWN
  */
CG_DivideLevel CG_GetPhiT0Level(void)
{
    uint32_t fprclk = 0U;
    CG_DivideLevel fgear = CG_DIVIDE_UNKNOWN;
    CG_DivideLevel phiT0Level = CG_DIVIDE_UNKNOWN;
    CG_PhiT0Src PhiT0_src = CG_PHIT0_SRC_FGEAR;

    /* read bit10,9,8 to fprclk */
    fprclk = (TSB_CG->SYSCR & ((uint32_t)0x07U << 8U )) >> 8U;
    
    PhiT0_src = CG_GetPhiT0Src();

    if (PhiT0_src == CG_PHIT0_SRC_FC) {
        phiT0Level = numToDivideLevel_table[fprclk];
    } else {
        fgear = CG_GetFgearLevel();
        if (fgear != CG_DIVIDE_UNKNOWN) {
            fprclk = fprclk + fgear;
            if (fprclk < CG_DIVIDE_UNKNOWN) {
                phiT0Level = numToDivideLevel_table[fprclk];
            } else {
                /* Do nothing */
            }
        } else {
            /* Do nothing */
        }
    }

    return phiT0Level;
}

/**
  * @brief  Set the clock source and count value for warm up timer 
  * @param  Source: Select source of warm-up counter
  *   This parameter can be one of the following values:
  *   CG_WARM_UP_SRC_OSC1, CG_WARM_UP_SRC_OSC2
  * @param  Time: Set count time for warm-up timer
  * @retval None
  */
void CG_SetWarmUpTime(CG_WarmUpSrc Source, uint16_t Time)
{
    uint32_t regval = TSB_CG->OSCCR;

    /* Check the parameters */
    assert_param(IS_CG_WARM_UP_SRC(Source));
    assert_param(IS_CG_WARM_UP_TIME_X1(Time));

    /* CG_OSCCR: clear WUODR13--2, WUPSEL2, then keep bit18,17,16, 8, 2, 1 */
    regval &= (uint32_t)0x00070106;
    regval |= (uint32_t)Time << 20U;

    if (Source == CG_WARM_UP_SRC_OSC1) { /* then set bit19 */
        regval |= (uint32_t)(0x01 << 19U);   
    } else {
        /* Do nothing */
    }

    TSB_CG->OSCCR = regval;
}

/**
  * @brief  Start operation of warm up timer for oscillator.
  * @param  None
  * @retval None
  */
void CG_StartWarmUp(void)
{
    TSB_CG_OSCCR_WUEON = 1U;
}

/**
  * @brief Check whether warm up is completed or not.
  * @param  None
  * @retval The state of warm-up
  *   The value returned can be one of the following values:
  *    DONE : the warm up time is completed.
  *    BUSY : the warm up time is in operation.
  */
WorkState CG_GetWarmUpState(void)
{
    WorkState state = BUSY;

    if (TSB_CG_OSCCR_WUEF == 0U) {
        state = DONE;
    } else {
        /* Do nothing */
    }

    return state;
}

/**
  * @brief  Enable PLL or disable it.
  * @param  NewState: New state of PLL
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CG_SetPLL(FunctionalState NewState)
{
    Result retval = ERROR;
    CG_FcSrc fcsrc = CG_FC_SRC_FPLL;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG_OSCCR_PLLON = 1U;
        retval = SUCCESS;
    } else {
        fcsrc = CG_GetFcSrc();
        if (fcsrc == CG_FC_SRC_FOSC) {  /* PLL is not used. So it can be shut off */
            /* Set register to disable PLL */
            TSB_CG_OSCCR_PLLON = 0U;
            retval = SUCCESS;
        } else {                /*fcsrc == CG_FC_SRC_FPLL. PLL is in use, so disabling it should be invalid */
            /* Do nothing */
        }
    }

    return retval;
}

/**
  * @brief  Get the status of PLL operation
  * @param  None
  * @retval Run or stop
  *   The value returned can be one of the following values:
  *   ENABLE or DISABLE
  */
FunctionalState CG_GetPLLState(void)
{
    FunctionalState pllstate = DISABLE;

    if (TSB_CG_OSCCR_PLLON == 1U) {
        pllstate = ENABLE;
    } else {
        /* Do nothing */
    }

    return pllstate;
}

/**
  * @brief  This function enables or disables high-speed oscillator (fosc).
  * @param  Source: Select clock source for fosc
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 : External high speed oscillation 
  *   CG_FOSC_OSC2 : Internal high speed oscillation
  * @param  NewState: oscillator is enabled or disabled
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval Success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CG_SetFosc(CG_FoscSrc Source, FunctionalState NewState)
{

    CG_FoscSrc fosc_src = CG_FOSC_OSC2;
    Result retval = ERROR;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_CG_FOSC_SRC(Source));

    switch (Source) {
    case CG_FOSC_OSC1:
        if (TSB_CG_OSCCR_HOSCON != 0U) {
            if (NewState == ENABLE) {
                /* Enable high-speed oscillator */
                TSB_CG_OSCCR_XEN1 = 1U;
                retval = SUCCESS;
            } else {
                fosc_src = CG_GetFoscSrc();
                if (fosc_src == CG_FOSC_OSC1) {
                    /* fosc1 is in use, so it can't be disabled */
                    retval = ERROR;
                } else {
                    /* Disable high-speed oscillator1 */
                    TSB_CG_OSCCR_XEN1 = 0U;
                    retval = SUCCESS;
                }
            }
        } else {
            /* Do nothing */
        }

        break;
    case CG_FOSC_OSC2:
        if (NewState == ENABLE) {
            /* Enable high-speed oscillator */
            TSB_CG_OSCCR_XEN2 = 1U;
            retval = SUCCESS;
        } else {
            fosc_src = CG_GetFoscSrc();
            if (fosc_src == CG_FOSC_OSC2) {
                /* fosc2 is in  use, so it can't be disabled */
                retval = ERROR;
            } else {
                /* Disable high-speed oscillator2 */
                TSB_CG_OSCCR_XEN2 = 0U;
                retval = SUCCESS;
            }
        }
        break;
    default:
        /* Do nothing */
        break;
    }

    return retval;

}


/**
  * @brief  Set the source of high-speed oscillator (fosc)
  * @param  Source: Select clock source for fosc
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 : External high speed oscillation 
  *   CG_FOSC_OSC2 : Internal high speed oscillation
  * @retval None
  */
void CG_SetFoscSrc(CG_FoscSrc Source)
{
    /* Check the parameters */
    assert_param(IS_CG_FOSC_SRC(Source));

    if (Source == CG_FOSC_OSC1) {
        TSB_CG_OSCCR_OSCSEL = 1U;
    } else {
        TSB_CG_OSCCR_OSCSEL = 0U;
    }
}

/**
  * @brief  Get the source of high-speed oscillator (fosc)
  * @param  None
  * @retval Source of fosc
  *   The value returned can be one of the following values:
  *   CG_FOSC_OSC1 : External high speed oscillation 
  *   CG_FOSC_OSC2 : Internal high speed oscillation
  */
CG_FoscSrc CG_GetFoscSrc(void)
{
    CG_FoscSrc fosc_src = CG_FOSC_OSC1;

    if (TSB_CG_OSCCR_OSCSEL == 0U) {
        fosc_src = CG_FOSC_OSC2;
    } else {
        /* Do nothing */
    }

    return fosc_src;
}

/**
  * @brief  Set portM for X1/X2 or general port
  * @param New mode of portM.
  *   This parameter can be one of the following values:
  *   CG_PORTM_AS_GPIO or CG_PORTM_AS_HOSC
  * @retval None
  */
void CG_SetPortM(CG_PortMMode Mode)
{
    /* Check the parameters */
    assert_param(IS_CG_PROTM_FUNCTION(Mode));

    TSB_CG_OSCCR_HOSCON = Mode;
}

/**
  * @brief  Get the state of input INT.
  * @param  INTSource: Select the release INT source
  *   This parameter can be one of the following values:
  *    For M376:
  *     CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2, CG_INT_SRC_3,
  *     CG_INT_SRC_4, CG_INT_SRC_5, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_8, CG_INT_SRC_9, CG_INT_SRC_A, CG_INT_SRC_B,
  *     CG_INT_SRC_C, CG_INT_SRC_D, CG_INT_SRC_E, CG_INT_SRC_F.
  *    For M377:
  *     CG_INT_SRC_3, CG_INT_SRC_4, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_B.
  * @retval The state of input INT
  */
CG_INTReqState CG_GetINTReq(CG_INTSrc INTSource)
{
    CG_INTReqState int_state = CG_NO_INT_REQ;
    uint8_t i = 0U;
    uint8_t j = 0U;
    uint8_t tmp = 0U;
    uint32_t num = 0U;
    CG_Byte4 regval[4] = { {0U}
    , {0U}
    , {0U}
    , {0U}
    };

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    regval[0].byte4 = TSB_CG->IMCGA;
    regval[1].byte4 = TSB_CG->IMCGB;
    regval[2].byte4 = TSB_CG->IMCGC;
    regval[3].byte4 = TSB_CG->IMCGD;

    num = (uint32_t) INTSource;
    i = (uint8_t) (num / 4U);
    j = (uint8_t) (num % 4U);
    tmp = regval[i].byte[j];
    
    tmp &= 0x02U;
    if (tmp == 0x02U) {
        int_state = CG_INT_REQ;
    } else {
        /* Do nothing */
    }

    return (int_state);
}

/**
  * @brief  Get the state of high-speed oscillator (fosc)
  * @param  Source: Select fosc source
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 : External high speed oscillation 
  *   CG_FOSC_OSC2 : Internal high speed oscillation
  * @retval State of fosc
  *   The value returned can be one of the following values:
  *   ENABLE or DISABLE
  */
FunctionalState CG_GetFoscState(CG_FoscSrc Source)
{
    FunctionalState state = DISABLE;

    /* Check the parameters */
    assert_param(IS_CG_FOSC_SRC(Source));

    if (Source == CG_FOSC_OSC1) {
        if (TSB_CG_OSCCR_XEN1 == 1U) {
            state = ENABLE;
        } else {
            /* Do nothing */
        }
    } else {
        if (TSB_CG_OSCCR_XEN2 == 1U) {
            state = ENABLE;
        } else {
            /* Do nothing */
        }
    }

    return state;
}

/**
  * @brief  Set the specified low-power mode
  * @param  Low power mode
  *   The value can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_IDLE
  * @retval None
  */
void CG_SetSTBYMode(CG_STBYMode Mode)
{
    uint32_t regval = TSB_CG->STBYCR;

    /* Check the parameter */
    assert_param(IS_CG_STBY_MODE(Mode));

    /* CG_STBYCR: only need to keep bit16, then clear bit2,1,0 */
    regval &= (uint32_t)( (0x01U << 16U) );
    /* bit 8 must be wrote '1' */
    regval |= (uint32_t) ( Mode | (0x01U << 8U ));

    TSB_CG->STBYCR = regval;
}

/**
  * @brief  Get the low-power consumption mode
  * @param  None
  * @retval Low power mode
  *   The value returned can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_IDLE or CG_STBY_MODE_UNKNOWN
  */
CG_STBYMode CG_GetSTBYMode(void)
{
    CG_STBYMode stby_mode = CG_STBY_MODE_UNKNOWN;
    
    uint32_t regval = TSB_CG->STBYCR & (uint32_t)0x07U;

    if( regval == 0x01U) {
        stby_mode = CG_STBY_MODE_STOP;
    } else if (regval == 0x03U ) {
        stby_mode = CG_STBY_MODE_IDLE;  
    } else {
        /* Do nothing */
    }      

    return stby_mode;
}

/**
  * @brief  Set I/O pins status in stop mode
  * @param  NewState: enable or disable
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE
  * @retval None
  */
void CG_SetPinStateInStopMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG_STBYCR_DRVE = 1U;
    } else {
        TSB_CG_STBYCR_DRVE = 0U;
    }
}

/**
  * @brief  Get setting for I/O pins status in stop mode
  * @param  None
  * @retval State of pin in stop mode
  *   The value returned can be one of the following values:
  *   DISABLE or ENABLE
  */
FunctionalState CG_GetPinStateInStopMode(void)
{
    FunctionalState state = DISABLE;

    if (TSB_CG_STBYCR_DRVE == 1U) {
        /* Pin status in stop mode is active */
        state = ENABLE;
    } else {
        /* Do nothing */
    }

    return state;
}

/**
  * @brief  Set the source of fc
  * @param  Source:  The source of fc
  *   This parameter can be one of the following values:
  *   CG_FC_SRC_FOSC or CG_FC_SRC_FPLL
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CG_SetFcSrc(CG_FcSrc Source)
{

    Result retval = ERROR;
    FunctionalState fosc_on = DISABLE;
    FunctionalState pllon = DISABLE;

    /* Check the parameters */
    assert_param(IS_CG_FC_SRC(Source));

    fosc_on = CG_GetFoscState(CG_FOSC_OSC1);
    pllon = CG_GetFoscState(CG_FOSC_OSC2);
    if ( fosc_on || pllon ) {
        fosc_on = ENABLE;
    } else {
        /* Do nothing */
    }

    if (fosc_on == ENABLE) {
        if (Source == CG_FC_SRC_FOSC) {
            TSB_CG_PLLSEL_PLLSEL = 0U;
            retval = SUCCESS;
        } else {
            pllon = CG_GetPLLState();
            if (pllon == ENABLE) {
                TSB_CG_PLLSEL_PLLSEL = 1U;
                retval = SUCCESS;
            } else {
                /* Do nothing */
            }
        }
    } else {
        /* Do nothing */
    }

    return retval;
}

/**
  * @brief  Get the source of fc
  * @param  None
  * @retval The source of fc
  *   The value returned can be one of the following values:
  *   CG_FC_SRC_FOSC or CG_FC_SRC_FPLL
  */
CG_FcSrc CG_GetFcSrc(void)
{
    CG_FcSrc fcsrc = CG_FC_SRC_FOSC;

    if (TSB_CG_PLLSEL_PLLSEL == 1U) {
        fcsrc = CG_FC_SRC_FPLL;
    } else {
        /* Do nothing */
    }

    return fcsrc;
}

/**
  * @brief  Setup the INT source for releasing low power mode.
  * @param  INTSource: Select the release INT source
  *   This parameter can be one of the following values:
  *    For M376:
  *     CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2, CG_INT_SRC_3,
  *     CG_INT_SRC_4, CG_INT_SRC_5, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_8, CG_INT_SRC_9, CG_INT_SRC_A, CG_INT_SRC_B,
  *     CG_INT_SRC_C, CG_INT_SRC_D, CG_INT_SRC_E, CG_INT_SRC_F.
  *    For M377:
  *     CG_INT_SRC_3, CG_INT_SRC_4, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_B.
  * @param  ActiveState: Select the active state for release trigger
  *   The  parameter can be one of the following values:
  *   CG_INT_ACTIVE_STATE_L, 
  *   CG_INT_ACTIVE_STATE_H, 
  *   CG_INT_ACTIVE_STATE_FALLING,
  *   CG_INT_ACTIVE_STATE_RISING, 
  *   CG_INT_ACTIVE_STATE_BOTH_EDGES
  * @param  NewState: Enable or disable this release trigger
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval None
  */
void CG_SetSTBYReleaseINTSrc(CG_INTSrc INTSource,
                             CG_INTActiveState ActiveState, FunctionalState NewState)
{
    uint32_t num = 0U;
    uint8_t i = 0U;
    uint8_t j = 0U;
    CG_Byte4 regval[4] = { {0U}
    , {0U}
    , {0U}
    , {0U}
    };

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));
    assert_param(IS_CG_INT_ACTIVE_STATE(ActiveState));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    num = (uint32_t) INTSource;
    i = (uint8_t) (num / 4U);
    j = (uint8_t) (num % 4U);

    switch (i) {
    case 0U:                   /* IMCGA */
        regval[0].byte4 = TSB_CG->IMCGA;
        regval[0].byte[j] &= 0x8eU;
        regval[0].byte[j] |= ActiveState;
        TSB_CG->IMCGA = regval[0].byte4;
        regval[0].byte[j] |= NewState;
        TSB_CG->IMCGA = regval[0].byte4;
        break;

    case 1U:                   /* IMCGB */
        regval[1].byte4 = TSB_CG->IMCGB;
        regval[1].byte[j] &= 0x8eU;
        regval[1].byte[j] |= ActiveState;
        TSB_CG->IMCGB = regval[1].byte4;
        regval[1].byte[j] |= NewState;
        TSB_CG->IMCGB = regval[1].byte4;
        break;

    case 2U:                   /* IMCGC */
        regval[2].byte4 = TSB_CG->IMCGC;
        regval[2].byte[j] &= 0x8eU;
        regval[2].byte[j] |= ActiveState;
        TSB_CG->IMCGC = regval[2].byte4;
        regval[2].byte[j] |= NewState;
        TSB_CG->IMCGC = regval[2].byte4;
        break;

    case 3U:                   /* IMCGD */
        regval[3].byte4 = TSB_CG->IMCGD;
        regval[3].byte[j] &= 0x8eU;
        regval[3].byte[j] |= ActiveState;
        TSB_CG->IMCGD = regval[3].byte4;
        regval[3].byte[j] |= NewState;
        TSB_CG->IMCGD = regval[3].byte4;
        break;

    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Get the active state for the specified INT source for releasing low power mode
  * @param  INTSource: Select the release INT source
  *   This parameter can be one of the following values:
  *    For M376:
  *     CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2, CG_INT_SRC_3,
  *     CG_INT_SRC_4, CG_INT_SRC_5, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_8, CG_INT_SRC_9, CG_INT_SRC_A, CG_INT_SRC_B,
  *     CG_INT_SRC_C, CG_INT_SRC_D, CG_INT_SRC_E, CG_INT_SRC_F.
  *    For M377:
  *     CG_INT_SRC_3, CG_INT_SRC_4, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_B.
  * @retval Active state of the input INT
  *   The value returned can be one of the following values:
  *     CG_INT_ACTIVE_STATE_FALLING, 
  *     CG_INT_ACTIVE_STATE_RISING,
  *     CG_INT_ACTIVE_STATE_BOTH_EDGES, 
  *     CG_INT_ACTIVE_STATE_INVALID
  */
CG_INTActiveState CG_GetSTBYReleaseINTState(CG_INTSrc INTSource)
{
    CG_INTActiveState int_active_state = CG_INT_ACTIVE_STATE_INVALID;
    uint8_t i = 0U;
    uint8_t j = 0U;
    uint8_t tmp = 0U;
    uint32_t num = 0U;
    CG_Byte4 regval[4] = { {0U}
    , {0U}
    , {0U}
    , {0U}
    };

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    regval[0].byte4 = TSB_CG->IMCGA;
    regval[1].byte4 = TSB_CG->IMCGB;
    regval[2].byte4 = TSB_CG->IMCGC;
    regval[3].byte4 = TSB_CG->IMCGD;

    num = (uint32_t) INTSource;
    i = (uint8_t) (num / 4U);
    j = (uint8_t) (num % 4U);
    tmp = regval[i].byte[j];
    tmp &= 0x0CU;

    switch (tmp) {
    case 0x04U:
        int_active_state = CG_INT_ACTIVE_STATE_RISING;
        break;
    case 0x08U:
        int_active_state = CG_INT_ACTIVE_STATE_FALLING;
        break;
    case 0x0CU:
        int_active_state = CG_INT_ACTIVE_STATE_BOTH_EDGES;
        break;
    default:
        /* Do nothing */
        break;
    }

    return (int_active_state);
}

/**
  * @brief  Clears the input INT request.
  * @param  INTSource: Select the release INT source
  *   This parameter can be one of the following values:
  *    For M376:
  *     CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2, CG_INT_SRC_3,
  *     CG_INT_SRC_4, CG_INT_SRC_5, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_8, CG_INT_SRC_9, CG_INT_SRC_A, CG_INT_SRC_B,
  *     CG_INT_SRC_C, CG_INT_SRC_D, CG_INT_SRC_E, CG_INT_SRC_F.
  *    For M377:
  *     CG_INT_SRC_3, CG_INT_SRC_4, CG_INT_SRC_6, CG_INT_SRC_7,
  *     CG_INT_SRC_B.
  * @retval None
  */
void CG_ClearINTReq(CG_INTSrc INTSource)
{
    uint32_t regval = INTSource;

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    TSB_CG->ICRCG = regval;
}


/**
  * @brief  Get the NMI flag that shows who triggered NMI.
  * @param  None
  * @retval NMI flag
  */
CG_NMIFactor CG_GetNMIFlag(void)
{
    CG_NMIFactor cg_nmi_factor = { 0U };

    cg_nmi_factor.All = TSB_CG->NMIFLG & (uint32_t)0x01;

    return cg_nmi_factor;
}


/**
  * @brief  Get the type of reset reason and clear the reset flag.
  * @param  None
  * @retval Reset flag
  */
CG_ResetFlag CG_GetResetFlag(void)
{
    CG_ResetFlag reset_flag = { 0U };

    /* only keep bit5,4, 3,2,1,0 */
    reset_flag.All = TSB_CG->RSTFLG & (uint32_t)(0x3FU);
    TSB_CG->RSTFLG = 0U;

    return reset_flag;
}

/** @} */
/* End of group CG_Exported_Functions */

/** @} */
/* End of group CG */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM376_CG_H) || defined(__TMPM377_CG_H) */
