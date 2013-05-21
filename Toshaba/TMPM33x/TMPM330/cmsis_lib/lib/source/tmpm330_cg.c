/**
 *******************************************************************************
 * @file    tmpm330_cg.c
 * @brief   This file provides API functions for CG driver 
 * @version V2.1.0
 * @date    2010/07/05
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm330_cg.h"

#if defined(__TMPM330_CG_H) || defined(__TMPM332_CG_H) || defined(__TMPM333_CG_H)
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
#define CG_FPSEL_MASK               ((uint32_t)0xFFFFEFFF)
#define CG_PRCLK_MASK               ((uint32_t)0xFFFFF8FF)
#define CG_SCOUT_MASK               ((uint32_t)0xFFFCFFFF)
#define CG_WUP_TIME_MASK            ((uint32_t)0xFFFFFF8F)
#define CG_WUP_COUNTER_MASK         ((uint32_t)0xFFFFFFF7)

#define CG_STBY_MODE_MASK           ((uint32_t)0xFFFFFFF8)

#define CG_NMI_FACTOR_PIN_WDT_MASK  ((uint32_t)0xFFFFFFFC)
#define CG_RESET_FLAG_MASK          ((uint32_t)0xFFFFFFE8)

#define FC_GEAR_1_1                 ((uint8_t)0x00)
#define FC_GEAR_1_2                 ((uint8_t)0x04)
#define FC_GEAR_1_4                 ((uint8_t)0x05)
#define FC_GEAR_1_8                 ((uint8_t)0x06)

#define FPERIPH_FGEAR               ((uint8_t)0x00)
#define FPERIPH_FC                  ((uint8_t)0x10)

#define PRCCLK_1_1                  ((uint8_t)0x00)

#define SCOUT_SRC_FS                ((uint32_t)0x00000000)
#define SCOUT_SRC_HALF_FSYS         ((uint32_t)0x00010000)
#define SCOUT_SRC_FSYS              ((uint32_t)0x00020000)
#define SCOUT_SRC_PHIT0             ((uint32_t)0x00030000)

#define WARM_UP_SEL_X1              ((uint8_t)0x00)
#define WARM_UP_SEL_XT1             ((uint8_t)0x08)
#define WARM_UP_TIME_NONE           ((uint8_t)0x00)
#define WARM_UP_TIME_X1_EXP10       ((uint8_t)0x01)
#define WARM_UP_TIME_XT1_EXP6       ((uint8_t)0x01)
#define WARM_UP_TIME_XT1_EXP15      ((uint8_t)0x04)

#define LOW_POWER_MODE_STOP         ((uint32_t)0x01)
#define LOW_POWER_MODE_SLEEP        ((uint32_t)0x02)
#define LOW_POWER_MODE_IDLE         ((uint32_t)0x03)

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
  * @brief  set dividing level between clock fgear and fc.
  * @param  DivideFgearFromFc: dividing level between fgear and fc.
  *   This parameter can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4, CG_DIVIDE_8.
  * @retval None
  */
void CG_SetFgearLevel(CG_DivideLevel DivideFgearFromFc)
{
    uint8_t gear = FC_GEAR_1_1;
    uint32_t regval = TSB_CG->SYSCR;

    /* Check the parameters */
    assert_param(IS_CG_GEAR_DIVIDE_LEVEL(DivideFgearFromFc));

    /* set the value of fgear */
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
    default:
        /*Do nothing */
        break;
    }
    regval &= CG_FC_GEAR_MASK;
    regval |= gear;
    TSB_CG->SYSCR = regval;
}

/**
  * @brief  get dividing level between clock fgear and fc.
  * @param  none
  * @retval  the dividing level between clock fgear and fc
  *   The value returned can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4 CG_DIVIDE_8 or CG_DIVIDE_UNKNOWN.
  */
