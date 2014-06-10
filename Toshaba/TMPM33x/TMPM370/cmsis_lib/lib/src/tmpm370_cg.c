/**
 *******************************************************************************
 * @file    tmpm370_cg.c
 * @brief   This file provides API functions for CG driver 
 * @version V2.2.0
 * @date    2011/07/06
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
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm370_cg.h"

#if defined(__TMPM370_CG_H) || defined(__TMPM372_CG_H) || \
    defined(__TMPM373_CG_H) || defined(__TMPM374_CG_H)
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
#define CG_FC_GEAR_MASK             ((uint32_t)0xFFFFFFF8)
#define CG_PRCK_MASK                ((uint32_t)0xFFFFF8FF)
#if defined(__TMPM370_CG_H)
#define CG_WUODR_MASK               ((uint32_t)0x000F3FF6)
#elif defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || defined(__TMPM374_CG_H)
#define CG_WUODR_MASK               ((uint32_t)0x0007FFF6)
#endif

#define CG_STBY_MODE_MASK           ((uint32_t)0xFFFFFFF8)
#if defined(__TMPM370_CG_H)
#define CG_NMIFLG_MASK              ((uint32_t)0xFFFFFFFE)
#endif
#define CG_RESET_FLAG_MASK          ((uint32_t)0xFFFFFFC0)

#define CG_FPSEL_MASK               ((uint32_t)0xFFFFEFFF)

#if defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || defined(__TMPM374_CG_H)
#define WARM_UP_SEL_OSC1            ((uint32_t)0x00080000)
#define WARM_UP_SEL_OSC2            ((uint32_t)0x00000000)
#endif

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

static CG_PhiT0Src numPhiT0Src_table[CG_PHIT0_SRC_MAX] = {
    CG_PHIT0_SRC_FGEAR,
    CG_PHIT0_SRC_FC,
};

static CG_STBYMode numToSTBYMode_table[CG_STBY_MODE_MAX] = {
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_STOP,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_IDLE,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_UNKNOWN,
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

    regval &= CG_FC_GEAR_MASK;
    regval |= gear;
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
    syscr &= (~CG_FC_GEAR_MASK);

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
  * @brief  Set fperiph for PhiT0
  * @param  PhiT0Src: Set PhiT0 Source
  *   This parameter can be one of the following values:
  *   CG_PHIT0_SRC_FGEAR, CG_PHIT0_SRC_FC
  * @retval None
  */
void CG_SetPhiT0Src(CG_PhiT0Src PhiT0Src)
{
    uint32_t regval = 0U;
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_CG_PHIT0_SRC(PhiT0Src));

    regval = TSB_CG->SYSCR;
    regval &= CG_FPSEL_MASK;
    tmp = (uint32_t) PhiT0Src;
    regval |= (tmp << 12U);

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
    regval &= (~CG_FPSEL_MASK);
    regval = (regval >> 12U);
    source = numPhiT0Src_table[regval];

    return source;
}

/**
  * @brief  Set dividing level between clock PhiT0 and fc.
  * @param  DividePhiT0FromFc: Dividing level between PhiT0 and fc.
  *   This parameter can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4, CG_DIVIDE_8,
  *   CG_DIVIDE_16, CG_DIVIDE_32, CG_DIVIDE_64, CG_DIVIDE_128,
  *   CG_DIVIDE_256 or CG_DIVIDE_512
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

        fprclk = (uint32_t) DividePhiT0FromFc;
        regval &= CG_PRCK_MASK;
        fprclk <<= 8U;
        regval |= fprclk;
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
                    regval &= CG_PRCK_MASK;
                    fprclk <<= 8U;
                    regval |= fprclk;
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
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4, CG_DIVIDE_8,
  *   CG_DIVIDE_16, CG_DIVIDE_32, CG_DIVIDE_64, CG_DIVIDE_128,
  *   CG_DIVIDE_256, CG_DIVIDE_512 or CG_DIVIDE_UNKNOWN
  */
