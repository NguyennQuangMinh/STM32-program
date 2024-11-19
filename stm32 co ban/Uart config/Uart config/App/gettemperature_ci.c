#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\gettemperature_ci.h"
#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\response_ci.h"
#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\lm35.h"
#include "stdlib.h"

void gettemperature(char **argv, uint8_t argv_num)
{
	if(argv_num < 2)
	{
//		HAL_UART_Transmit(&huart1, "don't enough arg", 16, 1000);
		response_print("don't enough arg, arg = %d", argv_num);
		return;
	}
	if(argv_num > 2)
	{
//		HAL_UART_Transmit(&huart1, "don't enough arg", 16, 1000);
		response_print("too much arg, arg = %d", argv_num);
		return;
	}
//	uint8_t channel = atoi(argv[1]);
//	response_print("temp = %f", LM35_Gettemp(channel));
}
