/**
 *******************************************************************************
 * @file    tmpm362_cg.c
 * @brief   This file provides API functions for CG driver 
 * @version V2.2.0
 * @date    2010/12/02
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
#include "tmpm362_cg.h"

#if defined(__TMPM360_CG_H) || defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H) ||  \
    defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)
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
#define CG_PRCLK_MASK               ((uint32_t)0xFFFFF8FF)
#define CG_SCOUT_MASK               ((uint32_t)0xFFFCFFFF)
#define CG_WUP_TIME_MASK            ((uint32_t)0x000F3FFF)
#define CG_WUP_COUNTER_MASK         ((uint32_t)0xFFFFFFF7)

#define CG_STBY_MODE_MASK           ((uint32_t)0xFFFFFFF8)
#define CG_NMI_FACTOR_PIN_WDT_MASK  ((uint32_t)0xFFFFFFFC)
#define CG_RESET_FLAG_MASK          ((uint32_t)0xFFFFFFE0)

#define CG_FPSEL_MASK               ((uint32_t)0xFFFFEFFF)
#define CG_PHIT0SEL_MASK            ((uint32_t)0xFFFFDFFF)

#define FC_GEAR_1_1                 ((uint8_t)0x00)
#define FC_GEAR_1_2                 ((uint8_t)0x04)
#define FC_GEAR_1_4                 ((uint8_t)0x05)
#define FC_GEAR_1_8                 ((uint8_t)0x06)

#define FPERIPH_FGEAR               ((uint8_t)0x00)

#define FPERIPH_FC                  ((uint8_t)0x10)

#define PRCCLK_1_1                  ((uint8_t)0x00)

#define WARM_UP_SEL_X1              ((uint8_t)0x00)
#define WARM_UP_SEL_XT1             ((uint8_t)0x08)

#define SCOUT_SRC_FS                ((uint32_t)0x00000000)
#define SCOUT_SRC_HALF_FSYS         ((uint32_t)0x00010000)
#define SCOUT_SRC_FSYS              ((uint32_t)0x00020000)
#define SCOUT_SRC_PHIT0             ((uint32_t)0x00030000)

#define CG_MUL_TIMES_MASK           ((uint32_t)0XFFFF0807)
#define CG_MUL_4TIMES_DATA          ((uint32_t)0x00007218)
#define CG_MUL_8TIMES_DATA          ((uint32_t)0x0000A138)

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
    CG_DIVIDE_UNKNOWN,
};

#if defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H) ||  \
    defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)
static CG_STBYMode numToSTBYMode_table[CG_STBY_MODE_MAX] = {
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_STOP,
    CG_STBY_MODE_SLEEP,
    CG_STBY_MODE_IDLE2,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_BACKUP_STOP,
    CG_STBY_MODE_BACKUP_SLEEP,
    CG_STBY_MODE_IDLE1,
};
#endif

#if defined(__TMPM360_CG_H)
static CG_STBYMode numToSTBYMode_table[CG_STBY_MODE_MAX] = {
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_STOP,
    CG_STBY_MODE_SLEEP,
    CG_STBY_MODE_IDLE2,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_IDLE1,
};
#endif


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
  * @retval the dividing level between clock fgear and fc
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

#if defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H) ||  \
    defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)
/**
  * @brief  set PhiT0 Source
  * @param  PhiT0Src:CG_PHIT0_SRC_FS, CG_PHIT0_SRC_FPSCALER
  * @retval none
  */
void CG_SetPhiT0Src(CG_PhiT0Src PhiT0Src)
{
    uint32_t regval = 0U;
    /* Check the parameters */
    assert_param(IS_CG_PHIT0_SRC(PhiT0Src));
    regval = TSB_CG->SYSCR;
    regval &= CG_PHIT0SEL_MASK;
    if (PhiT0Src == CG_PHIT0_SRC_FS) {
        regval |= ~CG_PHIT0SEL_MASK;
    } else {
        /*Do nothing */
    }
    TSB_CG->SYSCR = regval;
}

/**
  * @brief  get PhiT0 Source
  * @param  none
  * @retval PhiT0src:CG_PHIT0_SRC_FS, CG_PHIT0_SRC_FPSCALER
  */
