#include "stdlib.h"
#include "stdio.h"
#include "printTo.h"

typedef struct PID
{
    int head;
    int data_len;
    float kp;
    float ki;
    float kd;
    float i_max;
    int is_first;
    float *data;
} PID;

/// @brief 初始化PID
/// @param kp k值
/// @param ki i值
/// @param kd d值
/// @param data_len 积分最大长度
/// @param i_max 积分小于i_max时积分项才生效，防止过冲
/// @return 返回PID结构体的指针
PID *initPID(float kp, float ki, float kd, int data_len, float i_max)
{
    PID *pid = (PID *)malloc(sizeof(PID));

    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->i_max = i_max;
    pid->data_len = data_len;
    pid->data = (float *)malloc(sizeof(float) * data_len);
    for (int i = 0; i < data_len; i++)
        pid->data[i] = 0;
    pid->is_first = 1;
    pid->head = 0;

    return pid;
}

void update_Data(PID *pid, float cur, float tar)
{
    float err = tar - cur;
    pid->data[pid->head] = err;
    pid->head++;
    pid->head %= pid->data_len;
}

float get_P(PID *pid)
{
    float temp = 0;
    if (pid->head == 0)
        temp = pid->data[pid->data_len - 1];
    else
        temp = pid->data[pid->head - 1];
    // printTo(uart1, "P:%.0f\r\n", temp);
    return temp;
}

float get_I(PID *pid)
{
    float temp = 0;
    for (int i = 0; i < pid->data_len; i++)
        if (pid->data[i] <= pid->i_max)
            temp += pid->data[i];
    // printf("I:%.0f\r\n", temp);
    return temp;
}

float get_D(PID *pid)
{
    float temp = 0;
    if (pid->is_first == 0)
    {
        if (pid->head - 1 == 0)
        {
            temp = pid->data[pid->head - 1] - pid->data[pid->data_len - 1];
        }
        else if (pid->head != 0)
        {
            temp = pid->data[pid->head - 1] - pid->data[pid->head - 2];
        }
        else
        {
            temp = pid->data[pid->data_len - 1] - pid->data[pid->data_len - 2];
        }
    }
    else
    {
        pid->is_first = 0;
        temp = 0;
    }

    // printf("D:%.0f\r\n", temp);
    return temp;
}

/// @brief 返回PID的结果
/// @param pid 需要计算PID的PID结构体
/// @param cur 当前值
/// @param tar 目标值
/// @return 浮点类型的PID返回值
float returnPID(PID *pid, float cur, float tar)
{
    update_Data(pid, cur, tar);

    float P = get_P(pid);
    float I = get_I(pid);
    float D = get_D(pid);
    return pid->kp * P + pid->ki * I + pid->kd * D;
}
