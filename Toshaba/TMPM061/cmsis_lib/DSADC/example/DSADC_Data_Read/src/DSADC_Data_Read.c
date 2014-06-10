/** 
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of DSADC_Data_Read demo for the TOSHIBA
 *          'TMPM061' Device Series 
 * @version V0.100
 * @date    2013/04/25
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */


#include "tmpm061_dsad.h"
#include "main.h"
#include <stdio.h>

void DSADC_Data_Read(void);

/*******************************************************************************
* Function Name  : Delay
* Description    : delay time module
* Input          : How many count of time to delay
* Return         : None.
*******************************************************************************/
void Delay(uint32_t data)
{
    volatile uint32_t wait_timecount = 0;
    /* wait for 1 ms*/
    wait_timecount = data*2000;
    for(;wait_timecount>0;wait_timecount--);
}

/**
  * @brief  The main routine of DSADC demo
  * @param  None
  * @retval None
  */
/*int main(void)*/
void DSADC_Data_Read(void)
{
    TSB_DSAD_TypeDef *DSADCx = TSB_DSAD0;
    DSADC_InitTypeDef  InitStruct;
    uint32_t    result = 0U;
	uint8_t i = 0U;
    TSB_DSAD_TypeDef*  t_DSADx[]={TSB_DSAD0,TSB_DSAD1,TSB_DSAD2};
    
    /* Initialize system */
    SIO_Configuration(UART_RETARGET);
    SIO_ChInit();

    /* enable retarget Channel TX interrupt */
    NVIC_EnableIRQ(RETARGET_INT);

    printf("--------------DSADC Demo------------\n\r");
  
    TSB_TEMP->EN = 0x03U;  /*Enable AMP and BGR at same time*/
    Delay(1U);
  
    for(i = 0U; i < (sizeof(t_DSADx)>>2U); ++ i){        /*initilize all DSADC channel*/
        DSADCx = t_DSADx[i];
        DSADC_SWReset(DSADCx);
        DSADC_SetClkSupply(DSADCx,ENABLE);          /*Clock feed to DSADC*/
        
        InitStruct.Clk = DSADC_FC_DIVIDE_LEVEL_1;
        InitStruct.BiasEn = ENABLE;
        InitStruct.ModulatorEn = ENABLE;
        InitStruct.SyncMode = DSADC_SYNC_MODE;      /*DSADC_SYNC_MODE;*/
        
        InitStruct.Repeatmode = DSADC_REPEAT_MODE;  /*Repeat mode*/
        InitStruct.Amplifier = DSADC_GAIN_8x;
        InitStruct.Offset = DSADC_GAIN_8x;
        InitStruct.CorrectEn = ENABLE;
        DSADC_Init(DSADCx,&InitStruct);
    }
    DSADC_Start(TSB_DSAD0);
    DSADC_Start(TSB_DSAD1);
    DSADC_Start(TSB_DSAD2);
    while(1U){
        Delay(1000);
        result = DSADC_GetConvertResult(TSB_DSAD0);
        printf("DSAD0: %d\r\n",result);
        
        Delay(1000);
        result = DSADC_GetConvertResult(TSB_DSAD1);
        printf("DSAD1: %d\r\n",result);
        Delay(1000);
        result = DSADC_GetConvertResult(TSB_DSAD2);
        printf("DSAD2: %d\r\n",result);      
  }
}

#ifdef DEBUG
/**
  * @brief  Deal with the error parameter
  * @param  file: Pointer to the file where the error parameter locates
  * @param  line: Number of the line in which the error parameter locates
  * @retval None
  */
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
