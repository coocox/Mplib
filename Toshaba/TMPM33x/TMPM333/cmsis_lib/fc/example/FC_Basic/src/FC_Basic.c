 /**
 *******************************************************************************
 * @file    FC_Basic.c
 * @brief   The demo functions of FC for the 
 *          TOSHIBA 'TMPM333' Device Series.
 * @version V0.200
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

#include "tmpm333_fc.h"

void FC_Basic(void)
{
    FunctionalState tmp_value_sec0, tmp_value_sec1, tmp_value_block;
    int ret_0 = 0U, ret_1 = 0U;
    TSB_WD_MOD_WDTE = 0U;
    TSB_WD->CR = 0x000000B1;

    while (1) {
        /* Set security function "ENABLE" */
        FC_SetSecurityBit(ENABLE);

        /* Get security register value */
        tmp_value_sec0 = FC_GetSecurityBit();
        if (tmp_value_sec0 != ENABLE) {
            ret_0 = 1U;
        }

        /* Set security function "DISABLE" */
        FC_SetSecurityBit(DISABLE);

        /* Get security register value */
        tmp_value_sec1 = FC_GetSecurityBit();
        if (tmp_value_sec1 != DISABLE) {
            ret_1 = 1U;
        }

        /* Get Block 0 Protection status */
        tmp_value_block = FC_GetBlockProtectState(FC_BLOCK_0);

        /* Wait for Ready */
        while (FC_GetBusyState() != DONE) {
        /* Do nothing */
        };
    }
}

