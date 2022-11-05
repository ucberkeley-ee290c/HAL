
#ifndef __BEARLYML_HAL_CLINT_H
#define __BEARLYML_HAL_CLINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bearlyml.h"

void HAL_CLINT_triggerSoftwareInterrupt(uint32_t hartid);

uint64_t HAL_CLINT_getTime();

void HAL_CLINT_setTimerInterrupt(uint64_t time);

#ifdef __cplusplus
}
#endif

#endif /* __BEARLYML_HAL_CLINT_H */
