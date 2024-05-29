
/**
  ******************************************************************************
  * @file           : TaskButton.h
  * @brief          : Header for TSK_BUTTON.
  *                   This file contains the common defines of TSK_BUTTON.
  ******************************************************************************
  *
  * Copyleft, All rights reversed.
  * Gtuja.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_TASK_TASKBUTTON_H_
#define INC_TASK_TASKBUTTON_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void vTaskButtonInitialize(void);
void vTaskButtonProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_TASK_TASKBUTTON_H_ */
