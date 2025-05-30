/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define PIR_OUTPUT_Pin GPIO_PIN_13
#define PIR_OUTPUT_GPIO_Port GPIOC
#define COMM_MOTION_FLAG_Pin GPIO_PIN_0
#define COMM_MOTION_FLAG_GPIO_Port GPIOA
#define SERVO_PWM_Pin GPIO_PIN_1
#define SERVO_PWM_GPIO_Port GPIOA
#define SERIAL_TX_Pin GPIO_PIN_2
#define SERIAL_TX_GPIO_Port GPIOA
#define SERIAL_RX_Pin GPIO_PIN_3
#define SERIAL_RX_GPIO_Port GPIOA
#define MOTOR_DIR1_Pin GPIO_PIN_4
#define MOTOR_DIR1_GPIO_Port GPIOA
#define MOTOR_EN1_Pin GPIO_PIN_5
#define MOTOR_EN1_GPIO_Port GPIOA
#define MOTOR_DIR2_Pin GPIO_PIN_6
#define MOTOR_DIR2_GPIO_Port GPIOA
#define MOTOR_EN2_Pin GPIO_PIN_7
#define MOTOR_EN2_GPIO_Port GPIOA
#define COMM_MAN0_AUTO_ACK_Pin GPIO_PIN_0
#define COMM_MAN0_AUTO_ACK_GPIO_Port GPIOB
#define COMM_MAN1_Pin GPIO_PIN_1
#define COMM_MAN1_GPIO_Port GPIOB
#define COMMBUS_TX_Pin GPIO_PIN_10
#define COMMBUS_TX_GPIO_Port GPIOB
#define COMMBUS_RX_Pin GPIO_PIN_11
#define COMMBUS_RX_GPIO_Port GPIOB
#define COMM_AUTOMAN_STATE_Pin GPIO_PIN_12
#define COMM_AUTOMAN_STATE_GPIO_Port GPIOB
#define COMM_AUTO0_Pin GPIO_PIN_13
#define COMM_AUTO0_GPIO_Port GPIOB
#define COMM_AUTO1_Pin GPIO_PIN_14
#define COMM_AUTO1_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_15
#define BUZZER_GPIO_Port GPIOB
#define MOTOR_A_PWM_Pin GPIO_PIN_8
#define MOTOR_A_PWM_GPIO_Port GPIOA
#define MOTOR_B_PWM_Pin GPIO_PIN_9
#define MOTOR_B_PWM_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_10
#define LED_B_GPIO_Port GPIOA
#define LED_G_Pin GPIO_PIN_11
#define LED_G_GPIO_Port GPIOA
#define LED_R_Pin GPIO_PIN_12
#define LED_R_GPIO_Port GPIOA
#define COMM_HUM_FLAG_Pin GPIO_PIN_15
#define COMM_HUM_FLAG_GPIO_Port GPIOA
#define COMM_MAN2_Pin GPIO_PIN_3
#define COMM_MAN2_GPIO_Port GPIOB
#define ULTRASONIC_ECHO_Pin GPIO_PIN_4
#define ULTRASONIC_ECHO_GPIO_Port GPIOB
#define ULTRASONIC_TRIG_Pin GPIO_PIN_5
#define ULTRASONIC_TRIG_GPIO_Port GPIOB
#define GPS_TX_Pin GPIO_PIN_6
#define GPS_TX_GPIO_Port GPIOB
#define GPS_RX_Pin GPIO_PIN_7
#define GPS_RX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