CG_DivideLevel CG_GetFgearLevel(void)
{
    CG_DivideLevel DivideFgearFromFc = CG_DIVIDE_UNKNOWN;
    uint32_t syscr = TSB_CG->SYSCR;
    uint32_t tmp = ~CG_FC_GEAR_MASK;
    uint8_t gear = (uint8_t) (syscr & tmp);

    switch (gear) {
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
    default:
        /*Do nothing */
        break;
    }
    return DivideFgearFromFc;
}
/**
  * @brief  set dividing level between clock PhiT0 and fc.
  * @param  DividePhiT0FromFc: dividing level between PhiT0 and fc.
  *   This parameter can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4, CG_DIVIDE_8, CG_DIVIDE_16, CG_DIVIDE_32, 
  *   CG_DIVIDE_64, CG_DIVIDE_128 or CG_DIVIDE_256.
  * @retval result:success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetPhiT0Level(CG_DivideLevel DividePhiT0FromFc)
{
    uint32_t fperiph = FPERIPH_FC;
    uint32_t fprclk = PRCCLK_1_1;
    CG_DivideLevel fgear;
    uint32_t tmp = 0U;
    Result retval = SUCCESS;
    uint32_t regval = TSB_CG->SYSCR;

    /* Check the parameters */
    assert_param(IS_CG_T0_DIVIDE_LEVEL(DividePhiT0FromFc));

    /* set the value of fgear */
    switch (DividePhiT0FromFc) {
    case CG_DIVIDE_1:
    case CG_DIVIDE_2:
    case CG_DIVIDE_4:
    case CG_DIVIDE_8:
    case CG_DIVIDE_16:
    case CG_DIVIDE_32:
        fprclk = (uint32_t) DividePhiT0FromFc;
        tmp = fperiph | fprclk;
        tmp <<= 8U;
        regval &= CG_FPSEL_MASK & CG_PRCLK_MASK;
        regval |= tmp;
        TSB_CG->SYSCR = regval;
        break;
    case CG_DIVIDE_64:
    case CG_DIVIDE_128:
    case CG_DIVIDE_256:
        fgear = CG_GetFgearLevel();
        if (fgear != CG_DIVIDE_UNKNOWN) {
            fprclk = (uint32_t) DividePhiT0FromFc - (uint32_t) fgear;
            if (fprclk <= CG_DIVIDE_32) {
                fperiph = FPERIPH_FGEAR;
                tmp = fperiph | fprclk;
                tmp <<= 8U;
                regval &= CG_FPSEL_MASK & CG_PRCLK_MASK;
                regval |= tmp;
                TSB_CG->SYSCR = regval;
            } else {
                retval = ERROR;
            }
        } else {
            retval = ERROR;
        }
        break;
    default:
        retval = ERROR;
        break;
    }
    return retval;
}

/**
  * @brief  get dividing level between clock phiT0 and fc.
  * @param  none
  * @retval  the divide level between clock phiT0 and fc
  *   The value returned can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4, CG_DIVIDE_8, CG_DIVIDE_16, CG_DIVIDE_32, 
  *   CG_DIVIDE_64, CG_DIVIDE_128 or CG_DIVIDE_256 or CG_DIVIDE_UNKNOWN.
  */
CG_DivideLevel CG_GetPhiT0Level(void)
{
    uint32_t tmp = 0U;
    uint32_t fprclk = 0U;
    CG_DivideLevel fgear;
    CG_DivideLevel phiT0Level = CG_DIVIDE_UNKNOWN;

    tmp = TSB_CG->SYSCR & (~CG_PRCLK_MASK);
    fprclk = (uint8_t) (tmp >> 8U);

    if (fprclk <= CG_DIVIDE_32) {
        if (TSB_CG_SYSCR_FPSEL == 1U) { /*FPERIPH_FC */
            phiT0Level = numToDivideLevel_table[fprclk];
        } else {
            fgear = CG_GetFgearLevel();
            if (fgear != CG_DIVIDE_UNKNOWN) {
                tmp = fprclk + fgear;
                if (tmp < CG_DIVIDE_UNKNOWN) {
                    phiT0Level = numToDivideLevel_table[tmp];
                } else {
                    /*Do nothing */
                }
            } else {
                /*Do nothing */
            }
        }
    }
    return phiT0Level;
}

/**
  * @brief  sets the source of SCOUT output
  * @param Source: select source of SCOUT
  *   This parameter can be one of the following values:
  *   CG_SCOUT_SRC_FS,CG_SCOUT_SRC_HALF_FSYS, CG_SCOUT_SRC_FSYS or CG_SCOUT_SRC_PHIT0.
  * @retval None
  */
void CG_SetSCOUTSrc(CG_SCOUTSrc Source)
{
    /*get the original SCOUT SRC value */
    uint32_t tmp = 0U;
    uint32_t regval = TSB_CG->SYSCR;

    /* Check the parameters */
    assert_param(IS_CG_SCOUT_SRC(Source));

    switch (Source) {
    case CG_SCOUT_SRC_FS:
        tmp = SCOUT_SRC_FS;
        break;
    case CG_SCOUT_SRC_HALF_FSYS:
        tmp = SCOUT_SRC_HALF_FSYS;
        break;
    case CG_SCOUT_SRC_FSYS:
        tmp = SCOUT_SRC_FSYS;
        break;
    case CG_SCOUT_SRC_PHIT0:
        tmp = SCOUT_SRC_PHIT0;
        break;
    default:
        /*Do nothing */
        break;
    }
    regval &= CG_SCOUT_MASK;
    regval |= tmp;
    TSB_CG->SYSCR = regval;
}

/**
  * @brief  get the source of SCOUT output..
  * @param None
  * @retval source of SCOUT output
  *   The value returned can be one of the following values:
  *   CG_SCOUT_SRC_FS, CG_SCOUT_SRC_FSYS, CG_SCOUT_SRC_PHIT0 or SCOUT_SRC_HALF_FSYS.
  */
