#include "include_user_all.h"
#include "findline.h"
#include "keep.h"
#include "main.h"
#include "straight.h"
#include "turn.h"
#include "usart.h"
#include "turn_abs.h"

uint8_t sta = 0xff;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Receive_IT(&huart3, &sta, 1);
	  // printTo(uart4, "%hhu\r\n", sta);
	  turn_abs_head_init();
}

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
    buzzer_ring(3);
}

void go_start_to_end()
{
    delay(5);
    buzzer_ring(3);

    start_straight(2450);
    start_keep_angle(0.0);
    turn_abs_start_turn(45.0);
    start_straight(1700);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(3200);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(900);
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
    start_straight(1800);
    start_keep_angle(135.0);

    turn_abs_start_turn(178.0);
    start_straight(2000);
    start_keep_angle(178.0);

    buzzer_ring(3);
}

void go_stop_p1()
{
    delay(5);
    buzzer_ring(3);

    start_straight(2450);
    start_keep_angle(0.0);
    turn_abs_start_turn(45.0);
    start_straight(1200);
    start_keep_angle(45.0);

    turn_abs_start_turn(90.0);
    start_straight(1780);
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
    start_straight(900);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2700);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1800);
    start_keep_angle(135.0);

    turn_abs_start_turn(175.0);
    start_straight(1900);
    start_keep_angle(175.0);

    buzzer_ring(3);
}

void go_stop_p2()
{
    delay(5);
    buzzer_ring(3);

    start_straight(2450);
    start_keep_angle(0.0);

    turn_abs_start_turn(45.0);
    start_straight(1800);
    start_keep_angle(45.0);

    turn_abs_start_turn(0.0);
    start_straight(1120);
    start_keep_angle(0.0);

    {
        turn_abs_start_turn(90.0);
        start_straight(-1400);
        start_keep_angle(90.0);

        stop_ring();

        start_straight(1400);
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
    start_straight(900);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2600);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1900);
    start_keep_angle(135.0);

    turn_abs_start_turn(175.0);
    start_straight(1900);
    start_keep_angle(175.0);

    buzzer_ring(3);
}

void go_stop_p3()
{
    delay(5);
    buzzer_ring(3);

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
    delay(5);
    buzzer_ring(3);

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
    delay(5);
    buzzer_ring(3);

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
    delay(5);
    buzzer_ring(3);

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
    delay(5);
    buzzer_ring(3);

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
    delay(5);
    buzzer_ring(3);

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
        start_straight(1400);
        start_keep_angle(270.0);

        stop_ring();

        start_straight(-1400);
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
    delay(5);
    buzzer_ring(3);

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
    start_straight(900);
    start_keep_angle(180.0);

    {
        turn_abs_start_turn(270.0);
        start_straight(-1400);
        start_keep_angle(270.0);

        stop_ring();

        start_straight(1400);
        start_keep_angle(270.0);
    }

    turn_abs_start_turn(180.0);
    start_straight(2050);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p10()
{
    delay(5);
    buzzer_ring(3);

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
    start_straight(2170);
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
    start_straight(880);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p11()
{
    delay(5);
    buzzer_ring(3);

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
    start_straight(2100);
    start_keep_angle(180.0);

    {
        turn_abs_start_turn(270.0);
        start_straight(-1300);
        start_keep_angle(270.0);

        stop_ring();

        start_straight(1300);
        start_keep_angle(270.0);
    }

    turn_abs_start_turn(180.0);
    start_straight(880);
    start_keep_angle(180.0);

    turn_abs_start_turn(135.0);
    start_straight(1700);
    start_keep_angle(135.0);

    turn_abs_start_turn(180.0);
    start_straight(2000);
    start_keep_angle(180.0);

    buzzer_ring(3);
}

void go_stop_p12()
{
    delay(5);
    buzzer_ring(3);

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
    start_straight(3400);
    start_keep_angle(180.0);

    {
        turn_abs_start_turn(90.0);
        start_straight(-1500);
        start_keep_angle(90.0);

        stop_ring();

        turn_abs_start_turn(90.0);
        start_straight(1500);
        start_keep_angle(90.0);

        start_straight(4000);
        start_keep_angle(180.0);
    }

    buzzer_ring(3);
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
    while (1)
    {
        switch (sta) {
            case 0:  go_start_to_end();  break;
            case 1:
            case 21: go_stop_p1();       break;
            case 2:
            case 22: go_stop_p2();       break;
            case 3:
            case 23: go_stop_p3();       break;
            case 4:
            case 24: go_stop_p4();       break;
            case 5:
            case 25: go_stop_p5();       break;
            case 6:
            case 26: go_stop_p6();       break;
            case 7:
            case 27: go_stop_p7();       break;
            case 8:
            case 28: go_stop_p8();       break;
            case 9:
            case 29: go_stop_p9();       break;
            case 10:
            case 30: go_stop_p10();      break;
            case 11:
            case 31: go_stop_p11();      break;
            case 12:
            case 32: go_stop_p12();      break;
            default: continue;
        }
        sta = 0xff;
    }
}
