
/**
  ******************************************************************************
  * @file           : TaskRtc.h
  * @brief          : Header/Source for XXXX.
  *                   This file contains interfaces/methods of XXXX.
  ******************************************************************************
  *
  * Copyleft, All rights reversed.
  * Gtuja.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_TASK_TASKRTC_H_
#define INC_TASK_TASKRTC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
PUBLIC void vTaskRtcInitialize(void);
PUBLIC void vTaskRtcProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_TASK_TASKRTC_H_ */
