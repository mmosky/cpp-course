/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */
#include "ExprTree.h"
#include <iostream>

using namespace std;

ExprTreeNode::ExprTreeNode(const string &val, AtomicExpr type)
    : val(val), type(type)
{
    left = NULL;
    right = NULL;
}

ExprTreeNode::~ExprTreeNode()
{
    if (left != NULL)
    {
        delete left;
    }
    if (right != NULL)
    {
        delete right;
    }
}

ExprTree::ExprTree(const string &expr)
{
    // TODO: 合法性检查和规范化
    root = createFromInfix(expr);
}

const ExprTree &ExprTree::operator=(const string &expr)
{
    // TODO: 合法性检查和规范化
    if (root != NULL)
    {
        delete root;
    }
    root = createFromInfix(expr);
}

ExprTree::~ExprTree()
{
    if (root != NULL)
    {
        delete root;
    }
}

bool ExprTree::hasUselessBracket(const string &expr)
{
    int size = expr.size();
    if (expr[0] != '(' || expr[size - 1] != ')')
    {
        return false;
    }
    int bracket = 0;
    for (int i = 1; i < size - 1; i++)
    {
        bracket += (expr[i] == '(');
        bracket -= (expr[i] == ')');
        if (bracket < 0)
        {
            return false;
        }
    }
    return bracket == 0;
}

ExprTreeNode *ExprTree::createFromInfix(const string &expr)
{
    // 传递的是 const string, 不可更改, 所以用 l, r 表示这个字符串的左右边界
    int l = 0;
    int r = expr.size();

    // 如果有套在最外面的括号则把它们去除 TODO 可以优化成一次检查?
    while (hasUselessBracket(expr.substr(l, r - l)))
    {
        l++;
        r--;
    }

    // 检查 如果只含数字, 可以直接返回
    bool isNumber = true;
    for (int i = l; i < r; i++)
    {
        if (!isdigit(expr[i]))
        {
            isNumber = false;
            break;
        }
    }
    if (isNumber)
    {
        return new ExprTreeNode(expr.substr(l, r - l), NUMBER);
    }

    // 从右往左找到第一个不在括号内的 */ 和 +-
    int pos1 = -1, pos2 = -1;
    for (int i = r - 1, bkt = 0; i >= l; i--)
    {
        bkt -= (expr[i] == '(');
        bkt += (expr[i] == ')');
        if (bkt)
        {
            continue;
        }
        if (pos1 < 0 && (expr[i] == '+' || expr[i] == '-'))
        {
            pos1 = i; // 第一个加或减的位置
        }
        if (pos2 < 0 && (expr[i] == '*' || expr[i] == '/'))
        {
            pos2 = i; // 第一个乘或除的位置
        }
    }

    // 如果没有找到不在括号内的乘除, 那么这个节点的运算符是加减
    pos1 = pos1 < 0 ? pos2 : pos1;

    ExprTreeNode *rt = new ExprTreeNode(
        string(1, expr[pos1]), charToEnum.at(expr[pos1])); // 没有explicit啊, 为何不能触发隐式类型转换...

    // 递归建立左右子树
    rt->left = createFromInfix(expr.substr(l, pos1 - l));
    rt->right = createFromInfix(expr.substr(pos1 + 1, r - pos1 - 1));

    return rt;
}

void ExprTree::display(ExprTreeNode *rt, int intdent) const
{
    if (rt == NULL)
    {
        return;
    }
    cout << string(intdent, ' ') << rt->val << endl;;
    display(rt->left, intdent + 2);
    display(rt->right, intdent + 2);
}

void ExprTree::display() const
{
    display(root, 0);
}

/* 累计用时: 1.5h */