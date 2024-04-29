#include "statement.h"
#include "math_utils.h"

struct Statement static_statement;

void statement_init(float direction_offset) {
  static_statement.direction_offset = direction_offset;
  static_statement.current.direction = direction_offset;

  // 无聊的填 0 阶段
  static_statement.target.wheels.left = 0;
  static_statement.target.wheels.right = 0;
  static_statement.target.direction = 0.0;

  static_statement.current.wheels.left = 0;
  static_statement.current.wheels.right = 0;
}

struct Wheels statement_diff_wheels() {
  struct Wheels ret;
  ret.left = static_statement.target.wheels.left -
             static_statement.current.wheels.left;
  ret.right = static_statement.target.wheels.right -
              static_statement.current.wheels.right;
  return ret;
}

float statement_diff_direction() {
  float target_absolute_direction =
      static_statement.target.direction + static_statement.direction_offset;

  float diff_direciton =
      target_absolute_direction - static_statement.current.direction;

  return wrapping(diff_direciton, -180.0, 180.0);
}

void statement_update_current_wheels() {
  // TODO: motor
}

void statement_update_current_direction() {
  // TODO: gy901
}

void statement_update_current() {
  statement_update_current_wheels();
  statement_update_current_direction();
}

void statement_set_direction_offset(float offset) {
  static_statement.direction_offset = offset;
}

void statement_set_target_direction(float relative_direction) {
  static_statement.target.direction = relative_direction;
}

float statement_get_target_direction_relative() {
  return static_statement.target.direction;
}

float statement_get_target_direction_absolute() {
  return wrapping(static_statement.target.direction +
                      static_statement.direction_offset,
                  -180.0, 180.0);
}

void statement_set_current_direction(float absolute_direction) {
  static_statement.current.direction = absolute_direction;
}

float statement_get_current_direction() {
  return static_statement.current.direction;
}

void statement_add_target_wheels_right(int16_t delta_speed) {
  static_statement.target.wheels.right += delta_speed;
}

void statement_add_target_wheels_left(int16_t delta_speed) {
  static_statement.target.wheels.left += delta_speed;
}

void statement_set_target_wheels_right(int16_t speed) {
  static_statement.target.wheels.right = speed;
}

int16_t statement_get_target_wheels_right() {
  return static_statement.target.wheels.right;
}

void statement_set_target_wheels_left(int16_t speed) {
  static_statement.target.wheels.left = speed;
}

int16_t statement_get_target_wheels_left() {
  return static_statement.target.wheels.left;
}

void statement_set_current_wheels_right(int16_t speed) {
  static_statement.current.wheels.right = speed;
}

int16_t statement_get_current_wheels_right() {
  return static_statement.current.wheels.right;
}

void statement_set_current_wheels_left(int16_t speed) {
  static_statement.current.wheels.left = speed;
}

int16_t statement_get_current_wheels_left() {
  return static_statement.current.wheels.left;
}
