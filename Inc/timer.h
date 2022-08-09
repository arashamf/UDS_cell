//#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
//#include "stm32f030x6.h"
//#include "stm32f0xx_it.h"
//#include "stm32f0xx_hal_tim.h"

#define F_CPU 48000000

void init_timer17(unsigned int value);
void init_timer14(unsigned int value);
void delay_ms(uint16_t delay);
void delay_us(uint16_t delay);
