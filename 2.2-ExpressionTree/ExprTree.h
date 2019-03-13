/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#ifndef EXPR_TREE_H
#define EXPR_TREE_H

#include <string>
#include <map>

enum AtomicExpr
{
    PLUS = 0,
    MINUS = 1,
    MULTIPLY = 2,
    DIVISION = 3,
    NUMBER = 4
};

const std::map<char, AtomicExpr> charToEnum = {
    {'+', PLUS},
    {'-', MINUS},
    {'*', MULTIPLY},
    {'/', DIVISION}};

class ExprTreeNode
{
  public:
    std::string val;     // 该节点的值(可能是数字, 也可能是运算符)
    AtomicExpr type;     // 该节点的类型
    ExprTreeNode *left;  // 左子节点指针
    ExprTreeNode *right; // 右子节点指针

    ExprTreeNode(const std::string &val, AtomicExpr type);
};

/* 表达式二叉树 封装 */
class ExprTree
{
  public:
    /* 用户接口 建树, 首先进行合法性检查, 然后调用对应的私有函数 */
    static ExprTreeNode *createFromInfix(const std::string &expression);

  private:
    static ExprTreeNode *_createFromInfix(const std::string &expression);

  private:
    ExprTreeNode *root; // 根节点

    void display(ExprTreeNode *rt, int intdent) const;
    std::string toInfixExpression(ExprTreeNode *rt) const;
    std::string toPostfixExpression(ExprTreeNode *rt) const;

  public:
    /* 用户接口 */
    void display() const;
    std::string toInfixExpression() const;
    std::string toPostfixExpression() const;
};

#endif

/* 累计用时 20min */