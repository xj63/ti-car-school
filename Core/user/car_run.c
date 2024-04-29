#include "include_user_all.h"
#include "findline.h"
#include "keep.h"
#include "main.h"
#include "straight.h"
#include "turn.h"
#include "turn_abs.h"

void mode1(){
    start_straight(2350);
    start_keep_angle(0.0);
    turn_abs_start_turn(45.0);
    start_straight(1700);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(3200);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(700);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(3500);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(3000);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1600);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);
}

void mode2(){
    start_straight(2350);
    start_keep_angle(0.0);
    turn_abs_start_turn(45.0);
    start_straight(1700);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(3200);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(700);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);

    start_straight(-1000);

    start_straight(3500);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(3000);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1600);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);
}

void car_run()
{
    mode2();
}
