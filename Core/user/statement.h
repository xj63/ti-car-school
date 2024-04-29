#ifndef __STATEMENT_H__
#define __STATEMENT_H__

#ifdef DEV
#include <stdint.h>
#endif // DEV

struct Wheels {
  int16_t right;
  int16_t left;
};

struct Status {
  struct Wheels wheels;
  float direction;
};

struct Statement {
  struct Status current;
  struct Status target;

  /// 方向偏移设置，target 加上偏移是绝对目标方向
  float direction_offset;
};

extern struct Statement static_statement;

void statement_init(float direction_offset);

struct Wheels statement_diff_wheels();

float statement_diff_direction();

/// 一些 update 函数
void statement_update_current_wheels();
void statement_update_current_direction();
void statement_update_current();

/// 一些 set get 函数

void statement_set_direction_offset(float offset);

void statement_set_target_direction(float relative_direction);
float statement_get_target_direction_relative();
float statement_get_target_direction_absolute();
void statement_set_current_direction(float absolute_direction);
float statement_get_current_direction();

void statement_add_target_wheels_right(int16_t delta_speed);
void statement_add_target_wheels_left(int16_t delta_speed);

void statement_set_target_wheels_right(int16_t speed);
int16_t statement_get_target_wheels_right();
void statement_set_target_wheels_left(int16_t speed);
int16_t statement_get_target_wheels_left();
void statement_set_current_wheels_right(int16_t speed);
int16_t statement_get_current_wheels_right();
void statement_set_current_wheels_left(int16_t speed);
int16_t statement_get_current_wheels_left();

#endif // !__STATEMENT_H__
