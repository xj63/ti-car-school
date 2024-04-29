/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-29 14:26:01
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-29 14:43:12
 * @FilePath: \WuYi_xiaosai\Core\user\car_run.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "main.h"
#include "findline.h"
#include "turn.h"
#include "straight.h"
#include "turn_abs.h"
#include "keep.h"

void car_run()
{
    start_straight(2000);
    start_keep_angle(0);
    turn_abs_start_turn(90);
    start_straight(2000);
    start_keep_angle(90);
    turn_abs_start_turn(40);
    start_straight(2000);
    start_keep_angle(40);
}
