/**
 *******************************************************************************
 * @file    tmpm061_cg.c
 * @brief   This file provides API functions for CG driver 
 * @version V2.0.2.2
 * @date    2012/08/17
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
#include "tmpm061_cg.h"

#if defined(__TMPM061_CG_H)
/** @addtogroup TX00_Periph_Driver
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
#define CG_SCOUT_MASK               ((uint32_t)0xFFFCFFFF)
#define CG_WUODR_MASK               ((uint32_t)0x0007FFF6)                                                      

#define CG_STBY_MODE_MASK           ((uint32_t)0xFFFFFFF8)
#define CG_RESET_FLAG_MASK          ((uint32_t)0xFFFFFFC8)

#define CG_FPSEL_MASK               ((uint32_t)0xFFFFCFFF)

#define FC_GEAR_1_1                 ((uint32_t)0x00000000)
#define FC_GEAR_1_2                 ((uint32_t)0x00000004)
#define FC_GEAR_1_4                 ((uint32_t)0x00000005)
#define FC_GEAR_1_8                 ((uint32_t)0x00000006)
#define FC_GEAR_1_16                ((uint32_t)0x00000007)

#define WARM_UP_SEL_OSC1            ((uint32_t)0x00080000)
#define WARM_UP_SEL_OSC2            ((uint32_t)0x00000000)
#define WARM_UP_SEL_XT1             ((uint32_t)0x00000008)

#define SCOUT_SRC_FS                ((uint32_t)0x00000000)
#define SCOUT_SRC_HALF_FSYS         ((uint32_t)0x00010000)
#define SCOUT_SRC_FSYS              ((uint32_t)0x00020000)
#define SCOUT_SRC_PHIT0             ((uint32_t)0x00030000)

#define OSCCR_WUEON_SET             ((uint32_t)0x00000001)
#define OSCCR_WUEF_SET              ((uint32_t)0x00000002)
#define OSCCR_HOSCON_SET            ((uint32_t)0x00040000)
#define OSCCR_HOSCON_CLEAR          ((uint32_t)0xFFFBFFFF)
#define OSCCR_XEN1_SET              ((uint32_t)0x00000100)
#define OSCCR_XEN1_CLEAR            ((uint32_t)0xFFFFFEFF)
#define OSCCR_XTEN_SET              ((uint32_t)0x00000200)
#define OSCCR_XTEN_CLEAR            ((uint32_t)0xFFFFFDFF)
#define OSCCR_XEN2_SET              ((uint32_t)0x00010000)
#define OSCCR_XEN2_CLEAR            ((uint32_t)0xFFFEFFFF)
#define OSCCR_OSCSEL_SET            ((uint32_t)0x00020000)
#define OSCCR_OSCSEL_CLEAR          ((uint32_t)0xFFFDFFFF)
#define OSCCR_LOSCSEL_SET           ((uint32_t)0x00000400)
#define OSCCR_LOSCSEL_CLEAR         ((uint32_t)0xFFFFFBFF)
#define OSCCR_EHCLKEN_SET           ((uint32_t)0x00000800)
#define OSCCR_EHCLKEN_CLEAR         ((uint32_t)0xFFFFF7FF)
#define EHCLKSEL_EHCLKSEL_SET       ((uint32_t)0x00000001)
#define EHCLKSEL_EHCLKSEL_CLEAR     ((uint32_t)0xFFFFFFFE)
#define STBYCR_RXEN_SET             ((uint32_t)0x00000100)
#define STBYCR_RXEN_CLEAR           ((uint32_t)0xFFFFFEFF)
#define STBYCR_RXTEN_SET            ((uint32_t)0x00000200)
#define STBYCR_RXTEN_CLEAR          ((uint32_t)0xFFFFFDFF)
#define STBYCR_DRVE_SET             ((uint32_t)0x00010000)
#define STBYCR_DRVE_CLEAR           ((uint32_t)0xFFFEFFFF)
#define CKSEL_SYSCK_SET             ((uint32_t)0x00000002)
#define CKSEL_SYSCK_CLEAR           ((uint32_t)0xFFFFFFFD)
#define CKSEL_SYSCKFLG_SET          ((uint32_t)0x00000001)
#define CKSEL_SYSCKFLG_CLEAR        ((uint32_t)0xFFFFFFFE)

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
    CG_PHIT0_SRC_FS,
    CG_PHIT0_SRC_FS,
};

static CG_STBYMode numToSTBYMode_table[CG_STBY_MODE_MAX] = {
    CG_STBY_MODE_UNKNOWN,
    CG_STBY_MODE_STOP,
    CG_STBY_MODE_SLEEP,
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
  *   CG_PHIT0_SRC_FGEAR, CG_PHIT0_SRC_FC or CG_PHIT0_SRC_FS
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
  *   CG_PHIT0_SRC_FGEAR, CG_PHIT0_SRC_FC or CG_PHIT0_SRC_FS
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
  * @brief  Set dividing level between clock PhiT0 and fc/fs.
  * @param  DividePhiT0FromFc: Dividing level between PhiT0 and fc/fs.
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
    if ((PhiT0_src == CG_PHIT0_SRC_FS) || (PhiT0_src == CG_PHIT0_SRC_FC)) {
        /* Check the parameters */
        assert_param(IS_CG_DIVIDE_FS_FC_LEVEL(DividePhiT0FromFc));

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
  * @brief  Get dividing level between clock phiT0 and fc/fs.
  * @param  None
  * @retval The divide level between clock phiT0 and fc/fs
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

    if ((PhiT0_src == CG_PHIT0_SRC_FS) || (PhiT0_src == CG_PHIT0_SRC_FC)) {
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
  * @brief Set the source of SCOUT output
  * @param Source: Select source of SCOUT
  *   This parameter can be one of the following values:
  *   CG_SCOUT_SRC_FS, CG_SCOUT_SRC_HALF_FSYS,
  *   CG_SCOUT_SRC_FSYS or CG_SCOUT_SRC_PHIT0
  * @retval None
  */
void CG_SetSCOUTSrc(CG_SCOUTSrc Source)
{
    /* Get the original SCOUT SRC value */
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
        /* Do nothing */
        break;
    }

    regval &= CG_SCOUT_MASK;
    regval |= tmp;
    TSB_CG->SYSCR = regval;
}

