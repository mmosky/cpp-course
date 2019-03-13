/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#include "RandomWalk.h"

using namespace std;

void randomWalk(int N, bool &ok, int &length)
{
    static const int dx[4] = {0, 1, -1, 0};
    static const int dy[4] = {1, 0, 0, -1};

    int x = N / 2; // 初始位置
    int y = N / 2;
    length = 0;

    // 使用一个二维数组记录一个点是否访问过
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[x][y] = true;

    while (true)
    {
        vector<int> validDirections;

        // 将可选的方向放入vector中
        // 注意: 边界之外可选, 只有已走过的位置不可以选
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N ||
                ny < 0 || ny >= N || !visited[nx][ny])
            {
                validDirections.push_back(i);
            }
        }

        int size = validDirections.size();
        if (size == 0)  // 无路可走
        {
            ok = false;
            return;
        }

        // 随机选取方向
        int rnd = Random::randint(0, size - 1);
        x += dx[validDirections[rnd]];
        y += dy[validDirections[rnd]];
        length++;

        if (x < 0 || x >= N || y < 0 || y >= N) // 走出边界, 成功
        {
            ok = true;
            return;
        }
    }
}

/* 累计用时 20min */