#include "gw_findline.h"
#include "printTo.h"
#include "motor_control.h"
#include "pid.h"
#include "stdlib.h"

int8_t bin(int16_t buf)
{
    if (buf != 0)
        return 1;
    else
        return 0;
}

float find_line_diff()
{
    uint8_t buf = gw_gray_get_line_digital_is_black();
    int8_t cnt = 0;
    float diff = 0;
    diff += bin(buf & 0x01) * 10;
    diff += bin(buf & 0x02) * 5;
    diff += bin(buf & 0x04) * 2;
    diff += bin(buf & 0x08) * 1;
    diff += bin(buf & 0x10) * -1;
    diff += bin(buf & 0x20) * -2;
    diff += bin(buf & 0x40) * -5;
    diff += bin(buf & 0x80) * -10;

    while (buf)
    {
        if (buf & 0x01)
            cnt++;
        buf = buf >> 1;
    }
    if (cnt == 0)
        cnt = 1;

    printTo(uart1, "%f\r\n", diff / cnt);

    return diff / cnt;
}

PID *findline_pid;

void start_findline()
{
    findline_flag = 1;
    findline_pid = initPID(0.5, 0, 0, 10, 50);
}

void stop_findline()
{
    findline_flag = 0;
    free(findline_pid);
    findline_pid = NULL;
}

void findline()
{
    if (findline_flag == 1)
    {
        if (straight_flag == 0)
        {
            stop_findline();
            return;
        }
        float diff = find_line_diff();
        int8_t XZ = returnPID(findline_pid, diff, 0);

        left_tar += XZ;
        right_tar -= XZ;
    }

    return;
}
