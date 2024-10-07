/**
 * @file    asys_prd.h
 * @brief   This file is used to ... 
 * @author  Gtuja
 * @date    Oct 7, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PERIODIC_INCLUDE_APP_PRD_H_
#define PERIODIC_INCLUDE_APP_PRD_H_

/* Includes ------------------------------------------------------------------*/
#include "type.h"

/* Exported defines ----------------------------------------------------------*/
#define APRD_SRV_MAX          10
#define APRD_INTERVAL_LOW     100
#define APRD_INTERVAL_NORMAL  10
#define APRD_INTERVAL_HIGH    1

/* Exported types ------------------------------------------------------------*/
typedef enum {
  APRD_PRIOR_NA = 0,
  APRD_PRIOR_LOW,
  APRD_PRIOR_NORMAL,
  APRD_PRIOR_HIGH,
  APRD_PRIOR_MAX,
} tenuAprdPriority;

typedef void (*tpfAprdInitialize)(void* pvArgs);
typedef void (*tpfAprdService)(void* pvArgs);

/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/

EXTERN BOOL bAprdRegister(tenuAprdPriority enuPriority, tpfAprdInitialize pfInitialize, tpfAprdService pfService);

#endif /* PERIODIC_INCLUDE_APP_PRD_H_ */
