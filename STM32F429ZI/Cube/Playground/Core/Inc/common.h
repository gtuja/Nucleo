
/**
  ******************************************************************************
  * @file           : common.h
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
#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "cmsis_os.h"

/* Exported defines ----------------------------------------------------------*/
#ifdef PRIVATE
#undef PRIVATE
#endif

#ifdef PUBLIC
#undef PUBLIC
#endif

#define PRIVATE static
#define PUBLIC

#ifdef FALSE
#undef FALSE
#endif

#ifdef TRUE
#undef TRUE
#endif

#define FALSE (unsigned char)0
#define TRUE  (unsigned char)1

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* INC_COMMON_H_ */
