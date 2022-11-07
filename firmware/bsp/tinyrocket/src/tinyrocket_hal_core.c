
#include "tinyrocket_hal_core.h"


void HAL_CORE_disableGlobalInterrupt() {
  // Clear MPIE
  uint32_t mask = (1U << 3U);
  asm volatile("csrc mstatus, %0" :: "r"(mask));
}

void HAL_CORE_enableGlobalInterrupt() {
  // Set MPIE
  uint32_t mask = (1U << 3U);
  asm volatile("csrs mstatus, %0" :: "r"(mask));
}

void HAL_CORE_disableIRQ(IRQn_Type IRQn) {
  uint32_t mask = (1U << (uint32_t)IRQn);
  asm volatile("csrc mie, %0" :: "r"(mask));
}

void HAL_CORE_enableIRQ(IRQn_Type IRQn) {
  uint32_t mask = (1U << (uint32_t)IRQn);
  asm volatile("csrs mie, %0" :: "r"(mask));
}

void HAL_CORE_clearIRQ(IRQn_Type IRQn) {
  uint32_t mask = (1U << (uint32_t)IRQn);
  asm volatile("csrc mip, %0" :: "r"(mask));
}
