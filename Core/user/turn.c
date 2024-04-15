#include "gy901.h"
#include "motor.h"
#include "pid_yuan.h"
#include "motor_control.h"
#include "printTo.h"

int8_t turn_cnt = 0;
int8_t turn_init_flag = 0;
float angle = 0;
int8_t max_speed = 5;

float turn_head_abs(float num) { return num >= 0 ? num : -num; }
static struct pid_data turn_head_data;
float origin;
float move_line_angle;

// 初始化转向 得到原始角度 设置pid的值
void turn_head_init()
{
    origin = Get_gyr_value(gyr_z_yaw) + 180;
    pid_init(&turn_head_data, 0, 0.7, 0, 0.8, 20);
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
    if (turn_flag)
    {
        float diff;

        if (turn_init_flag == 1)
        {
            turn_head_init();
            turn_init_flag = 0;
        }
        diff = turn_head_diff(angle, origin);
        int turn_speed = pid_inc(&turn_head_data, -diff);
        printTo(uart1, "%.2f    %d\r\n", diff, turn_cnt);
        if ((diff <= 2) && (diff >= -2))
            turn_cnt--;
        if (turn_cnt == 0)
        {
            turn_flag = 0;
            angle = 0;
            origin = 0;
            left_tar = 0;
            right_tar = 0;
            return;
        }
        if (turn_speed > 20)
            turn_speed = TURN_SPEED;
        if (turn_speed < -20)
            turn_speed = -TURN_SPEED;
        left_tar = -turn_speed;
        right_tar = turn_speed;
    }
}

void start_turn(float turn_angle)
{
    while (moving_flag)
        continue;
    turn_flag = 1;
    turn_init_flag = 1;
    angle = turn_angle;
    turn_cnt = 1;
}
