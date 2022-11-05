
// #include "main.h"

// char str[512];

// // 128bit key
// uint8_t keyone[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88,0x09, 0xcf,  0x4f, 0x3c};

// // 256bit key
// uint8_t keytwo[32] = {0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81, 
//                             0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4};

// // 512bit text
// uint8_t plaintext[64]     = {0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
//                             0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
//                             0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
//                             0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10};

// // Expected for 128b enc
// uint8_t ciphertextone[64] = {0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97,
//                             0xf5, 0xd3, 0xd5, 0x85, 0x03, 0xb9, 0x69, 0x9d, 0xe7, 0x85, 0x89, 0x5a, 0x96, 0xfd, 0xba, 0xaf,
//                             0x43, 0xb1, 0xcd, 0x7f, 0x59, 0x8e, 0xce, 0x23, 0x88, 0x1b, 0x00, 0xe3, 0xed, 0x03, 0x06, 0x88,
//                             0x7b, 0x0c, 0x78, 0x5e, 0x27, 0xe8, 0xad, 0x3f, 0x82, 0x23, 0x20, 0x71, 0x04, 0x72, 0x5d, 0xd4};

// // Expected for 256b enc
// uint8_t ciphertexttwo[64] = {0xf3, 0xee, 0xd1, 0xbd, 0xb5, 0xd2, 0xa0, 0x3c, 0x06, 0x4b, 0x5a, 0x7e, 0x3d, 0xb1, 0x81, 0xf8,
//                             0x59, 0x1c, 0xcb, 0x10, 0xd4, 0x10, 0xed, 0x26, 0xdc, 0x5b, 0xa7, 0x4a, 0x31, 0x36, 0x28, 0x70,
//                             0xb6, 0xed, 0x21, 0xb9, 0x9c, 0xa6, 0xf4, 0xf9, 0xf1, 0x53, 0xe7, 0xb1, 0xbe, 0xaf, 0xed, 0x1d,
//                             0x23, 0x30, 0x4b, 0x7a, 0x39, 0xf9, 0xf3, 0xff, 0x06, 0x7d, 0x8d, 0x8f, 0x9e, 0x24, 0xec, 0xc7};

// // Scratch space for data
// uint8_t fillerspace[64]   = {0x0};

// int testAES_ECB_singlePoll() {
//   while (1) {

//     // ----------------- Single Block 128b Enc/Dec Loop -----------------
//     sprintf(str, "AES E/D Loop, Single Block, 128b Key, Polling:\n");
//     HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//     HAL_delay(10);
//     // Encrypting all four blocks using single block operations
//     // sprintf(str, "Encrypting plaintext and checking output...\n");
//     sprintf(str, "Encrypting ...\n");
//     HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//     HAL_delay(10);
//     for (int i = 0; i < 4; ++i) {
//       AES_ECB_ENC_POLL(keyone, 128, plaintext + (i * 16), fillerspace + (i * 16), 16);
//     }
//     HAL_delay(10);
//     // Comparing actual results to expected
//     checkBytes(fillerspace, ciphertextone, 64);
//     HAL_delay(10);
//     // Decrypting all four blocks using single block operations (using expected as source)
//     sprintf(str, "Decrypting ciphertext and checking output...\n");
//     HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//     HAL_delay(10);
//     for (int i = 0; i < 4; ++i) {
//       AES_ECB_DEC_POLL(keyone, 128, ciphertextone + (i * 16), fillerspace + (i * 16), 16);
//     }
//     HAL_delay(10);
//     // Comparing actual results to expected
//     checkBytes(fillerspace, plaintext, 64);
//     HAL_delay(10);
//     // ----------------- Single Block 256b Enc/Dec Loop -----------------
//     sprintf(str, "\nAES E/D Loop, Single Block, 256b Key, Polling:\n");
//     HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//     HAL_delay(10);
//     // Encrypting all four blocks using single block operations
//     sprintf(str, "Encrypting plaintext and checking output...\n");
//     HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//     HAL_delay(10);
//     for (int i = 0; i < 4; ++i) {
//       AES_ECB_ENC_POLL(keytwo, 256, plaintext + (i * 16), fillerspace + (i * 16), 16);
//     }
//     HAL_delay(10);
//     // Comparing actual results to expected
//     checkBytes(fillerspace, ciphertexttwo, 64);
//     HAL_delay(10);
//     // Decrypting all four blocks using single block operations (using expected as source)
//     sprintf(str, "Decrypting ciphertext and checking output...\n");
//     HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//     HAL_delay(10);
//     for (int i = 0; i < 4; ++i) {
//       AES_ECB_DEC_POLL(keytwo, 256, ciphertexttwo + (i * 16), fillerspace + (i * 16), 16);
//     }
//     HAL_delay(10);
//     // Comparing actual results to expected
//     checkBytes(fillerspace, plaintext, 64);
//     HAL_delay(10);

