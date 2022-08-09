#include "timer.h"
#include "pins.h"
#include "global.h"
#include "tim.h"
#include "adc.h"
#include "peripherals.h"
#include "show_errors.h"

int i=0;


//value - ms
void init_timer17(unsigned int value)
{
    // enable timer 17
    RCC->APB2ENR |= RCC_APB2ENR_TIM17EN;
    TIM17->PSC = SystemCoreClock /1000-1;  // for 1ms resolution
    TIM17->ARR = value;
    TIM17->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM17_IRQn); 
		NVIC_SetPriority(TIM17_IRQn, 1);
		TIM17->CR1 |= TIM_CR1_CEN;
}

//value - us
void init_timer14(unsigned int value)
{
    // enable timer 14
    RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
    TIM14->PSC = SystemCoreClock / 1000000-1;  // for 1us resolution
    TIM14->ARR = value;
    TIM14->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM14_IRQn); 
		NVIC_SetPriority(TIM14_IRQn, 1);
		TIM14->CR1 |= TIM_CR1_CEN;
}


void TIM14_IRQHandler(void) {	  
		TIM14->SR &= ~TIM_SR_UIF;	
}


//every 1 ms
void TIM17_IRQHandler(void) {
	
	TIM17->SR &= ~TIM_SR_UIF;	
	
	SetSolenoid();
	
	ReadButtons();
	
	CheckErrors();
	
	ShowErrors();
	
	//GREEN LED
	i++;
	if((i>0)&&(i<200)){LED_GREEN(1);return;}
	if((i>200)&&(i<400)&&(state_cell==1)){
		state_cell=0;
		LED_GREEN(0);
		return;
	}
	if(i==400){i=0;}
	
	//if(i==0){LED_GREEN(0);i=1;return;}
	//if(i==1){LED_GREEN(1);i=0;return;}
}


//Based on TIM16
 void delay_ms(uint16_t delay)
{
   RCC->APB2ENR |= RCC_APB2ENR_TIM16EN;
   TIM16->PSC = F_CPU/1000 - 1;
   TIM16->ARR = delay;
   TIM16->EGR |= TIM_EGR_UG;
   TIM16->CR1 |= TIM_CR1_OPM;
   TIM16->CR1 |= TIM_CR1_CEN;
   while (TIM16->CR1&TIM_CR1_CEN);
}
 
void delay_us(uint16_t delay)
{
   RCC->APB2ENR |= RCC_APB2ENR_TIM16EN;
   TIM16->PSC = F_CPU/1000000 - 1;
   TIM16->ARR = delay;
   TIM16->EGR |= TIM_EGR_UG;
   TIM16->CR1 |= TIM_CR1_OPM;
   TIM16->CR1 |= TIM_CR1_CEN;
   while (TIM16->CR1&TIM_CR1_CEN);   
}
 

