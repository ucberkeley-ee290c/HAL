
#include "main.h"

char str[128];

int main() {
  UART_InitTypeDef UART_init_config;
  UART_init_config.baudrate = 115200;
  UART_init_config.mode = UART_MODE_TX_RX;
  UART_init_config.stopbits = UART_STOPBITS_1;
  HAL_UART_init(UART0, &UART_init_config);

  GPIO_InitTypeDef GPIO_init_config;
  GPIO_init_config.mode = GPIO_MODE_OUTPUT;
  GPIO_init_config.pull = GPIO_PULL_NONE;
  GPIO_init_config.drive_strength = GPIO_DS_WEAK;
  HAL_GPIO_init(GPIOA, &GPIO_init_config, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);
  
  uint8_t counter = 0;
  while (1) {
    sprintf(str, "hello world!\n");
    HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
    HAL_GPIO_writePin(GPIOA, GPIO_PIN_0, counter % 2);
    HAL_GPIO_writePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2, ~(counter % 4));
    counter += 1;
    HAL_delay(500);
  }
}
