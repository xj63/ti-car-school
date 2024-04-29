#include "assert.h"
#include "unit_test.h"
#include <stdlib.h>

/*
#include "../statement.h"
void test_statement_diff_wheel() {
  statement_init_for_test(90.0);

  struct Wheels diff;
  diff = statement_diff_wheels();
  assert_eq_int(0, diff.left);
  assert_eq_int(0, diff.right);

  statement_set_target_wheels_left(20);
  diff = statement_diff_wheels();
  assert_eq_int(20, diff.left);
  assert_eq_int(0, diff.right);

  statement_set_current_wheels_left(20);
  diff = statement_diff_wheels();
  assert_eq_int(0, diff.left);
  assert_eq_int(0, diff.right);

  statement_set_target_wheels_right(20);
  diff = statement_diff_wheels();
  assert_eq_int(0, diff.left);
  assert_eq_int(20, diff.right);

  statement_set_current_wheels_right(20);
  diff = statement_diff_wheels();
  assert_eq_int(0, diff.left);
  assert_eq_int(0, diff.right);

  statement_add_target_wheels_right(1);
  diff = statement_diff_wheels();
  assert_eq_int(0, diff.left);
  assert_eq_int(1, diff.right);

  statement_add_target_wheels_left(1);
  diff = statement_diff_wheels();
  assert_eq_int(1, diff.left);
  assert_eq_int(1, diff.right);

  puts("test_statement_diff_wheel is " COLOR_TERMINAL_GREEN("ok"));
}

void test_statement_diff_direction() {
  statement_init_for_test(90.0);

  float diff;
  diff = statement_diff_direction();
  assert_eq_float(0.0, diff);

  statement_set_current_direction(45.0);
  diff = statement_diff_direction();
  assert_eq_float(45.0, diff);

  statement_set_target_direction(45.0);
  diff = statement_diff_direction();
  assert_eq_float(90.0, diff);

  statement_set_direction_offset(0.0);
  diff = statement_diff_direction();
  assert_eq_float(0.0, diff);

  statement_init_for_test(90.0);
  statement_set_current_direction(180.0);
  statement_set_target_direction(-270.0);
  diff = statement_diff_direction();
  assert_eq_float(0.0, diff);

  puts("test_statement_diff_direction is " COLOR_TERMINAL_GREEN("ok"));
}
*/

int main(int argc, char *argv[]) {
  // test_statement_diff_wheel();
  // test_statement_diff_direction();
  panic(0, "由于statement中使用了一些硬件，目前已经不能进行测试");
  return EXIT_SUCCESS;
}
