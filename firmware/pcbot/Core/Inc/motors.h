#ifndef INC_MOTORS_H
#define INC_MOTORS_H

#include "stm32g4xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

#define PWM_MAX   65535u

#define PWM_DEADBAND  2000u

void Motors_Init(void);

void Motor_A_Set(int32_t speed);

void Motor_B_Set(int32_t speed);

void set_motors(int32_t speedA, int32_t speedB);

void apply_motor_speeds(float vL, float vR);

void moteurs_legere_correction_droite(void);

void moteurs_legere_correction_gauche(void);

void moteurs_pivoter_droite(void);

void moteurs_pivoter_gauche(void);

void moteurs_stop(void);

#endif