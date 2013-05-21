/**
 *******************************************************************************
 * @file    DAC_Demo.c
 * @brief   the application functions of DAC demo for the TOSHIBA
 *          'TMPM369' Device Series 
 * @version V0.100
 * @date    2011/08/23
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
#include "tmpm369_dac.h"
#include "tmpm369_tmrb.h"


#define TMRB_DAC        0x5U

/*******************************************************************************
* Function Name  : DAC_Demo
* Description    : DAC_Demo function
* Input          : None.
* Return         : None.
*******************************************************************************/
void DAC_Demo(void)
{

    DAC_InitTypeDef InitStruct;
    TMRB_InitTypeDef m_tmrb;    
    /* DA0 Config */
    DAC_Start(TSB_DA0);

    InitStruct.DACClear = DAC_CLEAR;
    InitStruct.PostTime = 15U;
    InitStruct.PreTime = 8U;
 
    InitStruct.Offset = DAC_0DIV8_VDD;
    InitStruct.AmpSel = DAC_1DIV4_VDD;
    InitStruct.TrgSel = DAC_TRG_TMRB2;
    InitStruct.TrgFunc = DAC_TRG_ENABLE;
    InitStruct.DMAFunc = DAC_DMA_DISABLE;      
    InitStruct.Wave = DAC_TRIANGLE_WAVE;     
 
    DAC_Init(TSB_DA0, &InitStruct);
    DAC_SetOutputCode(TSB_DA0,0x3FFU); 

   	/*TMRB Config*/
    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.Cycle = TMRB_DAC;    
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.Duty = TMRB_DAC;     

    TMRB_Enable(TSB_TB2);
    TMRB_Init(TSB_TB2, &m_tmrb);
    NVIC_EnableIRQ(INTTB2_IRQn);
    TMRB_SetRunState(TSB_TB2, TMRB_RUN);
    
    while(1){

    }
}




