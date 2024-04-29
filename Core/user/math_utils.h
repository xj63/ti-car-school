#ifndef __MATH_UTILS_H__
#define __MATH_UTILS_H__

/// 回环算法
///
/// 对 num +/- range_size , 将范围限定到 (range_min, range_max]
///
/// error: 当range_max <= range_min 时直接返回 num
///
/// ```c
/// assert_eq_float(9.0, wrapping(9.0, 10.0, 9.0)); // error 范围错误
/// assert_eq_float(9.0, wrapping(9.0, 0.0, 10.0)); // 在范围内
/// assert_eq_float(1.0, wrapping(9.0, 0.0, 4.0));  // 回绕
/// assert_eq_float(2.0, wrapping(0.0, 1.0, 3.0));  // 回绕
/// ```
float wrapping(float num, float range_min, float range_max);

#endif // !__MATH_UTILS_H__
