
/**
  ******************************************************************************
  * @file           : ServiceRtc.h
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
#ifndef INC_SERVICE_SERVICERTC_H_
#define INC_SERVICE_SERVICERTC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef struct
{
  RTC_DateTypeDef Date;
  RTC_TimeTypeDef Time;
} sttRtcDateTime;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern osMessageQueueId_t QueRtcHandle;

#ifdef __cplusplus
}
#endif

#endif /* INC_SERVICE_SERVICERTC_H_ */
