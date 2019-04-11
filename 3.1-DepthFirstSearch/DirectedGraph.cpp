#include "DirectedGraph.h"
#include <string>

using namespace std;

DirectedGraph::DirectedGraph(int nodeNum)
    : nodeNum(nodeNum), edgeNum(0), linkedNodes(nodeNum, vector<int>())
{
}

int DirectedGraph::getNodeNum() const
{
    return nodeNum;
}

int DirectedGraph::getEdgeNum() const
{
    return edgeNum;
}

void DirectedGraph::addEdge(int u, int v)
{
    if (u < 0 || u >= nodeNum)
    {
        throw string("Error in addEdge(): u must be in the range of [0, ") + to_string(nodeNum) + ")";
    }
    if (v < 0 || v >= nodeNum)
    {
        throw string("Error in addEdge(): v must be in the range of [0, ") + to_string(nodeNum) + ")";
    }
    edgeNum++;
    linkedNodes[u].push_back(v); 
}

const vector<int> &DirectedGraph::getLinkedNodes(int u)
{
    if (u < 0 || u >= nodeNum)
    {
        throw string("Error in getLinkedNodes(): u must be in the range of [0, ") + to_string(nodeNum) + ")";
    }
    return linkedNodes[u];
}