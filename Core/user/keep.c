/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-28 21:11:33
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-30 15:31:28
 * @FilePath: \WuYi_xiaosai\Core\user\keep.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "keep.h"
#include "motor_control.h"
#include "pid_yuan.h"
#include "turn.h"
#include "turn_abs.h"
#include "include_user_all.h"

#include <stdint.h>

static struct pid_data keep_angle_pid;

void keep_angle_set(float angle)
{
    static_keep_angle = angle;
    // pid_init(&keep_angle_pid, 0, 3, 0.4, 5, 5);
    pid_init(&keep_angle_pid, 0, 3, 0.3, 3, 5);
}

void start_keep_angle(float angle)
{
    if (straight_flag == 1)
    {
        keep_angle_set(angle);
        keepangle_flag = 1;
    }
}

void keep_angle()
{
    if (keepangle_flag == 1)
    {
        if (straight_flag == 0)
        {
            keepangle_flag = 0;
            return;
        }
        float diff;
        diff = turn_head_diff(static_keep_angle, turn_abs_origin);
        int turn_speed = pid_inc(&keep_angle_pid, -diff);
        printTo(uart3, "%f    %d\r\n", diff, turn_speed);
        if (turn_speed > TURN_SPEED)
            turn_speed = TURN_SPEED;
        if (turn_speed < -TURN_SPEED)
            turn_speed = -TURN_SPEED;
        left_tar += -turn_speed;
        right_tar += turn_speed;
    }
}
