#include "include_user_all.h"
#include "findline.h"
#include "keep.h"
#include "main.h"
#include "straight.h"
#include "turn.h"
#include "turn_abs.h"

void delay(uint16_t S)
{
    for (int i = S; i > 0; i--)
    {
        HAL_Delay(500);
        HAL_Delay(500);
    }
}

void stop_ring()
{
    buzzer_ring(2);
    delay(5);
    buzzer_ring(2);
}

void go_start_to_end()
{
    start_straight(2450);
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
    start_straight(2900);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);
}

void go_stop_p1()
{
    // TODO:
    start_straight(2450);
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

    start_straight(-1900);

    stop_ring();

    start_straight(5500);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2850);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);
}

void go_stop_p2()
{
    // TODO:
}

void go_stop_p3()
{
    // TODO:
}

void go_stop_p4()
{
    // TODO:
}

void go_stop_p5()
{
    // TODO:
}

void go_stop_p6()
{
    start_straight(2450);
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

    start_straight(-1900);

    stop_ring();

    start_straight(5500);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2900);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1600);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);
}

void go_stop_p7()
{
    // TODO:
}

void go_stop_p8()
{
    // TODO:
}

void go_stop_p9()
{
    // TODO:
}

void go_stop_p10()
{
    // TODO:
}

void go_stop_p11()
{
    // TODO:
}

void go_stop_p12()
{
    // TODO:
}

void mode1()
{
    go_start_to_end();
}

void mode2()
{
    go_stop_p6();
}

void car_run()
{
    mode2();
}
