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
#include "pid.h"
#include "motor_control.h"
#include "pid_yuan.h"
#include "stdlib.h"
#include "main.h"

int8_t turn_cnt = 0;
int8_t turn_init_flag = 0;
float angle = 0;
int8_t max_speed = 5;

float turn_head_abs(float num) { return num >= 0 ? num : -num; }
int16_t abs_XZ(int16_t num) { return num >= 0 ? num : -num; };
struct PID *turn_pid;
float origin;
float move_line_angle;
static struct pid_data turn_head_data;
struct PID *turn_XZ_pid = NULL;

/**
 * 初始化转向PID结构体
 */

// 初始化转向 得到原始角度 设置pid的值
void turn_head_init()
{
    origin = Get_gyr_value(gyr_z_yaw) + 180;
    pid_init(&turn_head_data, 0, 0.6, 0, 0, 5);
}

// 传入目标旋转角度 初始角度
// 输出偏差值
float turn_head_diff(float angle, float origin_angle)
{
    float current = Get_gyr_value(gyr_z_yaw) + 180;
    float target = origin_angle + angle;
    target = target > 360 ? target - 360 : target;
    target = target < 0 ? target + 360 : target;
    float tc = target - current;
    if (turn_head_abs(tc) <= 180)
        return tc;
    else
    {
        if (tc > 180)
            return tc - 360;
        else
            return tc + 360;
    };
}

void turn()
{
    static int16_t left_L = 0;
    static int16_t right_L = 0;
    if (turn_flag)
    {
        float diff;

        left_L += abs_XZ(left_cur);
        right_L += abs_XZ(right_cur);
        int16_t diff_L = left_L - right_L;
        // int16_t turn_XZ = returnPID(turn_XZ_pid, diff_L, 0);
        int16_t turn_XZ = 0;
        if (turn_init_flag == 1)
        {
            turn_head_init();
            turn_init_flag = 0;
        }
        diff = turn_head_diff(angle, origin);
        int turn_speed = pid_inc(&turn_head_data, -diff);
        if ((diff <= 2) && (diff >= -2))
        {
            turn_cnt--;
            if (turn_cnt == 0)
            {
                turn_flag = 0;
                angle = 0;
                origin = 0;
                left_tar = 0;
                right_tar = 0;
                left_L = 0;
                right_L = 0;
                free(turn_XZ_pid);
                turn_XZ_pid = NULL;
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

void start_turn(float turn_angle)
{
    while (get_flag())
        ;
    turn_flag = 1;
    turn_init_flag = 1;
    angle = turn_angle;
    turn_cnt = 1;
    turn_XZ_pid = initPID(0.1, 0, 0, 1, 10);
    moving_flag = turn_flag | straight_flag;
}
