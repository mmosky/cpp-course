/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#include "Random.h"

#include <vector>
#include <iostream>

// ok表示是否成功逃出, length表示路径长度
void randomWalk(int N, bool &ok, int &length);

void repeatTest(
    int N, int T,                 // 地图大小和重复次数
    double &failed,               // 失败概率
    double &averLength,           // 平均路径长度
    double &averFailedLength,     // 失败时平均路径长度
    double &averSucceededLength); // 成功时平均路径长度