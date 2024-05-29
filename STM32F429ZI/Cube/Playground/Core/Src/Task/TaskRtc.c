
/**
  ******************************************************************************
  * @file           : TaskRtc.c
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
#include "common.h"
#include "feature.h"
#include "rtc.h"
#include "queue.h"
#include "Service/ServiceRtc.h"
#include "Task/TaskRtc.h"
#include "Tool/ToolSwd.h"

/* Private define ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

PUBLIC void vTaskRtcInitialize(void)
{
}

PUBLIC void vTaskRtcProcess(void)
{
  BaseType_t xStatus;
  sttRtcDateTime sttReceived;

  xStatus = xQueueReceive(QueRtcHandle, &sttReceived, portMAX_DELAY);
  if (xStatus == pdPASS)
  {
    SWD_PRINTF("20%02d.%02d.%02d %02d:%02d:%02d",
        sttReceived.Date.Year,
        sttReceived.Date.Month,
        sttReceived.Date.Date,
        sttReceived.Time.Hours,
        sttReceived.Time.Minutes,
        sttReceived.Time.Seconds
        );
  }
}
