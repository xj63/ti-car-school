/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-03-26 23:09:10
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-17 16:59:30
 * @FilePath: \DaChuang\Core\user\motor.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEif（
 */
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "motor.h"
#include "pid.h"
#include "include_user_all.h"
#include "motor_control.h"

PID *M_1;
PID *M_2;
PID *M_3;

void motor_init()
{
    M_1 = initPID(15, 10, 10, 5, 100);
    M_2 = initPID(10, 10, 10, 5, 100);
    M_3 = initPID(10, 10, 10, 5, 100);

    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);

    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);

    HAL_GPIO_WritePin(M1_D1_GPIO_Port, M1_D1_Pin, 1);
    HAL_GPIO_WritePin(M1_D2_GPIO_Port, M1_D2_Pin, 0);
    HAL_GPIO_WritePin(M2_D1_GPIO_Port, M2_D1_Pin, 1);
    HAL_GPIO_WritePin(M2_D2_GPIO_Port, M2_D2_Pin, 0);
    HAL_GPIO_WritePin(M3_D1_GPIO_Port, M3_D1_Pin, 1);
    HAL_GPIO_WritePin(M3_D2_GPIO_Port, M3_D2_Pin, 0);

    HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);

    __HAL_TIM_SET_COUNTER(&htim1, 0xEFFF);
    __HAL_TIM_SET_COUNTER(&htim2, 0xEFFF);
    __HAL_TIM_SET_COUNTER(&htim3, 0xEFFF);

    return;
}

int32_t motor_getSpeed(enum Motor M)
{
    int32_t buf = 0;
    if (M == M_L)
    {
        buf = __HAL_TIM_GET_COUNTER(&htim3) - 0xEFFF;
        __HAL_TIM_SET_COUNTER(&htim3, 0xEFFF);
    }
    if (M == M_R)
    {
        buf = __HAL_TIM_GET_COUNTER(&htim2) - 0xEFFF;
        __HAL_TIM_SET_COUNTER(&htim2, 0xEFFF);
    }
    if (M == M_G)
    {
        buf = __HAL_TIM_GET_COUNTER(&htim1) - 0xEFFF;
        __HAL_TIM_SET_COUNTER(&htim1, 0xEFFF);
    }
    return buf;
}

int32_t abs(int32_t B)
{
    if (B <= 0)
    {
        return -B;
    }
    else
    {
        return B;
    }
}

int32_t M1_P_buf = 0;
int32_t M2_P_buf = 0;

void motor_setSpeed(int s1, int s2, int s3)
{

    static int32_t M3_P_buf = 0;

    int32_t max_P = 50000;
    M1_P_buf += returnPID(M_1, left_cur, s1);
    M2_P_buf += returnPID(M_2, right_cur, s2);
    M3_P_buf += returnPID(M_3, gun_cur, s3);

    int32_t M1_P = M1_P_buf;
    int32_t M2_P = M2_P_buf;
    int32_t M3_P = M3_P_buf;

    if (M1_P >= 0)
    {
        HAL_GPIO_WritePin(M1_D1_GPIO_Port, M1_D1_Pin, 1);
        HAL_GPIO_WritePin(M1_D2_GPIO_Port, M1_D2_Pin, 0);
    }
    else
    {
        HAL_GPIO_WritePin(M1_D1_GPIO_Port, M1_D1_Pin, 0);
        HAL_GPIO_WritePin(M1_D2_GPIO_Port, M1_D2_Pin, 1);
    }
    M1_P = abs(M1_P);

    if (s1 != 0)
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, M1_P);
    else
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
    if (M2_P >= 0)
    {
        HAL_GPIO_WritePin(M2_D1_GPIO_Port, M2_D1_Pin, 1);
        HAL_GPIO_WritePin(M2_D2_GPIO_Port, M2_D2_Pin, 0);
    }
    else
    {
        HAL_GPIO_WritePin(M2_D1_GPIO_Port, M2_D1_Pin, 0);
        HAL_GPIO_WritePin(M2_D2_GPIO_Port, M2_D2_Pin, 1);
    }
    M2_P = abs(M2_P);
    if (M2_P > max_P)
        M2_P = max_P;
    if (s2 != 0)
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, M2_P);
    else
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
    if (M3_P >= 0)
    {
        HAL_GPIO_WritePin(M3_D1_GPIO_Port, M3_D1_Pin, 1);
        HAL_GPIO_WritePin(M3_D2_GPIO_Port, M3_D2_Pin, 0);
    }
    else
    {
        HAL_GPIO_WritePin(M3_D1_GPIO_Port, M3_D1_Pin, 0);
        HAL_GPIO_WritePin(M3_D2_GPIO_Port, M3_D2_Pin, 1);
    }
    M3_P = abs(M3_P);
    if (M3_P > max_P)
        M3_P = max_P;
    if (s3 != 0)
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, M3_P);
    else
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);

    return;
}

void motor_stop()
{
    if (!get_flag())
    {
        left_tar = 0;
        right_tar = 0;
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
        HAL_GPIO_WritePin(M1_D1_GPIO_Port, M1_D1_Pin, 1);
        HAL_GPIO_WritePin(M1_D2_GPIO_Port, M1_D2_Pin, 1);
        HAL_GPIO_WritePin(M2_D1_GPIO_Port, M2_D1_Pin, 1);
        HAL_GPIO_WritePin(M2_D2_GPIO_Port, M2_D2_Pin, 1);
				M1_P_buf = 0;
				M2_P_buf = 0;
    }

		return;
}

