/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M2_D1_Pin GPIO_PIN_2
#define M2_D1_GPIO_Port GPIOA
#define M2_D2_Pin GPIO_PIN_3
#define M2_D2_GPIO_Port GPIOA
#define M1_D2_Pin GPIO_PIN_4
#define M1_D2_GPIO_Port GPIOA
#define M1_D1_Pin GPIO_PIN_5
#define M1_D1_GPIO_Port GPIOA
#define M3_D1_Pin GPIO_PIN_8
#define M3_D1_GPIO_Port GPIOE
#define M3_D2_Pin GPIO_PIN_10
#define M3_D2_GPIO_Port GPIOE
#define M1_PWM_Pin GPIO_PIN_12
#define M1_PWM_GPIO_Port GPIOD
#define M2_PWM_Pin GPIO_PIN_13
#define M2_PWM_GPIO_Port GPIOD
#define M3_PWM_Pin GPIO_PIN_14
#define M3_PWM_GPIO_Port GPIOD
#define BUZZER_Pin GPIO_PIN_4
#define BUZZER_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
