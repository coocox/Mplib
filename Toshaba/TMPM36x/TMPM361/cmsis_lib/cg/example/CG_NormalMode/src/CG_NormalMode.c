/**
 *******************************************************************************
 * @file    CG_NormalMode.c
 * @brief   The demo functions of CG for the TOSHIBA 'TMPM363' Device Series 
 * @version V0.200
 * @date    2010/07/09
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

#include "tmpm361_cg.h"

#define C200US  0x0096U         /* @12M Oscillator */

Result CG_EnableClkMulCircuit(void);

void CG_NormalMode(void)
{
    /*SystemInit(); */
    /* Set CG Module  */
    /* set fgear = fc/2 */
    CG_SetFgearLevel(CG_DIVIDE_2);
    /* set fperi = fgear  fpreclk = fperi/32 */
#if defined (__TMPM361_CG_H)||defined(__TMPM362_CG_H)||defined(__TMPM363_CG_H)||defined(__TMPM363_CG_H)
    CG_SetPhiT0Src(CG_PHIT0_SRC_FPSCALER);
#endif
    CG_SetPhiT0Level(CG_DIVIDE_64);
    /* set SCOUT source to fT0 */
    CG_SetSCOUTSrc(CG_SCOUT_SRC_PHIT0);
    /* enable high-speed oscillation */
    CG_SetFosc(ENABLE);
    /* enable low-speed oscillation */
    CG_SetFs(ENABLE);
    /* set low power consumption mode sleep */
    CG_SetSTBYMode(CG_STBY_MODE_SLEEP);
    /* set high-speed and low-speed oscillation to be enabled after releasing stop mode */
    CG_SetExitStopModeFosc(ENABLE);
    CG_SetExitStopModeFs(ENABLE);
    /* set pin status in stop mode to "active" */
    CG_SetPinStateInStopMode(ENABLE);
    /*set up pll and wait 200us for pll to warm up , set fc source to fpll */
    CG_EnableClkMulCircuit();
    /* set system clock to fgear */
    CG_SetFsysSrc(CG_FSYS_SRC_FGEAR);

}

Result CG_EnableClkMulCircuit(void)
{

    Result retval = ERROR;
    WorkState st = BUSY;

    CG_SetClkMulTimes(CG_MUL_4TIMES);
    retval = CG_SetPLL(ENABLE);

    if (retval == SUCCESS) {
        /*set warm up time to about 200us */
        CG_SetWarmUpTime(CG_WARM_UP_SRC_X1, C200US);
        CG_StartWarmUp();
        /*wait warm up to end */
        do {
            st = CG_GetWarmUpState();
        } while (st != DONE);
        retval = CG_SetFcSrc(CG_FC_SRC_FPLL);

    } else {
        /*Do nothing */
    }
    return retval;
}
