
/**
  ******************************************************************************
  * @file           : ServicePeriodic.c
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
#include "Service/ServicePeriodic.h"
#include "Tool/ToolSwd.h"

/* Private define ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
PRIVATE uint32_t u32SrvButtonCounter;
PRIVATE uint32_t u32SrvLedCounter;

/* Private function prototypes -----------------------------------------------*/
PRIVATE void SrvPrdButton(void* pvArgs);
PRIVATE void SrvPrdLed(void* pvArgs);

/* Exported variables --------------------------------------------------------*/
const sttSrvPrd gstSrvPrdTbl[SRV_PRD_MAX] =
{
  { SRV_PRD_HIGH, SrvPrdButton },
  { SRV_PRD_HIGH, SrvPrdLed },
};

PUBLIC void vSrvPrdInitialize()
{
  u32SrvButtonCounter = 0;
  u32SrvLedCounter = 0;
}

PRIVATE void SrvPrdButton(void* pvArgs)
{
  u32SrvButtonCounter++;
  if (u32SrvButtonCounter % 1000 == 0) SWD_PRINTF_ISR("%s:%d is called on...", __FUNCTION__, __LINE__);
}

PRIVATE void SrvPrdLed(void* pvArgs)
{
  u32SrvLedCounter++;
  if (u32SrvButtonCounter % 2000 == 0) SWD_PRINTF_ISR("%s:%d is called on...", __FUNCTION__, __LINE__);
}

