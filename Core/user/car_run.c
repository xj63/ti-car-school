#include "include_user_all.h"
#include "findline.h"
#include "keep.h"
#include "main.h"
#include "straight.h"
#include "turn.h"
#include "turn_abs.h"

void car_run() {
  start_straight(2350);
	start_keep_angle(0.0);
	turn_abs_start_turn(45.0);
	start_straight(1700);
	start_keep_angle(45.0);
	turn_abs_start_turn(0.0);
  start_straight(3500);
	start_keep_angle(0.0);
	turn_abs_start_turn(90.0);
}