CG_PhiT0Src CG_GetPhiT0Src(void)
{
    uint32_t regval = 0U;
    CG_PhiT0Src tmp = CG_PHIT0_SRC_FS;

    regval = TSB_CG->SYSCR;
    regval &= (~CG_PHIT0SEL_MASK);

    if (regval == 0U) {
        tmp = CG_PHIT0_SRC_FPSCALER;
    } else {
        /*Do nothing */
    }
    return tmp;
}
#endif                          /*defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H)|| \    */
                /*defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)        */
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
    CG_DivideLevel fgear = CG_DIVIDE_UNKNOWN;
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
  * @retval the divide level between clock phiT0 and fc
  *   The value returned can be one of the following values:
  *   CG_DIVIDE_1, CG_DIVIDE_2, CG_DIVIDE_4, CG_DIVIDE_8, CG_DIVIDE_16, CG_DIVIDE_32, 
  *   CG_DIVIDE_64, CG_DIVIDE_128 or CG_DIVIDE_256 or CG_DIVIDE_UNKNOWN.
  */
CG_DivideLevel CG_GetPhiT0Level(void)
{
    uint32_t tmp = 0U;
    uint32_t fprclk = 0U;
    CG_DivideLevel fgear = CG_DIVIDE_UNKNOWN;
    CG_DivideLevel phiT0Level = CG_DIVIDE_UNKNOWN;

    tmp = TSB_CG->SYSCR & (~CG_PRCLK_MASK);
    fprclk = (uint8_t) (tmp >> 8U);

    if (fprclk <= CG_DIVIDE_32) {
        if (TSB_CG_SYSCR_FPSEL0 == 1U) {
            /*FPERIPH_FC */
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
  * @brief sets the source of SCOUT output
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
  * @brief  get the source of SCOUT output.
  * @param  None
  * @retval source of SCOUT output
  *   The value returned can be one of the following values:
  *   CG_SCOUT_SRC_FS, CG_SCOUT_SRC_FSYS, CG_SCOUT_SRC_PHIT0 or SCOUT_SRC_HALF_FSYS.
  */
CG_SCOUTSrc CG_GetSCOUTSrc(void)
{
    uint32_t tmp = 0U;
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
  * @param  Source: select source of warm-up counter
  *   This parameter can be one of the following values:
  *   CG_WARM_UP_SRC_X1 or CG_WARM_UP_SRC_XT1.
  * @param  Time: select count time of warm-up timer
  * @retval None
  */
void CG_SetWarmUpTime(CG_WarmUpSrc Source, uint16_t Time)
{
    uint32_t tmp = 0U;
    uint32_t regval = TSB_CG->OSCCR;

    /* Check the parameters */
    assert_param(IS_CG_WARM_UP_SRC(Source));

    regval &= CG_WUP_TIME_MASK;
    regval &= CG_WUP_COUNTER_MASK;
    if (Source == CG_WARM_UP_SRC_X1) {
        /* Check the parameters */
        assert_param(IS_CG_WARM_UP_TIME_X1(Time));
        tmp = Time;
        tmp = tmp << 20U;
        regval |= tmp;
        regval |= WARM_UP_SEL_X1;
    } else {
        /* Check the parameters */
        assert_param(IS_CG_WARM_UP_TIME_XT1(Time));

        /* get low 2 bits of warm-up time */
        tmp = Time;
        tmp = (tmp & 0x3U) << 14U;
        regval |= tmp;

        /* get high 12 bits of warm-up time */
        tmp = Time;
        tmp = (tmp & 0x3ffcU) << 18U;
        regval |= tmp;
        regval |= WARM_UP_SEL_XT1;
    }
    TSB_CG->OSCCR = regval;
}

/**
  * @brief  start operation of warm up timer for oscillator .
  * @param  none
  * @retval none
  */
void CG_StartWarmUp(void)
{
    TSB_CG_OSCCR_WUEON = 1U;
}

/**
  * @brief check whether warm up is completed or not.
  * @param none
  * @retval warm-up state: completed or not
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
  * @param  NewState:enable or disable
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval result:success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
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
        if (fcsrc == CG_FC_SRC_FOSC) {  /* PLL is not used.So it can be shut off */
            /* set register to disable PLL */
            TSB_CG_OSCCR_PLLON = 0U;
            retval = SUCCESS;
        } else {                /*fcsrc == CG_FC_SRC_FPLL. PLL is in use, so disabling it should be invalid */
            retval = ERROR;
        }
    }
    return retval;
}

/**
  * @brief  get the status of PLL operation
  * @param  none
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
  * @param  NewState: oscillation is enabled or disabled
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFosc(FunctionalState NewState)
{
    CG_FsysSrc fsys_src = CG_FSYS_SRC_FGEAR;
    Result retval = ERROR;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* enable high-speed oscillation */
        TSB_CG_OSCCR_XEN = 1U;
        retval = SUCCESS;
    } else {
        fsys_src = CG_GetFsysSrc();
        if (fsys_src == CG_FSYS_SRC_FGEAR) {    /* fosc is in  use. so it can't be disabled */
            retval = ERROR;
        } else {
            /* disable high-speed oscillation */
            TSB_CG_OSCCR_XEN = 0U;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief  get the state of high-speed oscillation (fosc)
  * @param  none
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
  * @param  NewState: oscillation is enabled or disabled
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFs(FunctionalState NewState)
{
    CG_FsysSrc fsys_src = CG_FSYS_SRC_FGEAR;
    Result retval = ERROR;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* enable low-speed oscillation */
        TSB_CG_OSCCR_XTEN = 1U;
        retval = SUCCESS;
    } else {
        fsys_src = CG_GetFsysSrc();
        if (fsys_src == CG_FSYS_SRC_FS) {
            /* fs is in  use. so it can't be disabled */
            retval = ERROR;
        } else {
            /* disable low-speed oscillation */
            TSB_CG_OSCCR_XTEN = 0U;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief  get the state of low-speed oscillation (fs)
  * @param  none
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
  * @param  low power mode
  *   The value can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_SLEEP, CG_STBY_MODE_IDLE2, 
  *   CG_STBY_MODE_BACKUP_STOP(for M361, M362, M363, M364 only),
  *   CG_STBY_MODE_BACKUP_SLEEP(for M361, M362, M363, M364 only),
  *   CG_STBY_MODE_IDLE1.
  * @retval none
  */
void CG_SetSTBYMode(CG_STBYMode Mode)
{
    uint32_t regval = TSB_CG->STBYCR;

    /*check the parameter */
    assert_param(IS_CG_STBY_MODE(Mode));

    regval &= CG_STBY_MODE_MASK;
    regval |= (uint32_t) Mode;

    TSB_CG->STBYCR = regval;
}

/**
  * @brief  get the low-power consumption mode
  * @param  none
  * @retval low power mode
  *   The value returned can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_SLEEP, CG_STBY_MODE_IDLE2,
  *   CG_STBY_MODE_BACKUP_STOP(for M361, M362, M363, M364 only), 
  *   CG_STBY_MODE_BACKUP_SLEEP(for M361, M362, M363, M364 only),
  *   CG_STBY_MODE_IDLE1 or CG_STBY_MODE_UNKNOWN.
  */
CG_STBYMode CG_GetSTBYMode(void)
{
    CG_STBYMode stby_mode = CG_STBY_MODE_UNKNOWN;
    uint8_t regval = (uint8_t) (TSB_CG->STBYCR & (~CG_STBY_MODE_MASK));

    stby_mode = numToSTBYMode_table[regval];
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
  * @param  none
  * @retval state of pin in stop mode
  *   The value returned can be one of the following values:
  *   DISABLE or ENABLE.
  */
FunctionalState CG_GetPinStateInStopMode(void)
{
    FunctionalState state = DISABLE;

    if (TSB_CG_STBYCR_DRVE == 1U) {
        /* pin status in stop mode is active */
        state = ENABLE;
    } else {
        state = DISABLE;
    }
    return state;
}

#if defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H) ||  \
    defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)
/**
  * @brief  set the IO port control in the backup mode as controllable or Hold on.
  * @param  NewState:ENABLE or DISABLE
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetPortKeep(FunctionalState NewState)
{
    Result retval = ERROR;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (NewState == ENABLE) {
        /*Holds the I/O Port setting in the Backup Mode by <DRVE>="1". */
        if (CG_GetPinStateInStopMode() == ENABLE) {
            TSB_CG_STBYCR_PTKEEP = 1U;
            retval = SUCCESS;
        } else {
            /* Do nothing */
            /* ERROR */
        }
    } else {
        TSB_CG_STBYCR_PTKEEP = 0U;
        retval = SUCCESS;
    }
    return (retval);
}
#endif

/**
  * @brief  set the source of fc
  * @param  Source:  the source of fc
  *   This parameter can be one of the following values:
  *   CG_FC_SRC_FOSC or CG_FC_SRC_FPLL.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFcSrc(CG_FcSrc Source)
{

    Result retval = ERROR;
    FunctionalState fosc_on = DISABLE;
    FunctionalState pllon = DISABLE;

    /* Check the parameters */
    assert_param(IS_CG_FC_SRC(Source));

    fosc_on = CG_GetFoscState();
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
  * @param  none
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
  * @brief  set the times that clock is multiplied by the PLL.
  * @param  MulTimes:: select the times of clock multiplied by the PLL.
  *     This parameter can be one of the following values:
  *     CG_MUL_4TIMES, CG_MUL_8TIMES
  * @retval none
  */
void CG_SetClkMulTimes(CG_ClkMul MulTimes)
{
    uint32_t regval = 0U;
    regval = TSB_CG->PLLSEL;
    regval &= CG_MUL_TIMES_MASK;

    /* Check the parameters */
    assert_param(IS_CG_CLK_MUL(MulTimes));

    if (MulTimes == CG_MUL_8TIMES) {
        regval |= CG_MUL_8TIMES_DATA;
    } else {
        regval |= CG_MUL_4TIMES_DATA;
    }
    TSB_CG->PLLSEL = regval;
}

/**
  * @brief  set the source of fsys
  * @param  Source: Source: select the source of fsys
  *   This parameter can be one of the following values:
  *   CG_FSYS_SRC_FGEAR or CG_FSYS_SRC_FS.
  * @retval success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR.
  */
Result CG_SetFsysSrc(CG_FsysSrc Source)
{
    Result retval = ERROR;
    FunctionalState fosc_on = DISABLE;
    FunctionalState fs_on = DISABLE;
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
            retval = SUCCESS;
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
            retval = SUCCESS;
        } else {
            retval = ERROR;
        }
    }
    return retval;
}

