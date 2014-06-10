/**
 ******************************************************************************
 * @file:    startup.c
 * @purpose: functions definition of TMPM341 STARTUP demonstration
 * @version: V0.100
 * @date:    2011/03/10
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
 ******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "startup.h"

/**
  * @brief  Initial WDT function
  * @param  None.
  * @retval None.
  */
void WDT_init(void)
{
    WDT_InitTypeDef WDT_InitStruct;
    WDT_InitStruct.DetectTime = WDT_DETECT_TIME_EXP_25;
    WDT_InitStruct.OverflowOutput = WDT_NMIINT;

    WDT_Init(&WDT_InitStruct);
    WDT_Enable();
}

/**
  * @brief  Clear WDT counter
  * @param  None.
  * @retval None.
  */
void WDT_Clear(void)
{
    WDT_WriteClearCode();
}

/**
  * @brief  Initialize CG
  * @param  None.
  * @retval None.
  */
void CG_init(void)
{
    WorkState tmp = BUSY;

    /* check ofd reset */
    CG_ResetFlag resetFlag = { 0 };
    resetFlag = CG_GetResetFlag();
    while (resetFlag.Bit.OFDReset);

    /* Start external high-speed oscillation */
    CG_SetFosc(CG_FOSC_OSC_EXT, ENABLE);
    
    /* Set warm up time */
    CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_EXT, CG_WUODR_EXT);
    CG_StartWarmUp();

    do {
        tmp = CG_GetWarmUpState();
    } while (tmp != DONE);
}

/**
  * @brief  Initial OFD function
  * @param  None.
  * @retval initial result: SUCCESS or ERROR.
  */
Result OFD_init(void)
{
    OFD_Status status = { 0U };
    Result retval = ERROR;

    /* Disable OFD reset */
    OFD_SetRegWriteMode(ENABLE);
    OFD_Reset(DISABLE);

    /* Config the OFD parameter */
    OFD_SetDetectionFrequency(OFD_10M_HIGHER_COUNT, OFD_10M_LOWER_COUNT);
    
    /* Enable the OFD */
    OFD_Enable();
   
    do{
        /* Read the OFD work status */  
        status = OFD_GetStatus();
    }while(status.Bit.OFDBusy==0);

    if (status.Bit.FrequencyError == 0U) {
        OFD_Disable();
        /* Enable the OFD Reset */
        OFD_Reset(ENABLE);
        OFD_Enable();
        retval = SUCCESS;
        CG_SetFoscSrc(CG_FOSC_OSC_EXT);
    } else {
        /* Do Nothing */
    }

    return retval;
}

/*********************************** END OF FILE ******************************/