/**
  * @brief  Get the source of SCOUT output.
  * @param  None
  * @retval Source of SCOUT output
  *   The value returned can be one of the following values:
  *   CG_SCOUT_SRC_FS, CG_SCOUT_SRC_FSYS,
  *   CG_SCOUT_SRC_PHIT0 or CG_SCOUT_SRC_HALF_FSYS
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
        /* Do nothing */
        break;
    }

    return source;
}

/**
  * @brief  Set the warm up time 
  * @param  Source: Select source of warm-up counter
  *   This parameter can be one of the following values:
  *   CG_WARM_UP_SRC_OSC1, CG_WARM_UP_SRC_OSC2 or CG_WARM_UP_SRC_XT1
  * @param  Time: Set count time for warm-up timer
  * @retval None
  */
void CG_SetWarmUpTime(CG_WarmUpSrc Source, uint16_t Time)
{
    uint32_t tmp = 0U;
    uint32_t regval = TSB_CG->OSCCR;

    /* Check the parameters */
    assert_param(IS_CG_WARM_UP_SRC(Source));

    regval &= CG_WUODR_MASK;

    switch (Source) {
    case CG_WARM_UP_SRC_OSC1:
        /* Check the parameters */
        assert_param(IS_CG_WARM_UP_TIME_X1(Time));
        tmp = Time;
        tmp = tmp << 20U;
        regval |= tmp;
        regval |= WARM_UP_SEL_OSC1;
        break;
    case CG_WARM_UP_SRC_OSC2:
        /* Check the parameters */
        assert_param(IS_CG_WARM_UP_TIME_X1(Time));
        tmp = Time;
        tmp = tmp << 20U;
        regval |= tmp;
        regval |= WARM_UP_SEL_OSC2;
        break;
    case CG_WARM_UP_SRC_XT1:
        /* Check the parameters */
        assert_param(IS_CG_WARM_UP_TIME_XT1(Time));
        /* Get low 2 bits of warm-up time */
        tmp = Time;
        tmp = (tmp & 0x0003U) << 14U;
        regval |= tmp;
        /* Get high 12 bits of warm-up time */
        tmp = Time;
        tmp = (tmp & 0x3ffcU) << 18U;
        regval |= tmp;
        regval |= WARM_UP_SEL_XT1;
        break;
    default:
        /* Do nothing */
        break;
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
    TSB_CG->OSCCR |= OSCCR_WUEON_SET;
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
    uint32_t tmp = TSB_CG->OSCCR;
    tmp &= OSCCR_WUEF_SET;
    if (tmp == 0U) {
        state = DONE;
    } else {
        /* Do nothing */
    }

    return state;
}

/**
  * @brief  Enable or disable high-speed oscillator (fosc)
  * @param  Source: Select clock source for fosc
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 or CG_FOSC_OSC2
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
    CG_FsysSrc fsys_src = CG_FSYS_SRC_FGEAR;
    Result retval = ERROR;
    uint32_t tmp = TSB_CG->OSCCR;
    tmp &= OSCCR_HOSCON_SET;
    
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_CG_FOSC_SRC(Source));

    switch (Source) {
    case CG_FOSC_OSC1:
        if (tmp != 0U) {
            if (NewState == ENABLE) {
                /* Enable high-speed oscillator */
                TSB_CG->OSCCR |= OSCCR_XEN1_SET;            
                retval = SUCCESS;
            } else {
                fosc_src = CG_GetFoscSrc();
                fsys_src = CG_GetFsysSrc();
                if ((fosc_src == CG_FOSC_OSC1)
                    && (fsys_src == CG_FSYS_SRC_FGEAR)) {
                    /* fosc1 is in  use, so it can't be disabled */
                    retval = ERROR;
                } else {
                    /* Disable high-speed oscillator1 */
                    TSB_CG->OSCCR &= OSCCR_XEN1_CLEAR;
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
            TSB_CG->OSCCR |= OSCCR_XEN2_SET;
            retval = SUCCESS;
        } else {
            fosc_src = CG_GetFoscSrc();
            fsys_src = CG_GetFsysSrc();
            if ((fosc_src == CG_FOSC_OSC2)
                && (fsys_src == CG_FSYS_SRC_FGEAR)) {
                /* fosc2 is in  use, so it can't be disabled */
                retval = ERROR;
            } else {
                /* Disable high-speed oscillator2 */
                TSB_CG->OSCCR &= OSCCR_XEN2_CLEAR;
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
  *   CG_FOSC_OSC1 or CG_FOSC_OSC2
  * @retval None
  */
void CG_SetFoscSrc(CG_FoscSrc Source)
{
    /* Check the parameters */
    assert_param(IS_CG_FOSC_SRC(Source));

    if (Source == CG_FOSC_OSC1) {
        TSB_CG->OSCCR |= OSCCR_OSCSEL_SET;
    } else {
        TSB_CG->OSCCR &= OSCCR_OSCSEL_CLEAR;
    }
}

/**
  * @brief  Get the source of high-speed oscillator (fosc)
  * @param  None
  * @retval Source of fosc
  *   The value returned can be one of the following values:
  *   CG_FOSC_OSC1 or CG_FOSC_OSC2
  */
CG_FoscSrc CG_GetFoscSrc(void)
{
    uint32_t tmp = TSB_CG->OSCCR;
    CG_FoscSrc fosc_src = CG_FOSC_OSC2;
    tmp &= OSCCR_OSCSEL_SET;

    if (tmp != 0U) {
        fosc_src = CG_FOSC_OSC1;
    } else {
        /* Do nothing */
    }

    return fosc_src;
}

/**
  * @brief  Get the state of high-speed oscillator (fosc)
  * @param  Source: Select fosc source
  *   This parameter can be one of the following values:
  *   CG_FOSC_OSC1 or CG_FOSC_OSC2
  * @retval State of fosc
  *   The value returned can be one of the following values:
  *   ENABLE or DISABLE
  */
FunctionalState CG_GetFoscState(CG_FoscSrc Source)
{
    FunctionalState state = DISABLE;
    uint32_t tmp1 = TSB_CG->OSCCR;
	uint32_t tmp2 = TSB_CG->OSCCR;

    tmp1 &= OSCCR_XEN1_CLEAR;
   
    tmp2 &= OSCCR_XEN2_CLEAR;    
    /* Check the parameters */
    assert_param(IS_CG_FOSC_SRC(Source));

    if (Source == CG_FOSC_OSC1) {
        if (tmp1 != 0U) {
            state = ENABLE;
        } else {
            /* Do nothing */
        }
    } else {
        if (tmp2 != 0U) {
            state = ENABLE;
        } else {
            /* Do nothing */
        }
    }

    return state;
}

/**
  * @brief  Enable or disable low-speed oscillator (fs)
  * @param  NewState: oscillator is enabled or disabled
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval Success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CG_SetFs(FunctionalState NewState)
{
    CG_FsysSrc fsys_src = CG_FSYS_SRC_FGEAR;
    Result retval = ERROR;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Enable low-speed oscillator */
        TSB_CG->OSCCR |= OSCCR_XTEN_SET;
        retval = SUCCESS;
    } else {
        fsys_src = CG_GetFsysSrc();
        if (fsys_src == CG_FSYS_SRC_FS) {
            /* fs is in  use. so it can't be disabled */
            retval = ERROR;
        } else {
            /* Disable low-speed oscillator */
            TSB_CG->OSCCR &= OSCCR_XTEN_CLEAR;
            retval = SUCCESS;
        }
    }

    return retval;
}

/**
  * @brief  Get the state of low-speed oscillator (fs)
  * @param  None
  * @retval State of fs
  *   The value returned can be one of the following values:
  *   DISABLE or ENABLE
  */
FunctionalState CG_GetFsState(void)
{
    FunctionalState state = DISABLE;
    uint32_t tmp = TSB_CG->OSCCR;
    tmp &= OSCCR_XTEN_SET;
    
    if (tmp != 0U) {
        state = ENABLE;
    } else {
        /* Do nothing */
    }

    return state;
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

    if (Mode == CG_PORTM_AS_HOSC) {
        TSB_CG->OSCCR |= OSCCR_HOSCON_SET;
    } else {
        TSB_CG->OSCCR &= OSCCR_HOSCON_CLEAR;
    }
}

/**
  * @brief  Select the Low-speed clock.
  * @param  Source £ºLow-speed clock
  *   This parameter can be one of the following values:
  *   CG_LOSC_OSC or CG_LOSC_CLK.
  * @retval None
  */
void CG_SetLowOscSrc(CG_LoscSrc Source)
{
    /* Check the parameters */
    assert_param(IS_CG_LOSC_FUNCTION(Source));

    if (Source == CG_LOSC_CLK) {
        TSB_CG->OSCCR |= OSCCR_LOSCSEL_SET;
    } else {
        TSB_CG->OSCCR &= OSCCR_LOSCSEL_CLEAR;
    }
}

/**
  * @brief  enable or disable external high-speed clock input.
  * @param  NewState: Enable or disable
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval None
  */
void CG_SetExtHighClk(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG->OSCCR |= OSCCR_EHCLKEN_SET;
    } else {
        TSB_CG->OSCCR &= OSCCR_EHCLKEN_CLEAR;
    }
}

