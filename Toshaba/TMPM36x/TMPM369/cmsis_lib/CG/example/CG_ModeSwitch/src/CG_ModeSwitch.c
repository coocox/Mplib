/**
 *******************************************************************************
 * @file    CG_ModeSwitch.c
 * @brief   the application functions of CG_ModeSwitch demo for the TOSHIBA
 *          'TMPM369' Device Series 
 * @version V0.100
 * @date    2011/09/14
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
#include "TMPM369.h"
#include "tmpm369_gpio.h"
#include "tmpm369_cg.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define NORMAL_MODE             ((uint8_t)0x00)
#define STOP_MODE               ((uint8_t)0x01)



#define SW0         0U
#define SW1         1U
#define SW2         2U
#define SW3         3U
#define SW4         4U
#define SW5         5U
#define SW6         6U
#define SW7         7U

#define LED0     0x01U
#define LED1     0x02U
#define LED2     0x04U
#define LED3     0x08U
#define LED_ALL  0x0FU

#define ON  1
#define OFF 0

#define LCD_COMMAND    0
#define LCD_CHARACTER  1

#define LCD_LINE_SIZE 16

#define LCD_DATA    (TSB_PD->DATA)
#define LCDE        (TSB_PJ_DATA_PJ5)
#define LCDRW       (TSB_PJ_DATA_PJ6)
#define LCDRS       (TSB_PJ_DATA_PJ7)

#define LCD_WRITE   0UL
#define LCD_READ    1UL


#define   CLR_DISP      0x00000001
#define   DISP          0x00000008
#define   DISP_ON       0x0000000C
#define   DISP_CUR      0x0000000E
#define   DISP_BINK_CUR 0x0000000F
#define   DISP_OFF      DISP
#define   CUR_HOME      0x00000002
#define   SCUR_OFF      DISP_ON
#define	  CUR_UNDER     DISP_CUR
#define   CUR_BLINK     DISP_BINK_CUR
#define   CUR_LEFT      0x00000010
#define   CUR_RIGHT     0x00000014
#define   FIRST_LINE    0x00000080
#define   SECOND_LINE   0x000000C0

#define FUNCTION_SET    0x20
#define CONFIG_8BIT_BUS 0x10    /* 8 bit bus */
#define CONFIG_2_LINES  0x08    /* 2 lines display */
#define CONFIG_1_LINE   0x00    /* 1 lines display */
#define CONFIG_5X10_DOT 0x04    /* 5*10 dot char font*/
#define CONFIG_5X7_DOT  0x00    /* 5*7 dot char font*/
#define ENTRY_MODE_SET  0x06

#define CG_WUODR_EXT     ((uint16_t)0x09C4)
#define CG_WUODR_PLL     ((uint16_t)0x09C4)


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
uint8_t gCurrentMode = NORMAL_MODE;

/* external variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Mode_Judgement(void);
void System_Init(void);
void SW_Init(void);
uint8_t SW_Get(uint8_t SW);
void LED_Init(void);
void LED_On(uint8_t led);
void LED_Off(uint8_t led);
void Send_To_LCD(unsigned char data, unsigned char type);
void Send_LCD_Text(char *str);
void LCD_Configuration(void);
void Delay(uint32_t time);
void CG_NormalToStop(void);
void CG_SetSystem(void);
Result CG_EnableClkMulCircuit(void);

/* Main function */
void CG_ModeSwitch(void)
{
    System_Init();

    /* Disable interrupts */
    __disable_irq();
    CG_ClearINTReq(CG_INT_SRC_9);
    /* Set external interrupt to wake up system */
    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_9, CG_INT_ACTIVE_STATE_FALLING, ENABLE);
    NVIC_ClearPendingIRQ(INT9_IRQn);
    NVIC_EnableIRQ(INT9_IRQn);
    __enable_irq();

    /* Initialize Variables */
    gCurrentMode = NORMAL_MODE;

    while (1) {
        Mode_Judgement();  /* Push SW1 to change Mode */

        switch(gCurrentMode) {
        case NORMAL_MODE:
            LED_On(LED_ALL);
            Send_To_LCD(FIRST_LINE, LCD_COMMAND);
            Send_LCD_Text("NORMAL MODE");
            break;
        case STOP_MODE:
            LED_Off(LED_ALL);
            Send_To_LCD(FIRST_LINE, LCD_COMMAND);
            Send_LCD_Text("STOP MODE");
            CG_NormalToStop();
            System_Init();
            gCurrentMode = NORMAL_MODE;
            break;
        default:
            gCurrentMode = NORMAL_MODE;
            break;
        }
    }
}

