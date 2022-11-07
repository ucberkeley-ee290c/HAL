
#include "tinyrocket_hal.h"

void HAL_init() {
  for (uint16_t i=0; i<64; i+=1) {
    HAL_PLIC_completeIRQ(0, i);
  }
}

uint64_t HAL_getTick() {
  return HAL_CLINT_getTime();
}

void HAL_delay(uint64_t time) {
  uint64_t target_tick = HAL_getTick() + (time * MTIME_FREQ);
  while (HAL_getTick() < target_tick) {
    // asm("nop");
  }
}