/**
  * @brief  Set to the specified low-power mode
  * @param  Low power mode
  *   The value can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_SLEEP, CG_STBY_MODE_IDLE
  * @retval None
  */
void CG_SetSTBYMode(CG_STBYMode Mode)
{
    uint32_t regval = TSB_CG->STBYCR;

    /* Check the parameter */
    assert_param(IS_CG_STBY_MODE(Mode));

    regval &= CG_STBY_MODE_MASK;
    regval |= (uint32_t)Mode;

    TSB_CG->STBYCR = regval;
}

/**
  * @brief  Get the low-power consumption mode
  * @param  None
  * @retval Low power mode
  *   The value returned can be one of the following values:
  *   CG_STBY_MODE_STOP, CG_STBY_MODE_SLEEP, CG_STBY_MODE_IDLE or CG_STBY_MODE_UNKNOWN
  */
CG_STBYMode CG_GetSTBYMode(void)
{
    CG_STBYMode stby_mode = CG_STBY_MODE_UNKNOWN;
    uint8_t regval = (uint8_t) (TSB_CG->STBYCR & (~CG_STBY_MODE_MASK));

    stby_mode = numToSTBYMode_table[regval];

    return stby_mode;
}

/**
  * @brief  Enables or disables fosc after releasing stop mode
  * @param  NewState: Enable or disable
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval None
  */
