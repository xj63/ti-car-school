#include "keep.h"
#include "motor_control.h"
#include "pid_yuan.h"
#include "turn.h"
#include "turn_abs.h"

#include <stdint.h>

static struct pid_data keep_angle_pid;

void keep_angle_set(float angle) {
  static_keep_angle = angle;
  pid_init(&keep_angle_pid, angle, 0.6, 0, 0, 0);
}

void keep_angle() {
  if (straight_flag) {
    float diff;
    int16_t turn_XZ = 0;
    diff = turn_head_diff(static_keep_angle, turn_abs_origin);
    int turn_speed = pid_inc(&keep_angle_pid, -diff);
    if (turn_speed > TURN_SPEED)
      turn_speed = TURN_SPEED;
    if (turn_speed < -TURN_SPEED)
      turn_speed = -TURN_SPEED;
    left_tar += -turn_speed - turn_XZ;
    right_tar += turn_speed - turn_XZ;
  }
}
