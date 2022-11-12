
#ifndef __OSCIBEAR_HAL_UART_H
#define __OSCIBEAR_HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "oscibear.h"
#include "oscibear_hal.h"

#define UART_FIFO_DEPTH   8

#define UART_MODE_RX                    0x01U
#define UART_MODE_TX                    0x02U
#define UART_MODE_TX_RX                 0x03U

#define UART_STOPBITS_1                 0
#define UART_STOPBITS_2                 UART_TXCTRL_NSTOP_MSK

typedef struct {
  uint32_t baudrate;  // the default baudrate divisor is 0xAD, 173
  uint32_t mode;
  uint32_t stopbits;
} UART_InitTypeDef;

// the default baudrate divisor is 0xAD, 173

void HAL_UART_init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_init);

uint8_t HAL_UART_getRXFIFODepth(UART_TypeDef *UARTx);

uint8_t HAL_UART_getTXFIFODepth(UART_TypeDef *UARTx);

Status HAL_UART_receive(UART_TypeDef *UARTx, uint8_t *data, uint16_t size, uint32_t timeout);

Status HAL_UART_transmit(UART_TypeDef *UARTx, uint8_t *data, uint16_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif /* __OSCIBEAR_HAL_UART_H */