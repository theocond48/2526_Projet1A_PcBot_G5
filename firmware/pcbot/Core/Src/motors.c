#include "motors.h"
#include "main.h"
#include "IMU.h"
#include "AsserAndOther.h"

#define CORRECTION
#define PIVOT

//1.Écriture du registre CCR 
//Moteur A- AIN1 : TIM2 channel 3
static inline void _set_AIN1(uint32_t duty)
{
    __HAL_TIM_SET_COMPARE( &htim2, TIM_CHANNEL_3, duty);
}

//Moteur A- AIN2 : TIM1 channel 3
static inline void _set_AIN2 (uint32_t duty)
{
    __HAL_TIM_SET_COMPARE( &htim1, TIM_CHANNEL_3, duty);
}

//Moteur B- BIN1 : TIM1 channel 2
static inline void _set_BIN1(uint32_t duty)
{
    __HAL_TIM_SET_COMPARE( &htim1, TIM_CHANNEL_2, duty);
}

//Moteur B- BIN2 : TIM1 channel 1 
static inline void _set_BIN2( uint32_t duty)
{
    __HAL_TIM_SET_COMPARE( &htim1, TIM_CHANNEL_1, duty);
}

//2. Motors_Init
void Motors_Init(void)
{
    //2.1. Démarrer TIM2 CH3 → AIN1
    HAL_TIM_PWM_Start( &htim2, TIM_CHANNEL_3);

    //2.2. Démarrer TIM1 CH3 → AIN2
    HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3)

    //2.3. Démarrer TIM1 CH2N → BIN1 
    HAL_TIMEx_PWMN_Start (&htim1, TIM_CHANNEL_2);

    //2.4. Démarrer TIM1 CH1N → BIN2
    HAL_TIMEx_PWMN_Start (&htim1, TIM_CHANNEL_1);

    //2.5. Tout à 0 au démarrage
    _set_AIN1(0); _set_AIN2(0);
    _set_BIN1(0); _set_BIN2(0);
}

//3. Motor_A_Set (roue gauche)

void Motor_A_Set(int32_t speed)
{
    //Saturation
    if (speed> (int32_t)PWM_MAX) speed = (int32_t)PWM_MAX;
    if (speed < -(int32_t)PWM_MAX) speed = -(int32_t)PWM_MAX;

    //Zone morte : en dessous de seuil les moteurs ne tournent pas 

    if ( speed > 0 && speed < (int32_t)PWM_DEADBAND) speed 0;
    if ( speed > 0 && speed > -(int32_t)PWM_DEADBAND) speed 0;

    if (speed>0)
    {
        //Avant
        _set_AIN1((uint32_t)speed);
        _set_AIN2(0u);
    }
    else if (speed<0)
    {
        //Arrière 
        _set_AIN1(0u);
        _set_AIN2 ((uint32_t)(-speed));    
    }
    else 
    {
        //Coast
        _set_AIN1(0u);
        _set_AIN2(0u);
    }
}

// 4. Motot_B_Set (roue droite)

void Motor_B_set(int32_t speed)
{
    //Saturation
    if (speed> (int32_t)PWM_MAX) speed= (int32_t)PWM_MAX;
    if (speed < -(int32_t)PWM_MAX) speed= -(int32_t)PWM_MAX;

    //Zone morte 
    if( speed>0 && speed< (int32_t)PWM_DEADBAND) speed 0;
    if ( speed >0 && speed > -(int32_t)PWM_DEADBAND) speed 0;

    if (speed>0)
    {
        //Avant
        _set_BIN1 ((uint32_t)speed);
        _set_BIN2 (0u);
    }
    else if ( speed<0)
    {
        //Arrière
        _set_BIN1(0u):
        _set_BIN2((uint32_t)(-speed));
    }
    else{
        //Coast
        _set_BIN1(0u);
        _set_BIN2(0u);
    }
}

void set_motors(int32_t speedA, int32_t speedB)
{
    Motor_A_Set ( speedA);
    Motor_B_Set (speedB);
}

void apply_motor_speeds(float vL, float vR)
{
    //Saturation flottante
    if( vL> 1.0f) vL= 1.0f;
    if (vL< -1.0f) vL=-1.0f;
    if ( vR> 1.0f) vR= 1.0f;
    if ( vR< -1.0f) vR=-1.0f;

    //Conversion en ticks MPWM
    int32_t pwmL = (int32_t) (vL * (float)PWM_MAX) ;
    int32_t pwmR = (int32_t) (vR* (float)PWM_MAX);

    Motor_A_Set(pwmL);
    Motor_B_Set (pwmR);
}
void moteurs_legere_correction_droite(void){
    apply_motor_speeds(vRobot+ CORRECTION,vRobot- CORRECTION)
}
void moteurs_legere_correction_gauche(void){
    apply_motor_speeds(vRobot-CORRECTION,vRobot +CORRECTION )
}