/**
  * @brief  Judge whether go to STOP_MODE
  * @param  None.
  * @retval None.
  */
void Mode_Judgement(void)
{
    uint8_t SW1_info = 0U; 
    SW1_info = SW_Get(SW1);

    if ((1U == SW1_info) && (gCurrentMode == NORMAL_MODE)) {
        gCurrentMode = STOP_MODE;
    } else {
        /* Do nothing */
    }
}

/**
  * @brief  Initialize system
  * @param  None.
  * @retval None.
  */
void System_Init(void)
{
    /* Initialize system */
    CG_SetSystem();

    /* Configure GPIO */
    GPIO_SetInput(GPIO_PI, GPIO_BIT_0);    /* Set port E pin6 to input */
    GPIO_EnableFuncReg(GPIO_PI, GPIO_FUNC_REG_1, GPIO_BIT_0);    /* Set port E pin6 for INT9 */
    GPIO_SetInput(GPIO_PI, GPIO_BIT_1);    /* Set port E pin7 to input */
    /* Configure GPIO to LED */
    LED_Init();
    LCD_Configuration();
}

/*******************************************************************************
* Function Name  : SW_Init
* Description    : Initialize the GPIO to SW 
* Input          : None 
* Return         : None.
*******************************************************************************/
void SW_Init(void)
{
    GPIO_SetInput(GPIO_PI, GPIO_BIT_0);
    GPIO_SetInput(GPIO_PI, GPIO_BIT_1);
    GPIO_SetInput(GPIO_PI, GPIO_BIT_2);
    GPIO_SetInput(GPIO_PI, GPIO_BIT_3);
    
    GPIO_SetOutput(GPIO_PJ, GPIO_BIT_2);
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
    		GPIO_WriteDataBit(GPIO_PJ, GPIO_BIT_2, GPIO_BIT_VALUE_0);
    	}else{
    		GPIO_WriteDataBit(GPIO_PJ, GPIO_BIT_2, GPIO_BIT_VALUE_1);
    	}
    switch (sw) {
    case SW0:
    case SW4:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_0) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW1:
    case SW5:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_1) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW2:
    case SW6:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_2) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW3:
    case SW7:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_3) == 1U) {
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

/*************************************************************************
 * Function Name: LED_Init
 * Parameters:None
 *
 * Return:None  
 *
 * Description: Init LED ports
 *
 *************************************************************************/
void LED_Init(void)
{
	/*Set PC bit0~3 output and turn off all leds*/
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_0);
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_1);
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_2);
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_3);

    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_0, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_1, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_2, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_3, GPIO_BIT_VALUE_0);
}

/*************************************************************************
 * Function Name: LED_On
 * Parameters:LED number, choose from LED0, LED1, LED2, LED3 or LED_ALL.
 *
 * Return:None  
 *
 * Description: The choosen Led is ON.
 *
 *************************************************************************/

void LED_On(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(GPIO_PC);
    tmp |= led;
    GPIO_WriteData(GPIO_PC, tmp);
}

/*************************************************************************
 * Function Name: LED_Off
 * Parameters:LED number, choose from LED0, LED1, LED2, LED3 or LED_ALL.
 *
 * Return:None  
 *
 * Description: The choosen Led is Off.
 *
 *************************************************************************/
void LED_Off(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(GPIO_PC);
    tmp &= (uint8_t) (~led);
    GPIO_WriteData(GPIO_PC, tmp);
}

/*******************************************************************************
* Function Name  : E_Pulse
* Description    : Generation a pulse enable the LCD.
* Input          : None.
* Return         : None.
*******************************************************************************/
void E_Pulse(void)
{
    // set E high
    LCDE = 1;
    Delay(20);
    // set E low
    LCDE = 0;
    Delay(20);
}

/*******************************************************************************
* Function Name  : Set_Data
* Description    : transfer data to LCD
* Input          : data --- The data will transfer to LCD
* Return         : None.
*******************************************************************************/
void Set_Data(unsigned char data)
{
    LCD_DATA = data;  
}

/*******************************************************************************
* Function Name  : Send_To_LCD
* Description    : send command or data to LCD
* Input          : data --- command or data
*                  type --- LCD_COMMAND or LCD_CHARACTER
* Return         : None.
*******************************************************************************/
void Send_To_LCD(unsigned char data, unsigned char type)
{  
    // enable write
    LCDRW = LCD_WRITE;
    Delay(20);
    Set_Data(data);
    // set RS port to set command mode or data
    if (type == LCD_COMMAND)
      LCDRS = 0;
    else
      LCDRS = 1;
    E_Pulse();
}

