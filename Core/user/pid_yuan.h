#ifndef __PID_H__
#define __PID_H__

#define PID_DATA_LOOP_LENGTH_MAX 40
#define PID_I_LIMIT 40

struct pid_data
{
    float k_p, k_i, k_d;
    float target;
    unsigned char index;
    unsigned char pid_data_loop_length;
    float error_history_loop[PID_DATA_LOOP_LENGTH_MAX];
    float error_sum;
};

/*
 * PID 参数设置
 */
void pid_init(struct pid_data *data, float target, float k_p, float k_i,
              float k_d, unsigned char pid_data_loop_length);

/* PID 目标值设置 */
void pid_set_target(struct pid_data *data, float target);

/* 获取 PID 偏差 */
int pid_inc(struct pid_data *data, float actural_speed);

/*
 * The distance from the limit value to the origin does not exceed the distance
 * from the boundary to the origin
 */
float limit(float value, float edge);

#endif // !__PID_H__
