#ifndef __SW_H
#define __SW_H

#include "TMPM373.h"
#include "tmpm373_gpio.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define SW0         0U
#define SW1         1U
#define SW2         2U
#define SW3         3U
#define SW4         4U
#define SW5         5U
#define SW6         6U
#define SW7         7U


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void SW_Init(void);
uint8_t SW_Get(uint8_t SW);

#endif                          /* SW_H */
