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
 */

class Random
{
  private:
    static bool sranded;

  public:
    static int randint();
    static int randint(int maxVal);
    static int randint(int minVal, int maxVal);
};

#endif