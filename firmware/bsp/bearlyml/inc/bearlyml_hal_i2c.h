
#ifndef __BEARLYML_HAL_I2C_H
#define __BEARLYML_HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bearlyml.h"
#include "bearlyml_hal.h"

typedef struct {
  uint16_t clock;
} I2C_InitTypeDef;

typedef enum {
  I2C_FLAG_IF = I2C_STAT_CMD_IF_MSK,
  I2C_FLAG_TIP = I2C_STAT_CMD_TIP_MSK,
  I2C_FLAG_BUSY = I2C_STAT_CMD_BUSY_STO_MSK,
  I2C_FLAG_RXACK = I2C_STAT_CMD_RXACK_STA_MSK,
} I2C_Flag;

#define I2C_DATA_WRITE        0b0U
#define I2C_DATA_READ         0b1U

void HAL_I2C_init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_init);

void HAL_I2C_disable(I2C_TypeDef *I2Cx);

void HAL_I2C_enable(I2C_TypeDef *I2Cx);

State HAL_I2C_getFlag(I2C_TypeDef *I2Cx, I2C_Flag flag);

Status HAL_I2C_waitForFlag(I2C_TypeDef *I2Cx, I2C_Flag flag, State state, uint32_t timestart, uint32_t timeout);

Status HAL_I2C_waitForTransaction(I2C_TypeDef *I2Cx, uint32_t timestart, uint32_t timeout);

Status HAL_I2C_masterReceive(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t *buffer, uint16_t size, uint64_t timeout);

Status HAL_I2C_masterTransmit(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t *buffer, uint16_t size, uint64_t timeout);

Status HAL_I2C_readMemory(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t mem_addr, uint8_t *buffer, uint16_t size, uint64_t timeout);

Status HAL_I2C_writeMemory(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t mem_addr, uint8_t *buffer, uint16_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif /* __BEARLYML_HAL_I2C_H */