/**
  ******************************************************************************
  * @file           : TaskSwd.h
  * @brief          : Header/Source for XXXX.
  *                   This file contains the common defines of XXXX.
  ******************************************************************************
  * @attention
  *
  * Copyleft. May 26, 2024 Gtuja.
  * All rights reversed.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_TASK_TASKSWD_H_
#define INC_TASK_TASKSWD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "queue.h"

/* Exported defines ----------------------------------------------------------*/
#define QUE_SWD_BUF_MAX (const size_t)50

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern osMessageQueueId_t QueSwdHandle;

/* Exported functions prototypes ---------------------------------------------*/

void vTaskSwdInitialize(void);
void vTaskSwdProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_TASK_TASKSWD_H_ */
