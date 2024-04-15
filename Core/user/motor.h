#ifndef __MOTOR_H
#define __MOTOR_H

#include "main.h"

enum Motor
{
    M_L,
    M_R,
    M_G
};

extern void motor_setSpeed(int s1, int s2, int s3);
extern void motor_init();
extern int32_t motor_getSpeed(enum Motor M);

#endif
