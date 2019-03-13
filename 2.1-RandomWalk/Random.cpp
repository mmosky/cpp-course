/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#include "Random.h"

bool Random::sranded = false;

int Random::randint()
{
    if (!sranded)
    {
        srand(time(NULL));
        sranded = true;
    }
    return rand();
}

// FIXME: 当|maxVal - minVal|较大时, 实际并不能生成该范围内的随机数
int Random::randint(int minVal, int maxVal)
{
    if (!sranded)
    {
        srand(time(NULL));
        sranded = true;
    }
    return (rand() % (maxVal - minVal + 1)) + minVal;
}

int Random::randint(int maxVal)
{
    if (!sranded)
    {
        srand(time(NULL));
        sranded = true;
    }
    return randint(0, maxVal);
}