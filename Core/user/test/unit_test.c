#include "unit_test.h"
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void panic(int error_code, const char *format, ...) {
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);

  exit(error_code);
}

void assert_eq_float(float left, float right) {
  float diff = fabsf(left - right);
  if (diff >= 1e-6)
    panic(1, "assert_eq panic:\nleft == %f\nright == %f\n", left, right);
}

void assert_eq_int(int left, int right) {
  if (left != right)
    panic(1, "assert_eq panic:\nleft == %d\nright == %d\n", left, right);
}
