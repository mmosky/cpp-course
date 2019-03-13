/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */
#include "ExprTree.h"
#include <iostream>

using namespace std;

ExprTreeNode::ExprTreeNode(
    const string &val, Expr type)
    : val(val), type(type)
{
    left = NULL;
    right = NULL;
}

ExprTreeNode *ExprTree::createFromInfix(
    const string &expression)
{
    // TODO: 合法性检查和规范化

    return ExprTree::_createFromInfix(expression);
}

ExprTreeNode *ExprTree::_createFromInfix(
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

    ExprTreeNode *rt = new ExprTreeNode(
        string(1, exp[pos1]), charToEnum.at(exp[pos1])); // 没有explicit啊, 为何不能触发隐式类型转换...

    rt->left = _createFromInfix(exp.substr(l, pos1 - l));
    rt->right = _createFromInfix(exp.substr(pos1, r - pos1));
}

void ExprTree::display(
    ExprTreeNode *rt, int intdent) const
{
    if (rt == NULL)
    {
        return;
    }
    cout << string(intdent, ' ') << rt->val;
    display(rt->left, intdent + 4);
    display(rt->right, intdent + 4);
}

void ExprTree::display() const
{
    display(root, 0);
}

/* 累计用时: 40min */