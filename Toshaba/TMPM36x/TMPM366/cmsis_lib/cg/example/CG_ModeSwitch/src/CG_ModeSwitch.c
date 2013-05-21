/**
 *******************************************************************************
 * @file    CG_ModeSwitch.c
 * @brief   the application functions of CG_ModeSwitch demo for the TOSHIBA
 *          'TMPM366' Device Series 
 * @version V0.100
 * @date    2011/03/03
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
#include "tmpm366_cg.h"
#include "tmpm366_gpio.h"
#include "tmpm366_uart.h"

//#include "LED.h"
/* Private typedef -----------------------------------------------------------*/
typedef enum { SLEEP = 0, WAKE = 1 } SYSSTAT;

/* Private define ------------------------------------------------------------*/
#define CG_WUODR_INT     ((uint16_t)0x9c40)
#define CG_WUODR_PLL     ((uint16_t)0x0960)
#define TSW_PORT        GPIO_PD
#define TSWBITS         0x02U
#define TSWRELEASE      0x02U      /* KEYRELEASE */
#define TSW1 0x00U

#define LED1 (1U<<0U)
#define LED2 (1U<<1U)
#define LED3 (1U<<2U)
#define LED4 (1U<<3U)
#define LED5 (1U<<4U)
#define LED6 (1U<<5U)
#define LED7 (1U<<6U)
#define LED8 (1U<<7U)

/* Global variables ----------------------------------------------------------*/
SYSSTAT fSysSleep = WAKE;

/* Private function prototypes -----------------------------------------------*/
void CG_NormalToStop1(void);
void CG_SetSystem(void);
void CG_NormalToStop1(void);
Result CG_EnableClkMulCircuit(void);
void SIO1_Configuration(void);
void UART_Print(char *string);
void GPIO_SetINT(void);
void INT0_IRQHandler(void);
void LedOff(uint8_t led);
void LedOn(uint8_t led);

void CG_ModeSwitch(void)
{
    uint8_t TSW_info = 0U;

    /* Initialize system */
    CG_SetSystem();
    GPIO_SetINT();
	
    GPIO_SetOutput(GPIO_PA,0xFFU);    
    GPIO_WriteData(GPIO_PA,0xFFU); 

    //UART_Print("TMPM366 CG_ModeSwitch DEMO\r\n");
	LedOn(LED1);
    while (1) {
        TSW_info = GPIO_ReadData(TSW_PORT) & TSWBITS;
        if (TSW_info == TSW1) {
            fSysSleep = SLEEP;
            //UART_Print("Now, Going to Sleep\r\n");
			LedOff(LED1);
            CG_NormalToStop1();

            /* Connect PG3 to VCC to recover from STOP mode */
			LedOn(LED1);
            fSysSleep = WAKE;
            NVIC_DisableIRQ(INT0_IRQn);
            UART_Print("Wakeup from Sleep\r\n");
        } else {
            /* Do nothing */
        }
    }

}


/**
  * @brief  Configure I/O ports for INT
  * @param  None
  * @retval None
  */
void GPIO_SetINT(void)
{
    //for INT0
    GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_3, DISABLE);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_1, GPIO_BIT_3);
    GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_3, ENABLE);

    //for SW1
    GPIO_SetOutputEnableReg(TSW_PORT, GPIO_BIT_1, DISABLE);
    GPIO_SetInputEnableReg(TSW_PORT, GPIO_BIT_1, ENABLE);
    GPIO_SetPullUp(TSW_PORT, GPIO_BIT_1, ENABLE);
}

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
    /* Set RMC wake up system */
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

        retval = CG_SetFcSrc(CG_FC_SRC_HALF_FPLL);
    } else {
        /*Do nothing */
    }

    return retval;
}

/**
  * @brief  SIO Configuration.
  * @param  SCx
  * @retval None
  */
void SIO1_Configuration()
{
	UART_InitTypeDef myUART;
	GPIO_SetOutputEnableReg(GPIO_PC, GPIO_BIT_0, ENABLE);
	GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_0);
	GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_1);
	GPIO_SetInputEnableReg(GPIO_PC, GPIO_BIT_1, ENABLE);
	GPIO_SetPullUp(GPIO_PC, GPIO_BIT_0, ENABLE);
	GPIO_SetPullUp(GPIO_PC, GPIO_BIT_1, ENABLE);

    /* configure SIO1 for reception */
    myUART.BaudRate = 115200;   /* baud rate = 115200 */
    myUART.DataBits = UART_DATA_BITS_8; /* no handshake, 8-bit data, clock by baud rate generator */
    myUART.StopBits = UART_STOP_BITS_1; /* 1-bit stop, LSB,  W-buff enable */
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;
	
    UART_Enable(UART1);
    UART_Init(UART1, &myUART);
}

void UART_Print(char *string)
{
	char *p = string;
	int i;
	while(*p)
	{
		UART_SetTxData(UART1, (uint32_t)(*p));
		p++;
		for(i = 0; i < 1000; i ++);
	}
}
/**
  * @brief  INT0_IRQHandler
  * @param  None
  * @retval None
  */
void INT0_IRQHandler(void)
{
    CG_ClearINTReq(CG_INT_SRC_0);
}

/*************************************************************************
 * Function Name: LedOff
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LedOff(uint8_t led)
{
    uint8_t reg;
    reg = GPIO_ReadData(GPIO_PA);
    reg &= (uint8_t)(~led);
    GPIO_WriteData(GPIO_PA,reg);
}

/*************************************************************************
 * Function Name: LedOn
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LedOn(uint8_t led)
{
    GPIO_WriteData(GPIO_PA,led);
}
