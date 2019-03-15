/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#include "HorseTraverse.h"

#include <string>
#include <iostream>

using namespace std;

const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2. -2, -1};

int main()
{
    cout << "本程序将求解 N * N 的地图中放置一个马, 是否可以不重复的遍历所有点" << endl;
    string line;

    // 读入地图大小
    int N = -1;
    while (N < 0)
    {
        cout << "请输入地图大小 N = ";
        getline(cin, line);
        try
        {
            N = stoi(line);
        }
        catch (const out_of_range &e)
        {
            N = -1;
        }
        catch (const invalid_argument &e)
        {
            N = -1;
        }
        if (N < 5 || N > 50)    // TODO 待确定上限
        {
            cout << "N 的取值范围是 [5, 50]" << endl;
        }
    }

    // 读入初始坐标
    int x = -1, y = -1;
    while (x < 0)
    {
        cout << "请输入马的初始位置坐标(两个整数, 空格隔开): ";
        getline(cin, line);
        int pos = line.find(' ');
        if (pos == line.npos)
        {
            continue;
        }
        try
        {
            x = stoi(line.substr(pos));
            y = stoi(line.substr(pos, line.size() - pos));
        }
        catch (const out_of_range &e)
        {
            x = -1;
        }
        catch (const invalid_argument &e)
        {
            x = -1;
        }
        if (x < 0 || x >= N || y < 0 || y >= N)
        {
            cout << "横纵坐标取值范围为 [0, " << N << ")" << endl;
        } 
    }

    // TODO: 待扩展 设置"蹩马腿"的棋子

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<int> path;

    if ()
}