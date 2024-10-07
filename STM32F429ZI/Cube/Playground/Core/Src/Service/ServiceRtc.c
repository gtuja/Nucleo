
/**
  ******************************************************************************
  * @file           : ServiceRtc.c
  * @brief          : Header/Source for XXXX.
  *                   This file contains interfaces/methods of XXXX.
  ******************************************************************************
  *
  * Copyleft, All rights reversed.
  * Gtuja.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "common.h"
#include "feature.h"
#include "queue.h"
#include "Service/ServiceRtc.h"

/* Private define ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Override callback functions  ----------------------------------------------*/

/**
  * @brief  Wakeup Timer callback.
  * @param  hrtc pointer to a RTC_HandleTypeDef structure that contains
  *                the configuration information for RTC.
  * @retval None
  */
void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc)
{
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_RTCEx_WakeUpTimerEventCallback could be implemented in the user file
   */
  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef sDate;
  sttRtcDateTime sttDateTime;

  HAL_RTC_GetTime(hrtc, &sTime, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(hrtc, &sDate, RTC_FORMAT_BIN);

  sttDateTime.Date = sDate;
  sttDateTime.Time = sTime;
  xQueueSendFromISR(QueRtcHandle, &sttDateTime, NULL);
}