/**
  * @brief  get the clock source of fsys
  * @param  none
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
  * @param  INTSource: select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2, CG_INT_SRC_3,     
  *   CG_INT_SRC_4, CG_INT_SRC_5, CG_INT_SRC_6, CG_INT_SRC_7, 
  *   CG_INT_SRC_8(For M360/M362/M364), CG_INT_SRC_9(For M360/M362/M364),
  *   CG_INT_SRC_A(For M360/M362/M364), CG_INT_SRC_B(For M360/M362/M364), 
  *   CG_INT_SRC_C(For M360/M362/M364), CG_INT_SRC_D(For M360/M362/M364),
  *   CG_INT_SRC_E(For M360/M361/M362), CG_INT_SRC_F(For M360/M361/M362), 
  *   CG_INT_SRC_CEC_RX , CG_INT_SRC_CEC_TX, CG_INT_SRC_RMC_RX_0,  
  *   CG_INT_SRC_RMC_RX_1(For M360/M362/M364), CG_INT_SRC_RTC, CG_INT_SRC_KWUP.
  * @param  ActiveState: select the active state for release trigger
  *   For INTCECRX, INTCECTX, INTRMCRX0 and INTRMCRX1, only "RISING" state will be set,
  *   no matter what the value of ActiveState is.
  *   For INTRTC , only "FALLING" state will be set, no matter what the value of ActiveState is.
  *   For INTKWUP, only "H level" state will be set, no matter what the value of ActiveState is.
  *   Others  parameter can be one of the following values:
  *   CG_INT_ACTIVE_STATE_L, CG_INT_ACTIVE_STATE_H, CG_INT_ACTIVE_STATE_FALLING,
  *   CG_INT_ACTIVE_STATE_RISING or CG_INT_ACTIVE_STATE_BOTH_EDGES.
  * @param  NewState: enable or disable this release trigger
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval none
  */
