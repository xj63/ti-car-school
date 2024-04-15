#ifndef __TURN_HEAD_H__
#define __TURN_HEAD_H__

/*
 * @brief 转向一个角度
 * @para angle 逆时针
 * 一次性不要让他转超过180度
 */
extern void turn();
extern void turn_head_init();
extern void start_turn(float angle);

#endif // !__TURN_HEAD_H__
