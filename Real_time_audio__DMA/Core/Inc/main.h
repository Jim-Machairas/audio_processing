/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <codec_registers.h>
#include <codec_hal.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct {
	float flat_gain;
	float gain_pot_setting;
	bool mute;
}GlobalGains_t;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define BUF_LENGTH 256

#define DEFAULT_FRAME_LENGTH       	32
#define SAMPLING_RATE 				48000.0000000F
#define CODEC_MCLK 					SAMPLING_RATE * 256   /* For STM32 host, i2s-MCLK is 256 * sample_rate */
#define DEFAULT_CHANNELS_NUM 		2
#define DEFAULT_BIT_PER_CHANL 		16
#define DEFAULT_DAI_SLOT_WIDTH      32
#define DEFAULT_DAI_SLOTS			2

#define DEFAULT_BIT_CLOCK 			SAMPLING_RATE * DEFAULT_CHANNELS_NUM * DEFAULT_BIT_PER_CHANL
#define NOISE_THRHLD				16
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Codec_ENBL_Pin GPIO_PIN_2
#define Codec_ENBL_GPIO_Port GPIOC
#define Green_Led_Pin GPIO_PIN_5
#define Green_Led_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */
extern I2S_HandleTypeDef hi2s1;
extern I2S_HandleTypeDef hi2s2;
extern I2C_HandleTypeDef hi2c1;



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
