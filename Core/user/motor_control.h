/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-03 23:09:00
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-07 19:05:53
 * @FilePath: \DaChuang\Core\user\motor_control.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __MOTOR_CONTROL_H
#define __MOTOR_CONTROL_H

#include "main.h"

#define TURN_SPEED 30
#define STRAIGHT_SPEED 30

extern int8_t left_tar;
extern int8_t right_tar;
extern int8_t gun_tar;
extern int8_t left_cur;
extern int8_t right_cur;
extern int8_t gun_cur;
extern uint8_t turn_flag;
extern uint8_t straight_flag;
extern uint8_t moving_flag;

extern void motor_driver();
extern void start_straight(int16_t L);
extern void start_turn(float turn_angle);

#endif
