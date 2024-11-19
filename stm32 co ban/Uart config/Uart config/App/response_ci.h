#ifndef _RESPONSE_CI_H_
#define _RESPONSE_CI_H_

#include "stm32f1xx_hal.h"

void response_print(const char *str ,...);
void response_init(UART_HandleTypeDef *_huart_print);

#endif
