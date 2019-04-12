/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 * 
 * g++ DirectedGraph.cpp RangeIO.cpp Random.cpp Sleep.cpp main.cpp -o tmp -std=c++11
 */

#include "DirectedGraph.h"
#include "RangeIO.h"
#include "Random.h"
#include "Sleep.h"

#include <set>
#include <iostream>

using namespace std;

void manulInputEdges(DirectedGraph &g, int edgeNum);     // 手动输入所有的边
void randomGenerateEdges(DirectedGraph &g, int edgeNum); // 随机生成所有的边
/**
 * @param now (int): 当前正在访问的节点编号
 * @param g (DirectedGraph): 当前dfs遍历的图
 * @param visited (vector<bool>): visited[i] 表示编号为i的点是否已经访问过
 * @param path (vector<int>): 记录dfs的路径
 * @return: void
 */
void getDfsPath(int now, DirectedGraph &g, vector<bool> &visited, vector<int> &path);

// 打印图g从startNode开始dfs的路径
void printDfsPath(int startNode, DirectedGraph &g, vector<bool> &visited);

////////////////////////////////////////////////////////////////////////////
////////////////////////////////// 主函数 ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////
int main()
{
    cout << ">>>>>>>>>> 有向图的深度优先遍历演示 <<<<<<<<<<" << endl;

    cout << "  请输入图的大小(节点数目): ";
    int nodeNum = RangeIO::readIntFromLine(cin, 1, 10000);
    DirectedGraph g(nodeNum);

    cout << "  请输入边的数目: ";
    int edgeNum = RangeIO::readIntFromLine(cin, 0, 100000000);

    cout << "  是否随机生成边 (Y/n, 输入n以手动输入所有的边): ";
    string ran;
    getline(cin, ran);
    if (ran == "n" || ran == "N")
    {
        manulInputEdges(g, edgeNum);
    }
    else
    {
        randomGenerateEdges(g, edgeNum);
    }

    cout << "  请输入深度优先遍历的起点(点的编号从0开始): ";
    int startNode = RangeIO::readIntFromLine(cin, nodeNum - 1);
    vector<bool> visited(nodeNum, false);

    printDfsPath(startNode, g, visited);

    while (find(visited.begin(), visited.end(), false) != visited.end())
    {
        Sleep::mSleep(1000);
        cout << "\n由于图中所有的点不完全连通, 下面这些点还没有访问" << endl;
        for (int i = 0, cnt = 0; i < nodeNum; i++)
        {
            if (!visited[i])
            {
                cout << i << " ";
                cnt++;
                if (cnt % 5 == 0)
                {
                    cout << endl;
                    Sleep::mSleep(200);
                }
            }
        }
        cout << "\n是否在其中选择一个起点, 再次进行深度优先遍历?" << endl;
        cout << "输入起点编号以开始, 输入 -1 以退出: ";
        startNode = RangeIO::readIntFromLine(cin, -1, nodeNum - 1);
        while (startNode >= 0 && visited[startNode])
        {
            cout << "请输入一个上面列出的还未访问过的点: ";
            startNode = RangeIO::readIntFromLine(cin, -1, nodeNum - 1);
        }
        if (startNode < 0)
        {
            break;
        }
        printDfsPath(startNode, g, visited);
    }

    return 0;
}

void printDfsPath(int startNode, DirectedGraph &g, vector<bool> &visited)
{
    cout << "\n准备开始深度优先遍历...\n";
    vector<int> path;
    getDfsPath(startNode, g, visited, path);

    cout << "path:\n  " << startNode << ' ';
    for (int i = 1; i < path.size(); i++)
    {
        cout << "-> " << path[i] << ' ';
        if (i % 5 == 0)
        {
            cout << endl << "  ";
        }
        cout.flush();   // flush 以立刻输出, 否则会缓冲直到输出回车
        Sleep::mSleep(200);
    }
    cout << "Over" << endl;
}

void manulInputEdges(DirectedGraph &g, int edgeNum)
{
    int nodeNum = g.getNodeNum();
    printf("  点以编号标识, 共有 %d 个点, 因此编号范围是 [0, %d)\n", nodeNum, nodeNum);
    printf("  请根据提示添加每条边\n");
    for (int i = 1; i <= edgeNum; i++)
    {
        printf("  请输入第 %d 条边的起点: ", i);
        int u = RangeIO::readIntFromLine(cin, 0, nodeNum - 1);
        printf("  请输入第 %d 条边的终点: ", i);
        int v = RangeIO::readIntFromLine(cin, 0, nodeNum - 1);
        g.addEdge(u, v);
    }
}

void randomGenerateEdges(DirectedGraph &g, int edgeNum)
{
    // 随机生成的边不包含自回路/重边
    set<pair<int, int>> edgeSet; // 边的集合, 避免生成重复的边
    pair<int, int> anEdge;
    int nodeNum = g.getNodeNum();
    for (int i = 0; i < edgeNum; i++)
    {
        anEdge.first = anEdge.second = 0;
        while (anEdge.first == anEdge.second || edgeSet.find(anEdge) != edgeSet.end())
        {
            anEdge.first = Random::randint(0, nodeNum - 1);
            anEdge.second = Random::randint(0, nodeNum - 1);
        }
        g.addEdge(anEdge.first, anEdge.second);
    }
}

void getDfsPath(int now, DirectedGraph &g, vector<bool> &visited, vector<int> &path)
{
    visited[now] = true;
    path.push_back(now);
    for (int nxt : g.getLinkedNodes(now))
    {
        if (!visited[nxt])
        {
            getDfsPath(nxt, g, visited, path);
        }
    }
}