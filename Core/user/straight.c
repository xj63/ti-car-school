#include "pid.h"
#include "motor_control.h"

int16_t straight_L = 0;

void start_straight(int16_t L)
{
    while (moving_flag)
        continue;
    straight_L = L;
    straight_flag = 1;
}

void straight()
{
    if (straight_flag)
    {
        if (straight_L > 0)
        {
            left_tar = STRAIGHT_SPEED;
            right_tar = STRAIGHT_SPEED;
            straight_L -= (left_cur + right_cur);
        }
        else
        {
            straight_flag = 0;
            left_tar = 0;
            right_tar = 0;
            straight_L = 0;
        }
    }

    return;
}
