
#ifndef __TINYROCKET_HAL_CORE_H
#define __TINYROCKET_HAL_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tinyrocket.h"

void HAL_CORE_disableGlobalInterrupt();

void HAL_CORE_enableGlobalInterrupt();

void HAL_CORE_disableIRQ(IRQn_Type IRQn);

void HAL_CORE_enableIRQ(IRQn_Type IRQn);

void HAL_CORE_clearIRQ(IRQn_Type IRQn);

#ifdef __cplusplus
}
#endif

#endif /* __TINYROCKET_HAL_CORE_H */