//     sprintf(str, "loop\n");
//     HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//     HAL_delay(1000);
//   }
// }


// int testAES_ECB_singleInt(void) {
//   while (1) {

//   // Enabling Interrupts
//   HAL_PLIC_setPriorityThreshold(0, 1); // Set Hart 0 priority threshold to 1
  
//   // I believe the RoCC interupt is a machine software interrupt?
//   HAL_CORE_enableIRQ(MachineSoftware_IRQn);

//   HAL_CORE_enableGlobalInterrupt();

//   // ----------------- Single Block 128b Enc/Dec Loop -----------------
//   sprintf(str, "AES E/D Loop, Single Block, 128b Key, Polling:\n");
//   HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//   HAL_delay(10);

//   // Encrypting all four blocks using single block operations
//   sprintf(str, "Encrypting plaintext and checking output...\n");
//   HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//   HAL_delay(10);

//   for (int i = 0; i < 4; ++i) {
//     AES_ECB_ENC_INT(keyone, 128, plaintext + (i * 16), fillerspace + (i * 16), 16);
//   }
//   HAL_delay(100);

//   // Comparing actual results to expected
//   checkBytes(fillerspace, ciphertextone, 64);
//   HAL_delay(10);

//   // Decrypting all four blocks using single block operations (using expected as source)
//   sprintf(str, "Decrypting ciphertext and checking output...\n");
//   HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//   HAL_delay(10);

//   for (int i = 0; i < 4; ++i) {
//     AES_ECB_DEC_INT(keyone, 128, ciphertextone + (i * 16), fillerspace + (i * 16), 16);
//   }
//   HAL_delay(100);

//   // Comparing actual results to expected
//   checkBytes(fillerspace, plaintext, 64);
//   HAL_delay(10);

//   // ----------------- Single Block 256b Enc/Dec Loop -----------------
//   sprintf(str, "\nAES E/D Loop, Single Block, 256b Key, Polling:\n");
//   HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//   HAL_delay(10);

//   // Encrypting all four blocks using single block operations
//   sprintf(str, "Encrypting plaintext and checking output...\n");
//   HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//   HAL_delay(10);
//   for (int i = 0; i < 4; ++i) {
//     AES_ECB_ENC_INT(keytwo, 256, plaintext + (i * 16), fillerspace + (i * 16), 16);
//   }
//   HAL_delay(10);

//   // Comparing actual results to expected
//   checkBytes(fillerspace, ciphertexttwo, 64);
//   HAL_delay(10);

//   // Decrypting all four blocks using single block operations (using expected as source)
//   sprintf(str, "Decrypting ciphertext and checking output...\n");
//   HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//   HAL_delay(10);
//   for (int i = 0; i < 4; ++i) {
//     AES_ECB_DEC_INT(keytwo, 256, ciphertexttwo + (i * 16), fillerspace + (i * 16), 16);
//   }
//   HAL_delay(10);

//   // Comparing actual results to expected
//   checkBytes(fillerspace, plaintext, 64);
//   HAL_delay(10);

//   sprintf(str, "loop\n");
//   HAL_UART_transmit(UART0, (uint8_t *)str, strlen(str), 0);
//   HAL_delay(1000);
// }
// }