void CG_SetSTBYReleaseINTSrc(CG_INTSrc INTSource,
                             CG_INTActiveState ActiveState, FunctionalState NewState)
{
    uint32_t num = 0U;
    uint8_t i = 0U;
    uint8_t j = 0U;
    CG_Byte4 regval[6] = { {0U}
    , {0U}
    , {0U}
    , {0U}
    , {0U}
    , {0U}
    };

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));
    assert_param(IS_CG_INT_ACTIVE_STATE(ActiveState));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (INTSource <= CG_INT_SRC_KWUP) {

        num = (uint32_t) INTSource;
        i = (uint8_t) (num / 4U);
        j = (uint8_t) (num % 4U);

        switch (i) {
        case 0:                /* IMCGA */
            regval[0].byte4 = TSB_CG->IMCGA;
            regval[0].byte[j] &= 0x8eU;
            regval[0].byte[j] |= ActiveState;
            TSB_CG->IMCGA = regval[0].byte4;
            regval[0].byte[j] |= NewState;
            TSB_CG->IMCGA = regval[0].byte4;
            break;

        case 1:                /* IMCGB */
            regval[1].byte4 = TSB_CG->IMCGB;
            regval[1].byte[j] &= 0x8eU;
            regval[1].byte[j] |= ActiveState;
            TSB_CG->IMCGB = regval[1].byte4;
            regval[1].byte[j] |= NewState;
            TSB_CG->IMCGB = regval[1].byte4;
            break;

#if defined(__TMPM360_CG_H) || defined(__TMPM362_CG_H) || defined(__TMPM364_CG_H)
        case 2:                /* IMCGC */
            regval[2].byte4 = TSB_CG->IMCGC;
            regval[2].byte[j] &= 0x8eU;
            regval[2].byte[j] |= ActiveState;
            TSB_CG->IMCGC = regval[2].byte4;
            regval[2].byte[j] |= NewState;
            TSB_CG->IMCGC = regval[2].byte4;
            break;
#endif

#if defined(__TMPM360_CG_H) || defined(__TMPM361_CG_H)|| defined(__TMPM362_CG_H) || defined(__TMPM364_CG_H)
        case 3:                /* IMCGD */
            regval[3].byte4 = TSB_CG->IMCGD;
            regval[3].byte[j] &= 0x8eU;
            regval[3].byte[j] |= ActiveState;
            TSB_CG->IMCGD = regval[3].byte4;
            regval[3].byte[j] |= NewState;
            TSB_CG->IMCGD = regval[3].byte4;
            break;
#endif

        case 4:                /* IMCGE */
            regval[4].byte4 = TSB_CG->IMCGE;
            regval[4].byte[j] &= 0x8eU;
            ActiveState = CG_INT_ACTIVE_STATE_RISING;
            regval[4].byte[j] |= ActiveState;
            TSB_CG->IMCGE = regval[4].byte4;
            regval[4].byte[j] |= NewState;
            TSB_CG->IMCGE = regval[4].byte4;
            break;

        case 5:                /* IMCGF */
            regval[5].byte4 = TSB_CG->IMCGF;
            regval[5].byte[j] &= 0x8eU;
            if (INTSource == CG_INT_SRC_RTC) {
                ActiveState = CG_INT_ACTIVE_STATE_FALLING;
            } else {
                ActiveState = CG_INT_ACTIVE_STATE_H;
            }
            regval[5].byte[j] |= ActiveState;
            TSB_CG->IMCGF = regval[5].byte4;
            regval[5].byte[j] |= NewState;
            TSB_CG->IMCGF = regval[5].byte4;
            break;

        default:
            /* Do nothing */
            break;
        }
    } else {
        /*Do nothing */
    }
}

