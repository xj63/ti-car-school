float wrapping(float num, float range_min, float range_max) {
  float range_size = range_max - range_min;

  if (range_size <= 0)
    return num; // 目标区间为空，错误

  while (num <= range_min)
    num += range_size;

  while (num >= range_max)
    num -= range_size;

  return num;
}
