/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 * 
 * 注意!! 类ExprTree没有定义拷贝构造函数, 所以不要尝试赋值
 */

#ifndef EXPR_TREE_H
#define EXPR_TREE_H

#include <string>
#include <map>
#include <set>

// 枚举类型, 定义标识符对应的值, 可用于优先级计算 (值 / 2)
enum AtomicExpr
{
    PLUS = 0,
    MINUS = 1,
    MULTIPLY = 2,
    DIVISION = 3,
    NUMBER = 4
};

// 解析字符串时用到的映射
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
    ~ExprTreeNode();
};

/* 表达式二叉树 封装 */
class ExprTree
{
  private:
    // 从表达式创建树, 返回树根, 会被ExprTree的构造函数调用
    static ExprTreeNode *createFromInfix(const std::string &expression);
    // 检查整个表达式两侧是否含有无用的括号, 比如 (1+2), ((1+2)*3)
    static bool hasUselessBracket(const std::string &expression);

  public:
    // 检查一个表达式是否合法的
    static bool isValid(const std::string &expression);

  private:
    ExprTreeNode *root; // 根节点

    /* 私有成员函数实现 分别为: 打印树; 返回中缀串; 返回后缀串 */
    void display(ExprTreeNode *rt, int intdent) const;
    std::string toInfixExpression(ExprTreeNode *rt) const;
    std::string toPostfixExpression(ExprTreeNode *rt) const;

  public:
    ExprTree();
    /* 建树, 首先进行合法性检查, 然后调用static私有函数生成一棵树 */
    ExprTree(const std::string &expression);
    ~ExprTree();

    /**
     * 可扩展:
     *   定义默认构造函数
     *   重载赋值运算符
     * 使得ExprTree类和string类之间无缝转换
     */

    const ExprTree &operator=(const std::string &expression);

    /* 用户接口 分别为: 打印树; 返回中缀串; 返回后缀串 */
    void display() const;
    std::string toInfixExpression() const;
    std::string toPostfixExpression() const;
};

#endif

/* 累计用时 20min */