/**
  * @brief  gets the active state of INT source standby clear request
  * @param  INTSource: select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2, CG_INT_SRC_3,     
  *   CG_INT_SRC_4, CG_INT_SRC_5, CG_INT_SRC_6, CG_INT_SRC_7, 
  *   CG_INT_SRC_8(For M360/M362/M364), CG_INT_SRC_9(For M360/M362/M364),
  *   CG_INT_SRC_A(For M360/M362/M364), CG_INT_SRC_B(For M360/M362/M364), 
  *   CG_INT_SRC_C(For M360/M362/M364), CG_INT_SRC_D(For M360/M362/M364),
  *   CG_INT_SRC_E(For M360/M361/M362), CG_INT_SRC_F(For M360/M361/M362), 
  *   CG_INT_SRC_CEC_RX , CG_INT_SRC_CEC_TX, CG_INT_SRC_RMC_RX_0,  
  *   CG_INT_SRC_RMC_RX_1(For M360/M362/M364), CG_INT_SRC_RTC, CG_INT_SRC_KWUP.
  * @retval active state of the input INT
  *   The value returned can be one of the following values:
  *   CG_INT_ACTIVE_STATE_FALLING, CG_INT_ACTIVE_STATE_RISING,
  *   CG_INT_ACTIVE_STATE_BOTH_EDGES or CG_INT_ACTIVE_STATE_INVALID.
  */
