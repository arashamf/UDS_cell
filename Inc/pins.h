#include "gpio.h"

#define LED_RED(x) ((x)? (HAL_GPIO_WritePin(GPIOA,LED_RED_Pin,GPIO_PIN_SET)) : (HAL_GPIO_WritePin(GPIOA,LED_RED_Pin,GPIO_PIN_RESET))); 
#define LED_GREEN(x) ((x)? (HAL_GPIO_WritePin(GPIOA,LED_GREEN_Pin,GPIO_PIN_SET)) : (HAL_GPIO_WritePin(GPIOA,LED_GREEN_Pin,GPIO_PIN_RESET))); 
#define DE(x) ((x)? (HAL_GPIO_WritePin(GPIOB,DE_Pin,GPIO_PIN_SET)) : (HAL_GPIO_WritePin(GPIOB,DE_Pin,GPIO_PIN_RESET))); 
#define RE(x) ((x)? (HAL_GPIO_WritePin(GPIOB,RE_Pin,GPIO_PIN_SET)) : (HAL_GPIO_WritePin(GPIOB,RE_Pin,GPIO_PIN_RESET))); 
#define RS485_TX DE(1);RE(1);
#define RS485_RX DE(0);RE(0);

//Adress switch
#define ADR1 HAL_GPIO_ReadPin(GPIOA,ADR1_Pin)
#define ADR2 HAL_GPIO_ReadPin(GPIOA,ADR2_Pin)
#define ADR3 HAL_GPIO_ReadPin(GPIOA,ADR3_Pin)
#define ADR4 HAL_GPIO_ReadPin(GPIOB,ADR4_Pin)
#define ADR5 HAL_GPIO_ReadPin(GPIOB,ADR5_Pin)
#define ADR6 HAL_GPIO_ReadPin(GPIOB,ADR6_Pin)
#define ADR7 HAL_GPIO_ReadPin(GPIOB,ADR7_Pin)
#define ADR8 HAL_GPIO_ReadPin(GPIOB,ADR8_Pin)

