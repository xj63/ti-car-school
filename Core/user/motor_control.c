/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-03 23:07:57
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-15 16:02:00
 * @FilePath: \DaChuang\Core\user\motor_control.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "main.h"
#include "motor.h"
#include "turn.h"
#include "straight.h"
#include "motor_control.h"
#include "printTo.h"

int8_t left_tar = 0;
int8_t right_tar = 0;
int8_t gun_tar = 0;
int8_t left_cur = 0;
int8_t right_cur = 0;
int8_t gun_cur = 0;
uint8_t turn_flag = 0;
uint8_t straight_flag = 0;
uint8_t moving_flag = 0;

void motor_driver()
{
    left_cur = -motor_getSpeed(M_L);
    right_cur = motor_getSpeed(M_R);
    gun_cur = motor_getSpeed(M_G);

    moving_flag = turn_flag | straight_flag;

		//printTo(uart1, "move:%d turn:%d stra:%d\r\n", moving_flag, turn_flag, straight_flag);

    turn();
    straight();
    motor_stop();

    motor_setSpeed(left_tar, right_tar, gun_tar);

    return;
}
