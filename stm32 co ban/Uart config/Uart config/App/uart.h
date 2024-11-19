#ifndef _UART_H
#define _UART_H

#include "stdint.h"
#include "stm32f1xx_hal.h"

void receive_data(uint8_t data_rx);
void uart_handle(void);
void uart_init(void);

#endif
