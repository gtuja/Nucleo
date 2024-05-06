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
/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "Service/TimBase.h"
#include "Service/Led.h"

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;

/* External functions --------------------------------------------------------*/
extern void Error_Handler(void);

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void vidSrvLedInitialize(void)
{
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void vidSrvLedProcess(void* args)
{
  uint32_t ulCounter;

  ulCounter = u32TimBaseGetCounter();

  if (ulCounter%2 == 0)
  {
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, LED_PWM_PRD + 1);
  }
  else
  {
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
  }
}
