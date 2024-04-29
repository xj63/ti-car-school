#include "gpio.h"
#include "main.h"

void buzzer_ring() {
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
  HAL_Delay(100);
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);
  HAL_Delay(100);
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
  HAL_Delay(100);
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);

  return;
}