void CG_SetExitStopModeFosc(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG->STBYCR |= STBYCR_RXEN_SET;
    } else {
        TSB_CG->STBYCR &= STBYCR_RXEN_CLEAR;
    }
}

/**
  * @brief  Get the state of fosc after releasing stop mode.
  * @param  None
  * @retval State of fosc after releasing stop mode
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  */
FunctionalState CG_GetExitStopModeFoscState(void)
{
    uint32_t tmp = TSB_CG->STBYCR;
	FunctionalState state = DISABLE;

    tmp &= STBYCR_RXEN_SET;

    if (tmp != 0U) {
        state = ENABLE;
    } else {
        /* Do nothing */
    }

    return state;
}

/**
  * @brief  Enables or disables fs after releasing stop mode
  * @param  NewState: enable or disable
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  * @retval None
  */
void CG_SetExitStopModeFs(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        TSB_CG->STBYCR |= STBYCR_RXTEN_SET;
    } else {
        TSB_CG->STBYCR &= STBYCR_RXTEN_CLEAR;
    }
}

/**
  * @brief  Get the state of fs after releasing stop mode.
  * @param  None
  * @retval State of fs after releasing stop mode
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE
  */
FunctionalState CG_GetExitStopModeFsState(void)
{
	FunctionalState state = DISABLE;
    uint32_t tmp = TSB_CG->STBYCR;
    tmp &= STBYCR_RXTEN_SET;

    if (tmp != 0U) {
        state = ENABLE;
    } else {
        /* Do nothing */
    }

    return state;
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
        TSB_CG->STBYCR |= STBYCR_DRVE_SET;
    } else {
        TSB_CG->STBYCR &= STBYCR_DRVE_CLEAR;
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
    uint32_t tmp = TSB_CG->STBYCR;
    tmp &= STBYCR_DRVE_SET;

    if (tmp != 0U) {
        /* Pin status in stop mode is active */
        state = ENABLE;
    } else {
        /* Do nothing */
    }

    return state;
}