CG_SCOUTSrc CG_GetSCOUTSrc(void)
{
    uint32_t tmp;
    CG_SCOUTSrc source = CG_SCOUT_SRC_FS;

    tmp = TSB_CG->SYSCR & (~CG_SCOUT_MASK);
    switch (tmp) {
    case SCOUT_SRC_FS:
        source = CG_SCOUT_SRC_FS;
        break;
    case SCOUT_SRC_HALF_FSYS:
        source = CG_SCOUT_SRC_HALF_FSYS;
        break;
    case SCOUT_SRC_FSYS:
        source = CG_SCOUT_SRC_FSYS;
        break;
    case SCOUT_SRC_PHIT0:
        source = CG_SCOUT_SRC_PHIT0;
        break;
    default:
        /*Do nothing */
        break;
    }
    return source;
}


/**
  * @brief  set the warm up time 
  * @param Source: select source of warm-up counter
  *   This parameter can be one of the following values:
  *   CG_WARM_UP_SRC_X1 or CG_WARM_UP_SRC_XT1.
  * @Time: select count time of warm-up timer
  *   This parameter can be one of the following values:
  *   CG_WARM_UP_TIME_NONE,CG_WARM_UP_TIME_EXP_6, CG_WARM_UP_TIME_EXP_7, 
  *   CG_WARM_UP_TIME_EXP_8,CG_WARM_UP_TIME_EXP_10,CG_WARM_UP_TIME_EXP_11, 
  *   CG_WARM_UP_TIME_EXP_12,CG_WARM_UP_TIME_EXP_13, CG_WARM_UP_TIME_EXP_14,
  *   CG_WARM_UP_TIME_EXP_15, CG_WARM_UP_TIME_EXP_16, CG_WARM_UP_TIME_EXP_17
  *   or CG_WARM_UP_TIME_EXP_18.
  * @retval success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetWarmUpTime(CG_WarmUpSrc Source, CG_WarmUpTime Time)
{
    Result retval = SUCCESS;
    uint8_t warmup_counter = WARM_UP_SEL_X1;
    uint8_t regValForTime = WARM_UP_TIME_NONE;
    uint32_t tmp = 0U;
    uint32_t regval = TSB_CG->OSCCR;

    /* Check the parameters */
    assert_param(IS_CG_WARM_UP_SRC(Source));
    assert_param(IS_CG_WARM_UP_TIME(Time));

    if (Source == CG_WARM_UP_SRC_X1) {
        switch (Time) {
        case CG_WARM_UP_TIME_NONE:
            regValForTime = WARM_UP_TIME_NONE;
            break;
        case CG_WARM_UP_TIME_EXP_10:
        case CG_WARM_UP_TIME_EXP_11:
        case CG_WARM_UP_TIME_EXP_12:
        case CG_WARM_UP_TIME_EXP_13:
        case CG_WARM_UP_TIME_EXP_14:
        case CG_WARM_UP_TIME_EXP_15:
        case CG_WARM_UP_TIME_EXP_16:
            /*calculate the register value */
            regValForTime = Time - CG_WARM_UP_TIME_EXP_10 + WARM_UP_TIME_X1_EXP10;
            break;
        default:
            retval = ERROR;
            break;
        }
    } else {
        warmup_counter = WARM_UP_SEL_XT1;
        switch (Time) {
        case CG_WARM_UP_TIME_NONE:
            regValForTime = WARM_UP_TIME_NONE;
            break;
        case CG_WARM_UP_TIME_EXP_6:
        case CG_WARM_UP_TIME_EXP_7:
        case CG_WARM_UP_TIME_EXP_8:
            /*calculate the register value */
            regValForTime = Time - CG_WARM_UP_TIME_EXP_6 + WARM_UP_TIME_XT1_EXP6;
            break;
        case CG_WARM_UP_TIME_EXP_15:
        case CG_WARM_UP_TIME_EXP_16:
        case CG_WARM_UP_TIME_EXP_17:
        case CG_WARM_UP_TIME_EXP_18:
            /*calculate the register value */
            regValForTime = Time - CG_WARM_UP_TIME_EXP_15 + WARM_UP_TIME_XT1_EXP15;
            break;
        default:
            retval = ERROR;
            break;
        }
    }

    if (retval != ERROR) {
        /* set register */
        tmp = ((uint32_t) regValForTime) << 4U;
        tmp |= warmup_counter;
        regval &= CG_WUP_TIME_MASK & CG_WUP_COUNTER_MASK;
        regval |= tmp;
        TSB_CG->OSCCR = regval;
    } else {
        /*Do nothing */
    }

    return retval;
}

