#include "color_terminal.h"
#include "../math_utils.h"
#include "unit_test.h"
#include <stdio.h>
#include <stdlib.h>

void test_wrapping() {
  assert_eq_float(9.0, wrapping(9.0, 10.0, 9.0)); // error 范围错误
  assert_eq_float(9.0, wrapping(9.0, 0.0, 10.0)); // 在范围内
  assert_eq_float(1.0, wrapping(9.0, 0.0, 4.0));  // 回绕
  assert_eq_float(2.0, wrapping(0.0, 1.0, 3.0));  // 回绕
  assert_eq_float(96.0, wrapping(456.0, -180.0, 180.0));  // 回绕
  assert_eq_float(96.0, wrapping(-624.0, -180.0, 180.0));  // 回绕
  puts("test_wrapping is " COLOR_TERMINAL_GREEN("ok"));
}

int main(int argc, char *argv[]) {
  test_wrapping();
  return EXIT_SUCCESS;
}
