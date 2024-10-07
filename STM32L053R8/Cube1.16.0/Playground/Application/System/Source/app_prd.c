/**
 * @file    app_prd.c
 * @brief   This file is used to ... 
 * @author  Gtuja
 * @date    Oct 7, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "type.h"
#include "feature.h"
#include "stm32l0xx_hal.h"

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim21;

/* Public functions ----------------------------------------------------------*/

PUBLIC void vidAprdInitialize(void) {
}

PUBLIC void vidAprdService(void) {
}

PUBLIC void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  static unsigned long count;
  if (htim == &htim21) {
    if (count >= 2399) count = 0;
    //__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, count++);
  }
}
