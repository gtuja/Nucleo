
/**
  ******************************************************************************
  * @file           : ToolSwd.h
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
#ifndef INC_TOOL_TOOLSWD_H_
#define INC_TOOL_TOOLSWD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/* Exported defines ----------------------------------------------------------*/
#define TOOL_SWD_MAX  50
#define TOOL_SWD_LEN  20

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern PUBLIC char gpcSwdBuffer[TOOL_SWD_LEN][TOOL_SWD_MAX];
extern PUBLIC uint8_t gu8SwdBufferIndex;
extern PUBLIC osMessageQueueId_t QueSwdHandle;

/* Exported macro ------------------------------------------------------------*/
#define SWD_PRINTF_ISR(fmt, ...) { \
  snprintf(gpcSwdBuffer[gu8SwdBufferIndex], TOOL_SWD_MAX, fmt, __VA_ARGS__);  \
  xQueueSendFromISR(QueSwdHandle, &gu8SwdBufferIndex, NULL);  \
  if (++gu8SwdBufferIndex >= TOOL_SWD_LEN) gu8SwdBufferIndex = 0; \
}

#define SWD_PRINTF(fmt, ...) { \
  snprintf(gpcSwdBuffer[gu8SwdBufferIndex], TOOL_SWD_MAX, fmt, __VA_ARGS__);  \
  xQueueSend(QueSwdHandle, &gu8SwdBufferIndex, NULL);  \
  if (++gu8SwdBufferIndex >= TOOL_SWD_LEN) gu8SwdBufferIndex = 0; \
}

/* Exported functions prototypes ---------------------------------------------*/
PUBLIC void vToolSwdInitialize(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_TOOL_TOOLSWD_H_ */
