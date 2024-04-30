#include "gpio.h"
#include "main.h"

void buzzer_ring(uint8_t len) {
  HAL_Delay(100);
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
  HAL_Delay(100);
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);
  buzzer_ring(len - 1);
}