/**
  * @brief  start operation of warm up timer for oscillator .
  * @param None
  * @retval None
  */
void CG_StartWarmUp(void)
{
    TSB_CG_OSCCR_WUEON = 1U;
}

/**
  * @brief  check whether warm up is completed or not.
  * @param None
  * @retval warm up state: completed or not
  *   The value returned can be one of the following values:
  *   DONE or BUSY.
  */
WorkState CG_GetWarmUpState(void)
{
    WorkState state = BUSY;

    if (TSB_CG_OSCCR_WUEF == 0U) {
        state = DONE;
    } else {
        /*Do nothing */
    }
    return state;
}

/**
  * @brief  enable PLL or disable it.
  * @param NewState:enable or disable
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval result:success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetPLL(FunctionalState NewState)
{
    Result retval = SUCCESS;
    CG_FcSrc fcsrc;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG_OSCCR_PLLON = 1U;
    } else {
        fcsrc = CG_GetFcSrc();
        if (fcsrc == CG_FC_SRC_FOSC) {  /* PLL is not used.So it can be shut off */
            /* set register to disable PLL */
            TSB_CG_OSCCR_PLLON = 0U;
        } else {                /*fcsrc == CG_FC_SRC_FPLL. PLL is in use, so disabling it should be invalid */
            retval = ERROR;
        }
    }
    return retval;
}

/**
  * @brief  get the status of PLL operation
  * @param None
  * @retval pll state: run or stop
  *   The value returned can be one of the following values:
  *   ENABLE or DISABLE.
  */
FunctionalState CG_GetPLLState(void)
{
    FunctionalState pllstate = DISABLE;

    if (TSB_CG_OSCCR_PLLON == 1U) {
        pllstate = ENABLE;
    } else {
        /*Do nothing */
    }
    return pllstate;
}

/**
  * @brief  enable or disable high-speed oscillation (fosc)
  * @param NewState: oscillation is enabled or disabled
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFosc(FunctionalState NewState)
{
    CG_FsysSrc fsys_src;
    Result retval = SUCCESS;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* enable high-speed oscillation */
        TSB_CG_OSCCR_XEN = 1U;
    } else {
        fsys_src = CG_GetFsysSrc();
        if (fsys_src == CG_FSYS_SRC_FGEAR) {    /* fosc is in  use. so it can't be disabled */
            retval = ERROR;
        } else {
            /* disable high-speed oscillation */
            TSB_CG_OSCCR_XEN = 0U;
        }
    }
    return retval;
}


/**
  * @brief  get the state of high-speed oscillation (fosc)
  * @param None
  * @retval state of fosc
  *   The value returned can be one of the following values:
  *   DISABLE or ENABLE.
  */
FunctionalState CG_GetFoscState(void)
{
    FunctionalState state = DISABLE;

    if (TSB_CG_OSCCR_XEN == 1U) {
        state = ENABLE;
    } else {
        /*Do nothing */
    }
    return state;
}

/**
  * @brief  enable or disable low-speed oscillation (fs)
  * @param NewState: oscillation is enabled or disabled
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFs(FunctionalState NewState)
{
    CG_FsysSrc fsys_src;
    Result retval = SUCCESS;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* enable low-speed oscillation */
        TSB_CG_OSCCR_XTEN = 1U;
    } else {
        fsys_src = CG_GetFsysSrc();
        if (fsys_src == CG_FSYS_SRC_FS) {
            /* fs is in  use. so it can't be disabled */
            retval = ERROR;
        } else {
            /* disable low-speed oscillation */
            TSB_CG_OSCCR_XTEN = 0U;
        }
    }
    return retval;
}

/**
  * @brief  get the state of low-speed oscillation (fs)
  * @param None
  * @retval state of fs
  *   The value returned can be one of the following values:
  *   DISABLE or ENABLE.
  */
FunctionalState CG_GetFsState(void)
{
    FunctionalState state = DISABLE;

    if (TSB_CG_OSCCR_XTEN == 1U) {
        state = ENABLE;
    } else {
        /*Do nothing */
    }
    return state;
}

/**
  * @brief  set to the specified low-power mode
  * @param low power mode
  *   The value returned can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_SLEEP or CG_STBY_MODE_IDLE.
  * @retval none
  */
void CG_SetSTBYMode(CG_STBYMode Mode)
{
    uint32_t regval = TSB_CG->STBYCR;

    /*check the parameter */
    assert_param(IS_CG_STBY_MODE(Mode));

    regval &= CG_STBY_MODE_MASK;
    switch (Mode) {
    case CG_STBY_MODE_STOP:
        regval |= LOW_POWER_MODE_STOP;
        break;
    case CG_STBY_MODE_SLEEP:
        regval |= LOW_POWER_MODE_SLEEP;
        break;
    case CG_STBY_MODE_IDLE:
        regval |= LOW_POWER_MODE_IDLE;
        break;
    default:
        break;
    }
    TSB_CG->STBYCR = regval;
}

