/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-03 23:56:39
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-30 17:58:01
 * @FilePath: \DaChuang\Core\user\straight.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "include_user_all.h"
#include "keep.h"
#include "motor_control.h"
#include "pid.h"
#include "stdlib.h"

int16_t straight_L = 0;
uint8_t is_forward = 1;
struct PID *speed_XZ_pid = NULL;

void start_straight(int16_t L)
{
    while (get_flag())
        ;
    is_forward = L >= 0 ? 1 : 0;
    straight_L = is_forward ? L : -L;
    straight_flag = 1;
    // moving_flag = turn_flag | straight_flag;
    // speed_XZ_pid = initPID(0, 0, 0, 5, 10);
}

void straight()
{
    static int32_t left_L = 0;
    static int32_t right_L = 0;
    if (straight_flag)
    {
        if (straight_L > 0)
        {
            // left_L += left_cur;
            // right_L += right_cur;
            // int16_t diff = left_L - right_L;
            // int16_t speed_XZ = returnPID(speed_XZ_pid, diff, 0);

            int8_t straight_speed = is_forward ? STRAIGHT_SPEED : -STRAIGHT_SPEED;
            if (straight_L < 500)
                straight_speed = straight_speed / 2;
            if (straight_L < 100)
                straight_speed = straight_speed / 2;
            left_tar += straight_speed; // 修正两边轮子走的距离不一样的问题
            right_tar += straight_speed;

            if (is_forward)
                straight_L -= (left_cur + right_cur) / 2;
            else
                straight_L += (left_cur + right_cur) / 2;

            // printTo(uart3, "%d, %d, %d, %d, %d\r\n", left_L, right_L, left_tar,
            // right_tar, speed_XZ);
        }
        else
        {
            straight_flag = 0;
            left_tar = 0;
            right_tar = 0;
            straight_L = 0;
            // free(speed_XZ_pid);
            speed_XZ_pid = NULL;
            left_L = 0;
            right_L = 0;
        }
    }

    return;
}
