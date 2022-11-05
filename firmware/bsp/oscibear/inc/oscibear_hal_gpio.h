
#ifndef __OSCIBEAR_HAL_GPIO_H
#define __OSCIBEAR_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "oscibear.h"

typedef enum {
  GPIO_PIN_0 = 0b0001U,
  GPIO_PIN_1 = 0b0010U,
  GPIO_PIN_2 = 0b0100U
} GPIO_PIN;

typedef enum {
  GPIO_MODE_INPUT,
  GPIO_MODE_OUTPUT,
  GPIO_MODE_INOUT,
  GPIO_MODE_ALTERNATE_FUNCTION
} GPIO_Mode;

typedef enum {
  GPIO_PULL_NONE,
  GPIO_PULL_UP
} GPIO_Pull;

typedef enum {
  GPIO_DS_WEAK,
  GPIO_DS_STRONG
} GPIO_DriveStrength;

typedef struct {
  GPIO_Mode mode;
  GPIO_Pull pull;
  GPIO_DriveStrength drive_strength;
} GPIO_InitTypeDef;

void HAL_GPIO_init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_init, GPIO_PIN pin);

uint8_t HAL_GPIO_readPin(GPIO_TypeDef *GPIOx, GPIO_PIN pin);

void HAL_GPIO_writePin(GPIO_TypeDef *GPIOx, GPIO_PIN pin, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif /* __OSCIBEAR_HAL_GPIO_H */
