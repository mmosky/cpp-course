/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <cstdlib>

/**
 * Random 类
 * 用于生成随机数
 * 封装rand()和srand()
 */

class Random
{
private:
  static bool sranded;

public:
  static int randint();                       // 返回一个随机数
  static int randint(int maxVal);             // 返回 [0, maxVal] 的随机数
  static int randint(int minVal, int maxVal); // 返回 [minVal, maxVal] 的随机数
};

#endif