
/**
  ******************************************************************************
  * @file           : ToolSwd.c
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
#include "Tool/ToolSwd.h"
#include <string.h>

/* Private define ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
PUBLIC char gpcSwdBuffer[TOOL_SWD_LEN][TOOL_SWD_MAX];
PUBLIC uint8_t gu8SwdBufferIndex;

PUBLIC void vToolSwdInitialize(void)
{
  memset(gpcSwdBuffer, 0, sizeof(gpcSwdBuffer));
  gu8SwdBufferIndex = 0;
}