/**
  * @brief  Use the clock selected by CGOSCCR<OSCSEL> or Use the external high-speed clock input
  * @param  Source: Select the source clock
  *   This parameter can be one of the following values:
  *   CG_EHCLK_OSCSEL or CG_EHCLK_OSC2
  * @retval None
  */
void CG_SelExtHighClk (CG_EHClkSrc Source)
{
    /* Check the parameters */
    assert_param(IS_CG_EHCLK_FUNCTION(Source));

    if (Source == CG_EHCLK_OSC2) {
        TSB_CG->EHCLKSEL |= EHCLKSEL_EHCLKSEL_SET;
    } else {
        TSB_CG->EHCLKSEL &= EHCLKSEL_EHCLKSEL_CLEAR;
    }
}

/**
  * @brief  Set the source of fsys
  * @param  Source: Select the source of fsys
  *   This parameter can be one of the following values:
  *   CG_FSYS_SRC_FGEAR or CG_FSYS_SRC_FS
  * @retval Success or failure
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CG_SetFsysSrc(CG_FsysSrc Source)
{
    Result retval = ERROR;
    FunctionalState fosc_on = DISABLE;
    FunctionalState fs_on = DISABLE;
    CG_FoscSrc fosc_src = CG_FOSC_OSC1;
    CG_FsysSrc fsyssrc = CG_FSYS_SRC_FGEAR;

    /* Check the parameters */
    assert_param(IS_CG_FSYS_SRC(Source));

    if (Source == CG_FSYS_SRC_FGEAR) {
        fosc_src = CG_GetFoscSrc();
        if (fosc_src == CG_FOSC_OSC1) {
            fosc_on = CG_GetFoscState(CG_FOSC_OSC1);
            if (fosc_on == ENABLE) {
                /* Set sysclk to fgear */
                TSB_CG->CKSEL &= CKSEL_SYSCK_CLEAR;

                do {
                    fsyssrc = CG_GetFsysSrc();
                } while (fsyssrc != CG_FSYS_SRC_FGEAR);
                retval = SUCCESS;
            } else {
                /* Do nothing */
            }
        } else {
            fosc_on = CG_GetFoscState(CG_FOSC_OSC2);
            if (fosc_on == ENABLE) {
                /* Set sysclk to fgear */
                TSB_CG->CKSEL &= CKSEL_SYSCK_CLEAR;

                do {
                    fsyssrc = CG_GetFsysSrc();
                } while (fsyssrc != CG_FSYS_SRC_FGEAR);
                retval = SUCCESS;
            } else {
                /* Do nothing */
            }
        }
    } else {
        fs_on = CG_GetFsState();
        if (fs_on == ENABLE) {
            /* Set sysclk to fs */
            TSB_CG->CKSEL |= CKSEL_SYSCK_SET;
            do {
                fsyssrc = CG_GetFsysSrc();
            } while (fsyssrc != CG_FSYS_SRC_FS);
            retval = SUCCESS;
        } else {
            /* Do nothing */
        }
    }

    return retval;
}

