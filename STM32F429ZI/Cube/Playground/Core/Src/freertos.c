/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Service/ServicePeriodic.h"
#include "Service/ServiceRtc.h"
#include "Task/TaskButton.h"
#include "Task/TaskLed.h"
#include "Task/TaskSwd.h"
#include "Task/TaskRtc.h"
#include "Tool/ToolSwd.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
static uint32_t gulTickCounter;

/* USER CODE END Variables */
/* Definitions for TSK_BUTTON */
osThreadId_t TSK_BUTTONHandle;
const osThreadAttr_t TSK_BUTTON_attributes = {
  .name = "TSK_BUTTON",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TSK_LED */
osThreadId_t TSK_LEDHandle;
const osThreadAttr_t TSK_LED_attributes = {
  .name = "TSK_LED",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TSK_SWD */
osThreadId_t TSK_SWDHandle;
const osThreadAttr_t TSK_SWD_attributes = {
  .name = "TSK_SWD",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for TSK_RTC */
osThreadId_t TSK_RTCHandle;
const osThreadAttr_t TSK_RTC_attributes = {
  .name = "TSK_RTC",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for QueSwd */
osMessageQueueId_t QueSwdHandle;
const osMessageQueueAttr_t QueSwd_attributes = {
  .name = "QueSwd"
};
/* Definitions for QueRtc */
osMessageQueueId_t QueRtcHandle;
const osMessageQueueAttr_t QueRtc_attributes = {
  .name = "QueRtc"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void TaskButton(void *argument);
void TaskLed(void *argument);
void TaskSwd(void *argument);
void TaskRtc(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);
void vApplicationTickHook(void);

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
void vApplicationTickHook( void )
{
   /* This function will be called by each tick interrupt if
   configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
   added here, but the tick hook is called from an interrupt context, so
   code must not attempt to block, and only the interrupt safe FreeRTOS API
   functions can be used (those that end in FromISR()). */
  uint8_t i;

  for (i=0; i<SRV_PRD_MAX; i++)
  {
    if (gulTickCounter % gstSrvPrdTbl[i].u32Period == 0)
    {
      if (gstSrvPrdTbl[i].pfService != NULL)
      {
        gstSrvPrdTbl[i].pfService(NULL);
      }
    }
  }
  gulTickCounter++;

}
/* USER CODE END 3 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  vSrvPrdInitialize();
  vToolSwdInitialize();
  gulTickCounter = 0;

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of QueSwd */
  QueSwdHandle = osMessageQueueNew (16, sizeof(uint8_t), &QueSwd_attributes);

  /* creation of QueRtc */
  QueRtcHandle = osMessageQueueNew (4, sizeof(sttRtcDateTime), &QueRtc_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of TSK_BUTTON */
  TSK_BUTTONHandle = osThreadNew(TaskButton, NULL, &TSK_BUTTON_attributes);

  /* creation of TSK_LED */
  TSK_LEDHandle = osThreadNew(TaskLed, NULL, &TSK_LED_attributes);

  /* creation of TSK_SWD */
  TSK_SWDHandle = osThreadNew(TaskSwd, NULL, &TSK_SWD_attributes);

  /* creation of TSK_RTC */
  TSK_RTCHandle = osThreadNew(TaskRtc, NULL, &TSK_RTC_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_TaskButton */
/**
  * @brief  Function implementing the TSK_BUTTON thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_TaskButton */
void TaskButton(void *argument)
{
  /* USER CODE BEGIN TaskButton */
  vTaskButtonInitialize();

  /* Infinite loop */
  for(;;)
  {
    vTaskButtonProcess();
    osDelay(1000);
  }
  /* USER CODE END TaskButton */
}

/* USER CODE BEGIN Header_TaskLed */
/**
* @brief Function implementing the TSK_LED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskLed */
void TaskLed(void *argument)
{
  /* USER CODE BEGIN TaskLed */
  vTaskLedInitialize();

  /* Infinite loop */
  for(;;)
  {
    vTaskLedProcess();
    osDelay(1000);
  }
  /* USER CODE END TaskLed */
}

/* USER CODE BEGIN Header_TaskSwd */
/**
* @brief Function implementing the TSK_SWD thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskSwd */
void TaskSwd(void *argument)
{
  /* USER CODE BEGIN TaskSwd */
  vTaskSwdInitialize();

  /* Infinite loop */
  for(;;)
  {
    vTaskSwdProcess();
  }
  /* USER CODE END TaskSwd */
}

/* USER CODE BEGIN Header_TaskRtc */
/**
* @brief Function implementing the TSK_RTC thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskRtc */
void TaskRtc(void *argument)
{
  /* USER CODE BEGIN TaskRtc */
  vTaskRtcInitialize();
  /* Infinite loop */
  for(;;)
  {
    vTaskRtcProcess();
  }
  /* USER CODE END TaskRtc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