CG_DivideLevel CG_GetPhiT0Level(void)
{
    uint32_t fprclk = 0U;
    CG_DivideLevel fgear = CG_DIVIDE_UNKNOWN;
    CG_DivideLevel phiT0Level = CG_DIVIDE_UNKNOWN;
    CG_PhiT0Src PhiT0_src = CG_PHIT0_SRC_FGEAR;

    fprclk = TSB_CG->SYSCR & (~CG_PRCK_MASK);
    fprclk = (uint32_t) (fprclk >> 8U);
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
  * @brief  Set the warm up time 
  * @param  Source: Select source of warm-up counter
  *   This parameter can be one of the following values:
  *   CG_WARM_UP_SRC_OSC1, CG_WARM_UP_SRC_OSC2(For M372/M373/M374)
  * @param  Time: Set count time for warm-up timer
  * @retval None
  */
void CG_SetWarmUpTime(CG_WarmUpSrc Source, uint16_t Time)
{
    uint32_t tmp = 0U;
    uint32_t regval = TSB_CG->OSCCR;

    /* Check the parameters */
    assert_param(IS_CG_WARM_UP_SRC(Source));
    assert_param(IS_CG_WARM_UP_TIME_X1(Time));

    regval &= CG_WUODR_MASK;
    tmp = Time;
    tmp = tmp << 20U;
    regval |= tmp;

#if defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || defined(__TMPM374_CG_H)
    if (Source == CG_WARM_UP_SRC_OSC1) {
        regval |= WARM_UP_SEL_OSC1;
    } else {
        regval |= WARM_UP_SEL_OSC2;
    }
#endif                          /* defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || */
                                /* defined(__TMPM374_CG_H) */

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
  *   DONE or BUSY
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
  * @brief  Enable or disable high-speed oscillator (fosc)
  * @param  Source: Select clock source for fosc
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 : External
  *   CG_FOSC_OSC2 : Internal (For M372/M373/M374)
  * @param  NewState: oscillator is enabled or disabled
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval Success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CG_SetFosc(CG_FoscSrc Source, FunctionalState NewState)
{

#if defined(__TMPM370_CG_H)

    Result retval = ERROR;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_CG_FOSC_SRC(Source));

    if (Source == CG_FOSC_OSC1) {
        if (NewState == ENABLE) {
            /* Enable high-speed oscillation */
            TSB_CG_OSCCR_XEN1 = 1U;
            retval = SUCCESS;
        } else {
            /* Disable high-speed oscillation */
            TSB_CG_OSCCR_XEN1 = 0U;
            retval = SUCCESS;
        }
    } else {
        retval = ERROR;
    }

    return retval;

#endif                          /*defined(__TMPM370_CG_H) */

#if defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || \
    defined(__TMPM374_CG_H)

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
                    /* fosc1 is in  use, so it can't be disabled */
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

#endif                          /* defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || */
                                /* defined(__TMPM374_CG_H) */
}

#if defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || \
    defined(__TMPM374_CG_H)
/**
  * @brief  Set the source of high-speed oscillator (fosc)
  * @param  Source: Select clock source for fosc
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 : External
  *   CG_FOSC_OSC2 : Internal (For M372/M373/M374)
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
  *   CG_FOSC_OSC1 : External
  *   CG_FOSC_OSC2 : Internal (For M372/M373/M374)
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
  *   CG_INT_SRC_3(For M372), CG_INT_SRC_4(For M372/M373),
  *   CG_INT_SRC_5(For M372/M373/M374), CG_INT_SRC_6(For M372/M373/M374),
  *   CG_INT_SRC_7(For M372/M373/M374), CG_INT_SRC_8(For M372),
  *   CG_INT_SRC_C(For M372/M373/M374), CG_INT_SRC_D(For M372/M373/M374),
  *   CG_INT_SRC_E(For M372/M373/M374), CG_INT_SRC_F(For M372/M373/M374).
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

#if defined(__TMPM372_CG_H)
    regval[0].byte4 = TSB_CG->IMCGA;
#endif
    regval[1].byte4 = TSB_CG->IMCGB;
#if defined(__TMPM372_CG_H)
    regval[2].byte4 = TSB_CG->IMCGC;
#endif
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
#endif                          /* defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || */
                                /* defined(__TMPM374_CG_H) */

/**
  * @brief  Get the state of high-speed oscillator (fosc)
  * @param  Source: Select fosc source
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 : External
  *   CG_FOSC_OSC2 : Internal (For M372/M373/M374)
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

#if defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || \
    defined(__TMPM374_CG_H)

    } else {
        if (TSB_CG_OSCCR_XEN2 == 1U) {
            state = ENABLE;
        } else {
            /* Do nothing */
        }
