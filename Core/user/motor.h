/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-03-26 23:09:02
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-17 17:00:02
 * @FilePath: \DaChuang\Core\user\motor.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __MOTOR_H
#define __MOTOR_H

#include "main.h"

enum Motor
{
    M_L,
    M_R,
    M_G
};

extern void motor_setSpeed(int s1, int s2, int s3);
extern void motor_init();
extern int32_t motor_getSpeed(enum Motor M);
extern void motor_stop();

#endif
