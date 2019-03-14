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

ExprTree::ExprTree()
{
    root = NULL;
}

ExprTree::ExprTree(const string &expr)
{
    if (!isValid(expr))
    {
        cerr << "Error: invalid expression \"" << expr << "\"" << endl;
        cerr << "An empty tree created" << endl;
        root = NULL;
    }
    else
    {
        root = createFromInfix(expr);
    }
}

const ExprTree &ExprTree::operator=(const string &expr)
{
    if (!isValid(expr))
    {
        cerr << "Error: invalid expression \"" << expr << "\"" << endl;
        cerr << "Did nothing to *this" << endl;
        return *this;
    }
    if (root != NULL)
    {
        delete root;
    }
    root = createFromInfix(expr);
    return *this;
}

bool ExprTree::isValid(const string &expr)
{
    set<char> validChar = {
        '+', '-', '*', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '(', ')'}; /* 可扩展加入空格或制表符, 只不过这样就要做额外的判断 */

    // 检查是否含有不合法的字符
    for (char i : expr)
    {
        if (validChar.find(i) == validChar.end())
        {
            return false;
        }
    }

    // '(' 左边必须是运算符, 右边必须是数字
    // ')' 左边必须是数字, 右边必须是运算符
    // 运算符不能相邻
    enum element {DIGIT, OP, LB, RB, NULLe}; // 数字, 运算符, 左括号, 右括号
    element last = NULLe;
    int bracket = 0;
    int size = expr.size();
    for (int i = 0; i < size; i++)
    {
        if (expr[i] == '(')
        {
            // 左括号前面不能是数字或右括号
            if (last == DIGIT || last == RB)
            {
                return false;
            }
            bracket++;
            last = LB;
        }
        else if (expr[i] == ')')
        {
            // 右括号前面不能是左括号或运算符
            if (last == OP || last == LB || bracket == 0)
            {
                return false;
            }
            bracket--;
            last = RB;
        }
        else if ('0' <= expr[i] && expr[i] <= '9')
        {
            // 数字前面不能是右括号
            if (last == RB)
            {
                return false;
            }
            // 数字可能是连续的数个
            while (i + 1 < size && '0' <= expr[i + 1] && expr[i + 1] <= '9')
            {
                i++;
            }
            last = DIGIT;
        }
        else
        {
            // 运算符前面不能为空/左括号/运算符
            if (last == NULLe || last == LB || last == OP)
            {
                return false;
            }
            last = OP;
        }
    }

    // 最后结尾的只能是数字或右括号, 且括号数量匹配
    return (last == DIGIT || last == RB) && bracket == 0;
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
    cout << string(intdent, ' ') << rt->val << endl;
    ;
    display(rt->left, intdent + 2);
    display(rt->right, intdent + 2);
}

void ExprTree::display() const
{
    display(root, 0);
}

string ExprTree::toInfixExpression(ExprTreeNode *rt) const
{
    if (rt->type == NUMBER)
    {
        return rt->val;
    }

    // 表达式二叉树的节点, 要么没有子节点, 要么有两个子节点
    string lhs = toInfixExpression(rt->left);
    string rhs = toInfixExpression(rt->right);

    // 根据枚举类型 AtomicExpr 的定义, 可以直接用其数值除以2作为优先级
    // +- -> 0
    // */ -> 1
    if (rt->type / 2 > rt->left->type / 2)
    {
        lhs = "(" + lhs + ")";
    }
    if (rt->type / 2 >= rt->right->type / 2)
    {
        rhs = "(" + rhs + ")";
    }

    return lhs + rt->val + rhs;
}

string ExprTree::toInfixExpression() const
{
    return toInfixExpression(root);
}

string ExprTree::toPostfixExpression(ExprTreeNode *rt) const
{
    if (rt->type == NUMBER)
    {
        return rt->val + " ";
    }

    return toPostfixExpression(rt->left) +
           toPostfixExpression(rt->right) + rt->val + " ";
}

string ExprTree::toPostfixExpression() const
{
    return toPostfixExpression(root);
}

/* 累计用时: 2.5h */