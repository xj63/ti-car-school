#include "include_user_all.h"

void car_timer() {
  left_cur = -motor_getSpeed(M_L);
  right_cur = motor_getSpeed(M_R);
  gun_cur = motor_getSpeed(M_G);

  // printTo(uart1, "move:%d turn:%d stra:%d\r\n", moving_flag, turn_flag,
  // straight_flag);

  left_tar = 0;
  right_tar = 0;

  turn();
  turn_abs();
  keep_angle();
  straight();
  findline();
  motor_stop();

  motor_setSpeed(left_tar, right_tar, gun_tar);
}
