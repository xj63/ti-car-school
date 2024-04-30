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
    buzzer_ring(3);
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

    buzzer_ring(3);
}

void go_stop_p1()
{
    start_straight(2450);
    start_keep_angle(0.0);
    turn_abs_start_turn(45.0);
    start_straight(1200);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(1700);
    start_keep_angle(90.0);

    stop_ring();

    start_straight(-1400);
    start_keep_angle(90.0);

    turn_abs_start_turn(0.0);
    start_straight(3600);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(700);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(3400);
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

    buzzer_ring(3);
}

void go_stop_p2()
{
    start_straight(2450);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(1800);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(1100);
    start_keep_angle(0.0);

    {
        turn_abs_start_turn(90.0);
        start_straight(-1600);
        start_keep_angle(90.0);

        stop_ring();

        start_straight(1600);
        start_keep_angle(90.0);
    }

    turn_abs_start_turn(0.0);
    start_straight(2000);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(700);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(3400);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2900);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1800);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2300);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p3()
{
    start_straight(2450);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(1800);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(1050);
    start_keep_angle(0.0);

    {
        turn_abs_start_turn(90.0);
        start_straight(1200);
        start_keep_angle(90.0);

        stop_ring();

        start_straight(-1200);
        start_keep_angle(90.0);
    }

    turn_abs_start_turn(0.0);
    start_straight(2000);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(700);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(3400);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(3000);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2300);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p4()
{
    start_straight(2450);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(1800);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(2330);
    start_keep_angle(0.0);

    {
        turn_abs_start_turn(90.0);
        start_straight(-1600);
        start_keep_angle(90.0);

        stop_ring();

        start_straight(1600);
        start_keep_angle(90.0);
    }

    turn_abs_start_turn(0.0);
    start_straight(850);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(700);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(3400);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2900);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1800);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2300);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p5()
{
    start_straight(2450);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(1800);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(2250);
    start_keep_angle(0.0);

    {
        turn_abs_start_turn(90.0);
        start_straight(1300);
        start_keep_angle(90.0);

        stop_ring();

        start_straight(-1300);
        start_keep_angle(90.0);
    }

    turn_abs_start_turn(0.0);
    start_straight(800);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(700);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(3400);
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
    start_straight(2300);
    start_keep_angle(180.0);

    buzzer_ring(3);
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
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p7()
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

    start_straight(5200);
    start_keep_angle(90.0);

    {
        stop_ring();
        start_straight(-1800);
        start_keep_angle(90.0);
    }

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2900);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1800);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p8()
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
    start_straight(3500);
    start_keep_angle(90.0);

    turn_abs_start_turn(135.0);
    start_straight(700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(970);
    start_keep_angle(180.0);

    {
        turn_abs_start_turn(270.0);
        start_straight(1300);
        start_keep_angle(270.0);

        stop_ring();

        start_straight(-1300);
        start_keep_angle(270.0);
    }

    turn_abs_start_turn(180.0);
    start_straight(2030);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);

    buzzer_ring(3);
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
    go_stop_p8();
}
