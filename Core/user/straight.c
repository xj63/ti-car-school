/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-03 23:56:39
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-19 19:48:57
 * @FilePath: \DaChuang\Core\user\straight.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "pid.h"
#include "motor_control.h"
#include "printTo.h"
#include "stdlib.h"

int16_t straight_L = 0;
struct PID *speed_XZ_pid = NULL;

void start_straight(int16_t L)
{
    while (moving_flag)
        ;
    straight_L = L;
    straight_flag = 1;
    moving_flag = turn_flag | straight_flag;
    speed_XZ_pid = initPID(0.1, 0, 0, 5, 10);
}

void straight()
{
    static int32_t left_L = 0;
    static int32_t right_L = 0;
    if (straight_flag)
    {
        if (straight_L > 0)
        {
            left_L += left_cur;
            right_L += right_cur;
            int16_t diff = left_L - right_L;
            int16_t speed_XZ = returnPID(speed_XZ_pid, diff, 0);
            left_tar = STRAIGHT_SPEED + speed_XZ; // 修正两边轮子走的距离不一样的问题
            right_tar = STRAIGHT_SPEED - speed_XZ;
            straight_L -= (left_cur + right_cur) / 2;
						// printTo(uart3, "%d, %d, %d, %d, %d\r\n", left_L, right_L, left_tar, right_tar, speed_XZ);

        }
        else
        {
            straight_flag = 0;
            left_tar = 0;
            right_tar = 0;
            straight_L = 0;
            free(speed_XZ_pid);
            speed_XZ_pid = NULL;
            left_L = 0;
            right_L = 0;
        }
    }

    return;
}
