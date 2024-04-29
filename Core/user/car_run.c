#include "findline.h"
#include "keep.h"
#include "main.h"
#include "straight.h"
#include "turn.h"
#include "turn_abs.h"

void car_run() {
  start_straight(2000);
  start_keep_angle(0);
  turn_abs_start_turn(90);
  start_straight(2000);
  start_keep_angle(90);
  turn_abs_start_turn(40);
  start_straight(2000);
  start_keep_angle(40);
}
