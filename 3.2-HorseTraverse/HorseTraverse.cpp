/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * (x, y) 表示当前位置, N * M 表示地图大小
 * left 表示剩余点的个数
 * visited 表示已经访问过的点
 * path 表示到达当前节点已走的路径
 */
bool traceBack(
    int x, int y, int N, int M, int left,
    vector<vector<bool>> &visited,
    vector<int> &paths);