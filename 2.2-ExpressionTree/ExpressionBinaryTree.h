/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#ifndef EXPRESSION_BINARY_TREE_H
#define EXPRESSION_BINARY_TREE_H

#include <string>
#include <map>

enum AtomicExpression
{
    PLUS = 0,
    MINUS = 1,
    MULTIPLY = 2,
    DIVISION = 3,
    NUMBER = 4
};

const std::map<char, AtomicExpression> charToEnum = {
    {'+', PLUS},
    {'-', MINUS},
    {'*', MULTIPLY},
    {'/', DIVISION}};

class ExpressionBinaryTreeNode
{
  public:
    std::string val;                 // 该节点的值(可能是数字, 也可能是运算符)
    AtomicExpression type;           // 该节点的类型
    ExpressionBinaryTreeNode *left;  // 左子节点指针
    ExpressionBinaryTreeNode *right; // 右子节点指针

    ExpressionBinaryTreeNode(const std::string &val, AtomicExpression type);
};

/* 表达式二叉树 封装 */
class ExpressionBinaryTree
{
  public:
    /* 用户接口 建树, 首先进行合法性检查, 然后调用对应的私有函数 */
    static ExpressionBinaryTreeNode *createFromInfix(const std::string &expression);

  private:
    static ExpressionBinaryTreeNode *_createFromInfix(const std::string &expression);

  private:
    ExpressionBinaryTreeNode *root; // 根节点

    std::string toInfixExpression(ExpressionBinaryTreeNode *rt) const;
    std::string toPostfixExpression(ExpressionBinaryTreeNode *rt) const;

  public:
    /* 用户接口 */
    void display() const;
    std::string toInfixExpression() const;
    std::string toPostfixExpression() const;
};

#endif

/* 累计用时 20min */