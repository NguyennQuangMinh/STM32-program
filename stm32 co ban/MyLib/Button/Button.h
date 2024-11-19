#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "main.h"

typedef struct
{
	uint8_t btn_current;
	uint8_t btn_last;
	uint8_t btn_filter;
	uint8_t is_debouncing; 		//bien co
	uint8_t is_press_timeout; // bien co nhan giu nut nhan
	
	uint32_t time_debounce;
	uint32_t time_start_press;

	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_PIN;
}Button_Typedef;

void button_handle(Button_Typedef *ButtonX);
void Button_Init(Button_Typedef *ButtonX, GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);

#endif