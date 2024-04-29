#include "main.h"
#include "motor.h"
#include "straight.h"
#include "tim.h"
#include "turn_abs.h"

void car_init() {
  motor_init();
  turn_abs_head_init();
  HAL_TIM_Base_Start_IT(&htim5);
}
