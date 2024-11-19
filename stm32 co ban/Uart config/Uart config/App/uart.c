#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\uart.h"
#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\gettemperature_ci.h"
#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\settemperature_ci.h"
#include "C:\hoc\stm32 turtorial\stm32 co ban\Uart config\Uart config\App\response_ci.h"
#include "string.h"

#define MAX_DATA_UART 100

static uint8_t uart_buff[MAX_DATA_UART];
static uint8_t uart_len;
uint8_t uart_flag = 0;

void receive_data(uint8_t data_rx)
{
	if( data_rx == '\n') // nhan xong
	{
		uart_flag = 1;
	}
	else // van dang nhan
	{
		uart_buff[uart_len++] = data_rx;
	}
}

void uart_handle()
{
	if(uart_flag)
	{
		uint8_t argv[10][20];
		uint8_t argv_num = 0;
		char *pch;
		pch = strtok((char *)uart_buff, " ");
		
		while(pch != NULL){
			strcpy((char *)argv[argv_num++], pch);
			pch = strtok(NULL, " ");
		}
		
//		for( uint8_t i =0 ; i<argv_num; i++) 
//		{
//			HAL_UART_Transmit(&huart1, argv[i], strlen((char *)argv[i]), 100 );
//			HAL_UART_Transmit(&huart1, (uint8_t *)"\n", 1, 100);
//		}
		
		if( strcmp((char *)argv[0], "gettemp") == 0)
		{
				gettemperature((char **) argv, argv_num);
		}
		
		else if( strcmp((char *)argv[0], "settempMax") == 0)
		{
				settemperatureMax((char **) argv, argv_num);
		}
		
		else if( strcmp((char *)argv[0], "settempMin") == 0)
		{
				settemperatureMin((char **) argv, argv_num);
		}
		
		uart_len = 0;
		uart_flag = 0;
	}

}

void uart_init()
{

}