/**
  * @brief  Get the clock source of fsys
  * @param  None
  * @retval Source of fsys
  *   The value returned can be one of the following values:
  *   CG_FSYS_SRC_FGEAR or CG_FSYS_SRC_FS
  */
CG_FsysSrc CG_GetFsysSrc(void)
{
    CG_FsysSrc fsyssrc = CG_FSYS_SRC_FGEAR;
    uint32_t tmp = TSB_CG->CKSEL;
    tmp &= CKSEL_SYSCKFLG_SET;
    
    if (tmp == 1U) {
        fsyssrc = CG_FSYS_SRC_FS;
    } else {
        /* Do nothing */
    }

    return fsyssrc;
}

/**
  * @brief  Setup the INT source for releasing low power mode.
  * @param  INTSource: Select the release INT source
  *   This parameter can be one of the following values:
  *   CG_INT_SRC_INTLVD, CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2,     
  *   CG_INT_SRC_3, CG_INT_SRC_RTC
  * @param  ActiveState: Select the active state for release trigger
  *   For INTRTC, only "FALLING" state can be set, no matter what the value of ActiveState is.
  *   For INTLVD, only "RISING" state can be set, no matter what the value of ActiveState is.
  *   Others  parameter can be one of the following values:
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
    CG_Byte4 regval[3] = { {0U}
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
        if(INTSource == CG_INT_SRC_INTLVD) {
          ActiveState = CG_INT_ACTIVE_STATE_RISING;
        }
        regval[0].byte[j] |= ActiveState;
        TSB_CG->IMCGA = regval[0].byte4;
        regval[0].byte[j] |= NewState;
        TSB_CG->IMCGA = regval[0].byte4;
        break;

    case 1U:                   /* IMCGB */
        regval[1].byte4 = TSB_CG->IMCGB;
        regval[1].byte[j] &= 0x8eU;
        if (INTSource == CG_INT_SRC_RTC) {
            ActiveState = CG_INT_ACTIVE_STATE_FALLING;
        }
        regval[1].byte[j] |= ActiveState;
        TSB_CG->IMCGB = regval[1].byte4;
        regval[1].byte[j] |= NewState;
        TSB_CG->IMCGB = regval[1].byte4;
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
  *   CG_INT_SRC_INTLVD, CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2,     
  *   CG_INT_SRC_3, CG_INT_SRC_RTC
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
    CG_Byte4 regval[2] = { {0U}
    , {0U}
    };

    /* Check the parameters */
    assert_param(IS_CG_INT_SRC(INTSource));

    regval[0].byte4 = TSB_CG->IMCGA;
    regval[1].byte4 = TSB_CG->IMCGB;

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
  *   CG_INT_SRC_INTLVD, CG_INT_SRC_0, CG_INT_SRC_1, CG_INT_SRC_2,     
  *   CG_INT_SRC_3,CG_INT_SRC_RTC
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
/* End of group TX00_Periph_Driver */
#endif                          /* defined(__TMPM061_CG_H)  */
