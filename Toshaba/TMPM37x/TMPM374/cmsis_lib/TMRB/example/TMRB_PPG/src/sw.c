/* Includes ------------------------------------------------------------------*/
#include "sw.h"

/*******************************************************************************
* Function Name  : SW_Init
* Description    : Initialize the GPIO to SW 
* Input          : None 
* Return         : None.
*******************************************************************************/
void SW_Init(void)
{
    GPIO_SetInput(GPIO_PE, GPIO_BIT_6 | GPIO_BIT_7);
    GPIO_SetInput(GPIO_PJ, GPIO_BIT_6 | GPIO_BIT_7);
    GPIO_SetOutput(GPIO_PK, GPIO_BIT_0);
}

/*******************************************************************************
* Function Name  : SW_Get
* Description    : Get SW Value
* Input          : SW (choose from SW0 ~ SW7).
* Return         : SW value.
*******************************************************************************/
uint8_t SW_Get(uint8_t sw)
{
    uint8_t tmp = 0U;
    if (sw < 4 )
    	{
    		GPIO_WriteDataBit(GPIO_PK, GPIO_BIT_0, GPIO_BIT_VALUE_0);
    	}else{
    		GPIO_WriteDataBit(GPIO_PK, GPIO_BIT_0, GPIO_BIT_VALUE_1);
    	}
    switch (sw) {
    case SW0:
    case SW4:
        if (GPIO_ReadDataBit(GPIO_PE, GPIO_BIT_6) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW1:
    case SW5:
        if (GPIO_ReadDataBit(GPIO_PE, GPIO_BIT_7) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW2:
    case SW6:
        if (GPIO_ReadDataBit(GPIO_PJ, GPIO_BIT_6) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW3:
    case SW7:
        if (GPIO_ReadDataBit(GPIO_PJ, GPIO_BIT_7) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    default:
        break;
    }
    return tmp;

}
