/**
 ******************************************************************************
 * @file           : TimBase.c
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
#include <stdio.h>

typedef enum {
  SRV_NAME_LED = 0,
  SRV_NAME_MAX,
} enuSrvName;

typedef struct {
  enuSrvName name;
  void (*pfProcess)(void* args);
} sttSrvAttr;

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim21;

/* External functions --------------------------------------------------------*/
extern void Error_Handler(void);

/* Static variables ----------------------------------------------------------*/
static uint32_t gulTimBaseCounter;

static sttSrvAttr gstSrvAttrTbl[SRV_NAME_MAX] = {
  {SRV_NAME_LED, vidSrvLedProcess},
};

/* Static function prototypes ------------------------------------------------*/
static void vidTimBaseProcess(void);

/* HAL override functions ----------------------------------------------------*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_PeriodElapsedCallback could be implemented in the user file
   */
  if (htim->Instance == TIM21)
  {
    vidTimBaseProcess();
  }
}

void vidTimBaseInitialize(void)
{
  gulTimBaseCounter = 0;
  if (HAL_TIM_Base_Start_IT(&htim21) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }
}

uint32_t u32TimBaseGetCounter(void)
{
  return gulTimBaseCounter;
}

static void vidTimBaseProcess(void)
{
  uint8_t i;

  gulTimBaseCounter++;

  for (i=0; i<SRV_NAME_MAX; i++)
  {
    if (gstSrvAttrTbl[i].pfProcess != NULL)
    {
      gstSrvAttrTbl[i].pfProcess((void*)gulTimBaseCounter);
    }
  }
}


