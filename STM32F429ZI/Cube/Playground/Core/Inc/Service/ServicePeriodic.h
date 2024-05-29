
/**
  ******************************************************************************
  * @file           : ServicePeriodic.h
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
#ifndef INC_SERVICE_SERVICEPERIODIC_H_
#define INC_SERVICE_SERVICEPERIODIC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "common.h"

/* Exported defines ----------------------------------------------------------*/
#define SRV_PRD         (uint32_t)1             /* The period of service. */
#define SRV_PRD_HIGH    SRV_PRD                 /* Service performed every SRV_PRD */
#define SRV_PRD_MED     (uint32_t)(10*SRV_PRD)  /* Service performed every SRV_PRD*10 */
#define SRV_PRD_LOW     (uint32_t)(100*SRV_PRD) /* Service performed every SRV_PRD*100 */

/* Exported types ------------------------------------------------------------*/
typedef void (*fpService)(void* pvArgs);

typedef enum
{
  SRV_PRD_BTN = 0,
  SRV_PRD_LED,
  SRV_PRD_MAX,
} enuSrvPrd;

typedef struct
{
  uint32_t  u32Period;
  fpService pfService;
} sttSrvPrd;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern const sttSrvPrd gstSrvPrdTbl[SRV_PRD_MAX];

/* Exported functions prototypes ---------------------------------------------*/
PUBLIC void vSrvPrdInitialize();

#ifdef __cplusplus
}
#endif

#endif /* INC_SERVICE_SERVICEPERIODIC_H_ */
