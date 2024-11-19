#ifndef _SERVO_H_
#define _SERVO_H_

#include "stm32f1xx_hal.h"

typedef struct
{
	TIM_HandleTypeDef *htim;
	uint16_t channel;
	uint8_t angle;
}SERVO;


void servo_write(SERVO *sv, uint8_t angle);
void servo_init(SERVO *sv, TIM_HandleTypeDef *htim, uint16_t channel);

#endif