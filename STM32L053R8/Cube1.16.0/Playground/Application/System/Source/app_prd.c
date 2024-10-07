/**
 * @file    app_prd.c
 * @brief   This file is used to ... 
 * @author  Gtuja
 * @date    Oct 7, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "type.h"
#include "feature.h"
#include "stm32l0xx_hal.h"
#include "app_prd.h"
#include <string.h>

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef struct {
  tenuAprdPriority  enuPriority;
  tpfAprdInitialize pfInitialize;
  tpfAprdService    pfService;
} tstrAprdService;

/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
PRIVATE void vidAprdServiceDetail(tenuAprdPriority enuAprdPriority);

/* Private variables ---------------------------------------------------------*/
PRIVATE U64 gullAprdCounter;

PRIVATE tstrAprdService gstrAprdService[APRD_SRV_MAX];

/* Exported variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim21;

/* Public functions ----------------------------------------------------------*/
PUBLIC void vidAprdInitialize(void) {
  gullAprdCounter = 0;
  memset(gstrAprdService, 0, sizeof(gstrAprdService));
}

PUBLIC void vidAprdService(void) {
  if ((gullAprdCounter % APRD_INTERVAL_LOW) == (U64)0)    vidAprdServiceDetail(APRD_PRIOR_LOW);
  if ((gullAprdCounter % APRD_INTERVAL_NORMAL) == (U64)0) vidAprdServiceDetail(APRD_PRIOR_NORMAL);
  if ((gullAprdCounter % APRD_INTERVAL_HIGH) == (U64)0)   vidAprdServiceDetail(APRD_PRIOR_HIGH);
}

PUBLIC BOOL bAprdRegister(tenuAprdPriority enuPriority, tpfAprdInitialize pfInitialize, tpfAprdService pfService)
{
  U8 i;
  BOOL bReturn = FALSE;

  for (i=0; i<(U8)APRD_SRV_MAX; i++)  {
    if (gstrAprdService[i].enuPriority != APRD_PRIOR_NA) {
      gstrAprdService[i].enuPriority = enuPriority;
      gstrAprdService[i].pfInitialize = pfInitialize;
      gstrAprdService[i].pfService = pfService;
      bReturn = TRUE;
      break;
    }
  }
  return bReturn;
}

PUBLIC void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim21) {
    gullAprdCounter++;
    vidAprdService();
  }
}

PRIVATE void vidAprdServiceDetail(tenuAprdPriority enuAprdPriority) {
  U8 i;

  for (i=0; i<(U8)APRD_SRV_MAX; i++)  {
    if (gstrAprdService[i].enuPriority == enuAprdPriority) {
      if (gstrAprdService[i].pfService != NULL) {
        gstrAprdService[i].pfService(NULL);
      }
    }
  }
}
