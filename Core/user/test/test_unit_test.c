#include "color_terminal.h"
#include "unit_test.h"
#include <stdio.h>
#include <stdlib.h>

void test_panic() {
  // set error code 0 to avoid crash.
  puts("test_panic is " COLOR_TERMINAL_GREEN("ok") " if panic");
  panic(0, "panic: should panic. error code is %d\n", 0);
}

void test_assert_eq_float() {
  assert_eq_float(1.0, 1.0);          // yes
  assert_eq_float(1.0, 1.0000000001); // yes
  assert_eq_float(0.0, -0.000000001); // yes
  // assert_eq_float(1.0, 0.0);          // no, panic
  puts("test_assert_eq_float is " COLOR_TERMINAL_GREEN("ok"));
}

void test_assert_eq_int() {
  assert_eq_int(1, 1);   // yes
  assert_eq_int(-1, -1); // yes
  assert_eq_int(0, 0);   // yes
  // assert_eq_int(1,   0); // no, panic
  puts("test_assert_eq_int is " COLOR_TERMINAL_GREEN("ok"));
}

int main(int argc, char *argv[]) {
  test_assert_eq_float();
  test_assert_eq_int();
  test_panic();
  return EXIT_SUCCESS;
}