/**
  * @brief  get the low-power consumption mode
  * @param none
  * @retval low power mode
  *   The value returned can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_SLEEP,CG_STBY_MODE_IDLE or CG_STBY_MODE_UNKNOWN.
  */
CG_STBYMode CG_GetSTBYMode(void)
{
    CG_STBYMode stby_mode = CG_STBY_MODE_STOP;
    uint32_t tmp = TSB_CG->STBYCR & (~CG_STBY_MODE_MASK);

    switch (tmp) {
    case LOW_POWER_MODE_STOP:
        stby_mode = CG_STBY_MODE_STOP;
        break;
    case LOW_POWER_MODE_SLEEP:
        stby_mode = CG_STBY_MODE_SLEEP;
        break;
    case LOW_POWER_MODE_IDLE:
        stby_mode = CG_STBY_MODE_IDLE;
        break;
    default:
        stby_mode = CG_STBY_MODE_UNKNOWN;
        break;
    }
    return stby_mode;
}

/**
  * @brief  enables or disables fosc after releasing stop mode
  * @param  NewState: enable or disable
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval none.
  */
void CG_SetExitStopModeFosc(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG_STBYCR_RXEN = 1U;
    } else {
        TSB_CG_STBYCR_RXEN = 0U;
    }
}

/**
  * @brief  get the state of fosc after releasing stop mode.
  * @param  none
  * @retval state of fosc after releasing stop mode
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  */
FunctionalState CG_GetExitStopModeFoscState(void)
{
    FunctionalState state = DISABLE;

    if (TSB_CG_STBYCR_RXEN == 1U) {
        state = ENABLE;
    } else {
        /*Do nothing */
    }
    return state;
}

/**
  * @brief  enables or disables fs after releasing stop mode
  * @param  NewState: enable or disable
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval none.
  */
void CG_SetExitStopModeFs(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG_STBYCR_RXTEN = 1U;
    } else {
        TSB_CG_STBYCR_RXTEN = 0U;
    }
}

/**
  * @brief  get the state of fs after releasing stop mode.
  * @param  none
  * @retval state of fs after releasing stop mode
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  */
FunctionalState CG_GetExitStopModeFsState(void)
{
    FunctionalState state = DISABLE;

    if (TSB_CG_STBYCR_RXTEN == 1U) {
        state = ENABLE;
    } else {
        /*Do nothing */
    }
    return state;
}

/**
  * @brief  set pin status in stop mode
  * @param  NewState: enable or disable
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval none.
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
  * @brief  get pin status in stop mode
  * @param  None
  * @retval   state of pin in stop mode
  *   The value returned can be one of the following values:
  *   DISABLE or ENABLE.
  */
FunctionalState CG_GetPinStateInStopMode(void)
{
    FunctionalState state = ENABLE;

    if (TSB_CG_STBYCR_DRVE == 1U) {
        /* pin status in stop mode is inactive */
        state = ENABLE;
    } else {
        state = DISABLE;
    }
    return state;
}

/**
  * @brief  set the source of fc
  * @param Source:  the source of fc
  *   This parameter can be one of the following values:
  *   CG_FC_SRC_FOSC or CG_FC_SRC_FPLL.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFcSrc(CG_FcSrc Source)
{

    Result retval = SUCCESS;
    FunctionalState fosc_on;
    FunctionalState pllon;

    /* Check the parameters */
    assert_param(IS_CG_FC_SRC(Source));

    fosc_on = CG_GetFoscState();
    if (fosc_on == ENABLE) {
        if (Source == CG_FC_SRC_FOSC) {
            TSB_CG_PLLSEL_PLLSEL = 0U;
        } else {
            pllon = CG_GetPLLState();
            if (pllon == ENABLE) {
                TSB_CG_PLLSEL_PLLSEL = 1U;
            } else {
                retval = ERROR;
            }
        }
    } else {
        retval = ERROR;
    }
    return retval;
}

/**
  * @brief  get the source of fc
  * @param None
  * @retval the source of fc
  *   The value returned can be one of the following values:
  *   CG_FC_SRC_FOSC or CG_FC_SRC_FPLL.
  */
CG_FcSrc CG_GetFcSrc(void)
{
    CG_FcSrc fcsrc = CG_FC_SRC_FOSC;

    if (TSB_CG_PLLSEL_PLLSEL == 1U) {
        fcsrc = CG_FC_SRC_FPLL;
    } else {
        /*Do nothing */
    }
    return fcsrc;
}

