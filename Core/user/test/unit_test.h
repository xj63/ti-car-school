#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

/// panic 崩溃
///
/// 打印错误信息到 stderr 并退出
///
/// 等价表达
/// ```c
/// fprintf(stderr, format, ...);
/// exit(error_code);
/// ```
///
/// eg.
/// ```c
/// panic(1, "panic: should panic! error_code is %d", 1);
/// ```
void panic(int error_code, const char *format, ...);

/// 断言两个 float 相等
///
/// 当两个浮点值的差在一定范围内(1e-6)，则正确，否则 painc
///
/// ```c
/// assert_eq_float(1.0, 1.0);          // yes
/// assert_eq_float(1.0, 1.0000000001); // yes
/// assert_eq_float(0.0, -0.000000001); // yes
/// assert_eq_float(1.0, 0.0);          // no, panic
/// ```
void assert_eq_float(float left, float right);

/// 断言两个 int 相等
///
/// ```c
/// assert_eq_int(1,   1); // yes
/// assert_eq_int(-1, -1); // yes
/// assert_eq_int(0,   0); // yes
/// assert_eq_int(1,   0); // no, panic
/// ```
void assert_eq_int(int left, int right);

#endif // !__UNIT_TEST_H__
