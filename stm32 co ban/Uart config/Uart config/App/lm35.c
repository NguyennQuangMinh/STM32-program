#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\lm35.h"

float LM35_Gettemp(uint8_t channel)
{
	float temp = 10.5;
	if(channel == 0)
	{
		temp = 20.5;
	}
	if(channel == 1){ temp = 50.2; }
	
	return temp;
}
