#include "C:\hoc\stm32 turtorial\stm32 co ban\MyLib\Servo\servo.h"

#define MIN_PULSEN_WIDTH 1000
#define MAX_PULSEN_WIDTH 2000

uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
// doc goc quay
uint8_t servo_read(SERVO *sv)
{
	return sv->angle;
}
// cai dat goc quay
// 0->180: 
void servo_write(SERVO *sv, uint8_t angle)
{
	uint16_t ccr = map(angle, 0, 180, MIN_PULSEN_WIDTH, MAX_PULSEN_WIDTH);
	sv->angle = angle;
	switch(sv->channel)
	{
		case TIM_CHANNEL_1:
			sv->htim->Instance->CCR1 = ccr;
			break;
		case TIM_CHANNEL_2:
			sv->htim->Instance->CCR2 = ccr;
			break;
		case TIM_CHANNEL_3:
			sv->htim->Instance->CCR3 = ccr;
			break;
		case TIM_CHANNEL_4:
			sv->htim->Instance->CCR4 = ccr;
			break;
	}
}
void servo_init(SERVO *sv, TIM_HandleTypeDef *htim, uint16_t channel)
{
	sv->htim = htim;
	sv->channel = channel;
	sv->angle = 0;
	
	//cau hinh timer
	htim->Instance->PSC = 63;
	htim->Instance->ARR = 19999;
	HAL_TIM_PWM_Start(htim, channel);
}