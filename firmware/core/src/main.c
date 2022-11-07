
#include "main.h"

char str[128];

int main() {
  while (1) {
    sprintf(str, "hello world\n");
    HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
    HAL_delay(100);
  }
}