CG_INTActiveState CG_GetSTBYReleaseINTState(CG_INTSrc INTSource)
{
    CG_INTActiveState int_active_state = CG_INT_ACTIVE_STATE_INVALID;
    CG_Byte4 regval[6] = { {0U}
    , {0U}
    , {0U}
    , {0U}
    , {0U}
    , {0U}
    };
    uint8_t i = 0U;
    uint8_t j = 0U;
    uint8_t tmp = 0U;
    uint32_t num = 0U;

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    if (INTSource <= CG_INT_SRC_KWUP) {
        regval[0].byte4 = TSB_CG->IMCGA;
        regval[1].byte4 = TSB_CG->IMCGB;
#if defined(__TMPM360_CG_H) || defined(__TMPM362_CG_H) || defined(__TMPM364_CG_H)
        regval[2].byte4 = TSB_CG->IMCGC;
#endif
#if defined(__TMPM360_CG_H) || defined(__TMPM361_CG_H)|| defined(__TMPM362_CG_H) || defined(__TMPM364_CG_H)
        regval[3].byte4 = TSB_CG->IMCGD;
#endif
        regval[4].byte4 = TSB_CG->IMCGE;
        regval[5].byte4 = TSB_CG->IMCGF;
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
    }
    return (int_active_state);
}

/**
  * @brief  clears the input INT request.
  * @param  INTSource: select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2, CG_INT_SRC_3,     
  *   CG_INT_SRC_4, CG_INT_SRC_5, CG_INT_SRC_6, CG_INT_SRC_7, 
  *   CG_INT_SRC_8(For M360/M362/M364), CG_INT_SRC_9(For M360/M362/M364),
  *   CG_INT_SRC_A(For M360/M362/M364), CG_INT_SRC_B(For M360/M362/M364), 
  *   CG_INT_SRC_C(For M360/M362/M364), CG_INT_SRC_D(For M360/M362/M364),
  *   CG_INT_SRC_E(For M360/M361/M362), CG_INT_SRC_F(For M360/M361/M362), 
  *   CG_INT_SRC_CEC_RX , CG_INT_SRC_CEC_TX, CG_INT_SRC_RMC_RX_0,  
  *   CG_INT_SRC_RMC_RX_1(For M360/M362/M364), CG_INT_SRC_RTC, CG_INT_SRC_KWUP.
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
  * @param  none
  * @retval NMI flag
  */
CG_NMIFactor CG_GetNMIFlag(void)
{
    CG_NMIFactor cg_nmi_factor = { 0U };
    uint32_t regval = TSB_CG->NMIFLG;
    uint32_t tmp = 0U;

    tmp = regval & (~CG_NMI_FACTOR_PIN_WDT_MASK);
    cg_nmi_factor.All = tmp;
    return cg_nmi_factor;
}

/**
  * @brief  get the type of reset reason and clear the reset flag.
  * @param  none
  * @retval reset flag
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
#endif                          /* defined(__TMPM360_CG_H) || defined(__TMPM361_CG_H) || \ */
                                /* defined(__TMPM362_CG_H) || defined(__TMPM363_CG_H) || \ */
                                /* defined(__TMPM364_CG_H) */
