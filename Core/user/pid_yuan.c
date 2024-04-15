#include "pid_yuan.h"

void pid_init(struct pid_data *data, float target, float k_p, float k_i,
              float k_d, unsigned char pid_data_loop_length)
{
    data->k_p = k_p;
    data->k_i = k_i;
    data->k_d = k_d;
    data->target = target;
    data->index = 0;
    data->pid_data_loop_length = pid_data_loop_length;
    for (int i = 0; i < pid_data_loop_length; i++)
        data->error_history_loop[i] = 0;
    data->error_sum = 0;
}

void pid_set_target(struct pid_data *data, float target)
{
    data->target = target;
}

int pid_inc(struct pid_data *data, float actural_speed)
{
    float err = data->target - actural_speed;

    data->error_sum += err - data->error_history_loop[data->index];
    data->error_history_loop[data->index] = err;

    float P = err;
    float I = (float)data->error_sum / data->pid_data_loop_length;
    float D = data->index == 0
                  ? err - data->error_history_loop[data->pid_data_loop_length - 1]
                  : err - data->error_history_loop[data->index - 1];
    data->index =
        data->index + 1 == data->pid_data_loop_length ? 0 : data->index + 1;

    // if I is to big then limit it
    I = limit(I, PID_I_LIMIT);

    return data->k_p * P + data->k_i * I + data->k_d * D;
}

float limit(float value, float edge)
{
    edge = edge >= 0 ? edge : -edge;
    if (value >= edge)
        return edge;
    if (value <= -edge)
        return -edge;
    return value;
}
