/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#include <vector>
#include <iostream>

/**
 * 马跳的八个方向的标识
 *   7   0  
 *  6     1
 *     S   
 *  5     2
 *   4   3  
 * 
 * 坐标方向为:
 * (0, 0) (0, 1)
 * (1, 0)  ...
 *              (N, M)
 */

extern const int dx[8], dy[8];

/**
 * (x, y) 表示当前位置, N * M 表示地图大小
 * left 表示剩余点的个数
 * visited 表示已经访问过的点
 * path 表示到达当前节点已走的路径
 */
bool traceBack(
    int x, int y, int N, int M, int left,
    std::vector< std::vector<bool> > &visited,
    std::vector<int> &paths);