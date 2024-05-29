
/**
  ******************************************************************************
  * @file           : TaskSwd.c
  * @brief          : Source for TSK_SWD.
  *                   This file contains methods of TSK_SWD.
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
#include "Task/TaskSwd.h"
#include "Tool/ToolSwd.h"

/* Private define ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void vTaskSwdInitialize(void)
{
  setbuf(stdout, NULL);
}

void vTaskSwdProcess(void)
{
  BaseType_t xStatus;
  uint8_t u8Received;

  xStatus = xQueueReceive(QueSwdHandle, &u8Received, portMAX_DELAY);
  if (xStatus == pdPASS)
  {
    printf("[%03d]%s\r\n", u8Received, gpcSwdBuffer[u8Received]);
  }
}