/**
  * @brief  set the source of fsys
  * @param Source: Source: select the source of fsys
  *   This parameter can be one of the following values:
  *   CG_FSYS_SRC_FGEAR or CG_FSYS_SRC_FS.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFsysSrc(CG_FsysSrc Source)
{

    Result retval = SUCCESS;
    FunctionalState fosc_on, fs_on;
    CG_FsysSrc fsyssrc;

    /* Check the parameters */
    assert_param(IS_CG_FSYS_SRC(Source));

    if (Source == CG_FSYS_SRC_FGEAR) {
        fosc_on = CG_GetFoscState();
        if (fosc_on == ENABLE) {
            /* set sysckl to fgear */
            TSB_CG_CKSEL_SYSCK = 0U;
            do {
                fsyssrc = CG_GetFsysSrc();
            } while (fsyssrc != CG_FSYS_SRC_FGEAR);
        } else {
            retval = ERROR;
        }
    } else {
        fs_on = CG_GetFsState();
        if (fs_on == ENABLE) {
            /* set sysckl to fs */
            TSB_CG_CKSEL_SYSCK = 1U;
            do {
                fsyssrc = CG_GetFsysSrc();
            } while (fsyssrc != CG_FSYS_SRC_FS);
        } else {
            retval = ERROR;
        }
    }
    return retval;
}

/**
  * @brief  get the clock source of fsys
  * @param none
  * @retval source of fsys
  *   The value returned can be one of the following values:
  *   CG_FSYS_SRC_FGEAR or CG_FSYS_SRC_FS.
  */
CG_FsysSrc CG_GetFsysSrc(void)
{
    CG_FsysSrc fsyssrc = CG_FSYS_SRC_FGEAR;

    if (TSB_CG_CKSEL_SYSCKFLG == 1U) {
        fsyssrc = CG_FSYS_SRC_FS;
    } else {
        /*Do nothing */
    }
    return fsyssrc;
}

/**
  * @brief  setup the INT source for releasing low power mode.
  * @param INTSource: select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2,
  *   CG_INT_SRC_3, CG_INT_SRC_4, CG_INT_SRC_5(For M330/333),
  *   CG_INT_SRC_CEC_RX(For M330/332), CG_INT_SRC_RMC_RX_0(For M330/332),
  *   CG_INT_SRC_RTC, CG_INT_SRC_6(For M330/333), CG_INT_SRC_7(For M330/333),
  *   CG_INT_SRC_RMC_RX_1(For M330) or CG_INT_SRC_CEC_TX(For M330/332).
  * @paramActiveState: select the active state for release trigger
  *   For INTCECRX, INTRMCRX0 and INTRMCRX1, only "RISING" state will be set, no matter what the value of ActiveState is.
  *   For INTRTC and INTCECTX, only "FALLING" state will be set, no matter what the value of ActiveState is.
  *   This parameter can be one of the following values:
  *   CG_INT_ACTIVE_STATE_L, CG_INT_ACTIVE_STATE_H, CG_INT_ACTIVE_STATE_FALLING,
  *   CG_INT_ACTIVE_STATE_RISING or CG_INT_ACTIVE_STATE_BOTH_EDGES.
  * @NewState: enable or disable this release trigger
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval none
  */
