/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */
#include "ExpressionBinaryTree.h"

using namespace std;

ExpressionBinaryTreeNode::ExpressionBinaryTreeNode(
    const string &val, AtomicExpression type)
    : val(val), type(type)
{
    left = NULL;
    right = NULL;
}

ExpressionBinaryTreeNode *ExpressionBinaryTree::createFromInfix(
    const string &expression)
{
    // TODO: 合法性检车和规范化

    return ExpressionBinaryTree::_createFromInfix(expression);
}

ExpressionBinaryTreeNode *ExpressionBinaryTree::_createFromInfix(
    const string &exp)
{
    // 传递的是 const string, 不可更改, 所以用 l, r 表示这个字符串的左右边界
    int l = 0;
    int r = exp.size();

    // 去括号
    if (exp[0] == '(')
    {
        l++;
        r--;
    }

    int pos1 = -1, pos2 = -1;
    // 找到第一个不在括号内的 */ 和 +-
    for (int i = l, lft = 0; i < r; i++)
    {
        lft += (exp[i] == '(');
        lft -= (exp[i] == ')');
        if (lft)
        {
            continue;
        }
        if (pos1 < 0 && (exp[i] == '*' || exp[i] == '/'))
        {
            pos1 = i; // 第一个乘或除的位置
        }
        if (pos2 < 0 && (exp[i] == '+' || exp[i] == '-'))
        {
            pos2 = i; // 第一个加或减的位置
        }
    }

    // 如果没有找到不在括号内的乘除, 那么这个节点的运算符是加减
    pos1 = pos1 < 0 ? pos2 : pos1;

    ExpressionBinaryTreeNode *rt = new ExpressionBinaryTreeNode(
        string(1, exp[pos1]), charToEnum.at(exp[pos1])); // 没有explicit啊, 为何不能触发隐式类型转换...

    rt->left = _createFromInfix(exp.substr(l, pos1 - l));
    rt->right = _createFromInfix(exp.substr(pos1, r - pos1));
}

/* 累计用时: 40min */