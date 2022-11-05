
#ifndef __BEARLYML_HAL_H
#define __BEARLYML_HAL_H


#ifdef __cplusplus
extern "C" {
#endif

#include "bearlyml.h"
#include "bearlyml_hal_core.h"
#include "bearlyml_hal_clint.h"
#include "bearlyml_hal_gpio.h"
#include "bearlyml_hal_plic.h"
#include "bearlyml_hal_rcc.h"
#include "bearlyml_hal_uart.h"


// #define SYS_CLK_FREQ  200000                    // Hz
#define SYS_CLK_FREQ  32000000                  // Hz
#define MTIME_FREQ    (SYS_CLK_FREQ / 20000)    // tick per milliseconds

void HAL_init();

uint64_t HAL_getTick();

void HAL_delay(uint64_t time);

#ifdef __cplusplus
}
#endif

#endif /* __BEARLYML_HAL_H */
