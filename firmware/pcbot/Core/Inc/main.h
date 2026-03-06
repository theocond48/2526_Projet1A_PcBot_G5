/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CE_NRF_Pin GPIO_PIN_0
#define CE_NRF_GPIO_Port GPIOA
#define INT_BMS_Pin GPIO_PIN_1
#define INT_BMS_GPIO_Port GPIOA
#define OTG_BMS_Pin GPIO_PIN_2
#define OTG_BMS_GPIO_Port GPIOA
#define CE_BMS_Pin GPIO_PIN_3
#define CE_BMS_GPIO_Port GPIOA
#define IRQ_NRF_Pin GPIO_PIN_4
#define IRQ_NRF_GPIO_Port GPIOA
#define IMU_INT1_Pin GPIO_PIN_0
#define IMU_INT1_GPIO_Port GPIOB
#define MOT_AIN1_Pin GPIO_PIN_8
#define MOT_AIN1_GPIO_Port GPIOA
#define MOT_BIN1_Pin GPIO_PIN_9
#define MOT_BIN1_GPIO_Port GPIOA
#define MOT_AIN2_Pin GPIO_PIN_11
#define MOT_AIN2_GPIO_Port GPIOA
#define MOT_BIN2_Pin GPIO_PIN_12
#define MOT_BIN2_GPIO_Port GPIOA
#define CSN_NRF_Pin GPIO_PIN_3
#define CSN_NRF_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
