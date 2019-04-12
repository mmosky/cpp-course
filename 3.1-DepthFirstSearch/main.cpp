/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 * 
 * g++ DirectedGraph.cpp RangeIO.cpp main.cpp -o tmp -std=c++11
 */

#include "DirectedGraph.h"
#include "RangeIO.h"
#include <iostream>

using namespace std;

void manulInputEdges(DirectedGraph &g, int edgeNum);        // 手动输入所有的边
void randomGenerateEdges(DirectedGraph &g, int edgeNum);    // 随机生成所有的边
/**
 * @param now (int): 当前正在访问的节点编号
 * @param depth (int): 当前节点在搜索树中的深度
 * @param g (DirectedGraph): 当前dfs遍历的图
 * @param visited (vector<bool>): visited[i] 表示编号为i的点是否已经访问过
 * @return: void
 */
void printDfsTree(int now, int depth, DirectedGraph &g, vector<bool> &visited);

////////////////////////////////////////////////////////////////////////////
////////////////////////////////// 主函数 ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////
int main()
{
    cout << ">>>>>>>>>> 图的深度优先遍历演示 <<<<<<<<<<" << endl;

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

    cout << "\n准备开始深度优先遍历...\n";
    printDfsTree(startNode, 0, g, visited);

    return 0;
}

void manulInputEdges(DirectedGraph &g, int edgeNum)
{
    // TODO
}

void randomGenerateEdges(DirectedGraph &g, int edgeNum)
{
    // 随机生成的边不包含自回路/重边
    // TODO
}

void printDfsTree(int now, int depth, DirectedGraph &g, vector<bool> &visited)
{
    // TODO
}