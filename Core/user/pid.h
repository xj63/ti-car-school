/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-03-26 23:25:23
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-03-26 23:25:56
 * @FilePath: \DaChuang\Core\user\pid.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-03-26 23:25:23
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-03-26 23:25:33
 * @FilePath: \DaChuang\Core\user\pid.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __PID_H_
#define __PID_H_

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

PID *initPID(float kp, float ki, float kd, int data_len, float i_max);
void reinitPID(PID *pid);
float returnPID(PID *pid, float cur, float tar);

#endif
