
/**
  ******************************************************************************
  * @file           : TaskLed.h
  * @brief          : Header for TSK_LED.
  *                   This file contains the common defines of TSK_LED.
  ******************************************************************************
  *
  * Copyleft, All rights reversed.
  * Gtuja.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_TASK_TASKLED_H_
#define INC_TASK_TASKLED_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void vTaskLedInitialize(void);
void vTaskLedProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_TASK_TASKLED_H_ */