void CG_SetSTBYReleaseINTSrc(CG_INTSrc INTSource,
                             CG_INTActiveState ActiveState, FunctionalState NewState)
{

    uint32_t active_setting = CG_INT_ACTIVE_STATE_L;
    uint32_t intxen = 0U;
    uint32_t regval;
    uint32_t mask = 0xffU;
    uint8_t leftshift_bits = 0U;

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));
    assert_param(IS_CG_INT_ACTIVE_STATE(ActiveState));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (INTSource) {
    case CG_INT_SRC_0:
    case CG_INT_SRC_1:
    case CG_INT_SRC_2:
    case CG_INT_SRC_3:
        if (ActiveState < CG_INT_ACTIVE_STATE_INVALID) {
            /* calculate the register offset */
            leftshift_bits = ((uint8_t) INTSource) << 3U;

            regval = TSB_CG->IMCGA;
            active_setting = ActiveState;
            if (NewState == ENABLE) {
                intxen = 1U;
            }
            active_setting <<= 4U;
            active_setting <<= leftshift_bits;
            mask <<= leftshift_bits;
            mask = ~mask;
            regval &= mask;
            regval |= active_setting;
            TSB_CG->IMCGA = regval;
            regval |= intxen << leftshift_bits;
            TSB_CG->IMCGA = regval;
        } else {
            /*Do nothing */
        }
        break;
    case CG_INT_SRC_4:
#if defined(__TMPM330_CG_H)
    case CG_INT_SRC_5:
    case CG_INT_SRC_CEC_RX:
    case CG_INT_SRC_RMC_RX_0:
#elif defined(__TMPM332_CG_H)
    case CG_INT_SRC_CEC_RX:
    case CG_INT_SRC_RMC_RX_0:
#elif defined(__TMPM333_CG_H)
    case CG_INT_SRC_5:
#endif                          /* End of defined(__TMPM330_CG_H) */
        if (ActiveState < CG_INT_ACTIVE_STATE_INVALID) {
            /* calculate the register offset */
            leftshift_bits = ((uint8_t) INTSource) - ((uint8_t) CG_INT_SRC_4);
            leftshift_bits <<= 3U;

            if ((INTSource == CG_INT_SRC_4)
#if defined(__TMPM330_CG_H)||defined(__TMPM333_CG_H)
                || (INTSource == CG_INT_SRC_5)
#endif                          /* End of defined(__TMPM330_CG_H)||defined(__TMPM333_CG_H) */
                ) {
                active_setting = ActiveState;
            } else {
                active_setting = CG_INT_ACTIVE_STATE_RISING;
            }

            regval = TSB_CG->IMCGB;
            if (NewState == ENABLE) {
                intxen = 1U;
            }
            active_setting <<= 4U;
            active_setting <<= leftshift_bits;
            mask <<= leftshift_bits;
            mask = ~mask;
            regval &= mask;
            regval |= active_setting;
            TSB_CG->IMCGB = regval;
            regval |= intxen << leftshift_bits;
            TSB_CG->IMCGB = regval;
        } else {
            /*Do nothing */
        }
        break;
    case CG_INT_SRC_RTC:
#if defined(__TMPM330_CG_H)
    case CG_INT_SRC_6:
    case CG_INT_SRC_7:
    case CG_INT_SRC_RMC_RX_1:
#elif defined(__TMPM333_CG_H)
    case CG_INT_SRC_6:
    case CG_INT_SRC_7:
#endif                          /* End of defined(__TMPM330_CG_H) */
        if (ActiveState < CG_INT_ACTIVE_STATE_INVALID) {
            /* calculate the register offset */
            leftshift_bits = ((uint8_t) INTSource) - ((uint8_t) CG_INT_SRC_RTC);
            leftshift_bits <<= 3U;

            if (INTSource == CG_INT_SRC_RTC) {
                active_setting = CG_INT_ACTIVE_STATE_FALLING;
            }
#if defined(__TMPM330_CG_H)
            else if (INTSource == CG_INT_SRC_RMC_RX_1) {
                active_setting = CG_INT_ACTIVE_STATE_RISING;
            }
#endif                          /* End of defined(__TMPM330_CG_H) */
            else {
                active_setting = ActiveState;
            }

            regval = TSB_CG->IMCGC;
            if (NewState == ENABLE) {
                intxen = 1U;
            } else {
                /*Do nothing */
            }
            active_setting <<= 4U;
            active_setting <<= leftshift_bits;
            mask <<= leftshift_bits;
            mask = ~mask;
            regval &= mask;
            regval |= active_setting;
            TSB_CG->IMCGC = regval;
            regval |= intxen << leftshift_bits;
            TSB_CG->IMCGC = regval;
        }
        break;
#if defined(__TMPM330_CG_H)||defined(__TMPM332_CG_H)
    case CG_INT_SRC_CEC_TX:
        active_setting = CG_INT_ACTIVE_STATE_FALLING;

        regval = TSB_CG->IMCGD;
        if (NewState == ENABLE) {
            intxen = 1U;
        } else {
            /*Do nothing */
        }
        active_setting <<= 4U;
        mask = ~mask;
        regval &= mask;
        regval |= active_setting;
        TSB_CG->IMCGD = regval;
        regval |= intxen;
        TSB_CG->IMCGD = regval;
        break;
#endif                          /* End of defined(__TMPM330_CG_H)||defined(__TMPM332_CG_H) */
    default:
        /*Do nothing */
        break;
    }

}

/**
  * @brief  gets the active state of INT source standby clear request
  * @param INTSource: select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2,
  *   CG_INT_SRC_3, CG_INT_SRC_4, CG_INT_SRC_5(For M330/333),
  *   CG_INT_SRC_CEC_RX(For M330/332), CG_INT_SRC_RMC_RX_0(For M330/332),
  *   CG_INT_SRC_RTC, CG_INT_SRC_6(For M330/333), CG_INT_SRC_7(For M330/333),
  *   CG_INT_SRC_RMC_RX_1(For M330) or CG_INT_SRC_CEC_TX(For M330/332).
  * @retval active state of the input INT
  *   The value returned can be one of the following values:
  *   CG_INT_ACTIVE_STATE_FALLING, CG_INT_ACTIVE_STATE_RISING,
  *   CG_INT_ACTIVE_STATE_BOTH_EDGES or CG_INT_ACTIVE_STATE_INVALID.
  */
