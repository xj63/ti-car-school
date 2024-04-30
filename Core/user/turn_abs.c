/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-03 22:47:52
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-17 22:33:33
 * @FilePath: \DaChuang\Core\user\turn.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-03 22:47:52
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-15 16:12:43
 * @FilePath: \DaChuang\Core\user\turn.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "include_user_all.h"
#include "motor.h"
#include "turn.h"
#include "pid.h"
#include "motor_control.h"
#include "pid_yuan.h"
#include "stdlib.h"
#include "main.h"

int8_t turn_abs_cnt = 0;
float turn_abs_angle = 0;
int8_t turn_abs_max_speed = 5;

struct PID *turn_abs_pid;
float turn_abs_origin;
float turn_abs_move_line_angle;
static struct pid_data turn_abs_head_data;
struct PID *turn_abs_XZ_pid = NULL;

/**
 * 初始化转向PID结构体
 */

// 初始化转向 得到原始角度 设置pid的值
void turn_abs_head_init()
{
    turn_abs_origin = Get_gyr_value(gyr_z_yaw) + 180;
    pid_init(&turn_abs_head_data, 0, 0.6, 0, 0, 5);
}

void turn_abs()
{
    static int16_t left_L = 0;
    static int16_t right_L = 0;
    if (turn_abs_flag)
    {
        float diff;

        left_L += abs_XZ(left_cur);
        right_L += abs_XZ(right_cur);
        int16_t diff_L = left_L - right_L;
        // int16_t turn_XZ = returnPID(turn_XZ_pid, diff_L, 0);
        int16_t turn_XZ = 0;
        diff = turn_head_diff(turn_abs_angle, turn_abs_origin);
        int turn_speed = pid_inc(&turn_abs_head_data, -diff);
        if ((diff <= 2) && (diff >= -2))
        {
            turn_abs_cnt--;
            if (turn_abs_cnt == 0)
            {
                turn_abs_flag = 0;
                turn_abs_angle = 0;
                left_tar = 0;
                right_tar = 0;
                left_L = 0;
                right_L = 0;
                // free(turn_abs_XZ_pid);
                // turn_abs_XZ_pid = NULL;
                return;
            }
        }
        if (turn_speed > 7)
            turn_speed = TURN_SPEED;
        if (turn_speed < -7)
            turn_speed = -TURN_SPEED;
        // printTo(uart1, "%d\r\n", turn_speed);
        left_tar = -turn_speed - turn_XZ;
        right_tar = turn_speed - turn_XZ;
        // printTo(uart3, "%d, %d, %d, %d, %d\r\n", left_L, right_L, left_tar, right_tar, turn_XZ);
    }
}

void turn_abs_start_turn(float turn_angle)
{
    while (get_flag())
        ;
    turn_abs_flag = 1;
    turn_abs_angle = turn_angle;
    turn_abs_cnt = 1;
    // turn_abs_XZ_pid = initPID(0.1, 0, 0, 1, 10);
    moving_flag = turn_flag | straight_flag | turn_abs_flag;
}
