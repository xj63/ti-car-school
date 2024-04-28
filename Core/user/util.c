#include "motor_control.h"

void await() {
  while (get_flag())
    continue;
}