CG_INTActiveState CG_GetSTBYReleaseINTState(CG_INTSrc INTSource)
{
    CG_INTActiveState int_active_state = CG_INT_ACTIVE_STATE_INVALID;
    uint32_t mask = (uint32_t) 0x0c;
    uint8_t rightshift_bits = 0U;
    uint32_t regval = 0U;

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    switch (INTSource) {
    case CG_INT_SRC_0:
    case CG_INT_SRC_1:
    case CG_INT_SRC_2:
    case CG_INT_SRC_3:
        /* calculate the register offset */
        rightshift_bits = ((uint8_t) INTSource) << 3U;

        regval = TSB_CG->IMCGA;
        regval >>= rightshift_bits;
        regval &= mask;
        break;
    case CG_INT_SRC_4:
#if defined(__TMPM330_CG_H)
    case CG_INT_SRC_5:
    case CG_INT_SRC_CEC_RX:
    case CG_INT_SRC_RMC_RX_0:
#elif defined(__TMPM332_CG_H)
    case CG_INT_SRC_CEC_RX:
    case CG_INT_SRC_RMC_RX_0:
#elif defined(__TMPM333_CG_H)
    case CG_INT_SRC_5:
#endif                          /* End of defined(__TMPM330_CG_H) */
        /* calculate the register offset */
        rightshift_bits = (uint8_t) INTSource - (uint8_t) CG_INT_SRC_4;
        rightshift_bits <<= 3U;

        regval = TSB_CG->IMCGB;
        regval >>= rightshift_bits;
        regval &= mask;
        break;
    case CG_INT_SRC_RTC:
#if defined(__TMPM330_CG_H)
    case CG_INT_SRC_6:
    case CG_INT_SRC_7:
    case CG_INT_SRC_RMC_RX_1:
#elif defined(__TMPM333_CG_H)
    case CG_INT_SRC_6:
    case CG_INT_SRC_7:
#endif                          /* End of defined(__TMPM330_CG_H) */
        /* calculate the register offset */
        rightshift_bits = (uint8_t) INTSource - (uint8_t) CG_INT_SRC_RTC;
        rightshift_bits <<= 3U;

        regval = TSB_CG->IMCGC;
        regval >>= rightshift_bits;
        regval &= mask;
        break;
#if defined(__TMPM330_CG_H)||defined(__TMPM332_CG_H)
    case CG_INT_SRC_CEC_TX:
        regval = TSB_CG->IMCGD & mask;
        break;
#endif
    default:
        /*Do nothing */
        break;
    }

    regval >>= 2U;
    switch (regval) {
    case 0U:
        break;
    case 1U:
        int_active_state = CG_INT_ACTIVE_STATE_RISING;
        break;
    case 2U:
        int_active_state = CG_INT_ACTIVE_STATE_FALLING;
        break;
    case 3U:
        int_active_state = CG_INT_ACTIVE_STATE_BOTH_EDGES;
        break;
    default:
        /*Do nothing */
        break;
    }
    return int_active_state;
}

/**
  * @brief  clears the input INT request.
  * @param INTSource: select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2,
  *   CG_INT_SRC_3, CG_INT_SRC_4, CG_INT_SRC_5(For M330/333),
  *   CG_INT_SRC_CEC_RX(For M330/332), CG_INT_SRC_RMC_RX_0(For M330/332),
  *   CG_INT_SRC_RTC, CG_INT_SRC_6(For M330/333), CG_INT_SRC_7(For M330/333),
  *   CG_INT_SRC_RMC_RX_1(For M330),CG_INT_SRC_CEC_TX(For M330/332).
  * @retval none
  */
void CG_ClearINTReq(CG_INTSrc INTSource)
{
    uint32_t regval = INTSource;

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    TSB_CG->ICRCG = regval;
}

/**
  * @brief  gets the NMI flag that shows who triggered NMI.
  * @param none
  * @retval NMI flag
  */
CG_NMIFactor CG_GetNMIFlag(void)
{
    CG_NMIFactor cg_nmi_factor;
    uint32_t regval = TSB_CG->NMIFLG;
    uint32_t tmp = 0U;

    tmp = regval & (~CG_NMI_FACTOR_PIN_WDT_MASK);
    cg_nmi_factor.All = tmp;
    return cg_nmi_factor;
}

/**
  * @brief  get the type of reset reason and clear the reset flag.
  * @param none
  * @retval reset flag
  */
CG_ResetFlag CG_GetResetFlag(void)
{
    CG_ResetFlag reset_flag ;
    reset_flag.All = TSB_CG->RSTFLG&(~CG_RESET_FLAG_MASK);
    TSB_CG->RSTFLG = 0U;
    return reset_flag;
}

/** @} */
/* End of group CG_Exported_Functions */

/** @} */
/* End of group CG */

/** @} */
/* End of group TX03_Periph_Driver */    
#endif                          /* defined(__TMPM330_CG_H) || defined(__TMPM332_CG_H) || defined(__TMPM333_CG_H) */
