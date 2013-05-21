#ifndef __LED_H
#define __LED_H

#include "TMPM372.h"
#include "tmpm372_gpio.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define LED0     0x01U
#define LED1     0x02U
#define LED2     0x04U
#define LED3     0x08U
#define LED_ALL  0x0FU

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void LED_Init(void);
void LED_On(uint8_t led);
void LED_Off(uint8_t led);

#endif                          /* LED_H */