#endif                          /* defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || */
                                /* defined(__TMPM374_CG_H) */

    }

    return state;
}

/**
  * @brief  Set to the specified low-power mode
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

    regval &= CG_STBY_MODE_MASK;
    regval |= (uint32_t) Mode;

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
    uint8_t regval = (uint8_t) (TSB_CG->STBYCR & (~CG_STBY_MODE_MASK));

    stby_mode = numToSTBYMode_table[regval];

    return stby_mode;
}

/**
  * @brief  Set pin status in stop mode
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
  * @brief  Get pin status in stop mode
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

#if defined(__TMPM370_CG_H)
    if (CG_GetFoscState(CG_FOSC_OSC1) == ENABLE) {
        fosc_on = ENABLE;
    } else {
        /* Do nothing */
    }
#endif

#if defined(__TMPM372_CG_H) || defined(__TMPM373_CG_H) || defined(__TMPM374_CG_H)
    if ((CG_GetFoscState(CG_FOSC_OSC1) == ENABLE) || (CG_GetFoscState(CG_FOSC_OSC2) == ENABLE)) {
        fosc_on = ENABLE;
    } else {
        /* Do nothing */
    }
#endif

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
  *   CG_INT_SRC_0(For M370 only), CG_INT_SRC_1(For M370 only), 
  *   CG_INT_SRC_2(For M370 only), CG_INT_SRC_3(For M370 M372), 
  *   CG_INT_SRC_4(For M370/M372/M373), CG_INT_SRC_5, CG_INT_SRC_6, 
  *   CG_INT_SRC_7, CG_INT_SRC_8(For M370/M372), CG_INT_SRC_9(For M370 only), 
  *   CG_INT_SRC_A(For M370 only), CG_INT_SRC_B(For M370 only), 
  *   CG_INT_SRC_C, CG_INT_SRC_D, CG_INT_SRC_E, CG_INT_SRC_F.
  * @param  ActiveState: Select the active state for release trigger
  *   The  parameter can be one of the following values:
  *   CG_INT_ACTIVE_STATE_L, CG_INT_ACTIVE_STATE_H, CG_INT_ACTIVE_STATE_FALLING,
  *   CG_INT_ACTIVE_STATE_RISING or CG_INT_ACTIVE_STATE_BOTH_EDGES
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

#if defined(__TMPM370_CG_H) || defined(__TMPM372_CG_H)
    case 0U:                   /* IMCGA */
        regval[0].byte4 = TSB_CG->IMCGA;
        regval[0].byte[j] &= 0x8eU;
        regval[0].byte[j] |= ActiveState;
        TSB_CG->IMCGA = regval[0].byte4;
        regval[0].byte[j] |= NewState;
        TSB_CG->IMCGA = regval[0].byte4;
        break;
#endif

    case 1U:                   /* IMCGB */
        regval[1].byte4 = TSB_CG->IMCGB;
        regval[1].byte[j] &= 0x8eU;
        regval[1].byte[j] |= ActiveState;
        TSB_CG->IMCGB = regval[1].byte4;
        regval[1].byte[j] |= NewState;
        TSB_CG->IMCGB = regval[1].byte4;
        break;