/*******************************************************************************
* Function Name  : Send_LCD_Text
* Description    : Send the string to LCD
* Input          : str --- pointer of the string
* Return         : None.
*******************************************************************************/
void Send_LCD_Text(char *str)
{
    unsigned char i;
    
    //Send_To_LCD(CUR_HOME,LCD_COMMAND);
    //Delay(1520);
    
    /* loop over string and send each character */
    for (i = 0; i < strlen(str); i++) {
        Send_To_LCD(str[i], LCD_CHARACTER);
    }
    for (; i < 16; i++)
        Send_To_LCD(' ', LCD_CHARACTER);
}

/*******************************************************************************
* Function Name  : LCD_IO
* Description    : Config LCD to IO
* Input          : data --- The data will transfer to LCD
* Return         : None.
*******************************************************************************/

void LCD_IO(void)
{
    TSB_PD->CR = (uint32_t)0xFF;
    TSB_PD->PUP = (uint32_t)0xFF;
    TSB_PJ->CR |= (uint32_t)0xE0;
    TSB_PJ->PUP |= (uint32_t)0xE0;  
   
}

/*******************************************************************************
* Function Name  : LCD_Configuration
* Description    : Configures LCD
* Input          : None.
* Return         : None.
*******************************************************************************/
void LCD_Configuration(void)
{
    LCD_IO();

    LCDE = 0;
    LCDRW = 0;
    LCDRS = 0;

    Send_To_LCD(FUNCTION_SET|CONFIG_8BIT_BUS,LCD_COMMAND);
    
    Send_To_LCD(FUNCTION_SET|CONFIG_8BIT_BUS,LCD_COMMAND);
    
    Send_To_LCD(FUNCTION_SET|CONFIG_8BIT_BUS,LCD_COMMAND);
    
    Send_To_LCD(FUNCTION_SET|CONFIG_8BIT_BUS|CONFIG_2_LINES|CONFIG_5X7_DOT,LCD_COMMAND);

    // enable display
    Send_To_LCD(DISP_ON, LCD_COMMAND);
    
    // clear display
    Send_To_LCD(CLR_DISP, LCD_COMMAND);
    Delay(3000);
}

void Delay(uint32_t time)   
{
    volatile uint32_t i = 0;

    for (i = 0; i < time*10U; ++i);
}

/* CG_SetSystem */
void CG_SetSystem(void)
{
    /* Set fgear = fc/2 */
    CG_SetFgearLevel(CG_DIVIDE_2);
    /* Set fperiph to fgear */
    CG_SetPhiT0Src(CG_PHIT0_SRC_FGEAR);
    CG_SetPhiT0Level(CG_DIVIDE_64);
    /* Enable high-speed oscillator */
    CG_SetFosc(CG_FOSC_OSC_EXT,ENABLE);
    /* select external oscillator */
    CG_SetFoscSrc(CG_FOSC_OSC_EXT);
    /* Set low power consumption mode stop */
    CG_SetSTBYMode(CG_STBY_MODE_STOP1);
    /* Set pin status in stop mode to "active" */
    CG_SetPinStateInStop1Mode(ENABLE);
    /* Set up pll and wait for pll to warm up, set fc source to fpll */
    CG_EnableClkMulCircuit();
}

/* CG_NormalToStop */
void CG_NormalToStop(void)
{
    /* Set CG module: Normal ->Stop mode */
    CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_INT_HIGH,CG_WUODR_EXT);
    /* Enter stop mode */
    __WFI();
}

/* CG_EnableClkMulCircuit */
Result CG_EnableClkMulCircuit(void)
{
    Result retval = ERROR;
    WorkState st = BUSY;
    CG_SetPLL(DISABLE);
    CG_SetFPLLValue(CG_FPLL_16M_MULTIPLY_5);
    retval = CG_SetPLL(ENABLE);
    if (retval == SUCCESS) {
        /* Set warm up time */
        CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_EXT_HIGH,CG_WUODR_PLL);
        CG_StartWarmUp();

        do {
            st = CG_GetWarmUpState();
        } while (st != DONE);

        retval = CG_SetFcSrc(CG_FC_SRC_FPLL);
    } else {
        /*Do nothing */
    }

    return retval;
}



/*********************************** END OF FILE ******************************/
