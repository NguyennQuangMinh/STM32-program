#include "Button.h"
#include "main.h"


// su kien nut nhan
__weak void btn_pressing_callback(Button_Typedef *ButtonX)
{
}

// su kien nut nhan nhanh
__weak void btn_press_short_callback(Button_Typedef *ButtonX)
{
}

// su kien giu nut nhan
__weak void btn_press_timeout_callback(Button_Typedef *ButtonX)
{
}

// su kien nha nut nhan
__weak void btn_release_callback(Button_Typedef *ButtonX)
{
}

// ham xu ly su kien nut nhan
void button_handle(Button_Typedef *ButtonX)
{
	uint8_t sta = HAL_GPIO_ReadPin(ButtonX->GPIOx, ButtonX->GPIO_PIN);
	//-------------Xu ly nhieu--------------
	if(sta != ButtonX->btn_filter)
	{
		ButtonX->btn_filter = sta;
		ButtonX->is_debouncing = 1;
		ButtonX->time_debounce = HAL_GetTick();	
	}
	//-----------xac nhan bam nut-------------
	if(ButtonX->is_debouncing && (HAL_GetTick() - ButtonX->time_debounce >= 15))
	{
		ButtonX->btn_current = ButtonX->btn_filter;
		ButtonX->is_debouncing = 0;
	}
	//----------Xu ly cac su kien nut nhan---------------
	if(ButtonX->btn_current != ButtonX->btn_last )
	{
		if(ButtonX->btn_current == 0) // nhan nut
		{
			ButtonX->is_press_timeout = 1;
			btn_pressing_callback(ButtonX);
			ButtonX->time_start_press = HAL_GetTick();
		}
		else	// nha nut
		{
			if(HAL_GetTick() - ButtonX->time_start_press <= 1000)
			{
				btn_press_short_callback(ButtonX);
			}
			btn_release_callback(ButtonX);
		}
		ButtonX->is_press_timeout = 0;
		ButtonX->btn_last = ButtonX->btn_current;
	}
	//-------------Nhan giu--------------
	if(ButtonX->is_press_timeout && (HAL_GetTick()-ButtonX->time_start_press > 5000))
	{
		btn_press_timeout_callback(ButtonX);
		ButtonX->is_press_timeout = 0;
	}
}

void Button_Init(Button_Typedef *ButtonX, GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
	ButtonX->GPIOx = GPIOx;
	ButtonX->GPIO_PIN= GPIO_PIN;
}
