/**
 * 图结构的声明, 支持添加边/获取可达节点列表
 */

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <vector>
using std::vector;

class DirectedGraph
{
  private:
    int nodeNum, edgeNum;            // 节点和边的数量
    vector<vector<int>> linkedNodes; // linkedNodes[i]表示编号为i点节点可以到达的点
  public:

    // constructer, 必须在构造的时候指定点的数量, 不可以改变
    explicit DirectedGraph(int nodeNum);

    // getter
    int getNodeNum() const;
    int getEdgeNum() const;

    void addEdge(int u, int v);               // 添加一条从 u 到 v 的有向边, 添加失败则抛出异常
    const vector<int> &getLinkedNodes(int u); // 获取 u 可以到达的点的列表
};

#endif