#if defined(__TMPM370_CG_H) || defined(__TMPM372_CG_H)
    case 2U:                   /* IMCGC */
        regval[2].byte4 = TSB_CG->IMCGC;
        regval[2].byte[j] &= 0x8eU;
        regval[2].byte[j] |= ActiveState;
        TSB_CG->IMCGC = regval[2].byte4;
        regval[2].byte[j] |= NewState;
        TSB_CG->IMCGC = regval[2].byte4;
        break;
#endif

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
  * @brief  Gets the active state of INT source standby clear request
  * @param  INTSource: Select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_0(For M370 only), CG_INT_SRC_1(For M370 only), 
  *   CG_INT_SRC_2(For M370 only), CG_INT_SRC_3(For M370 M372), 
  *   CG_INT_SRC_4(For M370/M372/M373), CG_INT_SRC_5, CG_INT_SRC_6, 
  *   CG_INT_SRC_7, CG_INT_SRC_8(For M370/M372), CG_INT_SRC_9(For M370 only), 
  *   CG_INT_SRC_A(For M370 only), CG_INT_SRC_B(For M370 only), 
  *   CG_INT_SRC_C, CG_INT_SRC_D, CG_INT_SRC_E, CG_INT_SRC_F.
  * @retval Active state of the input INT
  *   The value returned can be one of the following values:
  *   CG_INT_ACTIVE_STATE_FALLING, CG_INT_ACTIVE_STATE_RISING,
  *   CG_INT_ACTIVE_STATE_BOTH_EDGES or CG_INT_ACTIVE_STATE_INVALID
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

#if defined(__TMPM370_CG_H) || defined(__TMPM372_CG_H)
    regval[0].byte4 = TSB_CG->IMCGA;
#endif
    regval[1].byte4 = TSB_CG->IMCGB;
#if defined(__TMPM370_CG_H) || defined(__TMPM372_CG_H)
    regval[2].byte4 = TSB_CG->IMCGC;
#endif
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
  *   CG_INT_SRC_0(For M370 only), CG_INT_SRC_1(For M370 only), 
  *   CG_INT_SRC_2(For M370 only), CG_INT_SRC_3(For M370 M372), 
  *   CG_INT_SRC_4(For M370/M372/M373), CG_INT_SRC_5, CG_INT_SRC_6, 
  *   CG_INT_SRC_7, CG_INT_SRC_8(For M370/M372), CG_INT_SRC_9(For M370 only), 
  *   CG_INT_SRC_A(For M370 only), CG_INT_SRC_B(For M370 only), 
  *   CG_INT_SRC_C, CG_INT_SRC_D, CG_INT_SRC_E, CG_INT_SRC_F.
  * @retval None
  */
void CG_ClearINTReq(CG_INTSrc INTSource)
{
    uint32_t regval = INTSource;

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    TSB_CG->ICRCG = regval;
}

#if defined(__TMPM370_CG_H)
/**
  * @brief  Get the NMI flag that shows who triggered NMI.
  * @param  None
  * @retval NMI flag
  */
CG_NMIFactor CG_GetNMIFlag(void)
{
    CG_NMIFactor cg_nmi_factor = { 0U };

    cg_nmi_factor.All = TSB_CG->NMIFLG & (~CG_NMIFLG_MASK);

    return cg_nmi_factor;
}
#endif                          /*defined(__TMPM370_CG_H) */

/**
  * @brief  Get the type of reset reason and clear the reset flag.
  * @param  None
  * @retval Reset flag
  */
CG_ResetFlag CG_GetResetFlag(void)
{
    CG_ResetFlag reset_flag = { 0U };

    reset_flag.All = TSB_CG->RSTFLG & (~CG_RESET_FLAG_MASK);
    TSB_CG->RSTFLG = 0U;

    return reset_flag;
}

/** @} */
/* End of group CG_Exported_Functions */

/** @} */
/* End of group CG */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM370_CG_H) || defined(__TMPM372_CG_H) || */
                                /* defined(__TMPM373_CG_H) || defined(__TMPM374_CG_H) */
