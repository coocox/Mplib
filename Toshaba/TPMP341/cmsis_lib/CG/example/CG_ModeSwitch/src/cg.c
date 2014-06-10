/**
 *******************************************************************************
 * @file    cg.c
 * @brief   The driver functions of CG for the TOSHIBA 'TMPM341' Device Series 
 * @version V0.101
 * @date    2011/02/17
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
#include "cg.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define CG_WUODR_EXT     ((uint16_t)0x0FFF)
#define CG_WUODR_INT     ((uint16_t)0x07D0)
#define CG_WUODR_PLL     ((uint16_t)0x01F4)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
Result CG_EnableClkMulCircuit(void);
/* Private functions ---------------------------------------------------------*/

/* CG_SetSystem */
void CG_SetSystem(void)
{
    /* Set fgear = fc/2 */
    CG_SetFgearLevel(CG_DIVIDE_2);
    /* Set fperiph to fgear */
    CG_SetPhiT0Src(CG_PHIT0_SRC_FGEAR);
    CG_SetPhiT0Level(CG_DIVIDE_64);
    /* Set SCOUT source */
    CG_SetSCOUTSrc(CG_SCOUT_SRC_PHIT0);
    /* Enable high-speed oscillator */
    CG_SetFosc(CG_FOSC_OSC_EXT, ENABLE);
    /* Set fosc source */
    CG_SetFoscSrc(CG_FOSC_OSC_EXT);
    /* Set low power consumption mode stop1 */
    CG_SetSTBYMode(CG_STBY_MODE_STOP1);
    /* Set pin status in stop mode to "active" */
    CG_SetPinStateInStop1Mode(ENABLE);
    /* Set up pll and wait 200us for pll to warm up , set fc source to fpll */
    CG_EnableClkMulCircuit();
}

/* CG_NormalToStop1 */
void CG_NormalToStop1(void)
{
    /* Set CG module: Normal ->STOP1 mode */
    /* after exiting STOP mode, internal oscillator starts up */
    CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_INT, CG_WUODR_INT);
    /* Set INT0 to release standby mode */
    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_0, CG_INT_ACTIVE_STATE_H, ENABLE);

    /* Disable interrupts */
    __disable_irq();
    NVIC_ClearPendingIRQ(INT0_IRQn);
    NVIC_EnableIRQ(INT0_IRQn);
    CG_ClearINTReq(CG_INT_SRC_0);
    __enable_irq();

    __DSB();
    /* Enter stop1 mode */
    __WFI();

}

/* CG_EnableClkMulCircuit */
Result CG_EnableClkMulCircuit(void)
{
    Result retval = ERROR;
    WorkState st = BUSY;
    CG_SetPLL(DISABLE);
    CG_SetFPLLValue(CG_FPLL_MULTIPLY_8);
    retval = CG_SetPLL(ENABLE);
    if (retval == SUCCESS) {
        /* Set warm up time */
        CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_EXT, CG_WUODR_PLL);
        CG_StartWarmUp();

        do {
            st = CG_GetWarmUpState();
        } while (st != DONE);

        retval = CG_SetFcSrc(CG_FC_SRC_QUARTER_FPLL);
    } else {
        /*Do nothing */
    }

    return retval;
}

/*********************************** END OF FILE ******************************/
