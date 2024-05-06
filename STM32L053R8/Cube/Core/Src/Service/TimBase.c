/*
 * TimBase.c
 *
 *  Created on: May 6, 2024
 *      Author: admin
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"


static void vidTimBaseProcess(void);


extern TIM_HandleTypeDef htim21;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_PeriodElapsedCallback could be implemented in the user file
   */
  if (htim->Instance == htim21.Instance)
  {
    vidTimBaseProcess();
  }
}

unsigned long gulTimBaseCounter;

void vidTimBaseInitialize(void)
{
  gulTimBaseCounter = 0;
  if (HAL_TIM_Base_Start_IT(&htim21) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }
}

static void vidTimBaseProcess(void)
{
  gulTimBaseCounter++;
}
