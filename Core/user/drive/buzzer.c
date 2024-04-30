#include "gpio.h"
#include "main.h"
#include "include_user_all.h"

void buzzer_ring(uint8_t len) {
  while (get_flag())
    continue;

  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
  HAL_Delay(100);
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);

  if (len != 0) {
    HAL_Delay(100);
    buzzer_ring(len - 1);
  }
}
