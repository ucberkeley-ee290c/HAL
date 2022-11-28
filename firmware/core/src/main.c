
#include "main.h"

char str[128];

int main() {
  UART_InitTypeDef UART_init_config;
  UART_init_config.baudrate = 115200;
  UART_init_config.mode = UART_MODE_TX_RX;
  UART_init_config.stopbits = UART_STOPBITS_1;
  HAL_UART_init(UART0, &UART_init_config);

<<<<<<< HEAD
  GPIO_InitTypeDef GPIO_init_config;
  GPIO_init_config.mode = GPIO_MODE_OUTPUT;
  GPIO_init_config.pull = GPIO_PULL_NONE;
  GPIO_init_config.drive_strength = GPIO_DS_WEAK;
  HAL_GPIO_init(GPIOA, &GPIO_init_config, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);
  
  uint8_t counter = 0;
  while (1) {
    sprintf(str, "hello world!\n");
=======
  // I2C_InitTypeDef I2C_init_config;
  // HAL_I2C_init(I2C0, &I2C_init_config);
  
  // uint8_t config = 0;
  // HAL_I2C_writeMemory(I2C0, DEFAULT_ADDRESS, 0x06, &config, 1, 0);
  while (1) {

    // // I2C Test -- qwiic button
    // uint8_t rx_buffer;
    // HAL_I2C_masterReceive(I2C0, DEFAULT_ADDRESS, &rx_buffer, 1, 0);
    // uint8_t tx_buffer = 100;
    // HAL_I2C_writeMemory(I2C0, DEFAULT_ADDRESS, 0x19, &tx_buffer, 1, 0);
    // HAL_I2C_writeMemory(I2C0, DEFAULT_ADDRESS, 0x19, &tx_buffer, 1, 0);
    // tx_buffer = 0x00;
    // HAL_I2C_masterTransmit(I2C0, DEFAULT_ADDRESS, &tx_buffer, 1, 0);

    // HAL_delay(1000);
    // tx_buffer = 0;
    // HAL_I2C_writeMemory(I2C0, DEFAULT_ADDRESS, 0x19, &tx_buffer, 1, 0);

    // I2C Test -- qwiic IMU
    
    // uint8_t buffer;
    // HAL_I2C_readMemory(I2C0, DEFAULT_ADDRESS, 0x00, &buffer, 1, 0);

    uint8_t buffer[6];
    // HAL_I2C_readMemory(I2C0, DEFAULT_ADDRESS, 0x2D, &buffer, 6, 0);
    uint16_t accel_x = (buffer[0] << 8) | buffer[1];
    uint16_t accel_y = (buffer[2] << 8) | buffer[3];
    uint16_t accel_z = (buffer[4] << 8) | buffer[5];

    sprintf(str, "acc x: %d\ty: %d\tz: %d\n", accel_x, accel_y, accel_z);
>>>>>>> 6929e0c9f8e6f33acacc633a3ca2ae00cfe9fc6e
    HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
    HAL_GPIO_writePin(GPIOA, GPIO_PIN_0, counter % 2);
    HAL_GPIO_writePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2, ~(counter % 4));
    counter += 1;
    HAL_delay(500);
  }
}
